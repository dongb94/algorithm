package trouble_sort;


import java.util.*;
import java.io.*;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		
		int T = sc.nextInt();
		for(int i=0; i<T; i++) {
			
			int n = sc.nextInt();
			int list[] = new int[n]; 
			for(int j=0; j<n; j++) {
				list[j]=sc.nextInt();
			}
			
			boolean done = true;
			while(done) {
				done=false;
				for(int j=0; j<n-2; j++) {
					if(list[j]>list[j+2]) {
						done=true;
						int temp=list[j];
						list[j]=list[j+2];
						list[j+2]=temp;
					}
				}
			}
			
			for(int j=0; j<n-1; j++) {
				if(list[j]>list[j+1]) {
					System.out.println("Case #"+(i+1)+": "+j);
					break;
				}
				if(j==n-2)
					System.out.println("Case #"+(i+1)+": OK");
				
			}
		}
	}
}
