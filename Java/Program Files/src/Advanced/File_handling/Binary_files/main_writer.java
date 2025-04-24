package Advanced.File_handling.Binary_files;
import java.io.*;
public class main_writer {
    public static void main(String args[]) throws IOException {
        try{
            var writer = new ObjectOutputStream(new FileOutputStream("D:\\Programs\\Java\\Program Files\\src\\Advanced\\File_handling\\Binary_files\\file.dat"));
            writer.writeByte((int) 'A');
            writer.writeUTF("Hello World");
            System.out.println("Data Written!");
            writer.close();
        }catch (FileNotFoundException e){
            System.out.println("File Not Found!");
        }
    }
}
