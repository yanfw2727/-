import java.util.Scanner;

public class S0254023 {
	public static void main(String[] args)	{
	String str;
	int X, a, i, timer = 0;
	Scanner c = new Scanner(System.in);
	System.out.println("Please input a number:");
	do{
	str = c.next();
	X = Integer.parseInt(str);
	System.out.print(X+"=");
	a = X;
	for( i = 2; i < X; i++){

        if(a % i == 0 ){
            a = a / i;
			timer++;
			if(a % i != 0){
				if(a != 1){
					System.out.print(i+"^"+timer+"*");
					timer = 0;
			}
				else if ( a == 1){
					System.out.println(i+"^"+timer);
					}
			}
            i--;
                 }
    }
	}while(str.compareTo("q") != 0 || str.compareTo("Q") != 0);
	}
	}