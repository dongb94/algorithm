package beakJoon_Level20_Math;
/* Q
* M�� N�� �־��� �� M�̻� N������ �ڿ��� �� ������������ ���� ��� ��� �� ���� ���ϰ� �� �� �ּڰ��� ã�� ���α׷��� �ۼ��Ͻÿ�.
* ���� ��� M=60, N=100�� ��� 60�̻� 100������ �ڿ��� �� ������������ 64,  81,  100 �̷��� �� 3���� �����Ƿ� �� ���� 245�� �ǰ� �� �� �ּڰ��� 64�� �ȴ�.
* 
* comment
* �ִ밪�� 10000�̱� ������ �׳� ������ �� (1~100)
*/

import java.io.*;

public class Perfect_Square{
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int M = Integer.parseInt(br.readLine());
		int N = Integer.parseInt(br.readLine());
		
		int x = 1;
		int y = 1;
		for(int i=0; i<9; i++) { // �ٺ��δϾƹ� (������ �ٻ簪)
			x = (x*x+M)/(2*x);
			y = (y*y+N)/(2*y);
		}
		if(x*x<M) {
			x++;
		}
		
		int sum = 0;
		for(int i=x; i<=y; i++) {
			sum += i*i;
		}
		if(sum == 0) 
			bw.write("-1\n");
		else{
			bw.write(sum+"\n");
			bw.write(x*x+"\n");
		}
		bw.flush();
	}
}