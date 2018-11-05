package beakJoon_Level15_BinomialCoefficient;

/* Question
 * �ڿ��� N�� ���� K�� �־����� �� ���� ��� (n) �� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
 * 								(k)
 */

import java.io.*;
import java.util.*;

public class BinomialCoefficient {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		if(K<0 || K>N) bw.write("0");
		else {
			K = Math.max(K, N-K);
			int upper = 1;
			int under = 1;
			for(int i = 1; i<=N-K; i++) {
				upper *=N-i+1;
				under *=i;
			}
			bw.write(""+upper/under);
		}
		bw.flush();
	}

}
