package A_Whole_New_Word;
import java.io.*;
import java.util.*;

public class Solution {
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

		int T = sc.nextInt();
		for(int i=0; i<T; i++) {
			int N = sc.nextInt();
			int L = sc.nextInt();
			
			String card[] = new String[N]; 
			char array[][] = new char[N][L];
			String newString = "";
			
			int out = 0;
			
			for( int j =0; j<N; j++) {
				card[j] = sc.next();
				array[j] =card[j].toCharArray();
			}
			
			for(int j=1; j<L; j++) {
				for(int k=0; k<N; k++) {
					newString = "";
					int p=0;
					while(p<L-j) {
						newString += array[k][p];
						p++;
					}
					for(int l=0; l<N; l++) {
						String s = newString;
						int pin = p;
						while(pin<L) {
							s += array[l][p];
							pin++;
						}
						
						for(int n=0; n<N; n++) {
							if(card[n].equals(s)) {
								break;
							}
							
							if(n==N-1) {
								System.out.println("Case #"+(i+1)+": "+s);
								out=1;
								break;
							}
						}
						
						if(out==1) {
							break;
						}
						
					}
					if(out==1) {
						break;
					}	
				}
				if(out==1) {
					break;
				}
			}
			if(out==1) {
				continue;
			}
			System.out.println("Case #"+(i+1)+": "+"-");
		}
	}
}


