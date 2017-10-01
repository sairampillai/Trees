#include<iostream>

using namespace std;

class BST {
	
	struct node {
		int data;
		node* left;
		node* right;
	};

	node* root;

	node* insert(int x,node* t){
		if(t == NULL){
			t = new node;
			t->data = x;
			t->left = t->right = NULL;	
		}
		else if(x < t->data)
			t->left = insert(x,t->left);
		else if(x > t->data)
			t->right = insert(x, t->right);
		return t;
	}
	
	node* findMin(node* t){
		if(t == NULL){
			return NULL;
		}
		else if(t->left == NULL)
			return t;
		else
			return findMin(t->left);
	}

	node* findMax(node* t){
		if(t == NULL)
			return NULL;
		else if(t->right == NULL)
			return t;
		else
			return findMax(t->right);
	}
	
	node* remove(int x, node* t){
		node* temp;
		if(t == NULL)
			return NULL;
		else if(x < t->data)
			t->left = remove(x,t->left);
		else if(x > t->data)
			t->right = remove(x,t->right);
		else if(t->left && t->right)
		{
			temp = findMin(t->right);
			t->data = temp->data;
			t->right = remove(t->data,t->right);
		}
		else {
			temp = t;
			if(t->left == NULL)
				t = t->right;
			else if(t->right == NULL)
				t = t->left;
			delete temp;
		}

		return t;

	}

	void inorder(node* t) {
		if(t == NULL)
			return;
		inorder(t->left);
		cout<<t->data<<" ";
		inorder(t->right);
	}

	node* find(node* t, int x) {
		if(t == NULL)
			return NULL;
		else if(x < t->data)
			return find(t->left, x);
		else if(x > t->data)
			return find(t->right, x);
		else
			return t;
	}

	public:
		BST() {
			root = NULL;
		}
		
		void insert(int x) {
			root = insert(x,root);
		}

		void remove(int x){
			root = remove(x,root);
		}

		void display() {
			inorder(root);
			cout<<endl;
		}

		void search(int x) {
			root = find(root,x);
		}
	
};

int main() {
	BST tree;
	tree.insert(10);
	tree.insert(9);
	tree.insert(8);
	tree.insert(7);
	tree.insert(6);
	tree.display();
	tree.insert(1);
	tree.insert(2);
	tree.display();
	tree.remove(6);
	tree.display();
}
