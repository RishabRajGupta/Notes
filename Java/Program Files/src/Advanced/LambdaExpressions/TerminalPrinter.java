package Advanced.LambdaExpressions;

//class that implements printer interface
public class TerminalPrinter implements printer {
    @Override
    public void print(String message){
        System.out.println(message);
    }
}
