package graph;
/* Q
 * ö���� �丶�� ���忡���� �丶�並 �����ϴ� ū â�� ������ �ִ�. �丶��� �Ʒ��� �׸��� ���� ���� ��� ������ ĭ�� �ϳ��� �־ â�� �����Ѵ�. 

	n*m ����

	â�� �����Ǵ� �丶��� �߿��� �� ���� �͵� ������, ���� ���� ���� �丶��鵵 ���� �� �ִ�.
	 ���� �� �Ϸ簡 ������, ���� �丶����� ������ ���� �ִ� ���� ���� �丶����� ���� �丶���� ������ �޾� �Ͱ� �ȴ�.
	  �ϳ��� �丶���� ������ ���� ����, ������, ��, �� �� ���⿡ �ִ� �丶�並 �ǹ��Ѵ�.
	  �밢�� ���⿡ �ִ� �丶��鿡�Դ� ������ ���� ���ϸ�, �丶�䰡 ȥ�� ������ �ʹ� ���� ���ٰ� �����Ѵ�.
	   ö���� â�� ������ �丶����� ��ĥ�� ������ �� �Ͱ� �Ǵ���, �� �ּ� �ϼ��� �˰� �;� �Ѵ�.
	
	�丶�並 â�� �����ϴ� ���ڸ���� ���ڵ��� ũ��� ���� �丶���� ���� ���� �丶����� ������ �־����� ��, ��ĥ�� ������ �丶����� ��� �ʹ���, �� �ּ� �ϼ��� ���ϴ� ���α׷��� �ۼ��϶�.
	 ��, ������ �Ϻ� ĭ���� �丶�䰡 ������� ���� ���� �ִ�.
 */
import java.io.*;
import java.util.*;
public class Tomato {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		int box[][] = new int[M][N];
		LinkedList<Integer[]> qqq = new LinkedList<>();
		int depth;
		
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				box[i][j] = Integer.parseInt(st.nextToken());
				if(box[i][j] == 1) {
					Integer[] root = {i,j};
					qqq.add(root);
				}
			}
		}
		
		while(true) {
			Integer[] now = qqq.removeFirst();
			int n = now[0];
			int m = now[1];
			if(n!=0 && box[n-1][m] == 0) {
				box[n-1][m] = box[n][m]+1;
				Integer[] next = {n-1, m};
				qqq.add(next);
			}
			if(n!=M-1 && box[n+1][m] == 0) {
				box[n+1][m] = box[n][m]+1;
				Integer[] next = {n+1, m};
				qqq.add(next);
			}
			if(m!=0 && box[n][m-1] == 0) {
				box[n][m-1] = box[n][m]+1;
				Integer[] next = {n, m-1};
				qqq.add(next);
			}
			if(m!=N-1 && box[n][m+1] == 0) {
				box[n][m+1] = box[n][m]+1;
				Integer[] next = {n, m+1};
				qqq.add(next);
			}
			
			
			if(qqq.isEmpty()) {
				depth = box[n][m]-1;
				break;
			}
		}
		
		for(int i=0; i<M; i++) {
			for(int j=0; j<N; j++) {
				if(box[i][j] == 0) {
					bw.write("-1\n");
					bw.flush();
					return;
				}
			}
		}
		bw.write(depth+"\n");
		bw.flush();
		
	}

}
