#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int inf;
    struct lista *urm;
}lista;

lista *q;

lista *insert(lista *q,int poz,int x){
    lista *p,*nou;
    int i;

    nou = (lista *)malloc(sizeof(lista));
    nou->inf = x;

    if (poz==1){
        nou->urm = q;
        q = nou;
    }else{
        p = q;
        for(i=1;i<poz-1;i++)
            p = p->urm;
        nou->urm = p->urm;
        p->urm = nou;
    }
    return q;
}

void afisare(lista *q){
    lista *p = q;
    printf("\n");
    for(p=q;p!=NULL;p=p->urm)
        printf("%d -> ",p->inf);
    printf("NULL");
}

lista *creare(){
    int x,n,i;
    printf("Dati nrumarul de elemente: ");scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Dati valoarea: ");scanf("%d",&x);
        q = insert(q,i,x);
    }
    return q;
}

lista *delete(lista *q,int poz){
    lista *s,*p;
    int i;

    if(poz==1){
        s = q;
        q = q->urm;
        free(s);
    }else{
        p = q;
        for(i = 1;i < poz-1; i++)
            p = p->urm;
        s = p->urm;
        p->urm = s->urm;
        free(s);
    }
    return q;
}
int main(){

    q = creare();

    afisare(q);

    q = delete(q,1);
    afisare(q);

    q = insert(q,1,1);
    afisare(q);

    return 0;
}
