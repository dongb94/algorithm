package kakao_blind_2018;

import java.util.ArrayList;
import java.util.HashMap;

public class Q6 {


	
	
	
	 public static int solution(String word, String[] pages) {
		 	String letters = "abcdefghijklmnopqrstuvwxyz"
		 				+ "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	        int answer = 0;
	        HashMap<String, Integer> score = new HashMap<>();
	        HashMap<Integer, ArrayList<String>> link = new HashMap<>();
	        
	        float finalScore[] = new float[pages.length];
	        float pageScore[] = new float[pages.length];
	        
	        word = word.toLowerCase();
	        
	        int n=0;
	        for(String s:pages) {
	        	String pageName = "";
	        	ArrayList<String> linkPage=new ArrayList<>();
	        	String linkPageName = "";
	        	
	        	char c = ' ';
	        	String token = "";
	        	int index = 0;
	        	int selfScore = 0;
	        	
	        	boolean name = false;
	        	boolean linkName = false;
	        	boolean inhead = false;
	        	boolean ina = false;
	        	
	        	while(index<s.length()) {
	        		c = s.charAt(index);
		        	index++;
	        		while(letters.indexOf(c) >= 0) {
	        			token+=c;
	        			c = s.charAt(index);
			        	index++;
	        		}
	        		if(token.toLowerCase().equals(word) && !inhead) selfScore++;
	        			        		
	        		if(name&&c=='"') name=false;
	        		if(name) pageName+=token + c;
	        		if(linkName&&c=='"') {
	        			linkName=false;
	        			linkPage.add(linkPageName);
	        			linkPageName = "";
	        		}
	        		if(linkName) linkPageName+=token + c;
	        		
	        		if(token.equals("content") && inhead && c=='=') {
	        			name = true;
	        			index+=1;
	        		}else if(token.equals("href") && ina && c=='=') {
	        			linkName = true;
	        			index+=1;
	        		}
	        		if(token.equals("head") && c=='>') {
	        			 inhead = !inhead;
	        		}
	        		
	        		if(c=='<' && s.charAt(index)=='a') {
	        			ina = true;
	        		}
	        		
	        		token = "";
	        	}
	        	
	        	score.put(pageName, n);
	        	link.put(n, linkPage);
	        	pageScore[n] = selfScore;
	        	finalScore[n] = selfScore;
	        	n++;
	        }
	        
	        for(int i=0; i<pages.length; i++) {
	        	ArrayList<String> links = link.get(i);
	        	
	        	for(String s:links) {
	        		if(score.get(s)==null) continue;
	        		finalScore[score.get(s)]+=pageScore[i]/links.size();
	        	}
	        }
	        
	        for(int i=0; i<finalScore.length; i++) {
	        	if(finalScore[i]>finalScore[answer]) answer=i;
	        }
	        
	        return answer;
	    }
	 
	 
	 
		public static void main(String[] args) {
			// TODO Auto-generated method stub
			String[] pages = new String[3];
			pages[0] = "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>";
			pages[1] = "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>";
			pages[2] = "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\r\n" + 
					"<head>\r\n" + 
					"  <meta charset=\"utf-8\">\r\n" + 
					"  <meta property=\"og:url\" content=\"https://c.com\"/>\r\n" + 
					"</head>  \r\n" + 
					"<body>\r\n" + 
					"Ut condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\r\n" + 
					"<a href=\"https://a.com\"> Link to a </a>\r\n" + 
					"</body>\r\n" + 
					"</html>";
			solution("Muzi",pages);
		}

}
