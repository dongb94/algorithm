package kakao_blind_2018;

import java.io.*;
import java.util.*;

public class Q1 {

	public static void main(String[] args) throws IOException {
		
	}

}

class Solution {
    public String[] solution(String[] record) {
    	
    	HashMap<String, String> map = new HashMap<>();
    	ArrayList<String> log = new ArrayList<>();
    	String[] answer;
    	
        for(int i=0; i< record.length; i++) {
        	StringTokenizer st = new StringTokenizer(record[i], " ");
        	String token = st.nextToken();
        	switch(token) {
        	case "Enter" :
        		String id = st.nextToken();
        		map.put(id, st.nextToken());
        		log.add(id + " 0");
        		break;
        	case "Leave" :
        		String id2 = st.nextToken();
        		log.add(id2+" 1");
        		break;
        	case "Change" :
        		String id3 = st.nextToken();
        		map.put(id3, st.nextToken());
        		break;
        	}
        }
        answer = new String[log.size()];
        
        int i = 0;
        for(String s : log) {
        	answer[i] = map.get(s.substring(0, s.length()-2)) + "님이 ";
        	if(s.substring(s.length()-1).equals("0")) answer[i] += "들어왔습니다.";
        	else answer[i] += "나갔습니다.";
        	i++;
        }
        
        return answer;
    }
}