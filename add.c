#include "apc.h"

void add_lists(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *temp1 = tail1;
    node *temp2 = tail2;

    //initialised carry to 0
    int carry = 0,sum = 0;
    
    // start form tail of both lists
    while(temp1 != NULL || temp2 != NULL)
    {
        int sum1 = 0;
        int sum2 = 0;

        // take a digit from both
       if(temp1 != NULL)
       {
            sum1 = temp1 ->data;
            temp1 = temp1 -> prev;
       }

       if(temp2 != NULL)
       {
            sum2 = temp2 -> data;
            temp2 = temp2 -> prev;
       }

       // add sum + carry
       sum = sum1 + sum2 + carry;

       // store reminder (mod 10) at front
       insert_first(headR, tailR, sum % 10);
       // for every time we have to update carry
       carry = sum / 10;
    }
    // we have to store like if the carry exists insert at front
    if(carry == 1)
    {
        insert_first(headR, tailR, carry);
    }
}
