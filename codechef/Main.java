class Base {
	static int i;
     void foo() { i=10;System.out.println("Base"); }
}
  
public class Main {
    public static void main(String args[]) {
        Base b = new Base();
        b.foo();
        System.out.println(b.i);
    }
} 