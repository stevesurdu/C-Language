#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
    int inf;
    struct lista *urm;
}lista;

lista *q,*p;

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

lista *creare_for(int n){
    lista *p,*q;
    int i;
    q=NULL;

    for(i=1;i<=n;i++){
        p = (lista *)malloc(sizeof(lista));
        printf("info:");scanf("%d",&p->inf);
        p->urm = q;
        q = p;
    }
    return q;
}

void afisare(lista *q){
    lista *p = q;
    while(p!=NULL){
        printf("%d -> ",p->inf);
        p = p->urm;
    }
    printf("NULL");
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
int min(lista *q){
    lista *p = q->urm;
    int min=p->inf;
    while(p!=NULL){
        if (p->inf < min)
            min = p->inf;
        p = p->urm;
    }
    return min;
}
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
void pow_l(lista *q){
    lista *p;
    int k=1;
    p = q;
    while(p!=NULL){
        if(p->inf <0){

            q = delete(q,k);
        }else{
            p = p->urm;
            k++;
        }
    }
    afisare(q);
}
void delete_neg(lista *q){
    lista *p;
    int k=1;
    p = q;
    while(p!=NULL){
        q = delete(q,k+1,p->inf*p->inf);
        p = p->urm->urm;
        k+=2;
    }
    afisare(q);
}

int main(){
    int k;

    q = creare();
    //q = creare_for(3);
    afisare(q);
    //q = insert(q,1,999);
    //afisare(q);
    //delete(q,1);
    /**
    printf("\nmax: %d",max(q));
    printf("\nmin: %d",min(q));
    printf("\ndati pozitia dorita:");scanf("%d",&k);
    insert(q,k,min(q)+max(q));
    afisare(q);
    **/

    pow_l(q);


    return 0;
}
