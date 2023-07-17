# include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

int size = 0;

typedef struct treeNode {
	int id;
	int data;
	struct treeNode* left;
	struct treeNode* right;
	//struct treeNode* parent;
}treeNode;

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
void visit(treeNode* s) {
	printf(" %d", s->data);
}
void sum(treeNode* s) {
	size += s->data;
}

void preordertraversal(treeNode* s) {

	if (s != NULL) {
		sum(s);
		preordertraversal(s->left);
		preordertraversal(s->right);
	}

}

void inordertraversal(treeNode* s) {

	if (s != NULL) {
		inordertraversal(s->left);
		visit(s);
		inordertraversal(s->right);
	}
}

void postordertraversal(treeNode* s) {

	if (s != NULL) {
		postordertraversal(s->left);
		postordertraversal(s->right);
		visit(s);
	}

}
treeNode* findId(treeNode* s, int id) {
	treeNode* p;

	if (s != NULL) {
		if (s->id == id)
			return s;
		p = findId(s->left, id);
		if (p != NULL) return p;
		p = findId(s->right, id);
		if (p != NULL) return p;
	}

	return NULL;
}
int main() {
	treeNode* root = buildtree();
	treeNode* subroot;
	//subroot = (treeNode*)malloc(sizeof(treeNode));
	int select;
	int id;

	scanf("%d", &id);

	subroot = findId(root, id);

	if (subroot == NULL) {
		printf("-1");
		exit(1);
	}

	preordertraversal(subroot);
	printf("%d", size);


}