import java.util.Scanner;
public class S0254023 {
	public static void main(String[] args)	{
		
		int i, j, n;
		String a;
		Scanner scanner = new Scanner(System.in);
		
		
		
		do{
		a = scanner.next();
		n = Integer.parseInt(a);
			for(i = n;i>=1; i-- ){
				for(j = i; j>=1; j--){
				System.out.print("*");
			}
			System.out.println();
		}
		for(i = 2;i <=n; i++){
			for(j = 1; j <=i;j++){
				System.out.print("*");
			}
			System.out.println();
		}
		}while(a.compareTo("q")!=0||a.compareTo("Q")!=0);
	}
	}
