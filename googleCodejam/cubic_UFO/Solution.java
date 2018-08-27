package cubic_UFO;

import java.util.*;
import java.io.*;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		
		int T = sc.nextInt();
		for(int i=0; i<T; i++) {
			double A = sc.nextDouble();

			if(A==1) {
				System.out.println("Case #"+(i+1)+":");
				System.out.println(0.5+" "+0+" "+0);
				System.out.println(0+" "+0.5+" "+0);
				System.out.println(0+" "+0+" "+0.5);
			}else if(A<=1.414213) {
				double angle = Math.asin((A+1)*(A-1))/2;
				double sin=Math.sin(angle);
				double cos=Math.cos(angle);
				
				System.out.println("Case #"+(i+1)+":");
				System.out.println(0.5*cos+" "+0.5*sin+" "+0);
				System.out.println(-0.5*sin+" "+0.5*cos+" "+0);
				System.out.println(0+" "+0+" "+0.5);
			}else {
				
			}
			
		}
	}
}
