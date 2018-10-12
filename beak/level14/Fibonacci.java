package beakJoon_Level14_Fibonacci;

/* Question
 * �Ǻ���ġ ���� 0�� 1�� �����Ѵ�. 0��° �Ǻ���ġ ���� 0�̰�, 1��° �Ǻ���ġ ���� 1�̴�. �� ���� 2��° ���ʹ� �ٷ� �� �� �Ǻ���ġ ���� ���� �ȴ�.

	�̸� ������ �Ẹ�� Fn = Fn-1 + Fn-2 (n>=2)�� �ȴ�.
	
	n=17�϶� ���� �Ǻ���ġ ���� �Ẹ�� ������ ����.
	
	0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
	
	n�� �־����� ��, n��° �Ǻ���ġ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
 */

import java.io.*;

public class Fibonacci {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int N = Integer.parseInt(br.readLine());
		int dp[] = new int[50];
		dp[0] = 0;
		dp[1] = 1;
		for(int i=2; i<dp.length; i++) {
			dp[i] = dp[i-1]+dp[i-2];
		}
		
		bw.write(dp[N]+"\n");
		bw.flush();
	}
	
	private int Nth(int N) {
		if(N==1) return 0;
		if(N==2) return 1;
		
		return Nth(N-2)+Nth(N-1);
	}
}