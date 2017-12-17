import java.util.Scanner;
public class S0254023 {
	public static void max( int arr[], String []str){
		int max = -999999;
		for(int i = 0; i < str.length; i++){
    		if( arr[i] > max){
    			max = arr[i];
    		}
			}
			System.out.print("最大值="+max);
			}
	public static void min( int arr[], String []str){
		int min = 999999;
		for(int i = 0; i < str.length; i++){
    		if( arr[i] < min){
    			min = arr[i];
    		}
			}
			System.out.println("    最小值="+min);
			}	
	public static void sort( int arr[], String []str){
    	for(int i = 0 ;i < str.length; i++){
    		for(int j = 0; j < str.length; j++){
    			if(arr[i] < arr[j]){
    				int res;
    				res = arr[i];
    				arr[i] = arr[j];
    				arr[j] = res;
    			}
    			}
    		}
			
    	System.out.print("排序後:");
    	for(int i = 0 ; i < str.length; i ++){
    		System.out.print(arr[i]+", ");
    	}
			}
    public static void main(String[] args) {
    	
		String str;
    	Scanner sc = new Scanner(System.in);
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
    	System.out.print("排序前:");
    	for(int i = 0 ; i < data.length; i ++){
    		System.out.print(arr[i]+", ");
    	}
    	System.out.println();
		max( arr, data);
		min( arr, data);
		sort( arr, data);
		}while(str.compareTo("q") != 0||str.compareTo("Q") != 0); 
}
}