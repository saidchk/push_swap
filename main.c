#include "./push_swap.h"
#include <stdio.h>

 int count;
int ft_atoi(char *num)
{
    int i;
    int sig;
    int res;
//printf("%s\n", num);
    i = 0;
    res = 0;
    sig = (-1) * (num[0] == '-') + (num[0] != '-');
    if (num[0] == '+' || num[0] == '-')
        i++;
    while (num[i] >= '0' && num[i] <= '9')
    {
        res *= 10;
        res += (num[i++]- 48);
    }
//	printf("num == %i\n", res * sig);
    return (res * sig);
}
int search_min(t_stack *head/*, int *current_index*/)
{
	int min;

	min = head->data;
	//int i =1
	int i = 0;
	//*current_index = 1;
	int index = 0;
	while (head != NULL)
	{	
	if (head->data < min)
	{
		min = head->data;
		//*current_index = i;
		index  = i;
	}
	//printf("%i\n", i);
	//printf (". == \n");
	head = head->next;
	i++;
	}
	return(index);
}
void ra(t_stack **stack_a , int index)
{
	while (index != 1)
	{
		count++;
		printf("ra\n");
		ft_add_back(stack_a, *stack_a);
		index--;
	}
	
}

t_stack *last_node(t_stack *stack_a)
{

	// printf("ok\n");
	// printf("add == %p\n",stack_a);
	while (stack_a && stack_a->next != NULL)
	{
		//printf("emmm\n");
		stack_a = stack_a->next;
	}
		//printf("2-ok\n");

	return (stack_a);
}
void rra(t_stack **stack_a, int index, int size)
{
	while (index <= size)
	{
		count++;
				printf("rra\n");
				ft_add_front(stack_a, last_node(*stack_a));
		index++;
	}
}
// 1void sort_stack(t_stack **stack_a, int size)
// {
// 	t_stack		*stack_b;
// 	t_stack		*tmp;
// 	int			current_size;
// 	int 		min;
// 	int			current_index;

// 	current_size = size;
// 	stack_b = NULL;
// 	tmp = *stack_a;
// 	 while (current_size != 3)
// 	 {
// 		//min = search_min(*stack_a, &current_index);
// 		// if (current_index == 1)
//         //     tmp = *stack_a;
// 		if (current_index <= (size / 2))
// 		{
// 			ra(stack_a , current_index);
// 			tmp = *stack_a;
// 		}
//         else
//         {
//             rra(stack_a , current_index , current_size);
//              tmp = *stack_a;
//         }
//         *stack_a = (*stack_a)->next;
//          push(&stack_b , tmp);
// 		 		printf("pb\n");
// 				count++;
// 		current_size--;
// 	 }
// 	 while (current_size != size)
//      {
//        tmp = stack_b;
//         stack_b = stack_b->next;
//         push(stack_a, tmp);
// 				 		printf("pa\n");
// 		count++;
//         current_size++;
//      }
// }
#include<unistd.h>
typedef struct 
{
	int moves;
	int	moves_a;
	int	moves_a_v;
	int	position_in_b;
	int position_in_a;
	int	posi;
	int	moves_op;
	int	moves_back;
}scaner;

void count_moves(t_stack **stack_a, t_stack **stack_b, int size)
{
	int i;
	int number_moves;
	static int size_a;
	t_stack	*tmp;
	t_stack	*tmpb;
	scaner	counter;
	int		move_b;
	if (*stack_a == NULL)
		return;
	t_stack *last = last_node(*stack_a);

	i = 0;
	counter.moves = 1000;
	size_a++;
	printf("yessssssss size %i\n", size);
	printf ("\n-------------stack_a-----------\n");
	tmp = *stack_a;
	while (tmp != NULL)
	{
		printf("stacka== %i\n", tmp->data);
		tmp = tmp->next;
	}
		printf ("\n-------------stack_b-----------\n");

	tmp = *stack_b;
	while (tmp != NULL)
	{
		printf("stackb== %i\n", tmp->data);
		tmp = tmp->next;
	}
	//sleep(5);
	tmpb = *stack_b;
	while (tmpb)
	{
		tmp = *stack_a;
		number_moves = 0;
		counter.moves_a = 0;
		counter.posi = 0;
		 if (i < (size / 2))
				move_b = i;
		else
			move_b = size - i ;
		while ((i < 100 ) && tmp)
		{
		
			number_moves++;
			if (tmp->index < tmpb->index && tmp->next != NULL && tmp->next->index > tmpb->index)
			{
			//	printf ("stacka == %i , next_a ==  %i, stack_B == %i\n", tmp->data, tmp->next->data, tmpb->data);
				if (number_moves <= (size_a / 2))
					counter.moves_a = number_moves;
				else
					counter.moves_a = size_a - number_moves ;
				counter.posi = number_moves;
				// if (tmpb->data == 0)
				// 	printf("-%i === movea- , move_b = %i\n", counter.moves_a, move_b);
			}
			tmp = tmp->next;
		}
		//printf("num ============================= %i\n",tmpb->data);
		if (i < 100 && counter.moves_a == 0 && last->index > tmpb->index)
		{
			counter.moves_a = search_min(*stack_a);
			counter.posi = counter.moves_a;
			if (counter.moves_a >  (size_a / 2))
				counter.moves_a = size_a - counter.moves_a ;
			printf("up ======== %i\n",counter.moves_a);
		}
		//number_moves ;  /*+  (size - i + 1)* (i >= (size - 15))*/;
		counter.moves_a += move_b;
		if (tmpb->data == 6)
			printf("-%i === movea22 , move_b = %i\n", counter.moves_a, move_b);
		//if (i>15)
		//	printf("num ===%i ,   moves ==%i\n", i, number_moves);
	//	sleep(2);
		if (i < 100 && counter.moves_a < counter.moves)
		{
		//	printf("data == %i,up ======== %i\n",tmpb->data,counter.moves_a);
			counter.position_in_b = i + 1;
			counter.position_in_a = counter.posi;
			counter.moves = counter.moves_a;
			counter.moves_a_v = counter.moves_a - move_b;
			// if (tmpb->data == 26)
			// 	printf("//// -------moves == %i----------///\n", counter.moves_a_v );
		}
		tmpb = tmpb->next;
		i++;
	}
	//sleep(2);
	printf("position_number == %i, moves == %i, position_in_a == %i     a_v  == %i\n",counter.position_in_b, counter.moves, counter.position_in_a , counter.moves_a_v);
	////[[0printf("2---,up ======== %i\n",counter.moves_a);

	if (counter.position_in_a >= (counter.position_in_b - 1))
		counter.moves_op = counter.position_in_b- counter.position_in_a;
	// else
	// 	counter.moves_op = counter.position_in_b- counter.position_in_a;
	//counter.moves_back = size - counter.position_in_b + 1;
	// if (counter.moves_back >= counter.moves_a_v)
	// 	counter.moves_back = counter.moves_back - counter.position_in_a;
	// else
	// 	counter.moves_back = counter.moves_a_v - counter.moves_back ; 
	if ((counter.position_in_a <= (size_a / 2) &&  counter.position_in_b <= (size / 2)) /*|| (counter.position_in_b - 1 >= size_a)|| (counter.moves_op <= counter.moves_a_v)*/)
	{
		printf("-----frist-----\n");
		//  if (counter.moves_op <= counter.moves_a_v)
		// 			printf("///////////////////////////////nessssssssssss\n/////////// //////////////////////////////");

		while (counter.moves > 0)
		{
			if (counter.position_in_b != 1 && counter.moves_a_v != 0)
			{
				ft_add_back(stack_a, *stack_a);
				ft_add_back(stack_b, *stack_b);
				counter.moves--;
				counter.position_in_b--;
				counter.moves_a_v--;
			}
			else if (counter.position_in_b != 1)
			{
				ft_add_back(stack_b, *stack_b);
				counter.position_in_b--;
			}
			else
				ft_add_back(stack_a, *stack_a);
			counter.moves--;
			count++;
		}
	}
	else if ((counter.position_in_a > (size_a / 2) &&  counter.position_in_b > (size / 2)) /*|| (counter.moves_back <= counter.moves_a_v)*/)
	{
				printf("-----seconde-----\n");
			// if ((counter.moves_back <= counter.moves_a_v))
			// 	printf("///////////////////////////////yessssssssssss\n/////////////////////////////////////////");
			counter.position_in_b = counter.moves - counter.moves_a_v  + 1 ;
			//counter.moves_a_v =  size_a - counter.moves_a_v;
		while (counter.moves > 0)
		{
			if (counter.position_in_b != 1 && counter.moves_a_v != 0)
			{
				ft_add_front(stack_a, last_node(*stack_a));
				ft_add_front(stack_b, last_node(*stack_b));
				counter.moves--;
				counter.position_in_b--;
				counter.moves_a_v--;
			}
			else if (counter.position_in_b != 1)
			{
				counter.position_in_b--;
				ft_add_front(stack_b, last_node(*stack_b));
			}
			else
				ft_add_front(stack_a,last_node(*stack_a));
			counter.moves--;
			count++;
		}
	}
	else
	{
				//printf("-----thr-----\n");

		counter.posi = counter.moves - counter.moves_a_v;
		if (counter.position_in_a <= ((size_a) / 2))
		{
			while (counter.moves_a_v != 0)
			{
				ft_add_back(stack_a, *stack_a);
				counter.moves_a_v--;
				count++;
			}
		}
		else
		{
			printf("HAN\n");
			//counter.moves_a_v =  size_a - counter.moves_a_v ;
			while (counter.moves_a_v != 0)
			{
				ft_add_front(stack_a, last_node(*stack_a));
				counter.moves_a_v--;
				count++;
			}
		}

		if (counter.position_in_b <= (size / 2))
		{
			while (counter.position_in_b != 1)
			{
				ft_add_back(stack_b, *stack_b);
				counter.position_in_b--;
				count++;
			}
		}
		else
		{
						printf("Her\n");
			sleep(3);
			counter.position_in_b = counter.posi ;
			printf("res === %i\n",counter.position_in_b);
			while (counter.position_in_b != 0)
			{
				ft_add_front(stack_b, last_node(*stack_b));
				counter.position_in_b--;;
				count++;
			}
		}
			
	}
	/*if (counter.moves_a_v != 0 && (counter.position_in_b <= (size / 2) || counter.moves_a <= (size_a/2)))
	{
		printf("up\n");
		while (counter.moves > 0)
		{
			if (counter.position_in_b != 1 && counter.moves_a_v != 0)
			{
				ft_add_back(stack_a, *stack_a);
				ft_add_back(stack_b, *stack_b);
				counter.moves--;
				counter.position_in_b--;
			}
			else if (counter.position_in_b != 1)
				ft_add_back(stack_b, *stack_b);
			else
				ft_add_back(stack_a, *stack_a);
			counter.moves--;
			count++;
		}
	}
	else if (counter.moves != 0)
	{
		printf ("-----------size == %i, movea == %i\n",size, counter.moves_a);
		if (counter.moves_a <= counter.position_in_b)
			counter.moves =  size - counter.moves;
		else
			counter.moves =  size_a - counter.moves;
		while (counter.moves > 0)
		{
			if (counter.position_in_b != 1 && counter.moves_a_v != 0)
			{
				ft_add_front(stack_a, last_node(*stack_a));
				ft_add_front(stack_b, last_node(*stack_b));
				counter.moves--;
				counter.position_in_b--;
			}
			else if (counter.position_in_b != 1)
				ft_add_front(stack_b, last_node(*stack_b));
			else
				ft_add_front(stack_a,last_node(*stack_a));
			counter.moves--;
			count++;
		}
	}*/
}
void sort_stack(t_stack **stack_a, int size)
{
	int		current_size;
	t_stack *stack_b;
	t_stack *last;
	t_stack *tmp;
	int		range;
	int		part;
	int check = 0;

	part = 42;
	range = 42;
	current_size = size;
	stack_b = NULL;
	tmp = *stack_a;
	while (current_size != 1)
	{
		check = 0;
		last = last_node(*stack_a);
		//printf("last == %i\n",(*stack_a)->index);
		if (part == 0 && (range += 42) <= size)
			part = 42;
		else if (part == 0)
			part = size - (range - 42); 
		if ((*stack_a)->index <= last->index && (*stack_a)->index <= range)
		{
			//printf("so\n");
			tmp = *stack_a;
			//count++;
		}
		else if (last->index <= range)
		{
			//printf("front\n");
			ft_add_front(stack_a, last);
			tmp = last;
			count++;

		}
		else
		{
			tmp =NULL;
			//printf("back\n");
			ft_add_back(stack_a , *stack_a);
			count++;
		}
		if (tmp != NULL || tmp == last)
		{
			//printf("emm\n");
			*stack_a = (*stack_a)->next;
			push(&stack_b, tmp);
			part--;
			current_size--;
			count++;
		}
			//printf("cursize------%i\n", current_size);;

	}
	tmp = stack_b;
	// while (tmp != NULL)
	// {
	// 	printf("stackb--%i\n", tmp->data);
	// 	tmp = tmp->next;
	// }
	//printf (" --------moves---%i-----\n",count);
	while (stack_b != NULL)
	{
			//printf("good\n");

		//printf("after--%i\n", stack_b->data);
		// if (--size == 25)
		// 	break;
		//printf("stackb ====== %p\n", stack_b);
		count_moves(stack_a, &stack_b, --size);
		tmp = stack_b;
		//printf("befor--%i\n", stack_b->data);
		stack_b = stack_b->next;
		push(stack_a, tmp);
		// if (tmp->data == 29)
		// {
		// tmp = *stack_a;
		// while (tmp != NULL)
		// {
		// 	printf("-----stacka ==%i\n", tmp->data);
		// 	tmp = tmp->next;
		// }
		// 	sleep(6);
		// }
		count++;
	}
}
// void search_place(t_stack **stack_b, t_stack *tmp)
// {
// 	static int size = 0;
// 	int			i;
// 	int			position;
// 	t_stack		*search;

// 	// if (size < 30)
// 	// 	 push(stack_b , tmp);
// 	search = *stack_b;
// 	i = 0;
// 	position = 0;
// 	while (i < size)
// 	{
// 		if (search->data > tmp->data)
// 			position++;
// 		i++;
// 	}
// 	if (position == 0)
// 		 push(stack_b , tmp);
// 	else if (position <= size / 2)
// 	{
// 			ra(stack_b , position + 1);
// 			push(stack_b , tmp);

// 	}
// 	else
// 	{
// 		 rra(stack_b , position+1 , size);	
// 		 push(stack_b , tmp);
// 	}
// 	 printf("pb\n");
	
// }
// void sort_stack(t_stack **stack_a, int size)
// {
// 	t_stack		*stack_b;
// 	t_stack		*tmp;
// 	int			current_size;
// 	int 		min;
// 	int			current_index;

// 	current_size = size;
// 	stack_b = NULL;
// 	tmp = *stack_a;
// 	 while (current_size != 3)
// 	 {
// 		min = search_min(*stack_a, &current_index , current_size);
// 		if (current_index == 1)
//             tmp = *stack_a;
// 		else if (current_index <= (size / 2))
// 		{
// 			ra(stack_a , current_index);
// 			tmp = *stack_a;
// 		}
//         else
//         {
        
//             rra(stack_a , current_index , current_size);
//              tmp = *stack_a;
//         }
//         *stack_a = (*stack_a)->next;
// 		search_place(&stack_b , tmp);
//          //push(&stack_b , tmp);
// 		 		//printf("pb\n");
// 				count++;
// 		current_size--;
// 	 }
// 	 while (current_size != size)
//      {
//        tmp = stack_b;
//         stack_b = stack_b->next;
//         push(stack_a, tmp);
// 			printf("pa\n");
// 		count++;
//         current_size++;
//      }
// }

void    ft_split(char **str, int argc, t_stack **stack_a)
{
	t_stack *node;
	argc --;
    while (argc >= 1)
    {
		node = new_node(ft_atoi(str[argc]));
        push(stack_a, node);
		argc--;
    }
}

int main(int argc, char *argv[])
{
	t_stack *stack_a;
	t_stack *sorted_list;
	t_stack *tmp;
	int i = 1;

	count = 0;
	stack_a = NULL;
    ft_split(argv, argc, &stack_a);
	
	//printf("good\n");
	sorted_list = merge_sort(stack_a);
	tmp = stack_a;
	while (tmp)
	{
	//	printf("%i\n", tmp->data);
		sorted_list->index = i++;
		sorted_list = sorted_list->next1;
		tmp = tmp->next;
	}
	// while (tmp != NULL)
	// {
	// 	printf("number == %i , index == %i\n", tmp->data, tmp->index);
	// 	tmp = tmp->next;
	// }
	//printf("%p\n",stack_a->next);
	sort_stack(&stack_a, argc-1);

	// while (stack_a != NULL)
	// {
	// 	printf("2--%i\n", stack_a->data);
	// 	stack_a = stack_a->next;
	// }
	// printf("\nnumber moves == %i\n", count);
	 //if (count >= 700 )
	 	printf("\nyessessss   moves == %i\n", count);
}
//nekdar nzid dik kediya libhal likayen fel file push swap yenka y pushi oyedfa3 lka3 mli yejbar rakem lakherani fe stack sghir elihwalakin khesni nzid mli ykon kidor f stac_a yejbarch chi wa7id kbir elih 