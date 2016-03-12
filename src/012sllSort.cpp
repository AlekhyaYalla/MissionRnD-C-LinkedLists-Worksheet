/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

typedef struct node {
	int data;
	node *next;
};
node * place(node *, int, int);

void sll_012_sort(struct node *head){

	int zero = 0, one = 0, two = 0;
	node *p;
	p = head;
	while (p != '\0')
	{
		if (p->data == 0)
			zero++;
		else if (p->data == 1)
			one++;
		else if (p->data == 2)
			two++;
		p = p->next;
	}
	p = head;
	if (p != '\0')
	{
		p = place(p, zero, 0);
		p = place(p, one, 1);
		p = place(p, two, 2);
	}
}
node *place(node *p, int i, int n)
{
	while (i>0)
	{
		p->data = n;
		p = p->next;
		i--;
	}
	return p;
}