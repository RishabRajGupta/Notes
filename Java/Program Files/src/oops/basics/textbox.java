package oops.basics;
public class textbox {                                      //class named textbox

    //properties OR attributes OR fields
    public String text = "";                                //initialised with a value to prevent NullPointerException
    public static Integer length;

    //functions OR methods
    public void setText(String text){
        this.text = text;
    }
    public void clear(){
        this.text = null;
    }
}
