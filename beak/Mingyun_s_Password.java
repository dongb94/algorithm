import java.io.*;

public class Mingyun_s_Password {

	public static void main(String[] args) throws IOException {
		
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(r.readLine());
		String[] list = new String[T];
		
		for(int j =0; j<T; j++) {
			list[j] = r.readLine();
		}
		
		for(int j =0; j<T; j++) {
			char[] word = list[j].toCharArray();
			String revers = "";
			for(int i =0; i<word.length; i++) {
				revers = word[i]+revers;
			}
			for(int i =j; i<T; i++) {
				if(list[i].equals(revers)) {
					System.out.println(word.length+" "+word[word.length/2]);
				}
			}
		}
	}
}
