package BaekJoon_Level28_Sliding_Window;
/* Q
* 	********FAIL**********
	N개의 수 A1, A2, ..., AN과 L이 주어진다.
	Di = Ai-L+1 ~ Ai 중의 최솟값이라고 할 때, D에 저장된 수를 출력하는 프로그램을 작성하시오. 이때, i ≤ 0 인 Ai는 무시하고 D를 구해야 한다.
*/
import java.io.*;
import java.util.*;
public class LowerValue {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int L = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		
		int point = -L;
		int list[]= new int[N];
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		for(int i=0; i<N; i++, point++) {
			int in = Integer.parseInt(st.nextToken());
			list[i] = in;
			if(point >= 0) {
				pq.remove(list[point]);
			}
			pq.add(in);
			
			bw.write(pq.peek()+" ");
		}
		bw.flush();
	}
}
