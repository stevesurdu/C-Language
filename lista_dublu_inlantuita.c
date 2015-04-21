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
listad *stergere(listad *q,int poz){
    listad *p,*s;
    int i;

    if(q==NULL)printf("\nLista Vida");
    else{
        if(poz==1){
            s = q;
            q = q->next;
            if(q) q->prev =NULL;
            free(s);
        }else{
            p =q;
            for(i=1;i<poz-1;i++)
                p = p->next;
            s = p->next;
            p->next = s->next;
            s->next->prev = p;
            free(s);
        }
        n--;
    }
    return q;
}
void stergere_negative(listad *q){
    listad *p = q;
    FILE *f;
    int k=1;

    f = fopen("lista.txt","w");

    while(p){
        if(p->inf<0){
            p = p->next;
            q = stergere(q,k);
        }else{
            fprintf(f,"%d ",p->inf);
            p = p->next;
            k++;
        }
    }
}
int main(){
    listad *q;
    q = creare();
    afisareSD(q);
    printf("\nLungimea listei:%d",n);

    stergere_negative(q);
    afisareSD(q);

    return 0;
}
