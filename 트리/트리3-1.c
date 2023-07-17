# include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

typedef struct treenode {
	struct treenode* left;
	int data;
	struct treenode* right;

}treenode;
treenode* getnode() {
	treenode* newtreenode = NULL;
	newtreenode = (treenode*)malloc(1 * sizeof(treenode));
	newtreenode->left = NULL;
	newtreenode->right = NULL;
	return newtreenode;
}

void init(treenode* root, int id, int left, int right) {
	root->data = id;
	root->left = getnode();
	root->right = getnode();
	root->left->data = left;
	root->right->data = right;
}

void visit(treenode* root, char* p) {
	treenode* s = root;
	printf("%d ", s->data);
	for (int i = 0; i < strlen(p); i++) {
		if (p[i] == 'R') {
			s = s->right;
			printf("%d ", s->data);
		}
		else if (p[i] == 'L') {
			s = s->left;
			printf("%d ", s->data);
		}
		else
			continue;

	}
	return;
}



treenode* findId(treenode* s, int id) {
	treenode* p;
	if (s != NULL) {
		if (s->data == id)
			return s;
		p = findId(s->left, id);
		if (p != NULL)return p;
		p = findId(s->right, id);
		if (p != NULL)return p;
	}
	return NULL;
}

void build(treenode* root, int id, int left, int right) {
	treenode* p;
	p = findId(root, id);
	if (p == NULL) {
		printf("NONE");
	}
	else {
		p->data = id;
		if (left != 0) {
			p->left = getnode();
			p->left->data = left;
		}
		if (left == 0)
			p->left = NULL;
		if (right != 0) {
			p->right = getnode();
			p->right->data = right;
		}
		if (right == 0)
			p->right = NULL;
	}
}

int main() {
	int num, count;
	int data, LData, RData;
	char dir[101] = { 0 };
	treenode* root = NULL;
	root = (treenode*)malloc(sizeof(treenode));

	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d %d", &data, &LData, &RData);
		if (i == 0) {
			init(root, data, LData, RData);
		}
		else
			build(root, data, LData, RData);


	}

	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		scanf("%s", &dir);
		getchar();
		visit(root, dir);
		printf("\n");
	}

}