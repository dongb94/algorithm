package kakao_blind_2018_demo;

import java.io.*;
import java.util.*;

public class Q1 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		String output = "true";
		input = input.substring(1, input.length()-1);
		
		StringTokenizer st = new StringTokenizer(input,", ");
		int size = st.countTokens();
		boolean check_number[] = new boolean[size];
		while (st.hasMoreTokens()) {
			int n = Integer.parseInt(st.nextToken());
			if(n>size) {
				output = "false";
				break;
			}
			if(check_number[n-1] == false) {
				check_number[n-1] = true;
			}else {
				output = "false";
			}
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		bw.write(output);
		bw.flush();
	}

}

//fuction code
class Solution {
    public boolean solution(int[] arr) {
        boolean check[] = new boolean[arr.length];
        for (int n : arr){
            if(n > arr.length)  return false;
            if(check[n-1]==true)   return false;
            else check[n-1]=true;
        }
        return true;
    }
}
