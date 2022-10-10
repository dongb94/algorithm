package beakJoon_Level25_Graph_Phase_Alignment;
/* Q
 * 올해 ACM-ICPC 대전 인터넷 예선에는 총 n개의 팀이 참가했다.
 *  팀은 1번부터 n번까지 번호가 매겨져 있다. 놀랍게도 올해 참가하는 팀은 작년에 참가했던 팀과 동일하다.

	올해는 인터넷 예선 본부에서는 최종 순위를 발표하지 않기로 했다.
	 그 대신에 작년에 비해서 상대적인 순위가 바뀐 팀의 목록만 발표하려고 한다.
	  (작년에는 순위를 발표했다) 예를 들어, 작년에 팀 13이 팀 6의 보다 순위가 높았는데, 올해 팀 6이 팀 13보다 순위가 높다면, (6, 13)을 발표할 것이다.
	
	창영이는 이 정보만을 가지고 올해 최종 순위를 만들어보려고 한다.
	 작년 순위와 상대적인 순위가 바뀐 모든 팀의 목록이 주어졌을 때, 올해 순위를 만드는 프로그램을 작성하시오.
	  하지만, 본부에서 발표한 정보를 가지고 확실한 올해 순위를 만들 수 없는 경우가 있을 수도 있고, 본부에서 발표한 정보가 일관성이 없는 잘못되었을 수도 있다.
	   이 두 경우도 모두 찾아내야 한다.
 */

import java.io.*;
import java.util.*;
public class Final_Rank {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int N = Integer.parseInt(br.readLine());
		
		for(int i=0; i<N; i++) {
			int nOfTeam = Integer.parseInt(br.readLine());
			int rank[] = new int[nOfTeam + 1];
			int scoreBoard[] = new int[nOfTeam];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<nOfTeam; j++) {
				int team = Integer.parseInt(st.nextToken());
				rank[team] = j;
				scoreBoard[j] = team;
			}
			
			
			
			int m = Integer.parseInt(br.readLine());
			LinkedList<Integer[]> change = new LinkedList<>();
			for(int j=0; j<m; j++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				if(rank[a] - rank[b] == 1) {
					rank[a]--;
					rank[b]++;
					int temp = scoreBoard[rank[a]];
					scoreBoard[rank[a]] = scoreBoard[rank[b]];
					scoreBoard[rank[b]] = temp;
				}
				else if(rank[a] - rank[b] == -1) {
					rank[a]++;
					rank[b]--;
					int temp = scoreBoard[rank[a]];
					scoreBoard[rank[a]] = scoreBoard[rank[b]];
					scoreBoard[rank[b]] = temp;
				}else {
					Integer[] temp = {a,b};
					change.add(temp);
				}
			}
			
			int check = 0;
			while(!change.isEmpty()) {
				if(check==change.size()) {
					bw.write("IMPOSSIBLE");
					break;
				}
				int a = change.getFirst()[0];
				int b = change.removeFirst()[1];
				if(rank[a] - rank[b] == 1) {
					rank[a]--;
					rank[b]++;
					int temp = scoreBoard[rank[a]];
					scoreBoard[rank[a]] = scoreBoard[rank[b]];
					scoreBoard[rank[b]] = temp;
					check = 0;
				}
				else if(rank[a] - rank[b] == -1) {
					rank[a]++;
					rank[b]--;
					int temp = scoreBoard[rank[a]];
					scoreBoard[rank[a]] = scoreBoard[rank[b]];
					scoreBoard[rank[b]] = temp;
					check = 0;
				}else {
					Integer[] temp = {a,b};
					change.addLast(temp);
					check++;
				}
				
			}
			if(change.isEmpty())
				for(int j:scoreBoard) {
					bw.write(j+" ");
				}
			bw.write("\n");
			bw.flush();
		}
	}
}
