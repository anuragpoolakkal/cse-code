class A {
	void show() {
		System.out.println("This is object of class");
		}
	}
	
public class garbage {
	public static void main (String args[]) {
		A obj1 = new A();
		obj1.show();
		obj1 = null;
		System.gc();
		obj1.show();
	}
}
