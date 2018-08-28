package kakao_code_festival_2018;

import java.io.*;
import java.util.StringTokenizer;

public class B {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       
    	String input = br.readLine();
		StringTokenizer st = new StringTokenizer(input, " ");
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		input = br.readLine();
		st = new StringTokenizer(input, " ");
		int man_N[] = new int[N];
		for(int i=0; i<N; i++) {
			man_N[i]=Integer.parseInt(st.nextToken());
        }
		int sum = 0;
		double sol = 99999999999999999999d;
		for(int l=K; l<N+1; l++) {
			for(int i=0; i<N-l+1; i++) {
				sum = 0;
				for(int j=i; j<l+i; j++) {
					sum += man_N[j];	
				}
				
				double m = (double)sum/l;
				double q = 0;
				
				for(int j=i; j<l+i; j++) {
					q+= (man_N[j]-m)*(man_N[j]-m);	
				}
				q = q/l;
				
				if(sol > q) 
					sol = q;
	        }
		}
		
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		bw.write(Double.toString(Math.sqrt(sol)));
		bw.flush();
	}
}
