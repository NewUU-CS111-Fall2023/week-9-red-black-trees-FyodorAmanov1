#include <iostream>

// Node structure for the Red-Black tree
struct Node {
  int data;
  bool color; // true for red, false for black
  int childrenCount; // Tracks the number of children
  Node* left;
  Node* right;
  Node* parent;

  Node(int data, bool color = false, Node* parent = nullptr) : data(data), color(color), childrenCount(0), left(nullptr), right(nullptr), parent(parent) {}
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

  // Print the tree recursively, now including children count
  void printTreeWithChildren(Node* node) {
    if (node) {
      std::cout << node->data << (node->color ? " (red)" : " (black)") << " - children: " << node->childrenCount << std::endl;
      if (node->left) {
        printTreeWithChildren(node->left);
      }
      if (node->right) {
        printTreeWithChildren(node->right);
      }
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
      return;
    }
    if (newNode->data < parent->data) {
      parent->left = newNode;
      newNode->parent = parent;
    } else {
      parent->right = newNode;
      newNode->parent = parent;
    }
    // Update children count of parent on insert
    updateChildrenCount(parent);
  }

  // Update children count recursively
  void updateChildrenCount(Node* node) {
    if (node) {
      node->childrenCount = 1;
      if (node->left) {
        node->childrenCount += node->left->childrenCount;
      }
      if (node->right) {
        node->childrenCount += node->right->childrenCount;
      }
    }
  }

  // Remaining tree operations not included for brevity...
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

  tree.printTreeWithChildren(tree.root);

  return 0;
}
