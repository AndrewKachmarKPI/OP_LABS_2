#include <iostream>
#include <vector>
#include "TreeNode.h"
#include "treeService.h"

using namespace std;

int main() {
    srand(time(0));
    int levels = 2 + rand() % 20; //Випадкова кількість рівнів
    cout<<"Select levels between 1 and "<<levels<<endl;
    int n = 0;
    cout << "Enter tree level:";cin >> n;
    while (n<0 && n>levels){
        cout << "Enter tree level:";cin >> n;
    }

    TreeNode *root;
    root = new TreeNode(-10 + rand() % 100);
    root = generateTreeNode(root, levels); //Генерація дерева

    int totalLevels = countNumberOfLevels(root, 0); //Вирахувана кількість рівнів
    cout << "Total number of tree levels:" << totalLevels << endl;
    //Кількість вершин на вибраному рівні дерева
    cout << "Number of nodes on level " <<n<<" :" << getNumberOfNodesOnLevel(root, n-1, 0) << endl;

    printTree(root, totalLevels);  //Виведення дерева
}