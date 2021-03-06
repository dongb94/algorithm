package level_29_Binary_Search;
/* Q
 * N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.
 * 
 * 입력
	첫째 줄에 자연수 N(1≤N≤100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1≤M≤100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수들의 범위는 int 로 한다.

	출력
	M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.
 */
import java.io.*;
import java.util.*;

public class FindNumber {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int N = Integer.parseInt(br.readLine());
		int numbers[] = new int[N];
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		for(int i=0; i<N; i++) {
			numbers[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(numbers);
		
		int M = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine(), " ");
		
		int minIndex,maxIndex;
		for(int i=0; i<M; i++) {
			int find = Integer.parseInt(st.nextToken());
			minIndex = 0;
			maxIndex = N-1;
			while(true) {
				int middle = (minIndex + maxIndex)/2;
				if(numbers[middle] == find) {
					bw.write("1\n");
					break;
				}else if(numbers[middle] < find) {
					minIndex = middle+1;
				}else {
					maxIndex = middle-1;
				}
				if(maxIndex < minIndex) {
					bw.write("0\n");
					break;
				}
			}
		}
		bw.flush();
	}
}
