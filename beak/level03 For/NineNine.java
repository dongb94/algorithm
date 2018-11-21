// N을 입력받은 뒤, 구구단 N단을 출력하는 프로그램을 작성하시오. 출력 형식에 맞춰서 출력하면 된다.

import java.util.*;

public class NineNine{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int L = sc.nextInt();
        
        for(int i =0; i<9; i++){
            System.out.println((L)+" * "+(i+1)+" = "+(L*(i+1)));
        }
    }    
}
