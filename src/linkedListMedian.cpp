/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
int len(struct node *head){
	int i = 0;
	struct node *ptr;
	ptr = head;
	while (ptr != NULL){
		i++;
		ptr = ptr->next;
	}
	return i;
}

int linkedListMedian(struct node *head) {
	if (head == NULL)
		return -1;
	else{
		int l, n, v, i = 0;
		l = len(head);
		struct node *ptr,*ptr1;
		ptr = head;
		ptr1 = head;
		n = l / 2;
		if (l % 2){
			while (i < n){
				ptr = ptr->next;
				i++;
			}
			v = ptr->num;
		}
		if (!(l % 2)){
			while (i < n){
				ptr1 = ptr;
				ptr = ptr->next;
				i++;
			}
			v = (ptr->num + ptr1->num) / 2;
		}
		return v;
	}
}
