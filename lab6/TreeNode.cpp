//
// Created by kachm on 07.04.2022.
//

#include "TreeNode.h"

#include <bits/stdc++.h>

TreeNode::TreeNode(int number): number(number), leftNode(NULL),rightNode(NULL) {}

TreeNode::TreeNode(): number(0), leftNode(),
                      rightNode() {}

int TreeNode::getNumber() const {
    return number;
}
TreeNode *TreeNode::getLeftNode() const {
    return leftNode;
}
void TreeNode::setLeftNode(TreeNode *leftNode) {
    TreeNode::leftNode = leftNode;
}
TreeNode *TreeNode::getRightNode() const {
    return rightNode;
}
void TreeNode::setRightNode(TreeNode *rightNode) {
    TreeNode::rightNode = rightNode;
}
