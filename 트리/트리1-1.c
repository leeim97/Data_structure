# include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000

typedef struct trnode {
	struct trnode* left;
	struct trnode* right;
	int data;
}trnode;

void init(trnode* p) {
	p = NULL;
}


void make(trnode* p, int data, trnode* le, trnode* ri) {
	init(p);

	p->data = data;
	p->left = le;
	p->right = ri;

}
void print(int n, trnode* p) {
	if (n > 8 || n <= 0) {
		printf("-1");
		return;
	}
	if (p != NULL) {
		printf(" %d", p->data);
		if (p->left != NULL)
			printf(" %d", p->left->data);
		if (p->right != NULL) {
			printf(" %d", p->right->data);
		}
		printf("\n");
	}
	else {
		printf("-1");
		return;
	}
	return;
}

int main() {
	int num;
	trnode* F1 = (trnode*)malloc(sizeof(trnode));
	trnode* F2 = (trnode*)malloc(sizeof(trnode));
	trnode* F3 = (trnode*)malloc(sizeof(trnode));
	trnode* F4 = (trnode*)malloc(sizeof(trnode));
	trnode* F5 = (trnode*)malloc(sizeof(trnode));
	trnode* F6 = (trnode*)malloc(sizeof(trnode));
	trnode* F7 = (trnode*)malloc(sizeof(trnode));
	trnode* F8 = (trnode*)malloc(sizeof(trnode));
	make(F8, 80, NULL, NULL);
	make(F7, 130, NULL, NULL);
	make(F6, 120, F7, F8);
	make(F5, 90, NULL, NULL);
	make(F4, 70, NULL, NULL);
	make(F3, 50, NULL, F6);
	make(F2, 30, F4, F5);
	make(F1, 20, F2, F3);

	scanf("%d", &num);
	trnode* arr[8] = { F1,F2,F3,F4,F5,F6,F7,F8 };
	print(num, arr[num - 1]);

}
