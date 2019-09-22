package line_2018;


import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		
		int money = 20000;
		
		while(st.hasMoreTokens()) {
			int dist = Integer.parseInt(st.nextToken());
			
			if(dist < 4 || dist >178) break;
			
			if(dist <= 40) {
				money -= 720;
			}
			else {
				dist = (dist-33) / 8;
				money -= 720 + 80 * dist;
			}
		}
		
		bw.write(money+"");
		bw.flush();
	}
}