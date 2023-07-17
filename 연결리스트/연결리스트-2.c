#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 115

typedef struct node {

	struct node* next;
	int coef; //계수
	int exp; //차수


}node;

typedef struct list {
	node* head;

}list;

void init(list* A) {
	node* ohead;
	ohead = (node*)malloc(sizeof(node));
	ohead->next = NULL;
	
	A->head = ohead;
}

void appendTerm(node* x, int c, int e) {

	node* t;
	t = NULL;
	t = (node*)malloc(sizeof(node));
	t->coef = c;
	t->exp = e;
	t->next = NULL;
	node* k = x;

	while (k->next != NULL) {
		k = k->next;
	}
	
	k->next = t;


}
node* addpoly(list *x,list* y) {
	int sum;
	node* result;
	result = (node*)malloc(sizeof(node));
	result->next = NULL;

	node* i = x->head->next;
	node* j = y->head->next;
	node* k = result;
	while ((i != NULL) && (j != NULL)) {
		if (i->exp > j->exp) {
			appendTerm(k, i->coef, i->exp);
			i = i->next;
		}
		else if (i->exp < j->exp) {
			appendTerm(k, j->coef, j->exp);
			j = j->next;
		}
		else {
			sum = j->coef + i->coef;
			if (sum != 0) {
				appendTerm(k, sum, i->exp);
			}
			i = i->next;
			j = j->next;

		}
	}
		while (i != NULL) {
			appendTerm(k, i->coef, i->exp);
			i = i->next;
		}
		while (j != NULL) {
			appendTerm(k, j->coef, j->exp);
			j = j->next;
		}



		return result;

	
};
void print(list* x){

	node* p;
	p = x->head->next;
	while (p != NULL) {
		printf("%d %d ", p->coef, p->exp);
		p = p->next;
	}
	printf("\n");

}
int main()
{
	list x, y, z;
	init(&x),init(&y),init(&z);
	int num,coef,exp;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &coef, &exp);
		appendTerm(&x, coef, exp);
	}
	printf("\n");

	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &coef, &exp);
		appendTerm(&y, coef, exp);
	}

	z.head=addpoly(&x, &y);
	print(&z);

}
