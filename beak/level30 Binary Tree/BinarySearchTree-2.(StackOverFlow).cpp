/*이진 탐색 트리는 모든 노드가 많아야 2개의 자식 노드를 가지고 있는 트리이고, 각 노드에는 수가 하나씩 쓰여있다.
만약 어떤 노드에 쓰여 있는 수가 X라면, 그 노드의 왼쪽 서브트리에는 X보다 작은 수, 오른쪽 서브트리에는 X보다 큰 수만 저장되어 있어야 한다.

1보다 크거나 같고, N보다 작거나 같은 수 N개가 한 번씩 등장하는 수열이 입력으로 주어진다.
이 수열을 이용해서 이진 탐색 트리를 만드려고 한다.
이제 배열의 첫 번째 수를 루트 노드로 놓고, 다른 나머지 수들을 순서대로 삽입하면서 이진 탐색 트리를 만들려고 한다.
즉, 첫 번째 수를 제외한 모든 수에 대해서 insert(X,root)를 실행하는 것과 같다. 그 함수는 다음과 같다. 

이진 탐색 트리에 삽입하는 함수는 다음과 같다.

insert(number X, node N)
    카운터 C값을 1 증가시킨다
    if X가 노드 N에 있는 수보다 작다면
        if N의 왼쪽 자식이 없다면
            X를 포함하는 새 노드를 만든 뒤, N의 왼쪽 자식으로 만든다
        else
            insert(X, N의 왼쪽 자식)
    else (X가 노드 N에 있는 수보다 크다면)
        if N의 오른쪽 자식이 없다면
            X를 포함하는 새 노드를 만든 뒤, N의 오른쪽 자식으로 만들기
        else
            insert(X, N의 오른쪽 자식)
각 수를 삽입한 후에 C의 값을 출력하는 프로그램을 작성하시오. 카운터 C의 값은 0으로 초기화되어 있다.
*/


#include <stdio.h>


int tree[300001][2];

int cnt = 0;

void insert(int num, int _node) {
	++cnt;
	if (_node > num) {
		if (!tree[_node][0]) {
			tree[_node][0] = num;
		}
		else {
			insert(num, tree[_node][0]);
		}
	}
	else {
		if (!tree[_node][1]) {
			tree[_node][1] = num;
		}
		else {
			insert(num, tree[_node][1]);
		}
	}
}

int main() {

	int N;
	int first;

	scanf_s("%d%d",&N,&first);
	printf("%d\n", cnt);

	int input;
	for (; N > 1; N--) {	
		scanf_s("%d",&input);
		insert(input, first);
		printf("%d\n",cnt);
	}
}
