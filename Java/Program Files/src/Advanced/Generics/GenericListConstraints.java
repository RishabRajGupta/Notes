package Advanced.Generics;

public class GenericListConstraints<T extends Number> {  //class that can store only numbers(int, float, byte etc)
    private T[] items = (T[]) new Number[10];   //array of type T
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