package beakJoon_Level14_Fibonacci;

/* Question
 * 피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.

	이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n>=2)가 된다.
	
	n=17일때 까지 피보나치 수를 써보면 다음과 같다.
	
	0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
	
	n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.
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