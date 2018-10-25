package beakJoon_Level02_ArithmeticOperation;
/* Q
 * ����̴� ���� �������忡�� ������ ����ϰ� �ִ�. ����̴� ���� �������Կ� ������ ��Ȯ�ϰ� Nų�α׷��� ����ؾ� �Ѵ�. �������忡�� ����� ������ ������ ����� �ִ�. ������ 3ų�α׷� ������ 5ų�α׷� ������ �ִ�.

	����̴� ������ ������, �ִ��� ���� ������ ��� ������ �Ѵ�. ���� ���, 18ų�α׷� ������ ����ؾ� �� ��, 3ų�α׷� ���� 6���� �������� ������, 5ų�α׷� 3���� 3ų�α׷� 1���� ����ϸ�, �� ���� ������ ������ ����� �� �ִ�.
	
	����̰� ������ ��Ȯ�ϰ� Nų�α׷� ����ؾ� �� ��, ���� �� ���� �������� �Ǵ��� �� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	
	A
	DP ����
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
