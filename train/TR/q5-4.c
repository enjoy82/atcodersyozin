#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 80

typedef char *elementtype;

struct node {
    elementtype element;
    struct node *next;
};

typedef struct node *link;
typedef link list;
typedef link position;


list initlist(void) {
    list l;
    l = (link)malloc(sizeof(struct node));
    l->next = NULL;
    return l;
}

position first(list l) {
    return l;
}

position next(list l, position p) {
    return p->next;
}

position end(list l) {
	while(l->next != NULL){l = l->next;}
	return l;
}

elementtype retrieve(list l, position p) {
	return p->element;
}

position find(list l, elementtype e) {
    if(l->next != NULL && strcmp(l->next->element, e) > 0){return l;}
    else{
	while(l->next != NULL && strcmp(l->next->element, e) < 0){
		l = l->next;
        }
	return l;
    }
}

void insert(list l, position p, elementtype e) {
    position new;
    new = (position)malloc(sizeof(struct node));
    new->element = (char *)malloc(sizeof(char)*100);
    strcpy(new->element, e);
    position q;q = p->next;
    p->next = new;p->next->next = q;
}

void printlist(list l) {
    position p;
    p = next(l,l);
    while (p) {
        printf("%s", (retrieve(l,p)));
        p = next(l,p);
    }
}

int main(void) {
    list university;
    position p, tmp;

    university = initlist();
    while(1) {
        char buf[MAXLENGTH+2];
        fgets(buf, sizeof(buf), stdin);
        if(buf[0] == '.') {
            break;
        }
        p = find(university, buf);
        insert(university, p, buf);
    }
    printlist(university);

    for (p=first(university); p; p=next(university,p)) {
        tmp = p;
        free(tmp);
    }
    return 0;
}


