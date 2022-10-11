package BaekJoon_Level26_Graph_ShortestPath;
/* Q
 * 방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 단, 모든 간선의 가중치는 10 이하의 자연수이다.
 */
import java.io.*;
import java.util.*;
public class ShortestPath {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int V = Integer.parseInt(st.nextToken());
		int E = Integer.parseInt(st.nextToken());
		
		int K = Integer.parseInt(br.readLine());//start node
		
		int[] shortest = new int[V+1];
		Vector<Integer[]> edge[] = new Vector[V+1];
		
		for(int i=1; i<=V; i++) {
			shortest[i] = Integer.MAX_VALUE;
			edge[i] = new Vector<>();
		}
		
		for(int i=0; i<E; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			int weight = Integer.parseInt(st.nextToken());
			Integer[] priorityEdge = {end, weight};
			edge[from].add(priorityEdge);
		}
		
		
		PriorityQueue<Node> pq = new PriorityQueue<>();
		shortest[K]=0;
		Integer[] StartNode = {shortest[K], K};
		pq.offer(new Node(shortest[K] , K));
		
		while(!pq.isEmpty()) {
			Node cur = pq.poll();
			int curNode = cur.nodeNum;
			for(int i=0; i<edge[curNode].size(); i++) {
				int endNode = edge[curNode].get(i)[0];
				int length = cur.length + edge[curNode].get(i)[1];
				if(shortest[endNode] > length) {
					shortest[endNode] = length;
					pq.offer(new Node(shortest[endNode] , endNode));
				}
			}
		}
		
		for(int i = 1; i<shortest.length; i++) {
			if(shortest[i] == Integer.MAX_VALUE) bw.write("INF\n");
			else bw.write(shortest[i]+"\n");
		}
		bw.flush();
	}
}

class Node implements Comparable<Node>{
	int length;
	int nodeNum;
	public Node(int len, int node) {
		length = len;
		nodeNum = node;
	}
	
	public int compareTo(Node o) {
		if(this.length > o.length) return 1;
		return -1;
	}
}
