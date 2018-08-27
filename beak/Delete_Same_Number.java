import java.util.*;

public class Delete_Same_Number {
	public int[] solution(int []arr) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        int point = -1;
        for(int i:arr){
            if(point == i){
                continue;
            }
            point = i;
            list.add(i);
        }
        int[] answer = new int[list.size()];
        Iterator itr = list.iterator();
        for(int i=0; i< answer.length; i++){
            answer[i] = (int) itr.next();
        }
        return answer;
        
        
	}
}