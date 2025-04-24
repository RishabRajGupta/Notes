package oops.inheritance;
import com.sun.security.jgss.GSSUtil;

import java.util.*;

public class main {
    public static void main(String[] args){
        var control = new textbox();
        var control2 = new UIControl(true ){             //anonymous class example
                @Override
                public void control(){
                System.out.println("Controls Initiated");
            }
        };
        control.setText("Hello");                   //own property of textbox
        control.disable();                          //inherited property of textbox from UIControl
        System.out.println(control.isEnabled());

        var text1 = new textbox();
        var text2 = text1;
        System.out.println(text1.hashCode());       //memory location integer
        System.out.println(text2.hashCode());       //same for both
    }
}
