package Advanced.Generics;

public class main {
    public static void main(String[] args){

        //Regular List Object - can have only one type (int/float/boolean/etc)
        RegularList rl = new RegularList();
        rl.setItems(10);
        rl.setItems(12);
        rl.getItems(1);

        //Generic List Object - can have multiple types
        //Integer Type
        GenericList<Integer> gl = new GenericList<>();
        gl.setItems(100);
        gl.setItems(45);
        gl.getItems(0);
        //String Type
        GenericList<String> gl1 = new GenericList<>();
        gl1.setItems("hello");
        gl1.setItems("Generics");
        gl1.getItems(1);
        //Object Type
        GenericList<Object> gl2 = new GenericList<>();
        gl2.setItems("java");
        gl2.setItems(2);
        gl2.getItems(0);
        //User Defined Class Type
        GenericList<User> gl3 = new GenericList<>();
        gl3.setItems(new User("ABC",1,5));
        gl3.setItems(new User());
        gl3.getItems(0);

        //Constraints - Number (Integer, Float, Byte, Long, Double, ....)
        GenericListConstraints<Integer> gl4 = new GenericListConstraints<>();

        //Constraints - Comparable
        var UserC = new UserComparable(10);
        var UserC2 = new UserComparable(12);
        UserC.compareTo(UserC2);
        GenericListComparable<UserComparable> gl5 = new GenericListComparable<>();
        gl5.setItems(UserC);
        gl5.setItems(UserC2);
        gl5.setItems(new UserComparable(23));
        gl5.getItems(1);

        //Generic Methods
        var Util = new UtilityTools();
        System.out.println(Util.max(2,3));          //max function
        Util.print("ID Number",1305);
    }
}
