import java.io.*;

publc class filehandling {
    public static void main (String[] args) throws exception {
        File inf = new File("in.txt");
        File outf = new FIle("out.txt");
        FileReader ins = new FileReader(ins);
        FileReader outs = new FileReader(outs);
        
        int ch;
        while((ch=ins.read() != -1)){
            out.write(ch);
        }

        if (outs != null) {
            System.out.print("Content written successfully");
            ins.close();
            outs.close();
        }
    }
}
