class Node:
  def __init__(self, data, color="red", left=None, right=None):
    self.data = data
    self.color = color
    self.left = left
    self.right = right

def count_nodes(root):
  if not root:
    return 0
  else:
    return 1 + count_nodes(root.left) + count_nodes(root.right)

# Example usage
root = Node(10)
root.left = Node(5)
root.right = Node(15)
root.left.left = Node(2)
root.left.right = Node(7)
root.right.left = Node(12)
root.right.right = Node(20)

node_counts = {}
def traverse_and_count(node, path=""):
  if not node:
    return
  node_counts[path] = count_nodes(node)
  traverse_and_count(node.left, path + "L")
  traverse_and_count(node.right, path + "R")

traverse_and_count(root)

print(node_counts)
