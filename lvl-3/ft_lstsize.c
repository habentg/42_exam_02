
#include "ft_lst.h"

t_list *ft_lstcreate(int num)
{
    t_list  *newnode;

    newnode = (t_list *)malloc(sizeof(t_list *));
    if (!newnode)
        exit(0);
    newnode->value = num;
    newnode->next = NULL;
    printf("node created val: %d\n", newnode->value);
    return (newnode);
}

void	ft_lstadd_back(t_list **head, t_list *node)
{
    t_list  *lst;

    lst = *head;
    if (lst == NULL)
        lst = node;
    else
    {
        printf("lst: %d\n", lst->value);
        while (lst != NULL)
        {
            if (lst->next == NULL)
                (lst)->next = node;
            lst = (lst)->next;
        }
    }
    printf("%d \n", (lst)->value);
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
        printf("node value: %d \n", (temp->value));
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
}