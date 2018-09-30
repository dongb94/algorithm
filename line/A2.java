package line_2018;


import java.io.*;
import java.util.*;

public class A2 {
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int N = Integer.parseInt(br.readLine());
		String Map[][] = new String[N][N];
		int d[][] = new int[N][N];
		int point[] = {0,0};
		int cur_D = 2;

		for(int i = 0 ; i< N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j < N; j++) {
				Map[i][j] = st.nextToken();
				d[i][j] = 0;
			}
		}
		while(true) {
			String pointer = Map[point[0]][point[1]]; 
			String direction = pointer.substring(0, 1);
			int distance = Integer.parseInt(pointer.substring(1));
			int mask;
			switch(direction){
			case "R": cur_D = (cur_D+1)%4;
				break;
			case "L": cur_D = (cur_D+3)%4;
				break;
			case "B": cur_D = (cur_D+2)%4;
				break;
			case "F": 
				break;
			}
			mask = 1<<cur_D;
			if((d[point[0]][point[1]] & mask) == 0) d[point[0]][point[1]] |= mask;
			else break;
			
			switch(cur_D) {
			case 0: point[0] -= distance;
				break;
			case 1: point[1] += distance;
				break;
			case 2: point[0] += distance;
				break;
			case 3: point[1] -= distance;
				break;
			}
		}
		
		bw.write(point[1]+" "+point[0]);
		bw.flush();
	}
}