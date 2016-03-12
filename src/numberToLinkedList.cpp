/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>
typedef struct node {
	int num;
	node *next;
};
node* createNode(int);
node * numberToLinkedList(int N) {
	
	if (N < 0)
		N = N*(-1);
	node *head = createNode(N % 10);
	N /= 10;
	while (N) {
		node *temp = createNode(N % 10);
		temp->next = head;
		head = temp;
		N /= 10;
	}
	return head;
}
node * createNode(int num) {
	node *temp = (node *)malloc(sizeof(node));
	temp->num = num;
	temp->next = NULL;
	return temp;
}
/*int exp(int);
int reverse(int, int, node *);

struct node * numberToLinkedList(int N) {

	node *head, *temp;
	temp = (node*)calloc(1,sizeof(node));
	head = temp;
	if (N == 0)
	{
		head->num = 0;
		return head;
	}
	if (N < 0)
		N = N*(-1);
	N = reverse(N, 0, temp);
	N = reverse(N, 1, temp);
	return head;
}
int reverse(int n, int f, node *temp)
{
	int s = 0, r, i = 0, m = n;
	while (m>0)
	{
		m = m / 10;
		i++;
	}
	while (n>0 && i >= 1)
	{
		r = n % 10;
		s = s + (r*exp(i - 1));
		if (f == 1)
		{
			node *curr;
			curr = (node*)calloc(1, sizeof(node));
			temp->num = r;
			if (i>1)
			{
				temp->next = curr;
				temp = curr;
			}
		}
		n = n / 10;
		i--;
	}

	return s;
}
int exp(int j)
{
	int s = 1;
	while (j>0)
	{
		s = s * 10;
		j--;
	}
	return s;
}*/