#include "push_swap.h"

t_stack *merge(t_stack *frist, t_stack *seconde)
{
    t_stack *res = NULL;
    t_stack **current = &res;
    while (frist && seconde)
    {
        if (frist->data > seconde->data)
        {
            *current= seconde;
            seconde = seconde->next1;
        }
        else
        {
            *current= frist;
             frist = frist->next1;
        }
         current = &((*current)->next1);
    }  
    if (seconde)
        *current = seconde;
    else
        *current = frist;
        
    return (res);
}

t_stack *search_midel (t_stack *head)
{
    t_stack *slow = head;
    t_stack *fast = head;
    t_stack *prev_slow = NULL;
    
    while (fast != NULL && fast->next1 != NULL)
    {
        prev_slow = slow;
        slow = slow->next1;
        fast = fast->next1->next1;
    }
    
    if (prev_slow != NULL)
        prev_slow->next1 = NULL; // Break the stack into two halves
    
    return slow;
}

t_stack *merge_sort(t_stack *head)
{
    t_stack *frist_p;
    t_stack *seconde_p;
    
    
    
    if (!head  || !head->next1)
    {
        return(head);
    }
    seconde_p =search_midel(head);
    frist_p = head;
    
    frist_p = merge_sort(frist_p);
    seconde_p = merge_sort(seconde_p);
    return(merge(frist_p, seconde_p));
   
}
// void add_back_m(t_stack **head , int data)
// {
//    t_stack *new_node  = malloc(sizeof(t_stack));
//    t_stack *tmp = *head;
//    t_stack *tmp2 = *head;
    
//     new_node->data = data;
//      new_node->next = NULL;
//          new_node->next1 = NULL;
//     if (tmp == NULL)
//     {
//         *head = new_node;
//     }
//     else
//     {
//     while (tmp->next)
//     {
//         tmp = tmp->next;
//         tmp2 = tmp2->next1;
//     }
//     tmp->next = new_node;
//     tmp2->next1 = new_node;
//     }
// }