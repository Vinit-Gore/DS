#include<stdio.h>
struct stack
{
        int stack[1000];
        int SP;
};
int pop(struct stack *mystack, int *status)
{
*status =1;
if(--mystack->SP>=0){
 return mystack->stack[mystack->SP];
}       
 else
 {
     mystack->SP++;
     *status =0;
     return 0;
 }
 

}
int push(struct stack *mystack, int elem)
{
if(mystack->SP<1000){
    mystack->stack[mystack->SP++]=elem;
    return 1;
}
else{
    return 0;
}

}
int main()
{
        int n, i, elem, status;
        struct stack mystack;
        mystack.SP = 0;
        printf("Please enter the number of elements to stack: ");
        scanf("%d", &n);
        printf("Please enter the stack elements: ");
        for(i = 0; i < n; i++)
        {
                scanf("%d", &elem);
                push(&mystack, elem);
        }
        printf("The stack contents are :");
        printf("\n");
        for(i = 0; i < n; i++)
        {
                elem = pop(&mystack, &status);
                if(status == 0)//should not happen as we know n here
                {
                        break;
                }
                printf("\nelem = %d ", elem);
                printf("\n status = %d ",status);
        }
        printf("\n");

}