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
listad *inserare(listad *q,int poz,int x){
    listad *p, *nou;
    int i;

    nou = (listad*) malloc(sizeof(listad));
    nou->inf = x;

    if(poz==1){
        nou->prev =NULL;
        nou->next = q;
        if(q) q->prev = nou;
        q=nou;
    }else{
        p = q;
        for(i=1;i<poz-1;i++)
            p = p->next;
        p->next->prev = nou;
        nou->next = p->next;
        p->next = nou;
        nou->prev = p;
    }
    n++;
    return q;
}
/*listad *stergere(){
    listad *p = q;

    s = p->next;
    p->next = s->next;
    s->next->prev = p;

    free(s);

    return q;
}*/
int main(){
    listad *q;
    q = creare();
    afisareSD(q);
    afisareDS(q);
    printf("\nLungimea listei:%d",n);

    q = inserare(q,3,100);
    afisareSD(q);
    afisareDS(q);
    printf("\nLungimea listei:%d",n);

    return 0;
}
