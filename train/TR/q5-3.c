#include <stdio.h>
#include <stdlib.h>

struct node{
    char element;
    struct node *next;
};
typedef struct node *nodep;
struct node *initlist() {
    struct node *n;
    n = (nodep)malloc(sizeof(struct node));
    n->next = NULL;
    return n;
}

void insert(struct node *p, char x) {
    struct node *n, *e;
    n = (nodep)malloc(sizeof(struct node));
    e = (nodep)malloc(sizeof(struct node));
    e = p;
    while(e->next != NULL){e = e->next;}
    n->element = x;
    e->next = n;
}

void printlist(struct node *p) {
    p = p->next;
    while (p) {
        putchar(p->element);
        p = p->next;
    }
    putchar('\n');
}

void remove_1st(struct node *p) {
    char ans = p->next->element;\
    p->next=p->next->next;
    while(p->next != NULL){
	while(ans == p->next->element){
		if(p->next->next != NULL){
			p->next = p->next->next;
		}else{
			p->next = NULL;
		}
	}
	p = p->next;
    }
}

int main(int argc, char *argv[]) {
    struct node *list, *head;
    char *p;

    if (argc<2)
        exit(-1);

    list = initlist();
    p = argv[1];
    for (; *p; p++)
        insert(list, *p);

    remove_1st(list);
    printlist(list);

    for (; list; ) {
        head = list;
        list = list->next;
        free(head);
    }
    return 0;
}

