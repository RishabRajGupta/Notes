package Advanced.File_handling;
import java.io.*;
import java.util.*;

public class main_reader {
    public static void main(String[] args) throws IOException{
        try{
            var r = new FileReader("D:\\Programs\\Java\\Program Files\\src\\Advanced\\File_handling\\file.txt");
            var reader = new BufferedReader(r);
            String line;
            String input = "";
            while ((line = reader.readLine()) != null){
                input += line + ",";
                System.out.println(input);
            }
            //String Tokenizer
            var tokenizer = new StringTokenizer(input, " ");    //tokenizer object
            int count = tokenizer.countTokens();                      //counting the number of tokens
            var arr = new String[count];                              //array to store tokens
            int i = 0;
            while(tokenizer.hasMoreTokens()) {                        //checks if it has more tokens
                arr[i] = tokenizer.nextToken();
                i++;
            }
            System.out.println("\nTokens:");
            for (String token : arr) {
                System.out.println(token);
            }
            reader.close();
        }catch (FileNotFoundException e){
            System.out.println("File Not Found!");
        }
    }
}
