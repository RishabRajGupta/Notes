package oops.inheritance;

public abstract class UIControl {
    private boolean isEnabled = false;

    public UIControl(boolean text) {                        //Constructor
        this.isEnabled = text;
        System.out.println("UIControl");
    }

    public void enable(){
        isEnabled = true;
    }
    public void disable(){
        isEnabled = false;
    }
    public boolean isEnabled(){
        return isEnabled;
    }
    public abstract void control();
}
