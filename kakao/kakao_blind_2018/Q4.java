package kakao_blind_2018;

import java.util.LinkedList;
import java.util.Queue;

public class Q4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] a = {4,2,1,3,2};
		int[] b = {6,2,3,4,2,3,5,2,2,12,1,2,4,3,3,4,2,1,3,2};
		
		System.out.println(solution(b,30));
	}

	public static int solution(int[] food_times, long k) {
        int nof = food_times.length;
        int d = (int)k/nof;
        k%=nof;
        
        LinkedList<Integer> q = new LinkedList<>();
        LinkedList<Integer> q2 = new LinkedList<>();
        
        for(int i=0; i<nof; i++) {
        	if(food_times[i]<=d) {
        		k += d-food_times[i];
        		food_times[i]=0;
        	}else {
        		food_times[i]-=d;
        		q.add(i);
        	}
        }
        while(k>(nof=q.size())) {
        	if(nof==0) return -1;
        	d = (int)k/nof;
        	k%=nof;
        	
        	int index = 0;
        	for(int i:q) {
            	if(food_times[i]<=d) {
            		k += d-food_times[i];
            		food_times[i]=0;
            		q.remove(index);
            	}else {
            		food_times[i]-=d;
            		index++;
            	}
            }
        }
        while(k>0) {
        	int i = q.removeFirst();
        	food_times[i]--;
        	k--;
        	
        	if(food_times[i]!=0) q.add(i);
        }
        return q.removeFirst()+1;
    }
}
