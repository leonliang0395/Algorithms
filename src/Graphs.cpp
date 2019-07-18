#include "common.h"
#include "GraphsAndTrees.h"
#include "LinkedList.h"

void DFS(GraphNode *root, int val)
{
  if (!root)
    return;
  if (root->val == val)
    return;
  root->visited = true;
  for (int i = 0; i < root->adjacent.size(); ++i)
  {
    if (!root->adjacent[i]->visited)
    {
      DFS(root->adjacent[i]);
    }
  }
  return;
}

void BFS(GraphNode *root, GraphNode *val)
{
  deque<GraphNode *> queue;
  root->visited = true;
  queue.push_back(root);

  while (!queue.empty())
  {
    GraphNode *cur = queue.front();
    if (cur == val)
    {
      return;
    }
    queue.pop_front();

    cur->visited = true;

    for (int i = 0; i < cur->adjacent.size(); ++i)
    {
      if (!cur->adjacent[i]->visited)
      {
        queue.push_back(cur->adjacent[i]);
      }
    }
  }
}

// Find out if there is a route between the two nodes
bool routeBetweenNodes(GraphNode *root, GraphNode *a, GraphNode *b)
{
  // Simple BFS just keep checking if a == b.
  deque<GraphNode *> queue;
  a->visited = true;
  queue.push_back(a);

  while (!queue.empty())
  {
    GraphNode *cur = queue.front();
    if (cur == b)
    {
      return true;
    }

    queue.pop_front();
    cur->visited = true;

    for (int i = 0; i < cur->adjacent.size(); ++i)
    {
      if (!cur->adjacent[i]->visited)
      {
        queue.push_back(cur->adjacent[i]);
      }
    }
  }

  return false;
}

/*
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
1. Mid = 0 + 9 / 2 = 4. a[4] = 5
  minimalHeightHelper(a, 0, 3)
  minimalHeightHelper(a, 5, 9)

[0 -> 3]
2. Mid = 0 + 3 / 2 = 1. a[1] = 2
  minimalHeightHelper(a, 0, 0)
  minimalHeightHelper(a, 2, 3)

[0 -> 0]
3. Mid = 0 + 0 / 2 = 0.
  minimalHeightHelper(a, 0, -1) -- DONE
  minimalHeightHelper(a, 1, 0) -- DONE

[2 -> 3]
4. Mid = 2 + 3 / 2 = 2.
  minimalHeightHelper(a, 2, 1) -- DONE
  minimalHeightHelper(a, 3, 3)
*/

TreeNode *minimalHeightHelper(const vector<int> &a, int start, int end)
{
  if (start > end)
  {
    return nullptr;
  }

  int mid = (start + end) / 2;

  TreeNode *root = new TreeNode();
  root->data = a[mid];
  root->left = minimalHeightHelper(a, start, mid - 1);
  root->right = minimalHeightHelper(a, mid + 1, end);

  return root;
}

// Create a Binary Tree with minimal height from a sorted array
TreeNode *minimalHeightTreeFromArray(const vector<int> &a)
{
  if (a.empty())
    return nullptr;

  return minimalHeightHelper(a, 0, a.size() - 1);
}

// Given a binary tree, design an algorithm that creates a linked list of all the nodes at each depth.
// e.g. if you have D depth, you should have D linked lists.
// Perform a Breadth first search.
// Keep track of when you change to a different depth.
vector<LinkedList<int>> listOfDepths(TreeNode *root)
{
  if (!root)
  {
    return {};
  }

  // Initialize the queue and result vector
  int depth = 0;
  vector<LinkedList<int> *> result;
  result.push_back(new LinkedList<int>);
  deque<pair<TreeNode *, int>> queue;
  queue.push_front(make_pair(root, depth));

  while (!queue.empty())
  {
    int curDepth = queue.front().second;
    TreeNode *curNode = queue.front().first;

    // Check if the node we just picked up has a different depth.
    if (depth != curDepth)
    {
      // If so, then we need to start a new Linked List.
      result.push_back(new LinkedList<int>);
      depth = curDepth;
    }
    
    // If the depth is the same as the node's depth, then we just append to the last linked list in the result vec.
    Node<int> *n = new Node<int>();
    n->data = curNode->data;
    result[result.size() - 1]->append(n);

    // Push the children of this node to the end of the queue with depth + 1.
    if (curNode->left)
    {
      queue.push_back(make_pair(curNode->left, depth + 1));
    }
    if (curNode->right)
    {
      queue.push_back(make_pair(curNode->right, depth + 1));
    }
  }
}

// Use numeric_limits<int>::min() as error code.
int balancedTreeHelper(TreeNode* n) {
  if (!n) {
    return 0;
  }

  int leftH = balancedTreeHelper(n->left);
  if (leftH == numeric_limits<int>::min()) return numeric_limits<int>::min();

  int rightH = balancedTreeHelper(n->right);
  if (rightH == numeric_limits<int>::min()) return numeric_limits<int>::min();

  if (abs(leftH - rightH) > 1) {
    return numeric_limits<int>::min();
  }

  return max(leftH, rightH) + 1;
}

// Check if a binary tree is balanced.
// This means that the heights of the two subtrees of any node never differ by more than one.
bool checkBalancedTree(TreeNode* root) {
  if (!root) return 0;

  int result = balancedTreeHelper(root);
  if (result == numeric_limits<int>::min()) return false;
  else return true;
}

/*

      5
    2   9
   1 5 7 10


      5
    2   9
   1     10  
 */

// Update max when branching left, update min when branching right.
bool validateBSTHelper(TreeNode* n, int min, int max) {
  if (!n) return true;

  if (n->data >= min && n->data < max) {
    return validateBSTHelper(n->left, min, n->data) && validateBSTHelper(n->right, n->data, max);
  } else {
    return false;
  }
}

// Validate BST
// BST is a BT where all left descendants <= current node < all right descendants.
// Do an in-order traversal.
bool validateBST(TreeNode* root) {
  return validateBSTHelper(root, numeric_limits<int>::min(), numeric_limits<int>::max());
}

TreeNode* nextNodeOfBST(TreeNode* root) {
  if (!root) return nullptr;
  // Go left until you hit nullptr.
  // If you are returned a nullptr, you are the node.

  TreeNode* left = nextNodeOfBST(root->left);
  if (!left) {
    return root;
  }
}