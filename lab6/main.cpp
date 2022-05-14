#include <iostream>
#include <vector>
#include "TreeNode.h"
#include "treeService.h"

using namespace std;

int main() {
    srand(time(0));
    int n = 0;
    cout << "Enter tree level:";cin >> n;

    int levels = 0;
    cout << "Enter number of levels:";cin >> levels;

    TreeNode *root;
    root = new TreeNode(-10 + rand() % 100);
    root = generateTreeNode(root, levels);

    int totalLevels = countNumberOfLevels(root, 0);
    cout << "Total number of tree levels:" << totalLevels << endl;
    cout << "Number of nodes on level " <<n<<" :" << getNumberOfNodesOnLevel(root, n-1, 0) << endl;

    printTree(root, totalLevels);
}