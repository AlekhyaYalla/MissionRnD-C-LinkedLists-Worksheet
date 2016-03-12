/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>
int exponential(int);
typedef struct node {
	int digit1;
	int digit2;
	node *next;
};


int convert_sll_2digit_to_int(node *head){
	
	node *p;
	int n = 0, i, s = 0;
	p = head;
	while (p != '\0')
	{
		p = p->next;
		n++;
	}
	p = head;
	n *= 2;
	while (p != '\0')
	{
		i = p->digit1;
		s += i*exponential(n - 1);
		n--;
		i = p->digit2;
		s += i*exponential(n - 1);
		n--;
		p = p->next;
	}
	return s;
}
int exponential(int j)
{
	int s = 1;
	while (j>0)
	{
		s = s * 10;
		j--;
	}
	return s;
}
