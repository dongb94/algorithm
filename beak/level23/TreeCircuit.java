package beakJoon_Level23_Tree;
/* Q
 * 이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.
 */

import java.util.*;
import java.io.*;
public class TreeCircuit {

	static Deque<Integer> stack = new ArrayDeque<Integer>();
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int N = Integer.parseInt(br.readLine());
		int tree[][] = new int[N][3];
		for(int i=0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			char c = st.nextToken().charAt(0);
			c -= 'A';
			
			tree[c][0] = st.nextToken().charAt(0)-'A';
			tree[c][1] = st.nextToken().charAt(0)-'A';
		}

		//pre - order
		PreOrder(tree, 0);
		while(!stack.isEmpty()) {
			int i = stack.removeLast();
			char c = (char) (i+'A'); 
			bw.write(c);
		}
		bw.write("\n");
		//in - order
		InOrder(tree, 0);
		while(!stack.isEmpty()) {
			int i = stack.removeLast();
			char c = (char) (i+'A'); 
			bw.write(c);
		}
		bw.write("\n");
		//post - order
		PostOrder(tree, 0);
		while(!stack.isEmpty()) {
			int i = stack.removeLast();
			char c = (char) (i+'A'); 
			bw.write(c);
		}
		bw.flush();
	}
	static void PreOrder(int[][] tree, int node) {
		stack.push(node);
		if(tree[node][0] != '.'-'A')
			PreOrder(tree, tree[node][0]);
		if(tree[node][1] != '.'-'A')
			PreOrder(tree, tree[node][1]);
	}
	static void InOrder(int[][] tree, int node) {
		if(tree[node][0] != '.'-'A')
			InOrder(tree, tree[node][0]);
		stack.push(node);
		if(tree[node][1] != '.'-'A')
			InOrder(tree, tree[node][1]);
	}
	static void PostOrder(int[][] tree, int node) {
		if(tree[node][0] != '.'-'A')
			PostOrder(tree, tree[node][0]);
		if(tree[node][1] != '.'-'A')
			PostOrder(tree, tree[node][1]);
		stack.push(node);
	}
}
