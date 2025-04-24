package Advanced.File_handling.Binary_files;
import java.io.*;
public class main_reader {
    public static void main(String args[]) throws IOException{
        try{
            var reader = new ObjectInputStream(new FileInputStream("D:\\Programs\\Java\\Program Files\\src\\Advanced\\File_handling\\Binary_files\\file.dat"));
            try{
                while(true){
                    System.out.println(reader.readInt());
                    System.out.println(reader.readChar());
                }
            } catch (EOFException ex){
                System.out.println("End Of File!");
            }
            reader.close();
        } catch (FileNotFoundException e){
            System.out.println("File Not Found!");
        }
    }
}
