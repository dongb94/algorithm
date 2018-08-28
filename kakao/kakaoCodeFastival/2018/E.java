//time out
package kakao_code_festival_2018;

import java.io.*;
import java.util.*;

public class E {
	public static tree nodes[];
	static int singer[];
	static int singer_[];
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    	String input = br.readLine();
		StringTokenizer st = new StringTokenizer(input, " ");
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		double J = Double.parseDouble(st.nextToken());
		
		singer = new int[N];
		singer_ = new int[N];
		nodes = new tree[N];
		Integer score[][] = new Integer[K][3];
		
		for(int i=0; i<N; i++) {
			nodes[i] = new tree();
		}
		
		input = br.readLine();
		st = new StringTokenizer(input, " ");
		for(int i=1; i<N; i++) {
			int parant = Integer.parseInt(st.nextToken());
			nodes[i].parant = parant-1;
			plus_noc(i);
			nodes[parant-1].c.add(i);
		}
		
		//singer
		input = br.readLine();
		st = new StringTokenizer(input, " ");
		for(int i=0; i<N; i++) {
			singer[i] = Integer.parseInt(st.nextToken());
			nodes[i].singer = singer[i]-1;
			for(int j=0; j<N; j++) {
				if(singer[j]==singer[i]) {
					if(i!=j)
						nodes[i].nOfSameSinger++;
					nodes[j].nOfSameSinger++;
				}
			}
		}
		
		for(int i=0; i<N; i++) {
			singer[i]=0;
			singer_[i]=-1;
		}
		
		for(int i=0; i<K; i++) {
			input = br.readLine();
			st = new StringTokenizer(input, " ");
			
			score[i][0] = Integer.parseInt(st.nextToken());
			score[i][1] = Integer.parseInt(st.nextToken())-1;
			score[i][2] = Integer.parseInt(st.nextToken());
		}
		
//		Arrays.sort(score, new Comparator<Integer[]>() {
//			public int compare(Integer[] o1, Integer[] o2) {
//				if(o1[0]>o2[0]) return 1;
//				else return -1;
//			}
//		});
		
		for(int i=0; i<K; i++) {
			int node_num = score[i][1];
			int p_score = score[i][2]/(nodes[node_num].nOfC+1);
			plus_score(node_num, p_score);
			
			check(node_num, J, score[i][0]);
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		for(int i=0; i<N; i++) {
			bw.write(Integer.toString(singer_[nodes[i].singer])+"\n");
		}
		bw.flush();
	}
	
	static void plus_noc(int i) {
		if(nodes[i].parant!=-1) {
			nodes[nodes[i].parant].nOfC++;
			plus_noc(nodes[i].parant);
		}
	}
	
	static void plus_score(int i, int score) {
		if(singer[nodes[i].singer]!=-1) singer[nodes[i].singer] += score;
		if(!nodes[i].c.isEmpty()) {
			for(int j:nodes[i].c) {
				plus_score(j, score);
			}
		}
	}
	
	static void check(int i, double J, int time) {
		if((double)singer[nodes[i].singer]/nodes[i].nOfSameSinger>J) {
			singer_[nodes[i].singer] = time;
			singer[nodes[i].singer] = -1;
		}
	}
}

class tree {
	int parant = -1;
	int nOfC =0;
	ArrayList<Integer> c = new ArrayList<>();
	int singer;
	int nOfSameSinger = 0;
}