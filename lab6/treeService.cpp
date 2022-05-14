

#include "treeService.h"

int countNumberOfLevels(TreeNode *root, int levels) {
    if (root->getRightNode() != NULL) {
        return countNumberOfLevels(root->getLeftNode(), levels + 1);
    }
    if (root->getLeftNode() != NULL) {
        return countNumberOfLevels(root->getRightNode(), levels + 1);
    }
    return levels;
}
TreeNode *generateTreeNode(TreeNode *root, int numberOfLevels) {
    if (numberOfLevels > 0) {
        root->setLeftNode(generateTreeNode(new TreeNode(-30 + rand() % 100), numberOfLevels - 1));
        root->setRightNode(generateTreeNode(new TreeNode(-30 + rand() % 100), numberOfLevels - 1));
    }
    return root;
}
int getNumberOfNodesOnLevel(TreeNode *node, int selected, int current) {
    if (selected == current) {
        return 1;
    } else {
        return getNumberOfNodesOnLevel(node->getLeftNode(), selected, current + 1) +
               getNumberOfNodesOnLevel(node->getRightNode(), selected, current + 1);
    }
}

void printTree(TreeNode *root, int selected, int current, int total) {
    if (selected == current) {
        cout<<setw(total)<<root->getNumber();
        for (int i = 0; i < total; ++i) {
            cout<<" ";
        }
    } else {
        printTree(root->getLeftNode(), selected,
                  current + 1, total / 2);
        printTree(root->getRightNode(), selected,
                  current + 1, total / 2);
    }
}
void printTree(TreeNode *root, int totalLevels){
    if(totalLevels<=7) {
        int total = getNumberOfNodesOnLevel(root,totalLevels,0);
        for (int i = 0; i < totalLevels; ++i) {
            printTree(root,i,0, total);
            cout<<endl;
        }
        cout<<endl;
    }else{
        cout<<"Tree is too large for printing"<<endl;
    }
}
