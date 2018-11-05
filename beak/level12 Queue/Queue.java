package beakJoon_Level12_Queue;

/* Question
 * ������ �����ϴ� ť�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

	����� �� ���� �����̴�.
	
	push X: ���� X�� ť�� �ִ� �����̴�.
	pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
	size: ť�� ����ִ� ������ ������ ����Ѵ�.
	empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
	front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
	back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
 */

import java.io.*;
import java.util.*;

public class Queue {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int N = Integer.parseInt(br.readLine());
		String queue[] = new String[N];
		int in = 0;
		int out = -1;
		
		for(int i=0; i<N; i++) {
			String commend = br.readLine();
			StringTokenizer st = new StringTokenizer(commend, " ");
			
			switch(st.nextToken()) {
			case "push": queue[in] = st.nextToken();
						 if(out==-1) out=in;
						 in = (++in)%N;
						 break;
			case "pop": if(out==-1) {
							bw.write("-1\n");
							break;
						}
						bw.write(queue[out]+"\n");
						out = (++out)%N;
						if(out==in) out = -1;
						break;
			case "size": bw.write((out==-1?0:(in>out?in-out:in-out+N))+"\n");
						break;
			case "empty": bw.write((out==-1?1:0)+"\n");
						break;	
			case "front": bw.write((out==-1?-1:queue[out])+"\n");
						break;
			case "back": bw.write((out==-1?-1:queue[(in-1+N)%N])+"\n");
						break;
			}
			

		}
		bw.flush();
	}
}