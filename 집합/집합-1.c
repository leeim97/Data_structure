#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 115

typedef struct node {
	int ele;
	struct node* next;
}node;

typedef struct list {
	node* head;
	int num;
}list;
void init(list* A) {
	node* ohead=NULL;
	ohead = (node*)malloc(sizeof(node));
	ohead->next = NULL;

	A->head = ohead;
	A->num = 0;
}
void insert(list* A, int x) {
	node* newnode;
	newnode = (node*)malloc(sizeof(node));
	newnode->ele = x;
	newnode->next = NULL;

	node* p;
	p = A->head;

	while (p->next != NULL) {
		p = p->next;
	}
	p ->next= newnode;
	A->num += 1;
}
int members(list* A, int ele) {
	int a;
	node* p = A->head;
	while (1) {
		a = p->ele;
		if (a<ele) {
			if ((p->next) == NULL)
				return 0;//멤버가 아니다
			else
			p = p->next;

		}
		else if (a >ele)
			return 0; //멤버가 아니다.
		else {
			return 1;//멤버가 맞다.
		}

	}
}

void subset(list* A, list* B) {//A가 B의 부분 집합인지
	if (A->num == 0) {
		printf("0");
		return ;
	}
	node* a,*b;
	a = A->head;
	while (1) {
		if (1 == members(B, a->ele)) {
			if (a->next == NULL) {
				printf("0");
				return;
			}
			else
				a = a->next;
		}
		else if (0== members(B,a->ele)) {
			printf("%d", a->ele);
			return;
		}
	}

}


int main()
{
	int result;
	list a, b;
	init(&a), init(&b);
	int numA, numB,ele;

	scanf("%d", &numA);
	getchar();

	for (int i = 0; i < numA; i++) {
		scanf("%d", &ele);
		getchar();
		insert(&a, ele);
	}

	scanf("%d", &numB);
	for (int i = 0; i < numB; i++) {
		scanf("%d", &ele);
		getchar();
		insert(&b, ele);
	}
	
	subset(&a, &b);
}
