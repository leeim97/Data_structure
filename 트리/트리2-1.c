# include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

typedef struct treeNode {
	int id;
	int data;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* find(treeNode* s, int id) {
	treeNode* p;
	if (s != NULL) {
		if (s->id == id) return s;
		p = find(s->left, id);
		if (p != NULL) return p;
		p = find(s->right, id);
		if (p != NULL) return p;
	}
	return NULL;
}

void visit(treeNode* s) {
	printf(" %d", s->data);
}

void pre(treeNode* s) {
	if (s != NULL) {
		visit(s);
		pre(s->left);
		pre(s->right);
	}
}

void inorder(treeNode* s) {
	if (s != NULL) {
		inorder(s->left);
		visit(s);
		inorder(s->right);
	}
}

void post(treeNode* s) {
	if (s != NULL) {
		post(s->left);
		post(s->right);
		visit(s);
	}
}
treeNode* insert(int id, treeNode* left, int data, treeNode* right) {
	treeNode* p = (treeNode*)malloc(sizeof(treeNode) * 1);

	p->id = id;
	p->left = left;
	p->data = data;
	p->right = right;
	return p;
}

treeNode* buildtree() {
	treeNode* n8 = insert(8, NULL, 80, NULL);
	treeNode* n7 = insert(7, NULL, 130, NULL);

	treeNode* n6 = insert(6, n7, 120, n8);
	treeNode* n5 = insert(5, NULL, 90, NULL);
	treeNode* n4 = insert(4, NULL, 70, NULL);

	treeNode* n2 = insert(2, n4, 30, n5);
	treeNode* n3 = insert(3, NULL, 50, n6);

	treeNode* n1 = insert(1, n2, 20, n3);

	return n1;
}

int main() {
	int num;
	int id;
	treeNode* root;
	root = (treeNode*)malloc(sizeof(treeNode));
	root = buildtree();
	treeNode* sub;
	sub = (treeNode*)malloc(sizeof(treeNode));

	scanf("%d %d", &num, &id);
	sub = find(root, id);
	if (sub == NULL) {
		printf("-1");
		exit(1);
	}


	if (num == 1) {
		pre(sub);
	}
	else if (num == 2) {
		inorder(sub);
	}
	else if (num == 3) {
		post(sub);
	}

	free(root);
	free(sub);
}