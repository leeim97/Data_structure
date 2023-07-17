# include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000
int front = 0;
int rear = 0;
void print(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");
}

void ins(int* arr, int value, int size) {
	if ((front % size) == ((rear + 1) % size)) {
		printf("overflow ");
		print(arr, size);
		exit(1);
	}

	rear++;
	arr[rear % size] = value;
	return;



}
void del(int* arr, int size) {
	if (rear == front) {
		printf("underflow");
		exit(1);
	}

	front++;
	arr[front % size] = 0;
	return;
}

void initQue(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

int main() {

	int num, size, tmp = 0;
	char ch;
	int* p;

	scanf("%d", &size);
	getchar();

	p = (int*)malloc(size * sizeof(int));
	initQue(p, size);

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		getchar();
		scanf("%c", &ch);
		if (ch == 'I') {
			scanf("%d", &tmp);
			ins(p, tmp, size);
		}
		else if (ch == 'P') {
			print(p, size);
		}
		else if (ch == 'D') {
			del(p, size);
		}

	}

}
