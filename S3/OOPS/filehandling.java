import java.io.FileWriter;
import java.io.IOException;

class createFile {
    public static void main (String[] args) {
        String str = "file handling in Java using" + " file writer and file reader";
        FileWriter hv = new FileWriter("file.txt");
    }
}