#include "apc.h"

void div_lists(node *head1, node *tail1,node *head2, node *tail2,node **headR, node **tailR)
{
    node *head_opr1  =NULL;
    node *tail_opr1 = NULL;

    node *temp = head1;
    int flag = 0;

    // check wether divide by zero (0) is
    if(head2 == NULL || (head2 -> data == 0 && head2 -> next == NULL))
    {
        printf("ERROR :- Divide By 0\n");
        return;
    }

    // if divident < divisior result will be result = 0
    if(compare_list(head1, head2) == OPERAND2)
    {
        insert_first(headR, tailR, 0);
        return;
    }

    // take a loop for whole division
    while(temp != NULL)
    {
        // take the last digit of the number
        insert_last(&head_opr1, &tail_opr1, temp -> data);
        // traverse the list
        temp = temp -> next;

        remove_pre_zeros(&head_opr1);

        int count  =0;

        // now substract divisiors repeatebely for this take a loop
        while(compare_list(head_opr1, head2) != OPERAND2)
        {
            node *head_SR = NULL;
            node *tail_SR = NULL;

            sub_lists(tail_opr1, tail2, &head_SR, &tail_SR);
            delete_list(&head_opr1, &tail_opr1);

            head_opr1 = head_SR;
            tail_opr1 = tail_SR;

            count++;
        }
        // now insert the quotient digits at the last
        // handling leading zeros conpare it with count
        if(count > 0)
        {
            insert_last(headR, tailR, count);
            flag  =1;
        }
        else
        {
            if(flag)
            {
                insert_last(headR, tailR, 0);
            }
        }
    }
    remove_pre_zeros(headR);

    // in any condition like substraction will never happen so no digit will be inserted in the res
    if (*headR == NULL)
        insert_first(headR, tailR, 0);

    //sub list will create new list to we have to clear the prev list
    //call delete function and clear hear_opr1,tail_opr1
    delete_list(&head_opr1, &tail_opr1);




}