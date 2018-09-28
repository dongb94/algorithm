package beakJoon_Level7_String;

import java.io.*;
import java.util.*;

public class NumberOfWord {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		System.out.println(st.countTokens());
	}

}
