package beakJoon_Level13_Deque;

/* Question
 * 정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

	명령은 총 여덟 가지이다.
	
	push_front X: 정수 X를 덱의 앞에 넣는다.
	push_back X: 정수 X를 덱의 뒤에 넣는다.
	pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	size: 덱에 들어있는 정수의 개수를 출력한다.
	empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
	front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 */

import java.io.*;
import java.util.StringTokenizer;

public class Deque {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());
		Deque _deque = new Deque();
		deque front = null;
		deque back = null;

		for (int i = 0; i < N; i++) {
			String commend = br.readLine();
			StringTokenizer st = new StringTokenizer(commend, " ");

			switch (st.nextToken()) {
			case "push_front":
				if (front == null) {
					int v = Integer.parseInt(st.nextToken());
					front = _deque.new deque(v);
					back = front;
				} else {
					deque newFront = _deque.new deque(Integer.parseInt(st.nextToken()));
					front._prev = newFront;
					newFront._next = front;
					front = newFront;
				}

				break;
			case "push_back":
				if (back == null) {
					front = _deque.new deque(Integer.parseInt(st.nextToken()));
					back = front;
				} else {
					deque newBack = _deque.new deque(Integer.parseInt(st.nextToken()));
					back._next = newBack;
					newBack._prev = back;
					back = newBack;
				}

				break;
			case "pop_front":
				if (front == null) {
					bw.write("-1\n");
				} else {
					bw.write(front._value + "\n");
					if (front._next == null) {
						front = null;
						back = null;
					} else {
						front = front._next;
						front._prev = null;
					}
				}
				break;
			case "pop_back":
				if (back == null) {
					bw.write("-1\n");
				} else {
					bw.write(back._value + "\n");
					if (back._prev == null) {
						front = null;
						back = null;
						break;
					} else {
						back = back._prev;
						back._next = null;
					}
				}
				break;
			case "size":
				if (front == null) {
					bw.write("0\n");
					break;
				}
				int size = 1;
				deque node = front;
				while (!node.equals(back)) {
					size++;
					node = node._next;
				}
				bw.write(size + "\n");
				break;
			case "empty":
				bw.write((front == null ? 1 : 0) + "\n");
				break;
			case "front":
				if (front == null)
					bw.write("-1\n");
				else
					bw.write(front._value + "\n");
				break;
			case "back":
				if (back == null)
					bw.write("-1\n");
				else
					bw.write(back._value + "\n");
				break;
			}

		}
		bw.flush();
	}

	public class deque {
		private int _value;
		private deque _prev;
		private deque _next;

		deque(int value) {
			_value = value;
		}
		// public void setValue(int value) {
		// _value = value;
		// }
		//
		// public void setNext(deque node) {
		// _next = node;
		// }
		//
		// public void setPrev(deque node) {
		// _prev = node;
		// }
	}

}
