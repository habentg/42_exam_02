
#include "ft_lst.h"

t_list *ft_lstcreate(int num)
{
    t_list  *newnode;

    newnode = (t_list *)malloc(sizeof(t_list *));
    if (!newnode)
        exit(0);
    newnode->value = num;
    newnode->next = NULL;
    return (newnode);
}

t_list  *ft_lst_last(t_list *head)
{
    if (!head)
        printf("head empty");
    while (head != NULL)
    {
        if (head->next == NULL)
            return (head);
        head = head->next;
    } 
    return (0);
}
void	ft_lstadd_back(t_list **lst, t_list *node)
{
	if (*lst == NULL)
		*lst = node;
    else
        ft_lst_last(*lst)->next = node;
}

void    ft_cleanlst(t_list *head)
{
    t_list  *temp;
    t_list  *temp2;

    temp = head;
    while (temp)
    {
        temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
}

int	ft_lstsize(t_list *begin_list)
{
    t_list  *temp;
    int     count;

    temp = begin_list;
    count = 0;
    while(temp)
    {
        count++;
        temp = temp->next;
    }
    return (count);
}

int main(void)
{
    t_list *head;
    t_list *newnode;

    int i = 0;

    head = (t_list *)malloc(sizeof(t_list));
    if (!head)
    {
        printf("mem aloc failed \n");
        exit(0);
    }
    head = NULL;
    while (i < 10)
    {
        newnode = ft_lstcreate(i);
        ft_lstadd_back(&head, newnode);
        i++;
    }
    printf("lst size: %d \n", ft_lstsize(head));
    ft_cleanlst(head);
}