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


typedef struct s_btree
{
	struct s_btree* left;
	struct s_btree* right;
	void*           item;
} t_btree;



t_btree* btree_create_node(void* item)
{
	t_btree* new_node = (t_btree*)malloc(sizeof(t_btree));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->item = item;

	return new_node;
}


void btree_apply_prefix(t_btree* root, void (*applyf)(void*))
{
	if (root == NULL)
		return;

	applyf(root->item);

	if(root->left != NULL)
		btree_apply_prefix(root->left,applyf);

	if (root->right != NULL)
		btree_apply_prefix(root->right, applyf);


}



void btree_apply_infix(t_btree* root, void (*applyf)(void*))
{
	if (root == NULL)
		return;

	if(root->left != NULL)
		btree_apply_infix(root->left,applyf);


	applyf(root->item);


	if (root->right != NULL)
		btree_apply_infix(root->right, applyf);

}


void btree_apply_sufffix(t_btree* root, void (*applyf)(void*))
{
	if (root == NULL)
		return;

	if(root->left != NULL)
		btree_apply_sufffix(root->left,applyf);

	if (root->right != NULL)
		btree_apply_sufffix(root->right, applyf);

	applyf(root->item);

}



void btree_insert_data(t_btree** root,void* item, int (*cmpf)(void*, void*))
{
	if (root == NULL || *root == NULL)
		return;

	if ((*root)->item == NULL)
		(*root)->item = item;

	t_btree* curr_elem = *root;

	if(curr_elem->left != NULL && cmpf(curr_elem->item , item) == LeftBiggerRight)
		btree_insert_data(&(curr_elem->left), item, cmpf );


	if (curr_elem->right != NULL && cmpf(curr_elem->item , item) == LeftSmallerRight)
		btree_insert_data(&(curr_elem->right), item, cmpf );


	if (curr_elem->right == NULL && cmpf(curr_elem->item , item) == LeftSmallerRight)
		curr_elem->right = btree_create_node(item);


	if (curr_elem->left == NULL && cmpf(curr_elem->item , item) == LeftBiggerRight)
		curr_elem->left = btree_create_node(item);


}

int btree_level_count_recurtion(t_btree* root, int counter1, int counter2)
{
	if(root->left != NULL)
		counter1 = 1 + btree_level_count_recurtion(root->left,counter1,counter2);


	if (root->right != NULL)
		counter2 = 1 +  btree_level_count_recurtion(root->right,counter1,counter2);

	if (counter2 > counter1)
		return counter2;

	return counter1;
}



int btree_level_count(t_btree* root)
{
	if (root == NULL)
		return -1;

	return btree_level_count_recurtion(root,0, 0);
}




void* btree_search_item_recursion(t_btree* root, void* data_ref, int (*cmpf)(void*, void*), void* result)
{
	if(root->left != NULL && cmpf(root->left->item , data_ref) == LeftBiggerRight)
		btree_search_item_recursion(root->left,data_ref, cmpf, result);


	if(cmpf(root->item, data_ref) == Equal)
		result = root;


	if (root->right != NULL && cmpf(root->right->item , data_ref) == LeftSmallerRight)
		btree_search_item_recursion(root->right, data_ref, cmpf , result);


	return result;
}



void* btree_search_item(t_btree* root, void* data_ref, int (*cmpf)(void*, void*))
{
	if (root == NULL || data_ref == NULL)
		return NULL;

	void* result = NULL;

	return btree_search_item_recursion(root, data_ref, cmpf, result);
}


void btree_apply_by_level_recurtion(t_btree* root, void (*applyf) (void* item, int current_level, int is_first), int curr_level, int level_to_apply,bool** is_first_arr)
{
	if(root->left != NULL && curr_level < level_to_apply)
		btree_apply_by_level_recurtion(root->left,applyf, ++curr_level, level_to_apply,is_first_arr);

	if (curr_level == level_to_apply)
	{
		applyf(root->item, curr_level, *(is_first_arr)[level_to_apply]);
		*(is_first_arr)[level_to_apply] = False;
	}

	if (root->right != NULL && curr_level < level_to_apply)
		btree_apply_by_level_recurtion(root->right, applyf, ++curr_level, level_to_apply, is_first_arr);
}

void btree_apply_by_level(t_btree* root, void (*applyf) (void* item, int current_level, int is_first))
{
	if (root == NULL)
		return;

	int tree_height = btree_level_count(root);
	int i = 0;

	bool* is_first_arr = (bool*)malloc(sizeof(bool) * tree_height);


	while(i < tree_height)
	{
		is_first_arr[i] = True;
		btree_apply_by_level_recurtion(root,applyf,0,i,&is_first_arr);
		++i;
	}

	free(is_first_arr);
}





int main()
{
	/* code */
	return 0;
}
