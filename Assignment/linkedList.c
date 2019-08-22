#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
	char digit;
	struct node * next;
};
struct node * makenode(char digit)
{
	
}
void printList(struct node * list)
{

}
struct node * readNum()
{
	char c;
	struct node * head, * trav;
	scanf("%c", &c);
	head = trav = makenode(c - '0');
	do
	{
		scanf("%c", &c);
		if(!isdigit(c)) break;
		trav -> next = makenode(c - '0');
		trav = trav -> next;

	}while(1);
	return head;
}
struct node* reverse(struct node * list, struct node **head)
{
	if(list -> next == NULL)
	{
		*head = list;//head of reversed list;
		return list;
	}
	reverse(list -> next, head) -> next = list;
	list -> next = NULL;
	return list;
}
struct node * simultrav(struct node* trav1, struct node * trav2, char carry)
{
	struct node * temp;
	char sum = carry;
	if(trav1 && trav2)
	{
		sum += trav1 -> digit + trav2 -> digit;
	}
	else if (trav1)
	{
		sum += trav1 -> digit;
	}	
	else if (trav2)
	{
		sum += trav2 -> digit;
	}	
	carry = sum /10;
	sum = sum % 10;
	temp = makenode(sum);

	if(trav1  && trav2)
	{
		temp -> next = simultrav(trav1-> next, trav2 -> next, carry);
	}
	else if(trav1)
	{
		temp -> next =  simultrav(trav1-> next, trav2, carry);
	}
	else if(trav2)
	{
		temp -> next =  simultrav(trav1, trav2 -> next, carry);
	}
	else 
	{
		if(carry)
		{
			temp -> next = makenode(carry);
		}
		else
			temp -> next = NULL;
	}
	return temp;
}

int main()
{
	struct node * num1, * num2, *rnum1, *rnum2, *sum, *rsum;
	printf("Enter the first number: ");
	num1 = readNum();
	printf("Enter the second number: ");
	num2 = readNum();
	printf("\n");
	reverse( num1, &rnum1);
	reverse( num2, &rnum2);
	rsum = simultrav(rnum1, rnum2, 0);
	reverse( rsum, &sum);
	printf("The sum is : ");
	printList(sum);
	printf("\n");

}
