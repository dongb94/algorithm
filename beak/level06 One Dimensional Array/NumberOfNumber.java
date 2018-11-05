package beakJoon_Level6_OneDimensionalArray;

////Question
/*
 * �� ���� �ڿ��� A, B, C�� �־��� �� A��B��C�� ����� ����� 0���� 9���� ������ ���ڰ� �� ���� ���������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ��� A = 150, B = 266, C = 427 �̶�� 

A �� B �� C = 150 �� 266 �� 427 = 17037300 �� �ǰ�, 

����� ��� 17037300 ���� 0�� 3��, 1�� 1��, 3�� 2��, 7�� 2�� ������.


ù° �ٿ��� A��B��C�� ����� 0 �� �� �� �������� ����Ѵ�. ���������� ��° �ٺ��� �� ��° �ٱ��� A��B��C�� ����� 1���� 9������ ���ڰ� ���� �� �� �������� ���ʷ� �� �ٿ� �ϳ��� ����Ѵ�.
 */

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