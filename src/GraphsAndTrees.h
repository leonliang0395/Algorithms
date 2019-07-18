struct GraphNode {
  vector<GraphNode*> adjacent;
  int val;
  bool visited = false;
};

struct TreeNode {
  TreeNode* parent;
  TreeNode* left;
  TreeNode* right;
  int data;
  bool visited = false;
};