package beakJoon_Level17_Simulation;

/*
 * �ֱٿ� ���ߵ� ������ ������ 1����(��߿�)���� 4����(������)���� 4���� �������� �ִ� �뼱���� ����ǰ� �ִ�. �� �������� Ÿ�ų� ������ ��� ���� �ڵ����� �ν��� �� �ִ� ��ġ�� �ִ�. �� ��ġ�� �̿��Ͽ� ��߿����� ���������� ���� ���� ���� �ȿ� ����� ���� ���� ���� ��� ���� ����Ϸ��� �Ѵ�. ��, �� ������ �̿��ϴ� ������� ���� �ǽ��� ��ö�Ͽ�, ������ ������ Ż ��, ���� ����� ��� ���� �Ŀ� ������ ź�ٰ� �����Ѵ�.

		 			���� ��� ��	ź ��� ��
		1����(��߿�)	0			32
		2����			3			13
		3����			28			25
		4����(������)	39			0
	���� ���, ���� ���� ��츦 ���캸��. �� ���, ���� �ȿ� ����� ���� ���� ���� 2�������� 3���� ����� �������� ������, 13���� ����� ������ ���� ����, �� 42���� ����� ���� �ȿ� �ִ�.
	
	�� ������ ���� ������ �����ϸ鼭 ����ȴٰ� �����Ѵ�.
	
	������ �� ��ȣ ������� �����Ѵ�.
	��߿����� ���� ��� ���� ���������� ź ��� ���� 0�̴�.
	�� ������ ���� ������ �ִ� ������� �� ���� ����� ������ ���� ����.
	������ ������ �ִ� 10,000���̰�, ������ �ʰ��Ͽ� Ÿ�� ���� ����.
	4���� ���� ���� �������� ���� ��� ���� ź ��� ���� �־����� ��, ������ ����� ���� ���� ���� ��� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
 */
import java.io.*;
import java.util.*;

public class IntelligentTrain {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st;
		
		int max=0;
		int passenger = 0;
		
        int i=0;
		while(i<4) {
			st = new StringTokenizer(br.readLine()," ");
			passenger -= Integer.parseInt(st.nextToken());
			passenger += Integer.parseInt(st.nextToken());
			max = max<passenger?passenger:max;
            i++;
		}
		bw.write(max+"\n");
		bw.flush();
	}

}
