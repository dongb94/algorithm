package beakJoon_Level10_PrimeNumber;
/* Problem
 * �־��� �� N�� �߿��� �Ҽ��� �� ������ ã�Ƽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
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
