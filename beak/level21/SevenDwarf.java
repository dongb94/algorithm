package beakJoon_Level21_BruteForce;
/* Q
 * 왕비를 피해 일곱 난쟁이들과 함께 평화롭게 생활하고 있던 백설공주에게 위기가 찾아왔다. 일과를 마치고 돌아온 난쟁이가 일곱 명이 아닌 아홉 명이었던 것이다.

	아홉 명의 난쟁이는 모두 자신이 "백설 공주와 일곱 난쟁이"의 주인공이라고 주장했다. 뛰어난 수학적 직관력을 가지고 있던 백설공주는, 다행스럽게도 일곱 난쟁이의 키의 합이 100이 됨을 기억해 냈다.
	
	아홉 난쟁이의 키가 주어졌을 때, 백설공주를 도와 일곱 난쟁이를 찾는 프로그램을 작성하시오.
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
