#include<stddef.h>
#include<assert.h>
#include "bst.h"
#include<stdlib.h>
#include<stdio.h>
//#define DATA_TYPE Node*
#include "queue.h"

BST bst_new()
{
    BST tree={NULL , 0};
    return tree;
}

static TreeNode* _make_new_node(int32_t element)
{
    TreeNode *node=(TreeNode*)malloc(sizeof(TreeNode));
    node->data=element;
    node->left=NULL;
    node->right=NULL;
    return node;
}

uint32_t bst_count(BST *tree)
{
    assert(tree!=NULL);
    return tree->mass;
}

BST* bst_add_node(BST *tree,int32_t element)
{
    assert(tree!=NULL);
    TreeNode *cur, *parent;
    cur=parent=tree->root;
    while(cur!=NULL && cur->data!=element)
    {
        parent=cur;
        if(element < cur->data)
        {
            cur=cur->left;
        }
        else if(element > cur->data)
        {
            cur=cur->right;
        }

    }//added
    if(cur==NULL)
    {
        TreeNode *tnode=_make_new_node(element);
        if(parent==NULL)
        {
            tree->root=tnode;
        }
        else if(element < parent->data)
        {
            parent->left=tnode;
        }
        else if(element > parent->data)
        {
            parent->right=tnode;
        }
        ++tree->mass;
    }
    return tree;
}

static TreeNode* _findMin_(TreeNode *node)
{
    if(node->left==NULL)
    {
        return node;
    }
    else
        return(_findMin_(node->left));
}

static TreeNode* _delete_(BST *tree,TreeNode *node,int32_t key)
{
    TreeNode *temp;
    if(node==NULL)
    {
        return node;
    }
    else if(key < node->data)
    {
        node->left=_delete_(tree,node->left,key);
    }
    else if(key > node->data)
    {
        node->right=_delete_(tree,node->right,key);
    }
    else if(node->left && node->right)
    {
        temp=_findMin_(node->right);
        node->data=temp->data;
        node->right=_delete_(tree,node->right,node->data);
    }
    else{
        temp=node;
        if(node->right==NULL)
        {
            node=node->left;
        }
        else{
            node=node->right;
        }
        free(temp);
        --tree->mass;
    }
    return node;
}

BST* bst_delete(BST *tree,int32_t element)
{
    assert(tree!=NULL);
    tree->root=_delete_(tree,tree->root,element);
    return tree;
}

uint32_t bst_lookup(BST *tree,int32_t key)
{
    assert(tree!=NULL);
    TreeNode *cur=tree->root;
    while(cur!=NULL && cur->data!=key)
    {
        if(key<cur->data)
        {
            cur=cur->left;
        }
        else if(key>cur->data)
        {
            cur=cur->right;
        }
    }
    return(cur!=NULL);
}

static void _inorder_(TreeNode *node)
{
    if(node)
    {
        _inorder_(node->left);
        printf("%d\t",node->data);
        _inorder_(node->right);
    }
}

void bst_inorder(BST *tree)
{
    assert(tree->root!=NULL);
    _inorder_(tree->root);
}

static void _preorder_(TreeNode *node)
{
    if(node)
    {
        printf("%d\t",node->data);
        _preorder_(node->left);
        _preorder_(node->right);
    }
}

void bst_preorder(BST *tree)
{
	assert(tree!=NULL);
	_preorder_(tree->root);
}

static void _postorder_(TreeNode *node)
{
    if(node)
    {
        _postorder_(node->left);
        _postorder_(node->right);
        printf("%d\t",node->data);
    }
}

void bst_postorder(BST *tree)
{
	assert(tree!=NULL);
	_postorder_(tree->root);
	printf("\n");
}
/*
void tree_levelorder(BST *tree)
{
	assert(tree->root!=NULL);
	TreeNode *temp;
	Queue Tree_queue = queue_new(tree->count);
	Queue *queue = &Tree_queue;
	Queue_Result *res = (Queue_Result*) malloc(sizeof(Queue_Result));
	queue = queue_add(queue,tree->root,res);
	while(queue->count!=0)
	{
		queue_delete(queue,res);
		temp = res->data;

		// having issue accessing res->data
		if(temp->left!=NULL)
		{
			queue_add(queue,temp->left,res);
		}
		if(temp->right!=NULL)
		{
			queue_add(queue,temp->right,res);
		}
		printf("%d \t",temp->data);
	}
	printf("\n");
}
*/
static int32_t max_height(TreeNode *node)
{
    int32_t left_height=0;
    int32_t right_height = 0;
    //printf("%d \n",n->data);
    if(node == NULL)
    {
        return 0;
    }
    else
    {
        //printf("%d \n",left_height);
        if(node->left!=NULL)
        {
            left_height = max_height(node->left);
        }
        if(node->right!=NULL)
        {
            right_height = max_height(node->right);

        }
        if(left_height>right_height)
        {
            return left_height+1;
        }
        else
        {
            return right_height+1;
        }
    }
}


int32_t tree_height(BST *tree)
{
    assert(tree!=NULL);
    int32_t max = max_height(tree->root);
    return max;
}

static int32_t _terminals_(TreeNode *node)
{
	int32_t count1 = 0;
	int32_t count2 = 0;

	if(node==NULL)
    {
        return 0;
    }
	if (node->left==NULL && node->right==NULL)
	{
		return 1;
	}
	else
    {
	    if(node->left!=NULL)
	    {
	        count1 = _terminals_(node->left);
	    }
	    if(node->right!=NULL)
	    {
            count2 = _terminals_(node->right);
	    }
	    return count1+count2;
    }
}

int32_t terminal_nodes(BST *tree)
{
	assert(tree!=NULL);
	int32_t count=0;
	count = _terminals_(tree->root);
	return count;
}

int32_t find_min(BST *tree)
{
    assert(tree!=NULL);
    TreeNode *temp=tree->root;
    while(temp->left!=NULL)
    {
        temp= temp->left;
    }
    return(temp->data);
}

int32_t find_max(BST *tree)
{
    assert(tree!=NULL);
    TreeNode *temp=tree->root;
    while(temp->right!=NULL)
    {
        temp = temp->right;
    }
return(temp->data);
}

static void _ascending_(TreeNode *node)
{
    if(node)
    {
        _ascending_(node->left);
        printf("%d\t",node->data);
        _ascending_(node->right);
    }
}

void tree_ascending(BST *tree)
{
	assert(tree!=NULL);
	_ascending_(tree->root);
}

static void _descending_(TreeNode *node)
{
    if(node)
    {
         _descending_(node->right);
         printf("%d\t",node->data);
         _descending_(node->left);
    }
}

void tree_descending(BST *tree)
{
	assert(tree!=NULL);
	_descending_(tree->root);
}
