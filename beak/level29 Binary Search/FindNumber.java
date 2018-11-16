package level_29_Binary_Search;
/* Q
 * N���� ���� A[1], A[2], ��, A[N]�� �־��� ���� ��, �� �ȿ� X��� ������ �����ϴ��� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.
 * 
 * �Է�
	ù° �ٿ� �ڿ��� N(1��N��100,000)�� �־�����. ���� �ٿ��� N���� ���� A[1], A[2], ��, A[N]�� �־�����. ���� �ٿ��� M(1��M��100,000)�� �־�����. ���� �ٿ��� M���� ������ �־����µ�, �� ������ A�ȿ� �����ϴ��� �˾Ƴ��� �ȴ�. ��� �������� ������ int �� �Ѵ�.

	���
	M���� �ٿ� ���� ����Ѵ�. �����ϸ� 1��, �������� ������ 0�� ����Ѵ�.
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
