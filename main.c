/*
Name        – Pratik Satsure
Batch       – 25026F
Batch id    – 25025_079

Title – Arbitrary Precision Calculator

Description 
The Arbitrary Precision Calculator is a C-based application designed to perform arithmetic 
operations on very large integers that exceed the limits of standard data types such as int, long, or double.

In this project, large numbers are represented using a doubly linked list, where each node 
stores a single digit. This allows the system to handle numbers of virtually unlimited size, constrained only by available memory.

The calculator supports fundamental arithmetic operations including:

Addition
Subtraction
Multiplication
Division

Each operation is implemented manually using digit-by-digit logic, similar to traditional 
pen-and-paper methods. The program takes input through command-line arguments, validates it, 
converts numbers into linked lists, performs the operation, and displays the result.

Objective
-To design and implement a calculator capable of handling large numbers beyond built-in data type limits
-To perform arithmetic operations using custom data structures
-To understand and apply linked list concepts and pointer manipulation
-To simulate real-world arithmetic operations at a digit level

Conclusion
The Arbitrary Precision Calculator successfully demonstrates how large number arithmetic can be 
implemented using data structures instead of built-in types. It highlights the importance of 
efficient memory management, algorithm design, and logical problem-solving. This project not only 
solves the limitation of standard data types but also strengthens core programming concepts, 
making it a valuable learning experience and a strong addition to a developer’s skill set.

*/
#include<stdio.h>
#include "apc.h" 

int main(int argc,char *argv[])
{
    node *head1 = NULL , *tail1 = NULL;
    node *head2 = NULL , *tail2 = NULL;
    node *headR = NULL , *tailR = NULL;

    int sign1 = 1, sign2 = 1;

    if(cla_validation(argc,argv) == FAILURE)
    return 0;
    
    if(argv[1][0] == '-')
    {
        sign1 = -1;
    }
    if(argv[3][0] == '-')
    {
        sign2 = -1;
    }
    
   

    create_list(argv[1], &head1, &tail1);
    create_list(argv[3], &head2, &tail2);

    remove_pre_zeros(&head1);
    remove_pre_zeros(&head2);

    char oper = argv[2][0];
    int cmp = compare_list(head1, head2);

    switch(oper)
    {
        case '+':
        {
            if(sign1 == sign2)
            {
                add_lists(tail1, tail2, &headR, &tailR);
                printf("Addition of The %s and %s is :",argv[1],argv[3]);

                if(sign1 == -1)
                {
                    printf("-");
                }
                print_list(headR);
            }
            else
            {
                if(cmp == OPERAND1)
                {
                    sub_lists(tail1, tail2, &headR, &tailR);
                    printf("Addition of The %s and %s is :",argv[1],argv[3]);

                    if(sign1 == -1)
                    {
                        printf("-");
                    }
                    print_list(headR);
                }
                else if(cmp == OPERAND2)
                {
                    sub_lists(tail2, tail1, &headR, &tailR);
                    printf("Addition of The %s and %s is :",argv[1],argv[3]);

                    if(sign2 == -1)
                    {
                        printf("-");
                    }
                    print_list(headR);
                }
                else
                {
                    printf("Addition of The %s and %s is :0\n",argv[1],argv[3]);
                }
            }
        }
        break;

        case '-':
        {
            sign2 = -sign2;

            if(sign1 == sign2)
            {
                add_lists(tail1, tail2, &headR, &tailR);
                

                if(sign1 == -1)
                {
                    printf("-");
                }
                
            }
            else
            {
                if(cmp == OPERAND1)
                {
                    sub_lists(tail1, tail2, &headR, &tailR);
                    if(sign1 == -1)
                    {
                        printf("-");
                    }
                 
                }
                else if(cmp == OPERAND2)
                {
                    sub_lists(tail2, tail1, &headR, &tailR);
                    if(sign2 == -1)
                    {
                        printf("-");
                    }
                }
                else
                {
                    printf("0\n");
                    break;
                }
            }

            printf("SUBTRACTION of The %s and %s is :",argv[1],argv[3]);
            print_list(headR);

        }
        break;

        case 'X':
        {
            multiply_lists(tail1, tail2, &headR, &tailR);
            remove_pre_zeros(&headR);

            printf("Multiplication of The %s and %s is :",argv[1],argv[3]);

            if(sign1 != sign2)
            {
                printf("-");
            }
            print_list(headR);
            
        }
        break;

        case '/':
        {
            div_lists(head1, tail1, head2, tail2, &headR, &tailR);

            printf("Division of The %s and %s is :",argv[1],argv[3]);

            if (sign1 != sign2)
            {
                printf("-");
            }
            print_list(headR);

        }
        break;
    }
    return 0;
}
