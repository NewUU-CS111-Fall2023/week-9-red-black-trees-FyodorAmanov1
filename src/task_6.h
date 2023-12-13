#include <iostream>

// Node structure for the Red-Black tree
struct Node {
  int data;
  bool color; // true for red, false for black
  int blackHeight; // Tracks the black height
  Node* left;
  Node* right;
  Node* parent;

  Node(int data, bool color = false, Node* parent = nullptr) : data(data), color(color), blackHeight(0), left(nullptr), right(nullptr), parent(parent) {}
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

  // Print the tree recursively, now including black height
  void printTreeWithBlackHeight(Node* node) {
    if (node) {
      std::cout << node->data << (node->color ? " (red)" : " (black)") << " - black height: " << node->blackHeight << std::endl;
      if (node->left) {
        printTreeWithBlackHeight(node->left);
      }
      if (node->right) {
        printTreeWithBlackHeight(node->right);
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
      newNode->blackHeight = 1; // Root has black height 1
      return;
    }
    if (newNode->data < parent->data) {
      parent->left = newNode;
      newNode->parent = parent;
    } else {
      parent->right = newNode;
      newNode->parent = parent;
    }
    // Update black heights on insert
    updateBlackHeights(parent, newNode);
  }

  // Update black heights recursively
  void updateBlackHeights(Node* node, Node* insertedNode) {
    if (node) {
      if (insertedNode->color && node->color) {
        node->blackHeight++;
      }
      updateBlackHeights(node->left, insertedNode);
      updateBlackHeights(node->right, insertedNode);
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

  tree.printTreeWithBlackHeight(tree.root);

  return 0;
}
