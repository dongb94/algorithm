package level_27_String_Middle;
/* Q
 * KMP �˰����� KMP�� ������ �̸� ���� ����� ���� Knuth, Morris, Prett�̱� �����̴�. �̷��� �˰��򿡴� �߰��� ����� ���� ���� �̸��� ���̴� ��찡 ����.

	�� �ٸ� ����, ������ ���Ī ��ȣȭ �˰��� RSA�� �̸� ���� ����� �̸��� Rivest, Shamir, Adleman�̴�.
	
	������� �̷��� ��� ���� �� �˰����� �� ���� ���·� �θ���.
	
	- ù ��°�� ���� ��� ����, �̸� ������(-)���� �̾� ���� ���̴�. ���� ���, Knuth-Morris-Pratt�̴�. �̰��� �� ���¶�� �θ���.
	- �� ��°�� ª�� ���´� ���� ����� ���� ù ���ڸ� ���� �θ��� ���̴�. ���� ���, KMP�̴�.
	
	�����̴� ���ϸ��� �ڽ��� �� ���� ��� �޸��忡 ������´�. ���� �ڱ� ����, ���� �Ϸ� ������ �ߴ��� �ǻ��� ���� ������ �Ϸ縦 �����Ѵ�.
	
	�Ϸ�� �� �޸� ���� ��, ���ݱ��� �� ���¿� ª�� ���¸� ��� ���� ���� ���� �߰��ߴ�.
	
	�̷��� �� ���·� �Ϸ� ���� ����ϴٰ��� �޸��� ������ �δ�Ǿ� �Ļ�� ���� ���ϱ� ������, �����δ� ª�� ���·� ����Ϸ��� �Ѵ�.
	
	�� ������ �˰��� �̸��� �־����� ��, �̸� ª�� ���·� �ٲپ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
 */
import java.io.*;
import java.util.*;
public class LongToShort {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = new StringTokenizer(br.readLine(), "-");
		
		while(st.hasMoreTokens()) {
			bw.write(st.nextToken().substring(0, 1));
		}
		bw.flush();
	}

}
