package 백준1단계_입출력;

import java.io.*;

public class Hello_World {
	public static void main(String[] args) throws IOException {
		String messege = "Hello World!";
		
		BufferedWriter br= new BufferedWriter(new OutputStreamWriter(System.out));
		
		br.write(messege);
		br.flush();
	}
}
