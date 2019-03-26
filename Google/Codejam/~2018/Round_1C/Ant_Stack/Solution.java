package Ant_Stack;
import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

		int T = sc.nextInt();
		for(int i=0; i<T; i++) {
			int N = sc.nextInt();
			int out = 0;
			
			long W[][] = new long[N][N];
			
			for(int j=0; j<N; j++) {
				if(j==0) {
					for(int k=0; k<N; k++) {
						W[k][0]=-1;
						W[0][k]=sc.nextLong();
					}
					continue;
				}
				
				for(int k=1; k<N; k++) { // W[j][k]
					long small = -1;
					for(int l=0; l<k; l++) {
						if(W[j-1][l]!=-1 && W[j-1][l]<=(W[0][k])*6) {
							long new_size =  W[j-1][l]+W[0][k];
							if(small > new_size || small==-1) {
								small = new_size;
							}
						}
					}
					W[j][k]=small;
				}
			}
			
			for(int j=N-1; j>=0; j--) {
				for(int k=N-1; k>=0; k--) {
					if(W[j][k]!=-1) {
						System.out.println("Case #"+(i+1)+": "+(j+1));
						out=1;
						break;
					}
				}
				if(out==1) {
					break;
				}
			}
			
			
		}
	}
}
