#include "apc.h"

void sub_lists(node *tail1, node *tail2, node **headR, node **tailR)
{
    // we going to need borrowed in this
    int borrow_flg  = 0;

    // start from tail of the both list
    node *temp1 = tail1;
    node *temp2 = tail2;

    // take a loop for first list is not NULL
    while(temp1 != NULL)
    {
        // take a var and store with data presented in the temp1
        int digit1 = temp1 -> data;
        int digit2 = 0;
        if(temp2 != NULL)
        {
            digit2 = temp2 -> data;
            temp2 = temp2 -> prev;
        }

        // if the borrow exists we have to substract it
        if(borrow_flg)
        {
            digit1 = digit1 - 1;
            borrow_flg = 0;
        }

        // check if digit1 is less than digit2 if yes set the borrow to 1
        if(digit1 < digit2)
        {
            digit1 = digit1 + 10;
            borrow_flg = 1;
        }

        //take a var and sub digit1 and digit 2
        int sub = digit1 - digit2;

        // insert it at the front
        insert_first(headR, tailR, sub); 
        
        // traverse the list
        temp1 = temp1 -> prev;
    }
    remove_pre_zeros(headR);


}