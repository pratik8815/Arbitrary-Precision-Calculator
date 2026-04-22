#include "apc.h"

int flag_pp = 1;
int flag_pm = 2;
int flag_mp = 3;
int flag_mm = 4;

int cla_validation(int argc, char* argv[])
{
    if(argc != 4)
    {
        printf("Usage: ./a.out <num1> <op> <num2>\n");
        return FAILURE;
    }

    int i = (argv[1][0] == '-' || argv[1][0] == '+') ? 1 : 0;

    for(; argv[1][i]; i++)
    {
        if(argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("First Operand Must Be Digit\n");
            return FAILURE;
        }
    }

    i = (argv[3][0] == '-' || argv[3][0] == '+') ? 1 : 0;
    
    for(; argv[3][i]; i++)
    {
        if(argv[3][i] < '0' || argv[3][i] > '9')
        {
            printf("Second Operand Must Be Digit\n");
            return FAILURE;
        }
    }

    if(argv[2][0] == '/' && strcmp(argv[3],"0") == 0)
    {
        printf("ERROR: Division By Zero\n");
        return FAILURE;
    }
    return SUCCESS;
}

void create_list(char *opr, node **head, node **tail)
{
    int i = 0;

    while(opr[i])
    {
        if(opr[i] == '+' || opr[i] == '-')
        {
            i++;
            continue;
        }

        insert_last(head, tail, opr[i] - '0');
        i++;
    }
}

int insert_last(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));

    if(!new)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if(*head == NULL)
    {
        *head = *tail = new;
        return SUCCESS;
    }

    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;

    return SUCCESS;
}

int insert_first(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));

    if(!new)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if(*head == NULL)
    {
        *head = *tail = new;
    }
    else
    {
        new->next = *head;
        (*head)->prev = new;
        *head = new;
    }

    return SUCCESS;
}

void print_list(node *head)
{
    if(head == NULL)
    {
        printf("0\n");
        return;
    }

    while(head)
    {
        printf("%d", head->data);
        head = head->next;
    }

    printf("\n");
}

int delete_list(node **head, node **tail)
{
    node *temp = *head;

    while(temp)
    {
        node *next = temp->next;
        free(temp);
        temp = next;
    }

    *head = NULL;
    *tail = NULL;

    return SUCCESS;
}

void remove_pre_zeros(node **head)
{
    if(*head == NULL)
        return;

    node *temp = *head;

    while(temp->data == 0 && temp->next != NULL)
    {
        *head = temp->next;
        (*head)->prev = NULL;
        free(temp);
        temp = *head;
    }
}

int list_len(node *head)
{
    int count = 0;

    while(head)
    {
        count++;
        head = head->next;
    }

    return count;
}

int compare_list(node *head1, node *head2)
{
    remove_pre_zeros(&head1);
    remove_pre_zeros(&head2);

    int len1 = list_len(head1);
    int len2 = list_len(head2);

    if(len1 > len2)
        return OPERAND1;

    if(len1 < len2)
        return OPERAND2;

    while(head1 && head2)
    {
        if(head1->data > head2->data)
            return OPERAND1;

        if(head1->data < head2->data)
            return OPERAND2;

        head1 = head1->next;
        head2 = head2->next;
    }

    return SAME;
}

int operation_decider(char *op1, char *op2)
{
    if(op1[0]=='-' && op2[0]=='-')
        return flag_mm;

    else if(op1[0]=='-' && op2[0] != '-')
        return flag_mp;

    else if(op1[0] != '-' && op2[0]=='-')
        return flag_pm;

    else
        return flag_pp;
}


