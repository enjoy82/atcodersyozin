
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

int counting(node* search){
    int  repeat = 1;
    if(search->element == NULL){
      search = search->next;
    }
    char tmp = search->element;
    for(; search->next != NULL;){
      if(tmp == search->next->element){
        repeat += 1;
        search = search->next;
      }else{
         break;
      }
     }
     return repeat;
}

int include(char ctmp[],int num,node* search){
    for(int i = num-2;i>=0;i--){
      if(ctmp[i] == search->element){
        return i;
      }
    }
    return -1;
}

int deleteint(int num,char ctmp[],node *start,node*search,int include){
    int countadd = 0;
    node * xsearch,*xstart;
    xsearch = (node*) malloc(sizeof(node));
    xstart = (node*) malloc(sizeof(node));
    xsearch = start->next;    xstart = start;
    if(include == -1){
      for(int t = counting(xstart->next);counting(xstart->next) != 1;t = counting(xstart->next)){
         for(int x = 0;x< t;x++){
           xstart = xstart->next;
          }
          if(t != 1){
            countadd = countadd + t;
           }
        
      }
      return countadd;

    }else{
      for(int j = 0;j != include ;j++){
         int t = counting(xstart->next);
         for(int x = 0;x< t;x++){
           xstart = xstart->next;
          }
         /*if(j+1 != include){                                                                                                         
           xstart = xstart->next;                                                                                                      
          }*/
       }
       xsearch = xstart->next;
      for(int y = include; y != num -1;y++){
        int h = counting(xsearch);
         for(int z = 0;z< h;z++){
           xsearch = xsearch->next;
          }
        countadd = countadd + h;
       }
       if(search->next != NULL ){
       countadd = countadd +1;
       }
      return countadd;
    }

}

int findMaxRemoval(node *head){

    // add your code here                                                                                                              
    int count = 0, num = 0,end = 0;
    char ctmp[50];
    if(head->next == NULL){return 0;}
    node * search, *start;
    search = (node*) malloc(sizeof(node));
    start = (node*) malloc(sizeof(node));
    start = head; search = head->next;
    for(;start->next != NULL;){
       ctmp[num++] = search->element;
       if(counting(search) == 1){  //rennzoku sinai toki                                                                               
         if(include(ctmp,num,search) == -1){
           count = count + deleteint(num,ctmp,start,search,include(ctmp,num,search));
           start->next = search;

           if(search->next !=NULL){
             start = start->next; search = search->next;  //henkou?                                                                    
            }else{
              start = search;
            }
           for(int i = num-1;i>=0;i--){
             ctmp[i] = NULL;
            }
            num = 0;

         }else{
           count = count + deleteint(num,ctmp,start,search,include(ctmp,num,search));
           if(search->next !=NULL){
              search = search->next;
              start->next = search;
            }

           /*for(int i = num-1;i>=include(ctmp,num,search);i--){                                                                       
             ctmp[i] = NULL;                                                                                                           
            }*/
            for(int i = num-1;i>=0;i--){
             ctmp[i] = NULL;
            }
            num = 0;
            //num = include(ctmp,num,search);                                                                                          

         }
       }else{ //renzoku                                                                                                                
          end = 1;
         int t = counting(search);
         for(int j = 0;j< t;j++){
          if(search->next == NULL){
           count = count + counting(start->next);
            start->next = NULL;
          }else{
             search = search->next;
           }
          }

       }
   }

   if( end == 0 ){
      return count;
    }else{
      count = count + findMaxRemoval(head);
      return count;
    }

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
