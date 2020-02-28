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
	if(list == NULL){
		return 0;
	}else if(list->next == NULL){
		return 1;
	}
	while(list->next != NULL){
		list = list->next;
		c++;
	}
	return c+1;
}


void printlist(node *l) {
    while(l->next != NULL){
		printf("%c ", l->element);
		l = l->next;
	}
	printf("%c \n", l->element);
}

node* copylist(node *head){
	node * h = initList();
    node * n = h;
	while (head != NULL) {
        n->next = newNode(head->element);
        n = n->next;
		head = head->next;
    }
	h = h->next;
//	printlist(h);
    return h;
}


int ans = 0;
int listsum = 0;
int saiki = 0;

int findMaxRemoval(node *head, int ct, int dele){
//	printf("ans is %d, dele is %d, ct is %d\n", ans, dele, ct);
//	printlist(head);
	saiki++;
	if(counter(head) < ct){
		if(dele > ans){
			ans = dele;
		}
		return 0;
	}
	node *b = head;
	//saiki list
	node *d = copylist(head);
	node *c = d;
	node *e = d;
	for(int i = 0; i< ct; i++){
		b = b->next;
	}
	for(int l = 0; l <ct-1;l++){
		e = e->next;
	}
	int countnext = 1;
	if(b->next == NULL){
		if(dele> ans){
				ans = dele;
			}
			return 0;
	}
	while(b->element == b->next->element){
		b = b->next;
		countnext++;
		if(b->next == NULL){
			if(dele+countnext > ans){
				ans = dele+countnext;
			}
			return 0;
		}
	}
	findMaxRemoval(head, countnext+ct, dele);
	if(countnext == 1){
		return 0;
	}
	if(ct == 0){
		for(int i=0; i<countnext; i++){
			c = c->next;
		}
		d = c;
	}else{
		for(int l = 0;l<countnext;l++){
				if(e->next->next == NULL){
					e->next = NULL;
					break;
				}
			e->next = e->next->next;
		}
	}
//	printlist(d);
	findMaxRemoval(d, 0, dele+countnext);
	return 0;
}

int main(int argc, char *argv[]){
    if (argc<2)
        exit(-1);
    node *head = buildList(argv[1]);
	head = head->next;
	listsum = counter(head);
    findMaxRemoval(head, 0, 0);
    printf("%d\n",ans);
    freeList(head);
    return 0;
}
