import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Solt {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new InputStreamReader(System.in));
	
		int S = sc.nextInt();
		int N = 0; 
		int nf,nt;
		
		nf = S/5;
		S = S%5;
		
		nt = S/3;
		S = S%3;
		
		N = nf + nt;
		
		while(S!=0) {
			
			if(nf==0) {
				N = -1;
				break;
			}
			
			nf--;
			S += 5;
			nt += S/3;
			S = S%3;
			
			if(S==0) {
				N = nf + nt;
				break;
			}
			
		}
		
		System.out.println(N);
	}
}
