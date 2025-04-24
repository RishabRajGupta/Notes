package Advanced.Exception_Handling;

public class InsufficientFundException extends Exception {  //exception class OR user defined exception
    public InsufficientFundException(){
        super("Insufficient Funds in your Account!");       //default message to be shown
    }
    public InsufficientFundException(String message){
        super(message);                                     //custom message defined while using
    }
}
