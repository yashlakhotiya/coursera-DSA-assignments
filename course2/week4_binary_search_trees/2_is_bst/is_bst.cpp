#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  long int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(long int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTree(const vector<Node>& tree, int root_index, long int min, long int mx) {
  // Implement correct algorithm here
	if(tree.size() == 0 || tree.size() == 1) return true;
	Node root = tree[root_index];

	if(root.key < min || root.key > mx) return false;
	if(root.left == -1 && root.right == -1){
		return true;
	}
	else if(root.left == -1 && root.right != -1){
		return IsBinarySearchTree(tree,root.right,root.key,mx);
	}
	else if(root.left != -1 && root.right == -1){
		return IsBinarySearchTree(tree,root.left,min,root.key);
	}
	else{
		return IsBinarySearchTree(tree,root.left,min,root.key) && IsBinarySearchTree(tree,root.right,root.key,mx);
	}
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    long int key;
    int left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  int root_index = 0;
  long int min = -99999999999, mx = 99999999999;
  if (IsBinarySearchTree(tree,root_index,min,mx)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
