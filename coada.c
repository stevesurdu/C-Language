#include <stdio.h>
#include <stdlib.h>

typedef struct coada{
    int inf;
    struct coada *urm;
}coada;

int n;

coada *creare(int n){
    coada *prim,*ultim,*p;
    int i;
    prim = ultim = NULL;
    for(i=1;i<=n;i++){
        p =(coada*)malloc(sizeof(coada));
        printf("info: ");
        scanf("%d",&p->inf);
        p->urm = NULL;
        if(prim == NULL){
            prim =p;
            ultim = p;
        }else{
            ultim->urm = p;
            ultim = p;
        }
    }
    return prim;
}
void afisare(coada *st){
    coada *p = st;
    printf("\n");
    while(p!=NULL){
        printf("%d -> ",p->inf);
        p = p->urm;
    }
    printf("NULL");
}
coada *pop(coada *c){
    coada *s;
    if(c == NULL)
        printf("\n Coada este vida");
    else{
        s = c;
        c = c -> urm;
    }
    n--;
    return c;
    free(s);
}
coada *push(coada *c, int x){
    coada *p=c,*nou;
    nou = (coada*) malloc(sizeof(coada));

    nou -> inf = x;
    while(p->urm!=NULL)
        p = p->urm;
    if(p)
        p->urm = nou;
    nou->urm = NULL;
    n++;
    return c;
}
int main(){
    coada *c;
    printf("n=");
    scanf("%d",&n);

    c = creare(n);
    afisare(c);

    c = push(c,111);
    afisare(c);

    c = pop(c);
    afisare(c);

    return 0;
}
