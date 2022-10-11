package BaekJoon_Level7_String;

////Question
/*
 * 영어 대소문자와 띄어쓰기만으로 이루어진 문자열이 주어진다. 이 문자열에는 몇 개의 단어가 있을까? 이를 구하는 프로그램을 작성하시오.
 */

import java.io.*;
import java.util.*;

public class NumberOfWord {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		System.out.println(st.countTokens());
	}

}
