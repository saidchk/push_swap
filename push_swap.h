# ifndef PUSH_SWAP_H
#define push_swap_H

#include <stdlib.h>
typedef struct push
{
    int				data;
	int				index;
	int				check;
	int				num_moves;
    struct push		*next;
	struct push		*next1;
}					t_stack;

void push(t_stack **head, t_stack *node);
t_stack *new_node(int data);
void ft_add_back(t_stack **head, t_stack *node);
void push(t_stack **head, t_stack *node);
void ft_add_front(t_stack **head , t_stack *node);
t_stack *merge_sort(t_stack *head);

#endif