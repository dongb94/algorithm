package beakJoon_Level28_Sliding_Window;
/* Q
* 	********FAIL**********
	N���� �� A1, A2, ..., AN�� L�� �־�����.
	Di = Ai-L+1 ~ Ai ���� �ּڰ��̶�� �� ��, D�� ����� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. �̶�, i �� 0 �� Ai�� �����ϰ� D�� ���ؾ� �Ѵ�.
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
