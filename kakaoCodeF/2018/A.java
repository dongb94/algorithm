package kakao_code_festival_2018;
import java.io.*;
import java.util.StringTokenizer;

public class A{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for(int i =0; i<T; i++){
        	String input = br.readLine();
    		StringTokenizer st = new StringTokenizer(input, " ");
    		int a = Integer.parseInt(st.nextToken());
    		int b = Integer.parseInt(st.nextToken());
    		
    		int sum = 0;
    		switch(a) {
    		case 1: sum+=5000000;
    			break;
    		case 2: 
    		case 3:sum+=3000000;
    			break;
    		case 4:
    		case 5:
    		case 6:sum+=2000000;
    			break;
    		case 7:
    		case 8: 
    		case 9: 
    		case 10: sum+=500000;
    			break;
    		case 11: 
    		case 12: 
    		case 13: 
    		case 14: 
    		case 15: sum+=300000;
    			break;
    		case 16: 
    		case 17: 
    		case 18: 
    		case 19: 
    		case 20: 
    		case 21: sum+=100000;
    			break;
    		}
    		
    		if (b==0) ;
    		else if(b==1) sum+=5120000;
    		else if (b<=3) sum+=2560000;
    		else if (b<=7) sum+=1280000;
    		else if (b<=15) sum+=640000;
    		else if (b<=31) sum+=320000;
    		
    		bw.write(Integer.toString(sum)+"\n");
        }
        bw.flush();
    }
}