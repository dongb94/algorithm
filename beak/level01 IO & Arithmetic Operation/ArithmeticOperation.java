package beakJoon_Level02_ArithmeticOperation;
/* Q
 * 두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 
 */
import java.io.*;
import java.util.StringTokenizer;

public class ArithmeticOperation {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int A = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());
		
		bw.write(A+B+"\n");
		bw.write(A-B+"\n");
		bw.write(A*B+"\n");
		bw.write(A/B+"\n");
		bw.write(A%B+"\n");
		bw.flush();
	}

}
