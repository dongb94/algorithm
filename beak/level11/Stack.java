package beakJoon_Level11_Stack;

/* Question
 * 
 * ������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	
	����� �� �ټ� �����̴�.
	
	push X: ���� X�� ���ÿ� �ִ� �����̴�.
	pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
	size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
	empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
	top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
 */


import java.io.*;
import java.util.*;

public class Stack {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int N = Integer.parseInt(br.readLine());
		String stack[] = new String[N];
		int pointer = 0;
		
		for(int i=0; i<N; i++) {
			String commend = br.readLine();
			StringTokenizer st = new StringTokenizer(commend, " ");
			
			switch(st.nextToken()) {
			case "push": stack[pointer++] = st.nextToken();
				break;
			case "pop": bw.write((pointer==0?-1:stack[--pointer])+"\n");
				break;
			case "size": bw.write(pointer+"\n");
				break;
			case "empty": bw.write((pointer==0?1:0)+"\n");
				break;	
			case "top": bw.write((pointer==0?-1:stack[pointer-1])+"\n");
				break;
			}
			
			bw.flush();
		}
	}
}
