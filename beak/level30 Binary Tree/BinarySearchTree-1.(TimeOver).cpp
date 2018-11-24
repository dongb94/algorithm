/*���� Ž�� Ʈ���� ��� ��尡 ���ƾ� 2���� �ڽ� ��带 ������ �ִ� Ʈ���̰�, �� ��忡�� ���� �ϳ��� �����ִ�.
���� � ��忡 ���� �ִ� ���� X���, �� ����� ���� ����Ʈ������ X���� ���� ��, ������ ����Ʈ������ X���� ū ���� ����Ǿ� �־�� �Ѵ�.

1���� ũ�ų� ����, N���� �۰ų� ���� �� N���� �� ���� �����ϴ� ������ �Է����� �־�����.
�� ������ �̿��ؼ� ���� Ž�� Ʈ���� ������� �Ѵ�.
���� �迭�� ù ��° ���� ��Ʈ ���� ����, �ٸ� ������ ������ ������� �����ϸ鼭 ���� Ž�� Ʈ���� ������� �Ѵ�.
��, ù ��° ���� ������ ��� ���� ���ؼ� insert(X,root)�� �����ϴ� �Ͱ� ����. �� �Լ��� ������ ����. 

���� Ž�� Ʈ���� �����ϴ� �Լ��� ������ ����.

insert(number X, node N)
    ī���� C���� 1 ������Ų��
    if X�� ��� N�� �ִ� ������ �۴ٸ�
        if N�� ���� �ڽ��� ���ٸ�
            X�� �����ϴ� �� ��带 ���� ��, N�� ���� �ڽ����� �����
        else
            insert(X, N�� ���� �ڽ�)
    else (X�� ��� N�� �ִ� ������ ũ�ٸ�)
        if N�� ������ �ڽ��� ���ٸ�
            X�� �����ϴ� �� ��带 ���� ��, N�� ������ �ڽ����� �����
        else
            insert(X, N�� ������ �ڽ�)
�� ���� ������ �Ŀ� C�� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ī���� C�� ���� 0���� �ʱ�ȭ�Ǿ� �ִ�.
*/


#include <stdio.h>

int cnt = 0;

class node {
public:
	int num;
	node *right;
	node *left;
	node(int n) {
		num = n;
	}
};

void insert(int num, node& _node) {
	++cnt;
	if (_node.num > num) {
		if (!_node.left) {
			_node.left = new node(num);
		}
		else {
			insert(num, *_node.left);
		}
	}
	else {
		if (!_node.right) {
			_node.right = new node(num);
		}
		else {
			insert(num, *_node.right);
		}
	}
}

int main(void) {

	int N;
	int first;
	
	node *start;

	scanf_s("%d%d",&N,&first);
	start = new node(first);
	printf("%d\n", cnt);

	int input;
	for (; N > 1; N--) {	
		scanf_s("%d",&input);
		insert(input, *start);
		printf("%d\n",cnt);
	}

	return 0;
}
