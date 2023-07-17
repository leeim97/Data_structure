# include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS


typedef struct stack {

	int max;
	char* arr;
	int top;

}stack;

void init(stack* s, int size) {
	s->arr = NULL;
	s->arr = (char*)malloc(size * sizeof(char));

	s->max = size;
	s->top = -1;
}
int isEmpty(stack* s) {

	return(s->top == -1);
}
void stackEmpty() {
	printf("Stack Empty\n");
}
int isFull(stack* s) {

	return(s->top == (s->max) - 1);
}
void stackFull() {
	printf("Stack FULL\n");
}
void push(stack* s, char ele) {
	if (isFull(s)) {
		stackFull();
		return;
	}
	s->top++;
	s->arr[s->top] = ele;
}
char pop(stack* s) {
	if (isEmpty(s)) {
		stackEmpty();
		return 0;
	}
	char ele;
	ele = s->arr[s->top];

	s->top -= 1;
	return ele;
}

void peek(stack* s) {
	if (isEmpty(s)) {
		stackEmpty();
		return;
	}
	printf("%c\n", s->arr[s->top]);
}

void duplicate(stack* s) {
	if (s->top > s->max - 2) {
		stackFull();
	}
	char ele;
	ele = pop(s);
	push(s, ele);

	push(s, ele);
}
void downRotate(stack* s, int n) {
	if (n <= s->top + 1) {
		int idx = (s->top) - n + 1;

		char d = s->arr[idx];

		for (int i = idx; i < s->top; i++) {
			s->arr[i] = s->arr[i + 1];
		}

		s->arr[s->top] = d;
	}
}
void upRotate(stack* s, int n) {

	if (n <= s->top + 1) {
		int idx = (s->top) - n + 1;

		char d = s->arr[s->top];

		for (int i = s->top; i > idx; i--) {
			s->arr[i] = s->arr[i - 1];
		}

		s->arr[idx] = d;
	}
}
void print(stack* s) {

	for (int i = s->top; i >= 0; i--) {
		printf("%c", s->arr[i]);

	}
	printf("\n");
}

int main() {
	int s_size, num, cnt;
	char ele;
	char tmp[10];

	stack* s = (stack*)malloc(sizeof(stack));
	scanf("%d", &s_size);

	init(s, s_size);

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%s", &tmp);



		if (strcmp(tmp, "POP") == 0) {
			pop(s);
		}
		else if (strcmp(tmp, "PUSH") == 0) {
			getchar();
			scanf(" %c", &ele);
			getchar();
			push(s, ele);
		}
		else if (strcmp(tmp, "PEEK") == 0) {
			peek(s);
		}
		else if (strcmp(tmp, "DUP") == 0) {

			duplicate(s);
		}
		else if (strcmp(tmp, "UpR") == 0) {
			scanf(" %d", &cnt);
			getchar();
			upRotate(s, cnt);
		}
		else if (strcmp(tmp, "DownR") == 0) {
			scanf(" %d", &cnt);
			getchar();
			downRotate(s, cnt);
		}
		else if (strcmp(tmp, "PRINT") == 0) {
			print(s);
		}

	}



}
