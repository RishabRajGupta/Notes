#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <cstdlib>
#include <fcntl.h> // Required for O_CREAT

using namespace std;

#define MAX_ORDERS 5
#define TOTAL_CUSTOMERS 6

int buffer[MAX_ORDERS];
int order_count = 0;
int total_orders_placed = 0;
pthread_mutex_t order_mutex;
sem_t *empty_slots, *full_slots;
bool stop_chefs = false;  // New flag to stop chefs

void* customer(void* arg) {
    long id = (long)arg;
    int order = rand() % 1000;

    sem_wait(empty_slots);
    pthread_mutex_lock(&order_mutex);

    buffer[order_count++] = order;
    total_orders_placed++;  // Track total orders placed
    cout << "Customer:" << id << " placed order:" << order
         << ". Remaining capacity: " << MAX_ORDERS - order_count << endl;

    pthread_mutex_unlock(&order_mutex);
    sem_post(full_slots);

    pthread_exit(NULL);
}

void* chef(void* arg) {
    long id = (long)arg;
    while (true) {
        sem_wait(full_slots);
        pthread_mutex_lock(&order_mutex);

        if (order_count > 0) {
            int order = buffer[--order_count];
            cout << "Chef:" << id << " is preparing order:" << order
                 << ". Remaining orders: " << order_count << endl;
        }

        // Stop execution if all orders have been placed and processed
        if (total_orders_placed == TOTAL_CUSTOMERS && order_count == 0) {
            stop_chefs = true;
        }

        pthread_mutex_unlock(&order_mutex);
        sem_post(empty_slots);

        if (stop_chefs) break;  // Exit loop when all orders are done

        sleep(1);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t customers[TOTAL_CUSTOMERS], chefs[3];

    pthread_mutex_init(&order_mutex, NULL);
    
    empty_slots = sem_open("/empty_slots", O_CREAT, 0644, MAX_ORDERS);
    full_slots = sem_open("/full_slots", O_CREAT, 0644, 0);

    for (int i = 0; i < 3; i++)
        pthread_create(&chefs[i], NULL, chef, (void*)(long)i);

    sleep(2);

    for (int i = 0; i < TOTAL_CUSTOMERS; i++)
        pthread_create(&customers[i], NULL, customer, (void*)(long)i);

    for (int i = 0; i < TOTAL_CUSTOMERS; i++)
        pthread_join(customers[i], NULL);

    // Wait for all chef threads to finish
    for (int i = 0; i < 3; i++)
        pthread_join(chefs[i], NULL);

    pthread_mutex_destroy(&order_mutex);
    sem_close(empty_slots);
    sem_close(full_slots);
    sem_unlink("/empty_slots");
    sem_unlink("/full_slots");

    return 0;
}
