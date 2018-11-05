package beakJoon_Level02_ArithmeticOperation;

/* Q
 * (A+B)%C는 (A%C + B%C)%C 와 같을까?

	(A×B)%C는 (A%C × B%C)%C 와 같을까?
	
	세 수 A, B, C가 주어졌을 때, 위의 네가지 값을 구하는 프로그램을 작성하시오.
 */
import java.io.*;
import java.util.StringTokenizer;

public class Mod {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int A = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
		
		bw.write((A+B)%C+"\n");
		bw.write((A%C+B%C)%C+"\n");
		bw.write((A*B)%C+"\n");
		bw.write(((A%C*B%C)%C)+"\n");
		bw.flush();
	}
}
