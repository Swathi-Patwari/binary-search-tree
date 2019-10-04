#ifndef _INCLUDED_BST_
#define _INCLUDED_BST_
#include<stdint.h>

typedef struct _tree_node_ TreeNode;
typedef struct _bst_ BST;

struct _tree_node_
{
    int32_t data;
    TreeNode *left;
    TreeNode *right;
};

struct _bst_
{
    TreeNode *root;
    int32_t mass;
};

BST bst_new();
uint32_t bst_count(BST *tree);
BST* bst_add_node(BST *tree, int32_t element);
BST* bst_delete_node(BST *tree, int32_t element);
uint32_t bst_lookup(BST *tree, int32_t key);
void bst_inorder(BST *tree);
void bst_preorder(BST *tree);
void bst_postorder(BST *tree);
//void tree_levelorder(BST *tree)
int32_t tree_height(BST *tree);
int32_t terminal_nodes(BST *tree);
int32_t find_min(BST *tree);
int32_t find_max(BST *tree);
void tree_ascending(BST *tree);
void tree_descending(BST *tree);

#endif // _INCLUDED_BST
