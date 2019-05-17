
template <class T>
class TreeNode{
public:
	T data;
	TreeNode* parent;
	TreeNode* left;
	TreeNode* right;

	TreeNode(T data) {
		this->data = data;
	}
};

template <class T>
class ListNode {
	T data;
	ListNode* previous;
	ListNode* next;

	ListNode(T data) {
		this->data = data;
	}
};
