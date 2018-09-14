class Solution {
  public String[] solution(int n, int[] arr1, int[] arr2) {
      String[] answer = new String[n];
      int[] arr3 = new int[n];
      for(int i = 0; i<n; i++){
          arr3[i] = arr1[i]|arr2[i];
          answer[i]="";
      }
      for(int i=0; i<n; i++){
          for(int j=0; j<n; j++){
              if(((arr3[i] >> n-j-1) & 1) == 1)
                  answer[i] += "#";
              else
                  answer[i] += " ";
          }
      }

      return answer;
  }
}