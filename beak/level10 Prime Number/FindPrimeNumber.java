package beakJoon_Level10_PrimeNumber;
/* Problem
 * 주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오. 
 */
import java.io.*;
import java.util.*;

public class FindPrimeNumber {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		boolean isPrime[] = new boolean[1001];
		
		for(int i=2; i<=1000; i++) {
			isPrime[i] = true;
		}
		
		for(int i = 2; i<=1000; i++) {
			if(!isPrime[i]) continue;
			for(int j = i+i; j<=1000; j += i) {
				isPrime[j] = false;
			}
		}
		
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		int nOfPrime = 0;
		for(int i=0; i<N; i++) {
			if(isPrime[Integer.parseInt(st.nextToken())])
				nOfPrime++;
		}
		bw.write(nOfPrime+"");
		bw.flush();
	}

}
