import java.io.*;
import java.util.Scanner;

class createFile {
    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Data to enter : ");
        String Str = scan.nextLine();
        FileWriter fw = new FileWriter("Output.txt");
        for (int i = 0; i < Str.length(); i++)
            fw.write(Str.charAt(i));
        System.out.println("Writing Successful...");
        fw.close();
        int ch;
        FileReader fr = null;
        try {
            fr = new FileReader("Output.txt");
        } catch (FileNotFoundException fe) {
            System.out.print("\tFile Not Found!!!!");
        }
        while ((ch = fr.read()) != -1)
            System.out.print((char) ch);
        fr.close();
    }
}
