 public static long pthFactor(long n, long p) {
		ArrayList<Long> list = new ArrayList<>();
		for(long i=1; i*i <= n; i++) {
			if(n%i==0) list.add(i);
		}
		Iterator<Long> it = list.iterator();
		for(long i=list.size()-1; i>=0; i--) {
			long num = list.get((int)i);
			if(num*num==n) continue;
			list.add(n/list.get((int)i));
		}
		
		if(p>list.size()) return 0;
		
		Iterator<Long> it2 = list.iterator();
		
		for(long i =0; i<p-1; i++) {
			it2.next();
		}
		
    	return it2.next();
    }
    
 static int maxStep(int n, int k) {
    	int step = 0;
    	int power = 1;
    	for(int i = 0; i<n; i++) {
    		step += power;
    		if(step == k) {
    			step--;
    		}
    		power++;
    	}
    	return step;
    }
    
    
    public static int minMoves(List<Integer> avg) {
    	Iterator<Integer> it = avg.iterator();
    	int N = avg.size();
    	int pointer = 0;
    	int sum = 0;
    	int nOfOne = 0;
    	
    	for(int i=0; i<N; i++) {
    		int input = it.next();
    		if(input==1) {
    			nOfOne++;
    			if(pointer!=i)
    				sum += i-pointer;
    			pointer++;
    		}
    	}
    	System.out.println();
    	sum = Math.min(sum, N*nOfOne-nOfOne*nOfOne - sum);
    	
    	return sum;
    }


    static Node[] node;
    public static int bestTrio(int friendsNodes, List<Integer> friendsFrom, List<Integer> friendsTo) {
    	
    	node = new Node[friendsNodes];
    	ArrayList<Integer> trio= new ArrayList<>();
    	
    	for(int i=0; i<friendsNodes; i++) {
    		node[i] = new Node();
    	}

    	for(int i=0; i<friendsFrom.size(); i++) {
    		int from = friendsFrom.get(i) -1;
    		int to = friendsTo.get(i) -1;

    		node[from].Friend.add(to);
    		node[to].Friend.add(from);
    		int th = node[from].FindTrio();
    		
    		if(th != -1) {
    			trio.add(from);
    			trio.add(to);
    			trio.add(th);
    		}
    	}
    	
    	if(trio.size()==0) return -1;
    	
    	int score =0;
    	int sum=0;
    	for(int i=0; i<trio.size(); i+=3) {
    		sum = node[trio.get(i)].Friend.size()-2;
    		sum += node[trio.get(i+1)].Friend.size()-2;
    		sum += node[trio.get(i+2)].Friend.size()-2;
    		if(score < sum) score = sum;
    	}
    	
    	return score;
    }
    static class Node{
    	ArrayList<Integer> Friend= new ArrayList<>();
    	
    	int FindTrio() {
    		for(int a : Friend) {
    			for(int b:node[a].Friend) {
    				if(Friend.indexOf(b) != -1) {
    					return Friend.indexOf(b);
    				}
    			}
    		}
    		return -1;
    	}
    }
    
    
    public static int countPairs(List<Integer> numbers, int k) {
    	HashSet<Integer> set =  new HashSet<>();
    	int out = 0;
    	
    	for(int i:numbers) set.add(i);
    	ArrayList<Integer> list = new ArrayList(set); 
    	
    	Collections.sort(list);
    	int position = 0;
    	for(int i =0; i<list.size(); i++) {
    		int a = list.get(i);
    		for(; position<list.size(); position++) {
    			if(list.get(position)-a > k) break;
    			if(list.get(position)-a == k) {
    				out++;
    				break;
    			}
    		}
    	}
    	
    	return out;
    }
