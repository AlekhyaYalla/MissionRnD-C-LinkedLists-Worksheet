/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

typedef struct node {
	int num;
	node *next;
};

void swap(node *, node *);

struct node * sortLinkedList(node *head) {
	node *p, *q;
	p = head;
	if (p == NULL)
		return NULL;
	while (p->next != '\0')
	{
		q = p->next;
		while (q->next != '\0')
		{
			if (p->num>q->num)
			{

				swap(p, q);
				q = q->next;
			}
			else
				q = q->next;
		}
		if (q->next == '\0')
		{
			if (p->num>q->num)
				swap(p, q);
		}
		p = p->next;
	}
	return head;
}
void swap(node *p, node *q)
{
	int t;
	t = p->num;
	p->num = q->num;
	q->num = t;
}