// 첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제

import java.io.*;

public class PrintStar01 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int N = Integer.parseInt(br.readLine());
		
		for(int n=1; n<=N; n++) {
			for(int i = 0; i<n; i++)
				bw.write("*");
			bw.write("\n");
		}
		bw.flush();
	}

}
