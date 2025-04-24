#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

int cnt = 1;
int readerCount = 0;
pthread_mutex_t mutexLock;  // Renamed from 'mutex' to avoid conflicts
pthread_mutex_t printLock;
pthread_mutex_t wrtLock;  // Replacing semaphore with mutex

void* reader(void* arg) {
    int id = *((int*)arg);

    // Entry section
    pthread_mutex_lock(&mutexLock);
    readerCount++;
    if (readerCount == 1)  // First reader locks the writer
        pthread_mutex_lock(&wrtLock);
    pthread_mutex_unlock(&mutexLock);

    // Critical section (Reading)
    pthread_mutex_lock(&printLock);
    cout << "Reader " << id << ": read cnt as : " << cnt << endl;
    pthread_mutex_unlock(&printLock);

    // Exit section
    pthread_mutex_lock(&mutexLock);
    readerCount--;
    if (readerCount == 0)  // Last reader unlocks the writer
        pthread_mutex_unlock(&wrtLock);
    pthread_mutex_unlock(&mutexLock);

    pthread_exit(NULL);
}

void* writer(void* arg) {
    int id = *((int*)arg);

    // Writer needs exclusive access
    pthread_mutex_lock(&wrtLock);

    // Critical section (Writing)
    cnt = cnt * 2;
    pthread_mutex_lock(&printLock);
    cout << "Writer " << id << ": modified cnt to : " << cnt << endl;
    pthread_mutex_unlock(&printLock);

    pthread_mutex_unlock(&wrtLock);

    pthread_exit(NULL);
}

int main() {
    pthread_t r[10], w[5];
    int r_id[10], w_id[5];

    // Initialize mutexes
    pthread_mutex_init(&mutexLock, NULL);
    pthread_mutex_init(&printLock, NULL);
    pthread_mutex_init(&wrtLock, NULL);

    // Create reader threads
    for (int i = 0; i < 10; i++) {
        r_id[i] = i + 1;
        pthread_create(&r[i], NULL, reader, &r_id[i]);
    }

    // Create writer threads
    for (int i = 0; i < 5; i++) {
        w_id[i] = i + 1;
        pthread_create(&w[i], NULL, writer, &w_id[i]);
    }

    // Join reader threads
    for (int i = 0; i < 10; i++) {
        pthread_join(r[i], NULL);
    }

    // Join writer threads
    for (int i = 0; i < 5; i++) {
        pthread_join(w[i], NULL);
    }

    // Destroy mutexes
    pthread_mutex_destroy(&mutexLock);
    pthread_mutex_destroy(&printLock);
    pthread_mutex_destroy(&wrtLock);

    return 0;
}
