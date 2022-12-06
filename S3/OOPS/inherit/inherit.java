import java.util.*;

class inherit {
	public static void main(String[] args) {
		officer o1 = new officer();
		manager m1 = new manager();

		o1.name = "Anil";
		o1.age = 40;
		o1.number = "9847651024";
		o1.address = "Rose Villa, Delhi";
		o1.salary = 18000;
		o1.specialization = "Data Science";

		m1.name = "Raj";
		m1.age = 28;
		m1.number = "976543218";
		m1.address ="Surya Homes, Banglore";
		m1.salary = 20000;
		m1.department = "Finance";

		System.out.println(o1.name);
		System.out.println(o1.age);
		System.out.println(o1.number);
		System.out.println(o1.address);
		System.out.println(o1.specialization);
		o1.printsalary();

		System.out.println(m1.name);
		System.out.println(m1.age);
		System.out.println(m1.number);
		System.out.println(m1.address);
		System.out.println(m1.department);
		m1.printsalary();
	}
}
