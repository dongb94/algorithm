// https://www.acmicpc.net/problem/2557

import java.io.*;

public class Hello_World {
	public static void main(String[] args) throws IOException {
		String messege = "Hello World!";
		
		BufferedWriter br= new BufferedWriter(new OutputStreamWriter(System.out));
		
		br.write(messege);
		br.flush();
	}
}
