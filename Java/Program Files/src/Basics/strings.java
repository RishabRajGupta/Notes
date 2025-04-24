package Basics;

public class strings {
    public static void main(String args[]){
        StringBuilder s = new StringBuilder();             //String builder
        String name = "Rishab Raj Gupta";
        String title = new String("Er.");

        int len = name.length();                           //finding length of a string
        String fullName = title + name;                    //String concatenation
        char a = fullName.charAt(4);                       //provides character at 4th index
        boolean isEqual = name.equals(title);              //checks the equality of Basics.strings
        int compare = name.compareTo(title);               //compares Basics.strings based on their ASCII values

        //string compression
        String str = "aaabbccddddd";
        String newstr = "";
        for(int i = 0; i < str.length(); i++){
            Integer count = 1;
            while(i < str.length()-1 && str.charAt(i) == str.charAt(i+1)){
                count++;
                i++;
            }
            newstr += str.charAt(i);
            if(count > 1){
                newstr += count.toString();
            }
        }
        System.out.println(newstr);
    }
}
