package beakJoon_Level18_DivideAndConquer;
/* Q
 * 수 N개 A1, A2, ..., AN이 주어진다. A를 오름차순 정렬했을 때, 앞에서부터 K번째 있는 수를 구하는 프로그램을 작성하시오. 
 */

import java.io.*;
import java.util.*;

public class KthNumber {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		Integer[] array = new Integer[N];
		st = new StringTokenizer(br.readLine(), " ");
		for(int i=0; i<N; i++) {
			array[i] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(array);
		
//		Merge(0, N-1, array, new Comparator<Integer>() {
//			public int compare(Integer o1, Integer o2) {
//				if(o1>o2) return -1;
//				else if(o1==o2) return 0;
//				else return 1;
//			}
//		});
		
		bw.write(array[K-1]+"\n");
		bw.flush();
	}
	
	static <T> T[] Merge(int min, int max, T[] array, Comparator<T> c) {
		//Divide
		int mid = (max+min)/2;
		if(mid == max) return array;

		T[] left = Merge(min, mid, array, c);
		T[] right = Merge(mid+1, max, array, c);
		
		//Conquer
		int lp = min;
		int rp = mid+1;
		Queue<T> temp = new LinkedList<T>();
		while(lp<=mid||rp<=max) {
			if(rp>max) {
				temp.add(array[lp++]);
				continue;
			}else if(lp>mid) {
				temp.add(array[rp++]);
				continue;
			}
			int result = c.compare(array[lp], array[rp]);
			if(result<0) temp.add(array[rp++]);
			else temp.add(array[lp++]);
		}
		lp = min;
		for(T t:temp) {
			array[lp++] = t;
		}
		
		return array; 
	}

}
