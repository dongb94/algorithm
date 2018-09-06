// beakjoon 11559
// https://www.acmicpc.net/problem/11559
import java.io.*;

public class Puyo_Puyo {

	static int[][] board = new int[12][6];
	static int[][] flag = new int[12][6];
	static int[][] linked = new int[12][6];
	
	public static void initialize() {
		for(int i=0; i<12; i++) {
			for(int j=0; j<6; j++) {
				linked[i][j] = 0;
				flag[i][j] = 0;
			}
		}
	}
	
	public static void check(int i, int j) {
		int puyo = board[i][j];
		if(puyo==0) return;
		if(i!=11 && puyo==board[i+1][j]) {
			count_up(i,j);
		}
		if(j!=5 && puyo==board[i][j+1]) {
			if(i!=0 && puyo==board[i-1][j+1] && puyo==board[i-1][j]) return; 
			count_up(i,j);
		}
	}
	
	public static void count_up(int i, int j) {
		
		int n = ++linked[i][j];
		if(n==3) flag[i][j]=1;
		
		if(i!=11 && board[i][j]==board[i+1][j] && linked[i][j]>linked[i+1][j]) count_up(i+1,j);
		if(i!=0 && board[i][j]==board[i-1][j] && linked[i][j]>linked[i-1][j]) count_up(i-1,j);
		if(j!=5 && board[i][j]==board[i][j+1] && linked[i][j]>linked[i][j+1]) count_up(i,j+1);
		if(j!=0 && board[i][j]==board[i][j-1] && linked[i][j]>linked[i][j-1]) count_up(i,j-1);
		
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		for(int i=0; i<12; i++) {
			String input = br.readLine();
			for(int j=0; j<6; j++) {
				char c = input.charAt(j);
				switch(c) {
				case 'R': board[i][j] = 1;
					break;
				case 'G': board[i][j] = 2;
					break;
				case 'B': board[i][j] = 3;
					break;
				case 'P': board[i][j] = 4;
					break;
				case 'Y': board[i][j] = 5;
					break;
				default : board[i][j] = 0;
					break;
				}
			}
		}
		
		int chain = 0;
		boolean con = true;
		while(con) {
			con = false;
			for(int i=0; i<12; i++) 
				for(int j=0; j<6; j++) 
					check(i,j);
			
			for(int i=0; i<12; i++) 
				for(int j=0; j<6; j++) 
					if(flag[i][j]==1) {
						con = true;
						for(int l=i; l>0; l--) {
							board[l][j]=board[l-1][j];
						}
						board[0][j] = 0;
					}
			if(con) {
				chain++;
				initialize();
			}
		}
		System.out.println(chain);
	}
}
