package Advanced.Generics;
class parent{
    private int value;
    public parent(int value){
        this.value = value;
    }
}
class child extends parent{
    public child(int value){
        super(10);
    }
}
public class WildCards {
    //here ? is the wildcard element

    //extends is used for parent and all inherited classes below
    //while using extends we can only read files
    public static void read(GenericList<? extends parent> user){
        parent x = user.getItems(0);
        Object y = user.getItems(1);
        System.out.println(x + " & " + y);
    }
    //super is used for parent and the class above it i.e. Object
    //while using super we can write and read files
    public static void write(GenericList<? super parent> user){
        user.setItems(new parent(11));
        Object x = user.getItems(0);
        System.out.println(x);
    }
    public static void main(String[] args){
        var li = new GenericList<parent>();
        li.setItems(new parent(100));
        li.setItems(new parent(101));
        read(li);
        write(li);
    }
}
