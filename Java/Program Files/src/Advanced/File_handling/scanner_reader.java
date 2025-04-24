package Advanced.File_handling;
import java.util.*;
import java.io.*;
public class scanner_reader {
    //Multiple datatype reader
    public static void Multiple_datatype_reader(File filename){
        try{
            Scanner sc2 = new Scanner(filename);
            if(filename.canRead()){
                System.out.println("Data Found : ");
                while(sc2.hasNextLine()){                                   //reads and returns a line
                    String line = sc2.nextLine();
                    Scanner sc3 = new Scanner(line);                        //reads the line
                    sc3.useDelimiter(",");                          //separates the line contents whenever comma is encountered
                    System.out.println("Name : " + sc3.next());             //reads only string from line
                    System.out.println("En No. : " + sc3.nextInt());     //reads only int from line
                    System.out.println("Balance : " + sc3.nextFloat());     //reads only float from line
                    System.out.println();
                }
            }
        }catch (FileNotFoundException e){
            System.out.println("File Not Found!");
        }
    }
    public static void main(String[] args){
        try{
            //new file object
            var file = new File(("D:\\Programs\\Java\\Program Files\\src\\Advanced\\File_handling\\file.txt"));
            var file2 = new File(("D:\\Programs\\Java\\Program Files\\src\\Advanced\\File_handling"));
            Scanner sc = new Scanner(file);                 //reader for file
            if(file.canRead()){                             //checks if OS permits to read the file
                String files[] = file2.list();              //returns array of files inside the directory
                for(String i : files){
                    System.out.println(i);
                }
                while(sc.hasNextLine()){                    //checks for EOF
                    String line = sc.nextLine();
                    System.out.println(line);
                }
                Multiple_datatype_reader(file);
            }
        } catch (FileNotFoundException e){
            System.out.println("File not found!");
        }
    }
}