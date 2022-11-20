#include <iostream>
#include "BinaryTree.h"

int main()
{
    BinaryTree tree;

    tree.AddLoop(9);
    //tree.AddLoop(16);
    //tree.AddLoop(1);
    //tree.AddLoop(5);
    ////tree.AddLoop(12);
    //tree.AddLoop(7);
    //tree.AddLoop(3);
    //tree.AddLoop(19);
    //tree.AddLoop(6);
    //tree.AddLoop(8);
    //tree.AddLoop(22);
    

    tree.List();
    std::cout << "\n";


    Node* node;
    if (node = tree.Find(9))
        std::cout << node->value << "\n";
    else
        std::cout << "not found\n";

    //std::cout << tree.Min(tree.Root())->value << "\n";

    tree.Delete(node);
    tree.List();

    std::cout << tree.Root()->value << "\n";
    std::cout << "\n";
}
