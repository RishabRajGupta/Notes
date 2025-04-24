package Advanced.Swing_Basics;

import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        var frame = new JFrame("RISHAB");
        frame.setSize(400, 400);

        var l1 = new JLabel("Label1");
        l1.setBounds(50,60,95,20);
        var button = new JButton("Click Here");
        button.setBounds(50,100,95,20);

        var l2 = new JLabel("Label2");
        l2.setBounds(50,160,95,20);
        var b = new JButton("Next");
        b.setBounds(50,200,95,20);

        frame.setLayout(null);
        frame.add(l1);
        frame.add(button);
        frame.add(l2);
        frame.add(b);
        frame.setVisible(true);

    }
}
