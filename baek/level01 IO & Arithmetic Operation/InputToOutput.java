package 백준1단계_입출력;

import java.io.*;

public class InputToOutput {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String s;
		while(!(s = br.readLine()).isEmpty()) bw.write(s);
		bw.flush();
	}
}
