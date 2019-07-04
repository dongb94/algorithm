
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

	void addLeft(T data) {
		TreeNode<T> *left = new TreeNode<T>(data);
		addLeft(left);
	}

	void addRight(TreeNode<T>* right) {
		this->right = right;
		right->parent = this;
	}

	void addRight(T data) {
		TreeNode<T> *right = new TreeNode<T>(data);
		addRight(right);
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
