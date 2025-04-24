package Advanced.Generics;

public class GenericListComparable <T extends Comparable>{
    private T[] items = (T[]) new Comparable[10];   //array of type T
    private int count;

    //getter and setter
    public void setItems(T item){
        items[count++] = item;
    }
    public T getItems(int i){
        System.out.println(items[i]);
        return items[i];
    }
}
