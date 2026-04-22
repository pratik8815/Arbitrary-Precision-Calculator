#include "apc.h"

void multiply_lists(node *tail1, node *tail2, node **headR, node **tailR)
{
    int count = 0,carry = 0;
    node *temp;

    node *temp1 = tail1;
    node *temp2 = tail2;

    // initialy the reasult list is empty
    node *headAR = NULL, *tailAR = NULL;
    node *headR2 = NULL, *tailR2 = NULL;
    
  
    // we have to go through each digit of the second number
    while(temp2 != NULL)
    {
        // take a loop to add zeros based on the count positions shifts for every new time
        for(int i = 0; i < count; i++)
        {
            insert_first(&headR2, &tailR2, 0);
        }
        //Multiply each digit of first number with current digit of second number
        while(temp1 != NULL)
        {
            int mul = (temp1 -> data) * (temp2 -> data) + carry;
            if(count == 0)
            {
                insert_first(headR, tailR, mul % 10);
            }
            else
            {
                insert_first(&headR2, &tailR2, mul % 10);
            }
            // make the carry / 10 every time
            carry = mul / 10;
            // traverse the list
            temp1 = temp1 -> prev;

            //if carry remains after the list 1 ended then insert it
            if(temp1 == NULL)
            {
                if(count == 0)
                {
                    insert_first(headR, tailR, carry);
                }
                else
                {
                    insert_first(&headR2, &tailR2, carry);
                }
                carry = 0;
            }
        }
        // replace old result with new result
        if(headR2 != NULL)
        {
            add_lists(*tailR,tailR2, &headAR, &tailAR);
            delete_list(headR,tailR);
            *headR = headAR;
            *tailR = tailAR;
            headAR = NULL;
            tailAR = NULL;
        }
        delete_list(&headR2,&tailR2);
        temp1 = tail1;

        // traverse the list
        temp2 = temp2->prev;
        count++;
    }
    

}