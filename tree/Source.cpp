#include <iostream>
using namespace std;
template<class T1, class T2>
class Tree
{
	struct Node
	{
		T1 key;
		T2 data;

		Node* left;
		Node* right;

		Node(int key, int data, Node* left = nullptr, Node* right = nullptr)
			: key(key), data(data), left(left), right(right)
		{ }
	};

	Node* root;

	void Add(int key, int data, Node*& root)
	{
		if (root == nullptr)
		{
			root = new Node(key, data);
			return;
		}

		if (key > root->key)
			Add(key, data, root->right);
		else
			Add(key, data, root->left);
	}


	void PrintKLP(Node* elem) const
	{
		if (elem != nullptr)
		{
			std::cout << elem->key << ":" << elem->data << " ";
			PrintKLP(elem->left);
			PrintKLP(elem->right);
		}
	}

	void PrintLKP(Node* elem) const
	{
		if (elem != nullptr)
		{
			PrintLKP(elem->left);
			std::cout << elem->key << ":" << elem->data << " ";
			PrintLKP(elem->right);
		}
	}
	void PrintPKL(Node* elem) const
	{
		if (elem != nullptr)
		{
			PrintPKL(elem->right);
			std::cout << elem->key << ":" << elem->data << " ";
			PrintPKL(elem->left);
		}
	}

	T2 Search(int key, Node* root) const
	{
		if (root == nullptr) return 0;

		if (key > root->key)
			Search(key, root->right);
		else if (key < root->key)
			Search(key, root->left);
		else
			return root->data;
	}

	void delete_subtree(Node* node) {
		if (!node) return;
		delete_subtree(node->left);
		delete_subtree(node->right);
		delete node;
	}

	void Copy(Node* other)
	{
		if (other != nullptr)
		{
			Add(other->key, other->data);
			Copy(other->left);
			Copy(other->right);
		}
	}

public:
	Tree() : root(nullptr) { }

	Tree(const Tree& other)
	{
		//this->root = other.root;
		Copy(other.root);
	}

	void Add(int key, int data)
	{
		Add(key, data, root);
	}

	T2 Search(int key) const
	{
		return Search(key, root);
	}

	void PrintKLP() const
	{
		PrintKLP(root);
	}
	void PrintLKP() const
	{
		PrintLKP(root);
	}
	void PrintPKL() const
	{
		PrintPKL(root);
	}

	~Tree()
	{
		delete_subtree(root);
	}

};

int main()
{
	Tree<int, int> tree;
	tree.Add(16, 200);
	tree.Add(75, 100);
	tree.Add(45, 12);
	tree.Add(22313, 5474);
	tree.Add(14, 54);
	tree.Add(174, 44);
	tree.Add(9, 10);
	tree.Add(32, 30);
	tree.Add(0, 33);
	tree.Add(5, 45);
	tree.Add(786, 11);
	tree.Add(5521, 233);
	tree.Add(100, 0);
	tree.PrintKLP(); cout << endl;
	tree.PrintLKP(); cout << endl;
	tree.PrintPKL(); cout << endl;
	cout << endl;
	cout << tree.Search(100);

	cout << endl;
	Tree<int, int> tree2(tree);
	tree2.PrintKLP();

	system("pause");
	return 0;
}