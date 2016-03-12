/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>


struct node {
	int num;
	struct node *next;
};
int listLen(node *);
node* removeNode(node *, int);


struct node * removeEveryKthNode(struct node *head, int K) {

	if (head == NULL || K<=1)
		return NULL;
	int i = 1,l,j=K-1;
	node *curr;
	l = listLen(head);
	if (K > l)
		return head;
	curr = head;
	while (K <= l)
	{
		curr=removeNode(curr, K);
		//K = K + j;
		l = l - K;
	}
	return head;
}
int listLen(node *head)
{
	int l = 1;
	node *curr;
	curr = head;
	while (curr->next != '\0')
	{
		curr = curr->next;
		l++;
	}
	return l;
}
node* removeNode(node *head, int k)
{
	int i=1;
	node *curr, *temp, *curr1;
	temp = (node*)malloc(sizeof(node));
	curr = (node*)malloc(sizeof(node));
	curr1 = (node*)malloc(sizeof(node));
	curr = head;
	while (i<k&&curr->next != '\0')
	{
		curr1 = curr;
		curr = curr->next;
		i++;
	}
	if (i == k)
	{
		temp = curr;
		curr1->next = temp->next;
		temp->next = '\0';
	}
	return curr1;
}