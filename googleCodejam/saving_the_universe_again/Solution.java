package saving_the_universe_again;

import java.util.*;
import java.io.*;

public class Solution {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		
		int T = sc.nextInt();
		for(int i=0; i<T; i++) {
			int D = sc.nextInt();
			String P = sc.nextLine();
			char c[]=P.toCharArray();
			int damage=1;
			int total_damage=0;
			int number_of_shot=0;
			LinkedList<Integer> dmg = new LinkedList<Integer>();
			for(int j=0; j<c.length; j++) {
				if(c[j]=='C') {
					damage*=2;
				}
				else if(c[j]=='S') {
					dmg.add(damage);
					total_damage+=damage;
					number_of_shot++;
				}
			}
			
			if(number_of_shot>D) {
				System.out.println("Case #"+(i+1)+": IMPOSSIBLE");
				continue;
			}
			
			int n=0;
			
			while(total_damage>D){
				n++;
				int os = dmg.pollLast();
				os/=2;
				dmg.add(os);
				total_damage-=os;
				dmg.sort(null);
			}
			
			System.out.println("Case #"+(i+1)+": "+n);
		}
	}
}
