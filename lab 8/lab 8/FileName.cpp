#include<iostream>
#include<queue>
using namespace std;

template<class T>
class BinaryTree {
private:
	struct Node {
		T data;
		Node* leftChild;
		Node* rightChild;
		Node* parentNode;
		Node(T val) : data(val), leftChild(nullptr), rightChild(nullptr), parentNode(nullptr) {}
	};

	Node* root;

	// Private traversal helpers
	void preOrder(Node* node) const {
		if (node == nullptr) return;
		cout << node->data << " ";
		preOrder(node->leftChild);
		preOrder(node->rightChild);
	}

	void inOrder(Node* node) const {
		if (node == nullptr) return;
		inOrder(node->leftChild);
		cout << node->data << " ";
		inOrder(node->rightChild);
	}

	void postOrder(Node* node) const {
		if (node == nullptr) return;
		postOrder(node->leftChild);
		postOrder(node->rightChild);
		cout << node->data << " ";
	}

public:
	BinaryTree() : root(nullptr) {}

	BinaryTree(T val) {
		root = new Node(val);
	}

	Node* getRoot() const {
		return root;
	}

	void setLeft(Node* parent, T val) {
		if (!parent) {
			cout << "Cannot insert to a null node.\n";
			return;
		}
		if (parent->leftChild == nullptr) {
			parent->leftChild = new Node(val);
			parent->leftChild->parentNode = parent;
		}
		else {
			cout << "Left child already exists.\n";
		}
	}

	void setRight(Node* parent, T val) {
		if (!parent) {
			cout << "Cannot insert to a null node.\n";
			return;
		}
		if (parent->rightChild == nullptr) {
			parent->rightChild = new Node(val);
			parent->rightChild->parentNode = parent;
		}
		else {
			cout << "Right child already exists.\n";
		}
	}

	void insert(T val) {
		Node* newNode = new Node(val);
		if (!root) {
			root = newNode;
			return;
		}
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			Node* temp = q.front(); q.pop();
			if (!temp->leftChild) {
				temp->leftChild = newNode;
				newNode->parentNode = temp;
				return;
			}
			else {
				q.push(temp->leftChild);
			}
			if (!temp->rightChild) {
				temp->rightChild = newNode;
				newNode->parentNode = temp;
				return;
			}
			else {
				q.push(temp->rightChild);
			}
		}
	}

	void preOrder() const {
		preOrder(root);
		cout << endl;
	}

	void inOrder() const {
		inOrder(root);
		cout << endl;
	}

	void postOrder() const {
		postOrder(root);
		cout << endl;
	}

	void levelOrder() const {
		if (!root) return;
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			Node* curr = q.front(); q.pop();
			cout << curr->data << " ";
			if (curr->leftChild) q.push(curr->leftChild);
			if (curr->rightChild) q.push(curr->rightChild);
		}
		cout << endl;
	}

	~BinaryTree() {
		if (!root) return;
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			Node* temp = q.front(); q.pop();
			if (temp->leftChild) q.push(temp->leftChild);
			if (temp->rightChild) q.push(temp->rightChild);
			delete temp;
		}
	}
};

int main() {
	BinaryTree<int> tree;
	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);

	cout << "Preorder: "; tree.preOrder();
	cout << "Inorder: "; tree.inOrder();
	cout << "Postorder: "; tree.postOrder();
	cout << "Level order: "; tree.levelOrder();

	return 0;
}

