package beakJoon_Level21_BruteForce;
/* Q
 * �պ� ���� �ϰ� �����̵�� �Բ� ��ȭ�Ӱ� ��Ȱ�ϰ� �ִ� �鼳���ֿ��� ���Ⱑ ã�ƿԴ�. �ϰ��� ��ġ�� ���ƿ� �����̰� �ϰ� ���� �ƴ� ��ȩ ���̾��� ���̴�.

	��ȩ ���� �����̴� ��� �ڽ��� "�鼳 ���ֿ� �ϰ� ������"�� ���ΰ��̶�� �����ߴ�. �پ ������ �������� ������ �ִ� �鼳���ִ�, ���ེ���Ե� �ϰ� �������� Ű�� ���� 100�� ���� ����� �´�.
	
	��ȩ �������� Ű�� �־����� ��, �鼳���ָ� ���� �ϰ� �����̸� ã�� ���α׷��� �ۼ��Ͻÿ�.
 */
import java.io.*;
import java.util.*;
public class SevenDwarf {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int[] height = new int[9];
		int sum = 0;
		SortedSet<Integer> dwarf = new TreeSet<>();
		
		for(int i=0; i<height.length; i++) {
			height[i] = Integer.parseInt(br.readLine());
			sum += height[i];
		}
		
		for(int i=0; i<7; i++) {
			for(int j=i+1; j<9; j++) {
				if(sum - height[i] - height[j] == 100) {
					for(int l = 0; l<9; l++) {
						if(l!=i && l!=j) {
							dwarf.add(height[l]);
						}
					}
					for(int l:dwarf) {
						bw.write(l+"\n");
					}

					bw.flush();
					return;
				}
			}
		}
		bw.write("-1\n");
		bw.flush();
	}
}
