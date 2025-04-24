package Advanced.Collections;

import java.util.*;
//using comparable in java collections
public class main_comparable {
    public static void main(String[] args){
        var list = new ArrayList<customer>();
        list.add(new customer("c", "e1"));
        list.add(new customer("a","e2"));
        list.add(new customer("b","e3"));

        //using sort method from collections interface
        //sorting on the basis of name
        Collections.sort(list);
        System.out.println(list);

        //sorting on the basis of email - using external comparator
        Collections.sort(list, new emailComparator());
        System.out.println(list);
    }
}
