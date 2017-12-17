import java.util.Scanner;

public class S0254023 {

	double reuse(double x){
	double b;
		if( x == 1){
			return 1;
			}
		else{
		b = (reuse(x-1)*2)/x;
			return b;
			}
		}
		
	public static void main(String[] args)	{
	S0254023 v = new S0254023();
	String a;
	double x, n;
	Scanner scanner = new Scanner(System.in);
	do{
	a = scanner.next();
	x = Double.parseDouble(a);
	n = v.reuse(x);
	System.out.println(n);
	}while(a.compareTo("q")!=0||a.compareTo("Q")!=0);
	}
	}