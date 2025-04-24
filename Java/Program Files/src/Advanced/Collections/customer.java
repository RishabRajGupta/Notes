package Advanced.Collections;

//class made comparable<to itself> to use sorting
public class customer implements Comparable<customer> {
    private String name;
    private String email;

    public customer(String name, String email){
        this.name = name;
        this.email = email;
    }

    public String getEmail(){
        return this.email;
    }

    //defining comparison factor for sorting
    @Override
    public int compareTo(customer other){
        return this.name.compareTo(other.name);
    }

    //making method to print
    @Override
    public String toString(){
        return this.name + " : " + this.email;
    }
}
