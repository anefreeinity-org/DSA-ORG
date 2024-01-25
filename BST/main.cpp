#include "bst.cpp"

int main()
{
    BST bst;

    bst.Insert(8);
    bst.Insert(3);
    bst.Insert(7);
    bst.Insert(4);
    bst.Insert(5);
    bst.Insert(2);
    bst.Insert(10);
    bst.Insert(9);

    bst.Preorder();

    bst.Delete(3);
    bst.Preorder();
}
