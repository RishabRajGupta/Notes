package oops.inheritance;
public final class textbox extends UIControl {

    //final keyword ensures that no subclasses are formed from the class textbox

    private String text = "";

    public textbox(){                           //constructor
        super(false);
        System.out.println("Textbox");
    }
    @Override
    public void control(){
        System.out.println("Controls activated!");  //initialisation of abstract method
    }

    public static Integer length;

    public void setText(String text){
        this.text = text;
    }
    public void clear(){
        this.text = null;
    }

    @Override
    public boolean isEnabled() {                    //method overriding
        System.out.println("Enable Status returned");
        return super.isEnabled();
    }
}