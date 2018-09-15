package kakao_blind_2018;

import java.io.*;
import java.util.*;

public class Q2 {

	public static void main(String[] args) throws IOException {
		int[] a = {2, 1, 2, 6, 2, 4, 3, 3};
		for(int i : solution(5, a)) System.out.println(i);
	}
	
	public static int[] solution(int N, int[] stages) {
        int[] answer = new int[N];
        int[] complet = new int[N+1];
        int[] reached = new int[N+1];
        HashMap<Double, Integer> score = new HashMap<>();
        
        for(int i=0; i<N+1; i++) {
        	complet[i] = 0;
        }
        for(int i : stages) {
        	complet[i-1] += 1;
        }
        reached[N] = complet[N];
        for(int i=N-1; i>=0; i--) {
        	reached[i] = complet[i]+reached[i+1];
        	double s = ((double)complet[i]/reached[i]);
        	while(score.get(s) != null) {
        		s += 0.00000000000000006;
        	}
        	score.put(s, i+1);
        }
        Set<Double> result = score.keySet();
        List<Double> list = new ArrayList<Double>(result);
        Collections.sort(list);
        Iterator<Double> itr = list.iterator();
        for(int i=0; i<N; i++) {
        	answer[N-1-i] = score.get(itr.next());
        }
        
        return answer;
    }

}
