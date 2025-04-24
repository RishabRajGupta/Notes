package Advanced.File_handling;
import java.util.*;
import java.io.*;
public class main_writer {
    public static void main(String[] args) {
        var sc = new Scanner(System.in);
        try {
            var s = new FileOutputStream("D:\\Programs\\Java\\Program Files\\src\\Advanced\\File_handling\\file.txt");
            //making a new fileOutputStream - opens a new text file
            var writer = new PrintWriter(s);
            //passing it to PrintWriter - connects PrintWriter to the textFile

            //alternative method
            var writer2 = new PrintWriter(new FileOutputStream("D:\\Programs\\Java\\Program Files\\src\\Advanced\\File_handling\\file.txt",true));
            System.out.println("Enter three lines of text:");
            for (int count = 1; count <= 3; count++)
            {
                String line = sc.nextLine();
                writer.println(line);
            }
            System.out.println("Data Written!");
            writer.close();
            System.out.println("Enter String to append : ");
            String data = sc.nextLine();
            writer2.println(data);
            System.out.println("Data Written!");
            writer2.close();                            //closed writer object
            sc.close();
        }catch (FileNotFoundException e){
            System.out.println("File Not Found!");
        }
    }
}
