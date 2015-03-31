#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct lista{
    char inf;
    struct lista *urm;
}lista;

lista *q;

lista *insert(lista *q,int poz,char x){
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
        printf("%c -> ",p->inf);
    printf("NULL");
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
void delete_c(){
    lista *p = q;
    int i;
    char x,y,z;

    printf("\nIntroduceti caracterele care doriti sa fie sterse: ");
    x = getche();
    printf("\t");
    y = getche();
    printf("\t");
    z = getche();

    i=1;
    for(p=q;p!=NULL;p=p->urm){
        if(p->inf == x){
            q = delete(q,i);
            i--;
        }
        if(p->inf == y){
            q = delete(q,i);
            i--;
        }
        if(p->inf == z){
            q = delete(q,i);
            i--;
        }
        i++;
    }
}
int count_c(){
    int k=0;
    lista *p = q;
    for(p=q;p!=NULL;p=p->urm)
        if(p->inf >'c' && p->inf < 's')
            k++;

    return k;
}
int main(){
    int n,i;
    char x;
    printf("Dati numarul de elemente: ");scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf(" info:");
        x = getche();
        q = insert(q,i,x);
    }
    afisare(q);

    printf("\n");
    q = insert(q,n+1,'Z');
    afisare(q);

    printf("\nNumarul de caractere intre c si s: %d",count_c());

    printf("\n");
    delete_c();
    afisare(q);


    return 0;
}
