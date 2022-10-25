public class shape {
void noOfSides() {
	};

}

public class triangle extends shape {
	void noOfSides() {
	System.out.println("no of sides = 3");
	}
}

public class hexagon extends shape {
	void noOfSides() {
	System.out.println("no of sides = 6");
	}
}

public class rectangle extends shape {
	void noOfSides() {
	System.out.println("no of sides = 4");
	}
}

class poly {
public static void main (String[] args) {
	triangle t1 = new triangle ();
	rectangle r1 = new rectangle();
	hexagon h1 = new hexagon();

	t1.noOfSides();
	r1.noOfSides();
	h1.noOfSies();
	}
}
