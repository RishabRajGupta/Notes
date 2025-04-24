package Advanced.Generics;

public class UtilityTools {
    //Generic Method
    public <T extends Comparable<T>> T max (T a, T b){
        return (a.compareTo(b) > 0) ? a : b;
    }
    public <K,V extends Number> void print(K key,V Value){
        System.out.println(key + " = " + Value);
    }
}
