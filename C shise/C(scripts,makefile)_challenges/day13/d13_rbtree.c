#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef enum t_bool
{
	True = 1,
	False = 0,
} bool;

#define LeftBiggerRight 1
#define Equal 0
#define LeftSmallerRight -1

enum e_rb_color
{
	RB_BLACK,
	RB_RED,
};

typedef struct s_rb_node
{
	struct s_rb_node* parent;
	struct s_rb_node* left;
	struct s_rb_node* right;
	void* data;
	enum e_rb_color color;

} t_rb_node;



// recursive action of finding the level of the node in the tree
int rbtree_black_level_count_recurtion(struct s_rb_node* root, int counter1, int counter2)
{
	if(root->left != NULL)
	{
		if (root->left->color == RB_BLACK)
			counter1 = 1 + rbtree_black_level_count_recurtion(root->left,counter1,counter2);

		else
			counter1 = rbtree_black_level_count_recurtion(root->left,counter1,counter2);
	}

	if (root->right != NULL)
	{
		if (root->right->color == RB_BLACK)
			counter2 = 1 +  rbtree_black_level_count_recurtion(root->right,counter1,counter2);

		else
			counter2 = rbtree_black_level_count_recurtion(root->right,counter1,counter2);
	}

	if (counter2 > counter1)
		return counter2;

	return counter1;
}


//finding the left subtrees black hight
int rbtree_black_level_count_left_subtree(struct s_rb_node* root)
{
	if (root == NULL || root->left == NULL)
		return -1;

	return rbtree_black_level_count_recurtion(root->left,0, 0);
}


//finding the right subtree black hight
int rbtree_black_level_count_right_subtree(struct s_rb_node* root)
{
	if (root == NULL || root->right == NULL)
		return -1;

	return rbtree_black_level_count_recurtion(root->right,0, 0);
}


//Left rotation of the node, his parent and his grandparent
void rbtree_LR(struct s_rb_node** inserted_node)
{
	struct s_rb_node** GrandParent = &(*inserted_node)->parent->parent;
	struct s_rb_node** Parent = &(*inserted_node)->parent;

	(*GrandParent)->right = (*Parent)->left;
	(*Parent)->parent = (*GrandParent)->parent;
	(*GrandParent)->parent = (*Parent);
	(*Parent)->left = (*GrandParent);
}

//right rotation of the node, his parent and his grandparent
void rbtree_RR(struct s_rb_node** inserted_node)
{
	struct s_rb_node** GrandParent = &(*inserted_node)->parent->parent;
	struct s_rb_node** Parent = &(*inserted_node)->parent;

	(*GrandParent)->left = (*Parent)->right;
	(*Parent)->parent = (*GrandParent)->parent;
	(*GrandParent)->parent = (*Parent);
	(*Parent)->right = (*GrandParent);
}

void rbtree_color_fix(struct s_rb_node** inserted_node,int (*cmpf)(void*, void*))
{
	bool is_parent_red = (*inserted_node)->parent->color == RB_RED;
	bool is_parent_right_child = cmpf((*inserted_node)->parent->parent->data,(*inserted_node)->parent->data)                == LeftSmallerRight;
	bool is_right_uncle_red    = cmpf((*inserted_node)->parent->parent->data,(*inserted_node)->parent->parent->right->data) == LeftSmallerRight;
	bool is_left_uncle_red     = cmpf((*inserted_node)->parent->parent->data,(*inserted_node)->parent->parent->left->data)  == LeftSmallerRight;
	bool is_grandparent_root   = (*inserted_node)->parent->parent->parent == NULL;

	if (is_parent_right_child && is_left_uncle_red && is_parent_red && !is_grandparent_root)
	{
		(*inserted_node)->parent->color         = RB_BLACK;
		(*inserted_node)->parent->parent->color = RB_RED;

		if (is_left_uncle_red)
			(*inserted_node)->parent->parent->left->color = RB_BLACK;
	}

	if (!is_parent_right_child && is_right_uncle_red && is_parent_red && !is_grandparent_root)
	{
		(*inserted_node)->parent->parent->color       = RB_RED;
		(*inserted_node)->parent->color               = RB_BLACK;

		if (is_right_uncle_red)
			(*inserted_node)->parent->parent->left->color = RB_BLACK;
	}

	if (!is_grandparent_root)
		rbtree_color_fix(&(*inserted_node)->parent->parent,cmpf);

}



//fixing the rbtree according to the rules after bst node insertion
void rb_insert_tree_fixing(struct s_rb_node** root,int (*cmpf)(void*, void*),struct s_rb_node** inserted_node)
{
	
	bool is_parent_red = (*inserted_node)->parent->color == RB_RED;
	bool is_node_right_child   = cmpf((*inserted_node)->parent->data,(*inserted_node)->data)                                == LeftSmallerRight;
	bool is_parent_right_child = cmpf((*inserted_node)->parent->parent->data,(*inserted_node)->parent->data)                == LeftSmallerRight;
	bool is_right_uncle_red    = cmpf((*inserted_node)->parent->parent->data,(*inserted_node)->parent->parent->right->data) == LeftSmallerRight;
	bool is_left_uncle_red     = cmpf((*inserted_node)->parent->parent->data,(*inserted_node)->parent->parent->left->data)  == LeftSmallerRight;

	if(is_parent_red)
	{
		if (is_node_right_child && is_parent_right_child)
		{
			if (!is_left_uncle_red)
				rbtree_LR(inserted_node);
			
			rbtree_color_fix(inserted_node,cmpf);
		}

		if (!is_node_right_child && !is_parent_right_child)
		{
			if (!is_right_uncle_red)
				rbtree_RR(inserted_node);
			
			rbtree_color_fix(inserted_node,cmpf);
		}

		if (is_node_right_child && !is_parent_right_child)
		{
			if (!is_right_uncle_red)
			{
				rbtree_LR(&(*inserted_node)->right);
				rbtree_RR(inserted_node);
			}

			rbtree_color_fix(inserted_node,cmpf);
		}

		if (!is_node_right_child && is_parent_right_child)
		{
			if (!is_left_uncle_red)
			{
				rbtree_RR(&(*inserted_node)->left);
				rbtree_LR(inserted_node);
			}

			rbtree_color_fix(inserted_node,cmpf);
		}

	}

}

//creates a new node
struct s_rb_node* rbtree_create_node(void* data, struct s_rb_node* parent)
{
	struct s_rb_node* new_node = (struct s_rb_node*)malloc(sizeof(struct s_rb_node));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->data = data;
	new_node->parent = parent;
	new_node->color = RB_RED;

	return new_node;
}




void rb_insert(struct s_rb_node** root, void* data, int (*cmpf)(void*, void*))
{
	if (root == NULL)
		return;

	if ((*root)->data == NULL)
	{
		(*root)->data = data;
		(*root)->color = RB_BLACK;
		return;
	}

	if (*root == NULL)
	{
		*root = rbtree_create_node(data, NULL);
		(*root)->color = RB_BLACK;
		return;
	}

	struct s_rb_node* curr_elem = *root;
	struct s_rb_node* new_elem = NULL;

	if(curr_elem->left != NULL && cmpf(curr_elem->data , data) == LeftBiggerRight)
		rb_insert(&(curr_elem->left), data, cmpf );

	if (curr_elem->right != NULL && cmpf(curr_elem->data , data) == LeftSmallerRight)
		rb_insert(&(curr_elem->right), data, cmpf );

	if (curr_elem->right == NULL && cmpf(curr_elem->data , data) == LeftSmallerRight){
		new_elem = rbtree_create_node(data,curr_elem);
		curr_elem->right = new_elem;
	}

	if (curr_elem->left == NULL && cmpf(curr_elem->data , data) == LeftBiggerRight){
		new_elem = rbtree_create_node(data,curr_elem);
		curr_elem->left = new_elem;
	}

	rb_insert_tree_fixing(root, cmpf, &new_elem);
}



int main()
{
	/* code */
	return 0;
}

