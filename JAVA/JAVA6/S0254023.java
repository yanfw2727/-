import java.util.Scanner;
public class S0254023{
	public static  int sum( int arr[], String[] str){
		int sum = 0;
		for(int i = 0; i < str.length; i++){
			
			if( arr[i] % 3 == 0){
				if( arr[i] % 2 == 0){
					sum = sum +0;
					}
				else{
					sum = sum + arr[i];
					}
					}
			}
		System.out.println(sum);
		return 0;
		}
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String str;
		do{
		System.out.println("請輸入一串數字:");
    	str = sc.nextLine();
		
		if(str.compareTo("q")== 0 || str.compareTo("Q") == 0){
		break;
		}
		String [] data = str.split(" ");
		int []arr = new int[data.length];
		for( int i = 0; i < data.length; i++){
			int temp = Integer.parseInt(data[i]);
			arr[i] += temp;
			}
		sum( arr, data);
		}while(str.compareTo("q") != 0||str.compareTo("Q") != 0); 
}
}