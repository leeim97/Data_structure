#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 115

typedef struct node {
	struct node* next;
	int ele;
}node;
typedef struct list {
	node* head;
	int size;
}list;

void init( list * A ){
	node* ohead;
	ohead = (node*)malloc(sizeof(node));
	ohead->next = NULL;

	A->head = ohead;
	A->size = 0;
}
void insert(list* A, int el) {
	node* newnode;
	newnode = (node*)malloc(sizeof(node));
	newnode->ele = el;
	newnode->next = NULL;

	node* p = A->head;

	if (p->next == NULL) {
		p->next = newnode;
	}
	else {
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = newnode;
	}
	A->size += 1;
}

void removeFirst(list* A) {
	node* p = A->head->next;

	if (A->size <= 0){
		printf("Empty");
		return;	
	}
	else {
		A->head->next = p->next;
		free(p);
		A->size -= 1;
	}
	
}

list uni(list* A, list* B) {
	list c;
	init(&c);
	node* a = A->head->next;
	node* b = B->head->next;

	while ((A->size != 0) && ((B->size) != 0)) {
		if (a->ele < b->ele) {
			insert(&c, a->ele);
			removeFirst(A);
		}
		else if (a->ele > b->ele) {
			insert(&c, b->ele);
			removeFirst(B);
		}
		else {
			insert(&c, a->ele);
			removeFirst(A);
			removeFirst(B);
		}
	}
	while (A->size != 0) {
		insert(&c, a->ele);
		removeFirst(A);
	}
	while (B->size != 0) {
		insert(&c, b->ele);
		removeFirst(B);
	}
	return c;


}
list intersect(list* A, list* B) {
	list c;
	init(&c);
	node* a = A->head->next;
	node *b=B->head->next;

	while ((A->size) != 0 && (B->size != 0)) {
		if (a->ele < b->ele) {
			removeFirst(A);
		}
		else if (a->ele > b->ele) {
			removeFirst(B);
		}
		else {
			insert(&c, a->ele);
			removeFirst(A);
			removeFirst(B);

		}
	}
	while ((A->size) != 0) {
		removeFirst(A);
	}
	while ((B->size) != 0) {
		removeFirst(B);
	}
	return c;
}
void print(list* A) {
	node* p = A->head->next;

	while (p != NULL) {
		printf("%d ", p->ele);
		p = p->next;
	}
	printf("\n");
}

int main()
{	
	list a, b,unio,inter;
	int numA, numB,ele;
	init(&a), init(&b), init(&unio), init(&inter);
	scanf("%d", &numA);
	getchar();
	for (int i = 0; i < numA; i++) {
		scanf("%d", &ele);
		getchar();
		insert(&a, ele);
	}

	scanf("%d", &numB);
	getchar();
	for (int i = 0; i < numB; i++) {
		scanf("%d", &ele);
		getchar();
		insert(&b, ele);
	}

	unio = uni(&a, &b);
	inter = intersect(&a, &b);
	print(&unio);
	print(&inter);
}
