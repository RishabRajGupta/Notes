package Advanced.Collections;
import java.util.*;
public class Main {
    public static void main(String[] args){
        //List
        //ArrayList
        var arr = new ArrayList<Integer>();
        ArrayList<Integer> arr2 = new ArrayList<Integer>();
        for(int i = 0; i < 10; i++){
            arr.add(i);                         //adding element
        }
        arr.remove(9);                    //removing elements
        arr.set(8,10);                          //setting element at index 8 to 10
        System.out.println(arr);                //printing array
        var itr = arr.iterator();               //iterator
        while(itr.hasNext()){                   //hasNext() checks for next element
            int element = itr.next();           //Next() returns next element
            System.out.print(element + " ");
        }
        //vector class -- same as ArrayList (all the functions are same)
        Vector<Integer> vec = new Vector<Integer>();
        //stack
        Stack<Integer> stack = new Stack<Integer>();
        stack.push(1);                      //adds 1 to stack
        stack.push(2);
        stack.pop();                             //removes last element(here 2)
        stack.peek();                            //returns last element(here 1)
        System.out.println(stack);
        //priority queue
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        pq.add(21);                              //adds new element
        pq.add(22);
        pq.add(20);
        pq.add(23);
        System.out.println(pq);
        pq.poll();                              //peek + remove function
        pq.remove();
        pq.peek();
        System.out.println(pq);
        //linked list
        //Set
        HashSet set = new HashSet<Integer>();
        set.add(12);
        set.add(13);
        System.out.println(set  );
        //HashSet
        //TreeSet
        //LinkedHashSet
        LinkedHashSet<Integer> lhs = new LinkedHashSet<Integer>();
        lhs.add(2);
        lhs.add(5);
        lhs.add(1);
        System.out.println(lhs);
        //hashmap
        HashMap<Integer,String> hmap = new HashMap<>();
        hmap.put(1,"hello");
        hmap.put(2,"hello");
        hmap.replace(1,"world");
        System.out.println(hmap);
        hmap.remove(1);
        hmap.get(2);
        //treemap
        //linkedHashMap
    }
}