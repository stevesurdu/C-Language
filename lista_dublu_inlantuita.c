#include <stdio.h>
#include <stdlib.h>

typedef struct listad{
    int inf;
    struct listad *next,*prev;
}listad;

int n;

listad *creare(){
    listad *p,*q;
    int x;
    q = NULL;
    printf("info:");
    scanf("%d",&x);
    n = 0;
    while(x!=0){
        p = (listad*) malloc(sizeof(listad));
        p->inf = x;
        p->next = q;
        p->prev = NULL;
        if(q) q->prev = p;
        q = p;
        printf("info:");
        scanf("%d",&x);
        n++;
     }
    return q;
}
void afisareSD(listad *q){
    listad *p = q;
    printf("\nAfisarea SD\n");
    while(p){
        printf("%d<=>",p->inf);
        p = p->next;
    }
}
void afisareDS(listad *q){
    listad *p = q;
    while(p->next)
        p = p->next;
    printf("\nAfisarea DS\n");
    while(p){
        printf("%d<=>",p->inf);
        p = p->prev;
    }
}
int main(){
    listad *q;
    q = creare();
    afisareSD(q);
    afisareDS(q);
    printf("\nLungimea listei:%d",n);

    return 0;
}
