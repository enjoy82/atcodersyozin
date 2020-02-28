
#include <stdio.h>
#include <stdlib.h>

typedef char elementtype;

typedef struct _node {
    elementtype element;
    struct _node * next;
}  node;

node* initList(){
    node * n;
    n = (node*) malloc(sizeof(node));
    n->next = NULL;
    return n;
}

node* newNode(elementtype e){
    node* n = (node*)malloc(sizeof(node));
    n->element = e;
    n->next = NULL;
    return n;
}

node* buildList(char *p) {
    node * h = initList();
    node * n = h;
    while (*p) {
        n->next = newNode(*p++);
        n = n->next;
    }
    return h;
}

void freeList(node* list) {
    node *head;
    for (; list; ) {
        head = list;
        list = list->next;
        free(head);
    }
}

int counter(node *list){
	int c = 0;
	while(list->next != NULL){
		list = list->next;
		c++;
	}
	return c;
}

int findMaxRemoval(node *head){
	int count = counter(head);
	int inlist[10000] = {0};
	node *b = head;
	b = b->next;
	for(int n = 0; n<count-1 ; n++){
		while(b->next != NULL && b->element == b->next->element){
			inlist[n] = 1;
			inlist[n+1] = 1;
			n++;
			b = b->next;
		}
		b = b->next;
	}
/*	for(int l = 0; l<count; l++){
		printf("%d ", inlist[l]);
	}*/
	for(int i = 0; i<count ; i++){
		node *a = head;
		a = a->next;
		for(int l = 0; l<count; l++){
			while(inlist[l] == 1){
				a = a->next;
				l++;
			}
		}
	}
	return 5;
}

int main(int argc, char *argv[]){
    if (argc<2)
        exit(-1);
    node *head = buildList(argv[1]);
    int m = findMaxRemoval(head);
    printf("%d\n",m);
    freeList(head);
    return 0;
}

