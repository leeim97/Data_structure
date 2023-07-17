#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 115

typedef struct node {
	char element;
	struct node* prev;
	struct node* next;
}node;

typedef struct list {
	int size;
	node* head;
	node* tail;

}list;
void reset(list* li);
void add(list* li, int r, char c);
void del(list* li, int r);
void get(list* li, int r);
void print(list* li);

int main()
{
	int num, ind; //index
	char F, e;//element
	list li;
	reset(&li);
	scanf("%d", &num);
	getchar();

	for (int i = 0; i < num; i++) {
		scanf("%c", &F);

		if (F == 'A') {
			scanf("%d %c", &ind, &e);
			getchar();
			add(&li, ind, e);

		}
		else if (F == 'D') {
			scanf("%d", &ind);
			getchar();
			del(&li, ind);

		}
		else if (F == 'G') {
			scanf("%d", &ind);
			getchar();
			get(&li, ind);

		}
		else if (F == 'P') {
			print(&li);
			getchar();
		}
	}

	free(li.head);
	free(li.tail);
	return 0;

}
void reset(list* li) {
	node* ohead, * otail;
	ohead = (node*)(malloc)(sizeof(node));
	otail = (node*)(malloc)(sizeof(node));
	li->head = ohead;
	li->tail = otail;
	ohead->prev = NULL;
	ohead->next = otail;
	otail->prev = ohead;
	otail->next = NULL;

	li->size = 0;

}

void add(list* li, int r, char c) {

	if (r<1 || r>li->size + 1) {
		printf("invalid position\n");
		return;
	}

	node* newnode;
	newnode = (node*)malloc(sizeof(node));
	newnode->element = c;


	node* p = li->head;
	for (int i = 1; i < r; i++)
		p = p->next;

	newnode->next = p->next;
	newnode->prev = p;
	p->next->prev = newnode;
	p->next = newnode;

	li->size++;


}


void del(list* li, int r) {
	if (r<1 || r>li->size) {
		printf("invalid position\n");
		return;
	}

	node* p;
	p = li->head;
	for (int i = 1; i < r + 1; i++)
		p = p->next;

	p->next->prev = p->prev;
	p->prev->next = p->next;
	free(p);
	li->size--;
}


void get(list* li, int r) {
	if (r<1 || r>li->size) {
		printf("invalid position\n");
		return;
	}
	node* p = li->head;
	for (int i = 1; i < r + 1; i++)
		p = p->next;

	printf("%c\n", p->element);

}
void print(list* li) {

	node* p = li->head->next;

	while (p != li->tail) {

		printf("%c", p->element);
		p = p->next;
	}
	printf("\n");
}
