# include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000

typedef struct stack {
	char* arr;
	int top;

}stack;
int isEmpty(stack* s) {
	return(s->top == -1);
}
void init(stack* s, int size) {
	s->arr = (char*)malloc(size * sizeof(char));
	s->top = -1;
}
void push(stack* s, char ele) {
	s->top++;
	s->arr[s->top] = ele;
}
char pop(stack* s) {
	if (isEmpty(s)) {
		printf("stack Empty");
		return;
	}
	char ele;
	ele = s->arr[s->top];

	s->top--;

	return ele;
}
int count(stack* s, char ele) {
	int cnt = 0;
	for (int i = 0; i < strlen(s->arr); i++) {
		if (s->arr[i] == ele) {
			cnt++;
		}
	}
	return cnt;
}



int main() {
	stack* s = NULL;
	s = (stack*)malloc(sizeof(stack));

	char Y[1000];
	gets(Y);
	init(s, strlen(Y));

	for (int i = 0; i < strlen(Y); i++) {
		if (Y[i] == '(' || Y[i] == '[' || Y[i] == '{' ||
			Y[i] == ')' || Y[i] == ']' || Y[i] == '}') {
			push(s, Y[i]);
		}
		else
			continue;
	}

	int cnt;
	cnt = count(s, '(') + count(s, '{') + count(s, '[')
		+ count(s, ')') + count(s, '}') + count(s, ']');
	if (count(s, '(') == count(s, ')') && count(s, '{') == count(s, '}')
		&& count(s, '[') == count(s, ']')) {

		printf("OK_%d", cnt);
	}
	else
		printf("Wrong_%d", cnt);



}