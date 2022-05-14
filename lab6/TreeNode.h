//
// Created by kachm on 07.04.2022.
//

#ifndef LAB6_TREENODE_H
#define LAB6_TREENODE_H


class TreeNode {
private:
    int number;
    TreeNode *leftNode;
    TreeNode *rightNode;
public:
    TreeNode(int number);
    TreeNode();

    int getNumber() const;

    TreeNode *getLeftNode() const;

    void setLeftNode(TreeNode *leftNode);

    TreeNode *getRightNode() const;

    void setRightNode(TreeNode *rightNode);
};


#endif //LAB6_TREENODE_H
