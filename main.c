#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include<assert.h>
/*
void test_empty_bst()
{
    BST tree = bst_new();
    BST *TreeNode=&tree;
    //TreeNode=bst_add_node(TreeNode,30);
    assert(bst_count(TreeNode)==1);

}

void test_add_node()
{
    BST tree = bst_new();
    BST *TreeNode=&tree;
    TreeNode=bst_add_node(TreeNode,50);
    assert(bst_count(TreeNode)==1);
}
*/
int main()
{
    //test_empty_bst();
    //test_add_node();
    BST t = bst_new();
    BST *tree=&t;
    // add, delete, count and search
    tree=bst_add_node(tree,50);
    tree=bst_add_node(tree,60);
    tree=bst_add_node(tree,20);
    tree=bst_add_node(tree,35);
    tree=bst_add_node(tree,30);
    tree=bst_add_node(tree,55);

    assert(bst_lookup(tree,30)==1);

    assert(bst_count(tree)==6);

    tree = bst_delete(tree,35);
    assert(bst_count(tree) == 5);
    tree = bst_delete(tree,35);

    //inorder, preorder,postorder and level order
    bst_inorder(tree);
    bst_preorder(tree);
    bst_postorder(tree);
   // tree_levelorder(tree);

    //height of the tree
    assert(tree_height(tree)==4);

    //terminal nodes
    assert(terminal_nodes(tree)==2);
    tree = bst_add_node(tree,25);
    assert(terminal_nodes(tree)==3);

    //minimum and maximum
    assert(find_min(tree)==20);
    assert(find_max(tree)==60);

    //ascending order
    printf("\n Ascending Order: ");
    tree_ascending(tree);

    //descending order
    printf("\n Descending Order: ");
    tree_descending(tree);

    return 0;
}
