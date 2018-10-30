package beakJoon_Level25_Graph_Phase_Alignment;
/* Q
 * ���� ACM-ICPC ���� ���ͳ� �������� �� n���� ���� �����ߴ�.
 *  ���� 1������ n������ ��ȣ�� �Ű��� �ִ�. ����Ե� ���� �����ϴ� ���� �۳⿡ �����ߴ� ���� �����ϴ�.

	���ش� ���ͳ� ���� ���ο����� ���� ������ ��ǥ���� �ʱ�� �ߴ�.
	 �� ��ſ� �۳⿡ ���ؼ� ������� ������ �ٲ� ���� ��ϸ� ��ǥ�Ϸ��� �Ѵ�.
	  (�۳⿡�� ������ ��ǥ�ߴ�) ���� ���, �۳⿡ �� 13�� �� 6�� ���� ������ ���Ҵµ�, ���� �� 6�� �� 13���� ������ ���ٸ�, (6, 13)�� ��ǥ�� ���̴�.
	
	â���̴� �� �������� ������ ���� ���� ������ �������� �Ѵ�.
	 �۳� ������ ������� ������ �ٲ� ��� ���� ����� �־����� ��, ���� ������ ����� ���α׷��� �ۼ��Ͻÿ�.
	  ������, ���ο��� ��ǥ�� ������ ������ Ȯ���� ���� ������ ���� �� ���� ��찡 ���� ���� �ְ�, ���ο��� ��ǥ�� ������ �ϰ����� ���� �߸��Ǿ��� ���� �ִ�.
	   �� �� ��쵵 ��� ã�Ƴ��� �Ѵ�.
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
