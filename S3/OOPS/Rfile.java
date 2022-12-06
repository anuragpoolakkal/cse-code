import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.FileReader;
class Rfile
{
public static void main(String[] args) throws IOException
{
int ch;
FileReader fr=null;
try
{
fr=new FileReader("Output.txt");
}
catch(FileNotFoundException fe)
{
System.out.print("\tFile Not Found!!!!");
}
while((ch=fr.read())!=-1)
System.out.print((char)ch);
fr.close();
}
}

