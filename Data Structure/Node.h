
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
	
	void addLeft(TreeNode<T>* left) {
		this->left = left;
		left->parent = this;
	}

	void addRight(TreeNode<T>* right) {
		this->right = right;
		right->parent = this;
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
