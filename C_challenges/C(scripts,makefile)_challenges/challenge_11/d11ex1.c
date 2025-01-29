#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_list.h"

#define True 1
#define False 0


void ft_list_push_back(t_list** begin_list, void* data)
{
	if (begin_list == NULL || *begin_list == NULL || data == NULL)
	{
		return;
	}

	t_list* current_elem = *begin_list;

	while(current_elem->next != NULL)
	{
		current_elem = current_elem->next;
	}

	current_elem->next = ft_create_elem(data);
}


void ft_list_push_front(t_list** begin_list, void* data)
{
	if (begin_list == NULL || *begin_list == NULL || data == NULL)
	{
		return;
	}

	t_list* new_first_elem = ft_create_elem(data);
	t_list* current_elem = *begin_list;

	new_first_elem->next = current_elem;
	*begin_list = new_first_elem;
}

t_list* ft_create_elem(void* data)
{	
	t_list* elem = (t_list*)malloc(sizeof(t_list));

	if (elem == NULL || data == NULL)
	{
		return (NULL);
	}
	
	elem->data = data;
	elem->next = NULL;
	
	return (elem);
}

void print_list(t_list* list)
{
	if (list == NULL)
	{
		return;
	}

	t_list* current_elem = list;
 
	while(current_elem->next != NULL)
	{
		char* ptr_data = current_elem->data;

		printf("%s", ptr_data);
		current_elem = current_elem->next;
	}

	printf("%s", (char*)current_elem->data);
}

int ft_list_size(t_list* begin_list)
{
	if (begin_list == NULL)
	{
		return -1;
	}

	int result = 0;
	t_list* current_elem = begin_list;

	while(current_elem -> next != NULL)
	{
		++result;
		current_elem = current_elem -> next;
	}

	++result;

	return result;
}

t_list* ft_list_last(t_list* begin_list)
{
	if (begin_list == NULL)
		return NULL;

	t_list* current_elem = begin_list;

	while(current_elem -> next != NULL)
		current_elem = current_elem -> next;

	return current_elem;
}

t_list* ft_list_push_params(int ac, char** av)
{
	if (*av == NULL)
		return NULL;

	int i = ac - 1;
	t_list* result = ft_create_elem(av[i]);
	t_list* current_elem = ft_create_elem(av[i - 1]);

	result -> next = current_elem;
	i = i - 2;

	while(i > 0)
	{
		current_elem -> next = ft_create_elem(av[i]);
		current_elem = current_elem -> next;
		--i;
	}

	return result;
}

void ft_list_clear(t_list** begin_list)
{

	if (begin_list == NULL || *begin_list == NULL)
		return;

	int list_size = ft_list_size(*begin_list);
	t_list* curr_elem = *begin_list;

	while(list_size > 0)
	{
		t_list* temp = curr_elem -> next;
		free(curr_elem);
		curr_elem = temp;
		--list_size;
	}

}


t_list* ft_list_at(t_list* begin_list, unsigned int num)
{
	if (begin_list == NULL || (int)num >= ft_list_size(begin_list))
		return NULL;

	int i = 0;
	t_list* current_elem = begin_list;

	while(i < (int)num)
	{
		current_elem = current_elem -> next;
		++i;
	}

	return current_elem;
}



void ft_list_reverse(t_list** begin_list)
{	
	if (begin_list == NULL || *begin_list == NULL)
		return;

	int i = 0;
	int j = ft_list_size(*begin_list);

	while(j > i)
	{
		t_list* ith_elem = ft_list_at(*begin_list,(unsigned int)i);
		t_list* jth_elem = ft_list_at(*begin_list,(unsigned int)j);

		void* temp = ith_elem -> data;
		ith_elem -> data = jth_elem -> data;
		jth_elem -> data = temp;

		++i;
		--j;
	}
}


void ft_list_foreach(t_list* begin_list, void (*f)(void*))
{
	if (begin_list == NULL)
		return;

	t_list* current_elem = begin_list;

	while(current_elem -> next != NULL)
	{
		f(current_elem -> data);
		current_elem = current_elem -> next;
	}
}

void ft_list_foreach_if(t_list* begin_list, void (*f)(void*),void* data_ref, int (*cmp)())
{
	if (begin_list == NULL || data_ref == NULL)
		return;

	t_list* current_elem = begin_list;

	while(current_elem -> next != NULL)
	{
		if (cmp(current_elem -> data, data_ref))
			f(current_elem -> data);

		current_elem = current_elem -> next;
	}
}

t_list* ft_list_find(t_list* begin_list, void* data_ref, int (*cmp)())
{
	if (begin_list == NULL || data_ref == NULL)
		return NULL;

	t_list* current_elem = begin_list;

	while(current_elem -> next != NULL)
	{
		if (cmp(current_elem -> data, data_ref))
			return current_elem;

		current_elem = current_elem -> next;
	}

	return NULL;
}



void ft_list_remove_if(t_list* begin_list, void* data_ref, int (*cmp)())
{
	if (begin_list == NULL || data_ref == NULL)
		return;

	t_list* current_elem = begin_list;
	t_list* next_elem = begin_list -> next;

	while(next_elem -> next != NULL)
	{
		if (cmp(next_elem-> data, data_ref))
		{
			t_list* temp = next_elem -> next;
			
			free(next_elem);
			current_elem -> next = temp;
		}

		current_elem = current_elem -> next;
		next_elem = current_elem -> next;
	}
	return;
}


void ft_list_merge(t_list** begin_list1, t_list* begin_list2)
{
	if (begin_list2 == NULL || begin_list1 == NULL || *begin_list1 == NULL)
		return;

	t_list* current_elem = *begin_list1;

	while(current_elem -> next != NULL)
		current_elem = current_elem -> next;

	current_elem -> next = begin_list2;
}

void ft_list_sort(t_list** begin_list, int (*cmp)())
{
	t_list* current_i_elem;
	t_list* current_j_elem;
	int list_size = ft_list_size(*begin_list);
	int i = 0;
	int j = 0;

	while(i < list_size)
	{
		current_i_elem = ft_list_at(*begin_list, (unsigned int) i);

		while(j < list_size)
		{
			current_j_elem = ft_list_at(*begin_list, (unsigned int) j);

			if (cmp(current_i_elem -> data, current_j_elem -> data) > 0)
			{
				void* data = current_i_elem -> data;
				current_i_elem -> data = current_j_elem -> data;
				current_j_elem -> data = data;
			}

			++j;
		}

		++i;
		j = i + 1;
	}
}


void ft_sorted_list_insert(t_list** begin_list, void* data, int (*cmp)())
{
	if (data == NULL || begin_list == NULL || *begin_list == NULL)
		return;

	t_list* current_elem = *begin_list;
	int was_inserted = False;

	while(current_elem -> next != NULL && !was_inserted)
	{
		if (cmp(current_elem -> data, data) < 0 && cmp(current_elem -> next -> data, data) > 0)
		{
			t_list* temp = current_elem -> next;
			current_elem -> next = ft_create_elem(data);
			current_elem -> next -> next = temp;
			was_inserted = True;
		}
	}

	if (!was_inserted)
		current_elem -> next = ft_create_elem(data);

}


void ft_sorted_list_merge(t_list** begin_list1, t_list* begin_list2, int (*cmp)())
{
	if (begin_list2 == NULL || begin_list1 == NULL || *begin_list1 == NULL)
		return;

	t_list* current_elem_list1 = *begin_list1;
	t_list* current_elem_list2 = begin_list2;
	int was_inserted = False;
	int bigger_than_list_1 = False;

	while(current_elem_list2 -> next != NULL && !bigger_than_list_1)
	{
		while(current_elem_list1 -> next != NULL && !was_inserted)
		{
			if (cmp(current_elem_list1 -> data, current_elem_list2 -> data) < 0 && cmp(current_elem_list1 -> next -> data, current_elem_list2 -> data) > 0)
			{
				t_list* temp = current_elem_list1 -> next;
				current_elem_list2 -> next = current_elem_list1;
				current_elem_list1 -> next -> next = temp;
				was_inserted = True;
			}
		}

		if (!was_inserted)
		{
			current_elem_list1 -> next = current_elem_list2;
			bigger_than_list_1 = True;
		}

		current_elem_list1 = *begin_list1;
		was_inserted = False;
	}
}



int main(int argc, char** argv)
{	

	t_list* lst = ft_list_push_params(argc, argv);
	// print_list(lst);
	printf("%s",(char*)(ft_list_at(lst,2)->data));
	return 0;
}


