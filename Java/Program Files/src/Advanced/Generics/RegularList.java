package Advanced.Generics;

public class RegularList {
    private int[] items = new int[10];          //array to store elements
    private int count;                          //counter to count elements

    // getter and setter
    public void setItems(int i){
        items[count++] = i;
    }
    public int getItems(int j){
        System.out.println(items[j]);
        return items[j];
    }
}
