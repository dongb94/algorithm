package beakJoon_Level8_FindPattern;

//ù° �ٿ��� �� 1��, ��° �ٿ��� �� 2��, N��° �ٿ��� �� N���� ��� ����

import java.io.*;

public class PrintStar {

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
