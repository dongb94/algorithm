
public class Return_middle_string {
	
	public String solution(String s) {
		return s.substring(s.length()/2-1,s.length()/2);	
		
	}
	
	
	
	// 1Ʈ
//	public String solution(String s) {
//	      char[] arr = s.toCharArray();
//	      int length = arr.length;
//	      String answer = "";
//	      if(length%2==0) 
//	    	  answer = ""+arr[length/2-1]+arr[length/2];
//	      else
//	    	  answer = ""+arr[length/2];
//	      return answer;
//	}
}
