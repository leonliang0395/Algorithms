#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct TreeNode {
  TreeNode* parent;
  TreeNode* left;
  TreeNode* right;
  int data;
};

void recursiveInOrderTraversal(TreeNode* head) {
  if (!head) return;

  recursiveInOrderTraversal(head->left);
  cout << head->data << " ";
  recursiveInOrderTraversal(head->right);

  return;
}

void iterativeInOrderTraversal(TreeNode* head) {
  deque<pair<TreeNode*, bool>> stack;
  if (head) {
    stack.push_front(make_pair(head, false));
  }

  while (!stack.empty()) {
    TreeNode* currNode = stack.front().first;
    bool visited = stack.front().second;
    stack.pop_front();

    if (visited) {
      cout << currNode->data << " ";
    }

    if (currNode->right) {
      stack.push_front(make_pair(currNode->right, false));
    }
    stack.push_front(make_pair(currNode, true));
    if (currNode->left) {
      stack.push_front(make_pair(currNode->left, false));
    }
  }
}

int heightTopDown(TreeNode* head, int currentHeight, int currentMax) {
  if (!head) return currentMax;

  int iterationHeight = currentHeight + 1;
  currentMax = max(iterationHeight, currentMax);

  return max(heightTopDown(head->left, iterationHeight, currentMax), 
             heightTopDown(head->right, iterationHeight, currentMax));
}

int heightBottomUp(TreeNode* head) {
  if (!head) return 0;
  return max(heightBottomUp(head->left), heightBottomUp(head->right)) + 1;
}

bool balancedTree(TreeNode* head) {
  if (!head) return true;

  int leftH = balancedTree(head->left);
  int rightH = balancedTree(head->right);

  if (leftH == -1 || rightH == -1) {
    return -1;
  } 
  if (abs(leftH - rightH) > 1) {
    return -1;
  }
  return 1 + max(leftH, rightH);
}

void printPathsToLeaf(TreeNode* head, string path) {
  if (!head->left && !head->right) cout << path << endl;
  path += head->data + " ";
  printPathsToLeaf(head->left, path);
  printPathsToLeaf(head->right, path);
}

class treeDiameter {
  int treeDiameter = 0;

  int diameterHelper(TreeNode* head) {
    if (!head) {
      return 0;
    }

    int leftH = diameterHelper(head->left);
    int rightH = diameterHelper(head->right);

    treeDiameter = max(leftH + rightH, treeDiameter);

    return max(leftH, rightH) + 1;
  }

  int diameter(TreeNode* head) {
    diameterHelper(head);
    return treeDiameter;
  }
};

int depthOfLCA(TreeNode* root, TreeNode* target, int level) {
  if (!root) return 0;

  if (root == target) return level;

  // check left subtree, pass on the current level.
  int leftTree = depthOfLCA(root->left, target, level + 1);

  if (leftTree != 0) {
    return leftTree;
  }

  int rightTree = depthOfLCA(root->right, target, level + 1);

  return rightTree;
}

TreeNode* lowestCommonAncestorWithParent(TreeNode* root, TreeNode* a, TreeNode* b) {
  if (!root) return nullptr;
  if (!a) return b;
  if (!b) return a;

  int aDepth = depthOfLCA(root, a, 0);
  int bDepth = depthOfLCA(root, b, 0);

  int depthDiff = abs(aDepth - bDepth);

  for (int i = 0; i < depthDiff; ++i) {
    if (aDepth < bDepth) {
      b = b->parent;
    }
    if (bDepth < aDepth) {
      a = a->parent;
    }
  }

  while (a != b) {
    a = a->parent;
    b = b->parent;
  }

  return a;

}

TreeNode* LCAWithoutParent(TreeNode* root, TreeNode* a, TreeNode* b) {
  if (!root) return nullptr; 

  if (root == a || root == b) return root;

  TreeNode* left = LCAWithoutParent(root->left, a, b);
  TreeNode* right = LCAWithoutParent(root->right, a, b);

  // If you've found a and b, then this node is the LCA.
  if (left && right) {
    return root;
  }

  // If you've only found one of them
  if (left) {
    return left;
  }

  if (right) {
    return right;
  }

  return nullptr;
}

// Each recursive call, construct the tree from [preorderStart, preorderEnd] and [inorderStart, inorderEnd]
TreeNode* treeReconstruction(const vector<int> &inorder, const vector<int> &preorder, int preorderStart, int preorderEnd, int inorderStart, int inorderEnd) {
  // Get root value from beginning of preorder 
  TreeNode* n = new TreeNode();
  n->data = preorder[preorderStart];

  // Find index of root in inorder
  auto it = find(inorder.begin(), inorder.end(), n->data);
  int idx = distance(inorder.begin(), it);

  n->left = treeReconstruction(inorder, preorder, preorderStart + 1, preorderStart + (idx - inorderStart), inorderStart, idx - 1);
  n->right = treeReconstruction(inorder, preorder, preorderStart + 1 + (idx - inorderStart), preorderEnd, idx + 1, inorderEnd);

  return n;
}