package beakJoon_Level5_Function;

import java.io.*;
import java.util.*;

public class Self_Number {

	
	public static void main(String[] args) throws IOException{
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		HashSet<Integer> n_self_number =  new HashSet<>();
		for(int i = 1; i<=10000; i++) {
			n_self_number.add(d(i));
		}
		for(int i = 1; i<=10000; i++) {
			if(n_self_number.contains(i)) continue;
			bw.write(i+"\n");
		}
		bw.flush();
	}
	
	private static int d(int num) {
		
		int dNum=num;
		
		while(num>0) {
			dNum += num%10;
			num /= 10;
		}
		
		return dNum;
	}

}
