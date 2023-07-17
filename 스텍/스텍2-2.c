# include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000

typedef struct node {
	struct node* next;
	char ele;
}node;

typedef struct stack {
	node* top;

}stack;

void init(stack* s) {
	s->top = NULL;
	return;
}

node* getNode() {
	node* p = (node*)malloc(sizeof(node));
	p->next = NULL;
	p->ele = -1;
	return p;
}
void push(stack* s, char ele) {
	node* p;
	p = getNode();
	p->ele = ele;
	p->next = s->top;
	s->top = p;
	return;
}
int isEmpty(stack* s) {
	return(s->top == NULL);

}
void emptyStackException() {
	printf("EmptyStackException");
}
void putNode(node* p) {
	free(p);
	p = NULL;
}
char pop(stack* s) {
	if (isEmpty(s)) {
		emptyStackException();
		return -1;
	}

	char ele;
	ele = s->top->ele;
	node* p = s->top;
	s->top = s->top->next;
	putNode(p);
	return ele;
}
int operate(char a, int x, int y) {
	int op;
	int b, s;
	x > y ? (b = x, s = y) : (s = x, b = y);
	switch (a) {
	case '+':op = b + s; break;
	case '-':op = b - s; break;
	case '/':op = b / s; break;
	case '*':op = b * s; break;

	}
	return op;
}
int isOperand(char ele) {
	if (ele >= '0' && ele <= '9')
		return 1;
	else
		return 0;
}

void evaluate(char* arr) {
	int size = strlen(arr);
	int index = 0, x = 0, y = 0;
	stack* s = (stack*)malloc(sizeof(stack));
	init(s);
	char ele;
	char tmp;
	while (size != index) {
		ele = arr[index];
		if (isOperand(ele)) {
			push(s, ele);
		}
		else {
			x = (int)(pop(s) - '0');
			y = (int)(pop(s) - '0');
			tmp = (char)(operate(ele, x, y) + '0');
			push(s, tmp);
		}
		index++;
	}
	printf("%d", (pop(s) - '0'));
	return;
}
int main() {
	int num;
	char arr[100];
	scanf("%d", &num);


	for (int i = 0; i < num; i++) {
		gets(arr);
		getchar();
		evaluate(arr);
		printf("\n");
	}

}