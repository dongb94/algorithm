package Number1;
import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

		int T = sc.nextInt();
		for(int i=0; i<T; i++) {
			int N = sc.nextInt();
			int L = sc.nextInt();
			
			
			double C[] = new double[L];
			double D[] = new double[N];
			int check[] = new int[L];
			
			double one = (double)1/N*100;
			boolean one_round=false;
			
			
			int sum = 0;
			int choose = 0;
			
			if(one < Math.round(one)) {
				one_round=true;
			}
			
			for(int j = 0; j<N; j++) {
				D[j] =0;
			}
			
			for( int j =0; j<L; j++) {
				int c = sc.nextInt();
				choose += c;
				C[j] = (double)c/N*100;
				D[j] = C[j];
				check[j] = 0;
			}
			
			for( int j =0; j<L; j++) {
				int round = (int) Math.round(C[j]);
				if(C[j]<round) {
					check[j] = 1;
				}
			}
			
			int noc = 0;
			boolean all_checked = false;
			while(choose < N && !all_checked) {
				noc++;
				all_checked =true;
				for( int j =0; j<L; j++) {
					if(check[j]==1) {
						continue;
					}
					all_checked = false;
					C[j] += one;
					int round = (int) Math.round(C[j]);
					if(C[j]<=round) {
						choose+=noc;
						if(choose >= N) {
							D[j] += one*(N-choose+noc);
							break;
						}
						if(C[j]==round && one_round) continue;
						D[j]=C[j];
						check[j] = 1;
					}
				}
			}
			
			if(all_checked) {
				int over=L;
				while(choose <N) {
					int round = (int)Math.round(D[over]);
					while(D[over]>=round) {
						D[over]+=one;
						choose++;
						if(choose == N) {
							break;
						}
					}
					over++;
				}
			}
			
			for( int j =0; j<N; j++) {
				sum += (int) Math.round(D[j]);
			}
			
			System.out.println("Case #"+(i+1)+": "+sum);
		}
	}

}
