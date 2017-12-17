import java.io.*;
public class S0254023{
	public static void main(String Args[]) throws IOException{
		FileReader fr = new FileReader("C:\\flie pratice.txt");
		FileWriter fw = new FileWriter("C:\\out.txt");
		BufferedReader buf = new BufferedReader(fr);
		BufferedWriter bfw = new BufferedWriter(fw);
		String [] str = new String[5];
		for(int i = 0; i < 5 ; i++){
			str [i]= buf.readLine();
		}
		for( int i = 0; i < 5; i++){

			String [] arr = str[i].split(" ");
			int data[] = new int [arr.length];
    		for (int j = 0 ; j < arr.length ; j++){
       			int temp = Integer.parseInt(arr[j]);
      		 	data[j] += temp;
     		}
			int tmp = 0;
     		for( int j = 0; j < arr.length ; j ++){

     			tmp = tmp + data[j];
     		}
     		double avg = (double)tmp /(double)arr.length;
     		tmp = 0;
     		bfw.write(String.valueOf(avg));
     		bfw.newLine();
		}

	bfw.flush();
	fw.close();
	}
	}
