/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * create(int n,struct node *start){
	struct node *ptr, *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->num = n;
	if (start == NULL){
		newnode->next = NULL;
		start = newnode;
	}
	else{
		ptr = start;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = newnode;
		newnode->next = NULL;
		newnode = start;
	}
	return start;
}
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	if (head1 == NULL && head2 == NULL)
		return NULL;
	struct node *start=NULL;
	while (head1 != NULL&&head2 != NULL){
		if (head1->num < head2->num){
			start = create(head1->num, start);
			head1 = head1->next;
		}
		else{
			start = create(head2->num, start);
			head2 = head2->next;
		}
	}
	while (head1 != NULL){
		start = create(head1->num, start);
		head1 = head1->next;
	}
	while (head2){
		start = create(head2->num, start);
		head2 = head2->next;
	}
	return start;
}
