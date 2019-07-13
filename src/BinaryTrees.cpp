#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct TreeNode {
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

TreeNode* lowestCommonAncestor(TreeNode* a, TreeNode* b) {
  
}