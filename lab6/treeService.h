
#include <iomanip>
#include "iostream"
#include "TreeNode.h"


using namespace std;

int countNumberOfLevels(TreeNode *root, int levels);
TreeNode *generateTreeNode(TreeNode *root, int numberOfLevels);
int getNumberOfNodesOnLevel(TreeNode *node, int selected, int current);
void printTree(TreeNode *root, int selected, int current, int total);
void printTree(TreeNode *root, int totalLevels);