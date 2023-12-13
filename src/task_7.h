#include <iostream>

// Node structure for the Red-Black tree
struct Node {
  int data;
  bool color; // true for red, false for black
  int height; // Tracks the node height
  Node* left;
  Node* right;
  Node* parent;

  Node(int data, bool color = false, Node* parent = nullptr) : data(data), color(color), height(0), left(nullptr), right(nullptr), parent(parent) {}
};

class RedBlackTree {
public:
  // Constructor
  RedBlackTree() : root(nullptr) {}

  // Insert a new node
  void Insert(int data) {
    Node* newNode = new Node(data);
    insertNode(root, newNode);
    insertFix(newNode);
  }

  // Print the tree recursively
  void printTree(Node* node) {
    if (node) {
      std::cout << node->data << (node->color ? " (red)" : " (black)") << std::endl;
      if (node->left) {
        printTree(node->left);
      }
      if (node->right) {
        printTree(node->right);
      }
    }
  }

  // Search for a node with given data
  void search(int data) {
    Node* foundNode = searchNode(data);
    if (foundNode) {
      std::cout << data << " is found, its height is " << foundNode->height << std::endl;
    } else {
      std::cout << data << " is not found" << std::endl;
    }
  }

private:
  // Root node of the tree
  Node* root;

  // Node search function
  Node* searchNode(int data) {
    Node* current = root;
    while (current) {
      if (data == current->data) {
        return current;
      } else if (data < current->data) {
        current = current->left;
      } else {
        current = current->right;
      }
    }
    return nullptr;
  }

  // Node insertion function with parent check and rotations
  void insertNode(Node* parent, Node* newNode) {
    if (!parent) {
      root = newNode;
      newNode->height = 1; // Root has height 1
      return;
    }
    if (newNode->data < parent->data) {
      parent->left = newNode;
      newNode->parent = parent;
    } else {
      parent->right = newNode;
      newNode->parent = parent;
    }
    // Update heights on insert (not shown for brevity)
  }

  // Remaining tree operations and height update logic not included for brevity...
};

int main() {
  int N;
  std::cin >> N;

  RedBlackTree tree;
  for (int i = 0; i < N; ++i) {
    int data;
    std::cin >> data;
    tree.Insert(data);
  }

  int searchValue;
  std::cin >> searchValue;
  tree.search(searchValue);

  return 0;
}
