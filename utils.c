#include "push_swap.h"

t_stack *new_node(int data)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->data = data;
    node->next = NULL;
    return (node);
}
#include <stdio.h>
void ft_add_front(t_stack **head , t_stack *node)
{
     t_stack *tmp;
	
    tmp = *head;
	//printf("---------%i\n",node->data);

    if (head == NULL || !node)
        return;
    while (tmp->next->next != NULL)
	{
		//printf("ok\n");
        tmp = tmp->next;
	}
    tmp->next = NULL;
    node->next = *head;
    *head = node;
		//printf("data --1 =%i/ 2= %i /3 =%i \n", (*head)->data, (*head)->next->data,(*head)->next->next->data);

}

void ft_add_back(t_stack **head, t_stack *node)
{
    t_stack *tmp;

    tmp = *head;
   
    if (*head == NULL)
    {
        *head = node;
        node->next = NULL;
        return;
    }
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
	(*head) = 	(*head)->next;
	node->next = NULL;
    tmp->next = node;
}
void ft_swap(t_stack **head)
{
    t_stack *tmp;

	tmp = (*head)->next;
    (*head)->next = tmp->next;
    tmp->next = *head;
	*head = tmp;

}

void push(t_stack **head, t_stack *node)
{
	 if (head == NULL || !node)
        return;
	if (*head == NULL)
	{
		*head = node;
		node->next = 0;
		node->next1 = 0;
	}
	else
	{
		node->next = *head;
		node->next1 = *head;
		*head = node;
	}
}