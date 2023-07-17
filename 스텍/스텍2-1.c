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

int isEmpty(stack* s) {
	return (s->top == NULL);
}
void emptyStackException() {
	printf("stackExecption");
}

node* getNode() {
	node* p = (node*)malloc(sizeof(node));
	p->ele = -1;
	p->next = NULL;
	return p;
}
void push(stack* s, char e) {

	node* p = getNode();
	p->ele = e;
	p->next = s->top;
	s->top = p;
	return;
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

int isOperand(char e) {
	if (('a' <= e && 'z' >= e) || ('A' <= e && 'Z' >= e)) {
		return 1;
	}

	return 0;
}
int prior(char ele, int dan) {
	char arr[9] = { '*','/','+','-','<','>','&','|' ,'(' };
	int prior[10] = { 5,5,4,4,3,3,2,1,0 };
	if (dan == 1) {
		return 6;
	}
	else {
		for (int i = 0; i < 9; i++) {
			if (arr[i] == ele)
				return prior[i];
		}
	}
}
int check(char ele) {
	char arr[8] = { '*','/','+','-','<','>' };
	for (int i = 0; i < 6; i++) {
		if (ele == arr[i])
			return 1;
	}
	return 0;
}
void write(char ele) {
	printf("%c", ele);
}
void convert(char* arr) {
	stack* s = (stack*)malloc(sizeof(stack));
	init(s);
	int size = strlen(arr);
	int index = 0; int tmp;
	char ele;
	int dan = 0; //dan이 1이면 단항연산자

	while (size != index) {
		tmp = index;
		ele = arr[index];
		if (index == 0) {
			if (arr[index] == '!' || arr[index] == '+' || arr[index] == '-') {
				push(s, arr[index]);
				index++;
				continue;
			}

		}
		if (isOperand(ele)) {
			write(ele);
		}
		else if (ele == '(') {
			push(s, ele);
		}
		else if (ele == ')') {
			while ((s->top->ele) != '(') {
				write(pop(s));
				tmp--;
			}
			pop(s);
		}
		else {
			if (check(arr[index - 1])) {
				dan = 1;
			}

			while (!isEmpty(s) && (prior(arr[index], dan) <= prior(s->top->ele, 0)))
			{

				write(pop(s));
			}
			if (arr[index] == '&' || arr[index] == '|') {
				push(s, arr[index]);
				index++;
			}

			push(s, arr[index]);

		}
		index++;
		dan = 0;
	}

	while (!isEmpty(s)) {
		write(pop(s));
	}
	return;

}

int main() {
	int num;
	char arr[100];

	scanf("%d", &num);
	getchar();

	for (int i = 0; i < num; i++) {
		gets(arr);
		convert(arr);
		printf("\n");


	}


}
