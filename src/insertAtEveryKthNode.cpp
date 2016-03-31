/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

int length(struct node *head){
	int i = 0;
	struct node *ptr;
	ptr = head;
	while (ptr->next != NULL){
		i++;
		ptr = ptr->next;
	}
	return i;
}

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL || K <= 0 )
		return NULL;
	int i = length(head);
	if (i >= K){
		int count = 1;
		struct node *ptr1, *ptr2, *k;
		ptr1 = head->next;
		ptr2 = head;
		while (ptr1 != NULL){
			if ((count % K) == 0){
				k = (struct node *)malloc(sizeof(struct node));
				k->num = K;
				ptr2->next = k;
				if (ptr1!=NULL)
					k->next = ptr1;
				count = 0;
			}
			count++;
			ptr2 = ptr1;
			ptr1 = ptr1->next;
		}
		if (K == 1){
			k = (struct node *)malloc(sizeof(struct node));
			k->num = K;
			ptr2->next = k;
			k->next = NULL;
		}
	}
	return head;
}
