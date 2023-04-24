class First
{
 synchronized public void display(String msg){
	System.out.println(msg);
	
	try
	{
		Thread.sleep(1000);
	}
	catch(InterruptedException e)
	{
		e.printStackTrace();
	}
 }
}

class Second extends Thread{
	String msg;
	First fobj;
	
	Second(First fp,String str){
		fobj=fp;
		msg=str;
		start();
    }
1

 	public void run(){
		fobj.display(msg);
 	}
}


public class threadsync
{
	public static void main(String[] args)
	{
 		First fnew=new First();
 		Second ss = new Second(fnew,"this program");
 		Second ss2 = new Second(fnew,"Aqeel");
 		Second ss1 = new Second(fnew,"is created by");
 	}
}
