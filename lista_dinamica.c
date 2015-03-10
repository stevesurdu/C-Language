#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
    int inf;
    struct lista *urm;
}lista;

lista *creare(){
    lista *p,*q;
    int x;
    q=NULL;

    printf("info:");scanf("%d",&x);

    while(x!=0){
        p = (lista *)malloc(sizeof(lista));
        p->inf = x;
        p->urm = q;
        q = p;

        printf("info:");scanf("%d",&x);
    }
    return q;
}

void afisare(lista *q){
    lista *p = q;
    while(p!=NULL){
        printf("%d -> ",p->inf);
        p = p->urm;
    }
}

void afisare_for(lista *q){
    lista *p = q;
    for(p=q;p!=NULL;p=p->urm)
        printf("%d -> ",p->inf);
}

int sum(lista *q){
    int s=0;
    lista *p = q;
    while(p!=NULL){
        s+=p->inf;
        p = p->urm;
    }
    return s;
}
int max(lista *q){
    lista *p = q->urm;
    int max=p->inf;
    while(p!=NULL){
        if (p->inf > max)
            max = p->inf;
        p = p->urm;
    }
    return max;
}
/**
nou->urm = p->urm;
p->urm = nou;


stergere
s = p->urm;
p->urm = s->urm;
free(s);
**/


int main(){
    lista *q;

    q = creare();
    afisare(q);
    printf("\nsuma: %d",sum(q));
    printf("\nmax: %d",max(q));
    return 0;
}
