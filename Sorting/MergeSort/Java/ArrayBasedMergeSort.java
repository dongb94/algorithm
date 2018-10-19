package sorting;

/*
 * Array<T> MergeSort
 * Array based sorting
 */

import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;

public class ArrayBasedMergeSort {

	// with return value
//	static <T> T[] Merge(int min, int max, T[] array, Comparator<T> c) {
//		//Divide
//		int mid = (max+min)/2;
//		if(mid == max) return array;
//
//		Merge(min, mid, array, c);
//		Merge(mid+1, max, array, c);
//		
//		//Conquer
//		int lp = min;
//		int rp = mid+1;
//		Queue<T> temp = new LinkedList<T>();
//		while(lp<=mid||rp<=max) {
//			if(rp>max) {
//				temp.add(array[lp++]);
//				continue;
//			}else if(lp>mid) {
//				temp.add(array[rp++]);
//				continue;
//			}
//			int result = c.compare(array[lp], array[rp]);
//			if(result<0) temp.add(array[rp++]);
//			else temp.add(array[lp++]);
//		}
//		lp = min;
//		for(T t:temp) {
//			array[lp++] = t;
//		}
//		
//		return array; 
//	}
	
	// without return value
	static <T> void Merge(int min, int max, T[] array, Comparator<T> c) {
			//Divide
			int mid = (max+min)/2;
			if(mid == max) return;

			Merge(min, mid, array, c);
			Merge(mid+1, max, array, c);
			
			//Conquer
			int lp = min;
			int rp = mid+1;
			Queue<T> temp = new LinkedList<T>();
			while(lp<=mid||rp<=max) {
				if(rp>max) {
					temp.add(array[lp++]);
					continue;
				}else if(lp>mid) {
					temp.add(array[rp++]);
					continue;
				}
				int result = c.compare(array[lp], array[rp]);
				if(result<0) temp.add(array[rp++]);
				else temp.add(array[lp++]);
			}
			lp = min;
			for(T t:temp) {
				array[lp++] = t;
			}
			
			return; 
		}
	
	//example code
	public static void main(String[] args) {
		Integer[] array = {4, 1, 2, 3, 5};
		Merge(0, array.length-1, array, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				if(o1>o2) return -1;
				else if(o1==o2) return 0;
				else return 1;
			}
		});
		
	}
}
