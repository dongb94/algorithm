package beakJoon_Level20_Math;
/* Q
* M과 N이 주어질 때 M이상 N이하의 자연수 중 완전제곱수인 것을 모두 골라 그 합을 구하고 그 중 최솟값을 찾는 프로그램을 작성하시오.
* 예를 들어 M=60, N=100인 경우 60이상 100이하의 자연수 중 완전제곱수는 64,  81,  100 이렇게 총 3개가 있으므로 그 합은 245가 되고 이 중 최솟값은 64가 된다.
* 
* comment
* 최대값이 10000이기 때문에 그냥 돌려도 됨 (1~100)
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
		for(int i=0; i<9; i++) { // 바빌로니아법 (제곱근 근사값)
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