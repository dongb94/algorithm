package beakJoon_Level12_Queue;

/* Question
 * 정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

	명령은 총 여섯 가지이다.
	
	push X: 정수 X를 큐에 넣는 연산이다.
	pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	size: 큐에 들어있는 정수의 개수를 출력한다.
	empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
	front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
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