package graph;
/* Q
 * 철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다. 

	n*m 상자

	창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다.
	 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다.
	  하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다.
	  대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다.
	   철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.
	
	토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라.
	 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.
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
