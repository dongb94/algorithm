package beakJoon_Level6_OneDimensionalArray;

import java.io.*;
public class NumberOfNumber {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int A = Integer.parseInt(br.readLine());
		int B = Integer.parseInt(br.readLine());
		int C = Integer.parseInt(br.readLine());
		
		int[] non = new int[10];
		int mul = A*B*C;
		
		while(mul>0) {
			non[mul%10]++;
			mul/=10;
		}
		
		for(int i:non) bw.write(i+"\n");

		bw.flush();
	}
}