package kakao_blind_2018_demo;

import java.io.*;
import java.util.*;

public class Q2 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		for(;m>0;m--) {
			for(int i=0;i<n;i++) {
				bw.write("*");
			}
			bw.write("\n");
		}
		
		bw.flush();
	}

}