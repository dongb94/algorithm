
// 대회 종료로 검증하지 못함
// 다른 Q를 거쳐서 이어지는 경우 작성 못함(미완)
package kakao_code_festival_2018;

import java.io.*;
import java.util.*;

public class D {
	public static void main(String[] args) throws IOException {
		ArrayList<HashSet> Qlist = new ArrayList<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    	String input = br.readLine();
		StringTokenizer st = new StringTokenizer(input, " ");
		int N = Integer.parseInt(st.nextToken());
		int Q = Integer.parseInt(st.nextToken());
		
		int inQ[] = new int[N];
		int point[][]=new int[N][2];
		for(int i=0; i<N; i++) {
			input = br.readLine();
			st = new StringTokenizer(input, " ");
			point[i][0]=Integer.parseInt(st.nextToken());
			point[i][1]=Integer.parseInt(st.nextToken());
			inQ[i]=0;
		}

		int noq = 0;
		Qlist.add(new HashSet<Integer>());//Q
		Qlist.add(new HashSet<Integer>());//X
		Qlist.add(new HashSet<Integer>());//Y
		boolean Loop=true;
		while(Loop) {
			Loop = false;
			HashSet<Integer> old_set = new HashSet<>();
			old_set.addAll(Qlist.get(noq*3));
			for(int i=0; i<N; i++) {
				if(inQ[i]==1) continue;
				Loop = true;
				if(Qlist.get(0+noq*3).isEmpty()) {
					Qlist.get(0+noq*3).add(i+1);
					Qlist.get(1+noq*3).add(point[i][0]);
					Qlist.get(2+noq*3).add(point[i][1]);
					inQ[i]=1;
				}else if(Qlist.get(1+noq*3).contains(point[i][0])) {
					Qlist.get(0+noq*3).add(i+1);
					Qlist.get(2+noq*3).add(point[i][1]);
					inQ[i]=1;
				}else if(Qlist.get(2+noq*3).contains(point[i][1])) {
					Qlist.get(0+noq*3).add(i+1);
					Qlist.get(1+noq*3).add(point[i][0]);
					inQ[i]=1;
				}
			}
			if(Loop==true && old_set.equals(Qlist.get(noq*3))) {
				noq++;
				Qlist.add(new HashSet<Integer>());//Q
				Qlist.add(new HashSet<Integer>());//X
				Qlist.add(new HashSet<Integer>());//Y
			}
		}

		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		for(int i=0; i<Q; i++) {
			input = br.readLine();
			st = new StringTokenizer(input, " ");
			int A=Integer.parseInt(st.nextToken());
			int B=Integer.parseInt(st.nextToken());
			double X=Double.parseDouble(st.nextToken());
			
			boolean f=false;
			for(int j=0 ; j<=noq; j++) {
				if(Qlist.get(0+j*3).contains(A)&&Qlist.get(0+j*3).contains(B)) {
					bw.write("YES\n");
					f = true;
					break;
				}else if(X==0) {
					bw.write("NO\n");
					f = true;
					break;
				}
			}
			if(f) continue;
			
			int AX[] = new int[2];
			int AY[] = new int[2];
			int BX[] = new int[2];
			int BY[] = new int[2];
			for(int j=0 ; j<=noq; j++) {
				if(Qlist.get(0+j*3).contains(A)){
					Iterator<Integer> itr = Qlist.get(1+j*3).iterator(); 
					AX[0] = itr.next();
					AX[1] = AX[0];
					while(itr.hasNext()) AX[1] = itr.next();
					Iterator<Integer> itr2 = Qlist.get(2+j*3).iterator(); 
					AY[0] = itr2.next();
					AY[1] = AY[0];
					while(itr2.hasNext()) AY[1] = itr2.next();
				}
				if(Qlist.get(0+j*3).contains(B)){
					Iterator<Integer> itr = Qlist.get(1+j*3).iterator(); 
					BX[0] = itr.next();
					BX[1] = BX[0];
					while(itr.hasNext()) BX[1] = itr.next();
					Iterator<Integer> itr2 = Qlist.get(2+j*3).iterator(); 
					BY[0] = itr2.next();
					BY[1] = BY[0];
					while(itr2.hasNext()) BY[1] = itr2.next();
				}
			}
			if(AX[0]<=BX[1]&&AX[1]>=BX[0]) {
				bw.write("YES\n");
			}else if(AY[0]<=BY[1]&&AY[1]>=BY[0]) {
				bw.write("YES\n");
			}else {
				bw.write("NO\n");
			}
		}
		bw.flush();
	}

}

