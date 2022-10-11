// https://www.acmicpc.net/problem/9498
package BaekJoon_Level4_If;

////Question
////���� ������ �Է¹޾� 90 ~ 100���� A, 80 ~ 89���� B, 70 ~ 79���� C, 60 ~ 69���� D, ������ ������ F�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

import java.io.*;

public class ScoreToRank {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int score = Integer.parseInt(br.readLine());
		if(score >= 90) bw.write("A");
		else if (score >= 80) bw.write("B");
		else if (score >= 70) bw.write("C");
		else if (score >= 60) bw.write("D");
		else bw.write("F");
		bw.flush();
	}
}
