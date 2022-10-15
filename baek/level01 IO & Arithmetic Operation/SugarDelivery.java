package BaekJoon_Level02_ArithmeticOperation;
/* Q
 * 상근이는 요즘 설탕공장에서 설탕을 배달하고 있다. 상근이는 지금 사탕가게에 설탕을 정확하게 N킬로그램을 배달해야 한다. 설탕공장에서 만드는 설탕은 봉지에 담겨져 있다. 봉지는 3킬로그램 봉지와 5킬로그램 봉지가 있다.

	상근이는 귀찮기 때문에, 최대한 적은 봉지를 들고 가려고 한다. 예를 들어, 18킬로그램 설탕을 배달해야 할 때, 3킬로그램 봉지 6개를 가져가도 되지만, 5킬로그램 3개와 3킬로그램 1개를 배달하면, 더 적은 개수의 봉지를 배달할 수 있다.
	
	상근이가 설탕을 정확하게 N킬로그램 배달해야 할 때, 봉지 몇 개를 가져가면 되는지 그 수를 구하는 프로그램을 작성하시오.
	
	A
	DP 가능
 */
import java.io.*;
public class SugarDelivery {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());
		
		int five = N/5;
		
		switch(N%5) {
		case 0 : bw.write(five+"\n"); 
			break;
		case 1 : 
			if(five == 0) bw.write("-1\n");
			else bw.write(five+1+"\n");
			break;
		case 2 :
			if(five < 2) bw.write("-1\n");
			else bw.write(five+2+"\n");
			break;
		case 3 : bw.write(five+1+"\n");
			break;
		case 4 :
			if(five == 0) bw.write("-1\n");
			else bw.write(five+2+"\n");
			break;	
		}
		bw.flush();
	}

}
