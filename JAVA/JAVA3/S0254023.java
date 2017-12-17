import java.util.Scanner;
public class S0254023 {
	public static void main(String[] args)	{
	
	String str, str1;
	int a, b, c, res;
	Scanner scanner = new Scanner(System.in);
	
	do{
	str = scanner.next();
	a = Integer.parseInt(str);
	b = scanner.nextInt();
	 int max = 1;
        for (int i = 2; i <= a; i++) {
            if (a % i == 0 && b % i == 0) {
                max = i;
            }
        }
	c = a * b / max;
		System.out.print("rectangle  quantity:");
		res = c/max;
		System.out.println(res);
		System.out.print("side of square:");
		res = c;
		System.out.println(res);
		
	
	}while(str.compareTo("q") != 0 || str.compareTo("Q") != 0);
	}
	}