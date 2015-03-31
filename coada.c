#include <stdio.h>
#include <stdlib.h>

typedef struct coada{
    int inf;
    struct coada *urm;
}coada;

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
int main(){
    coada *c;
    int n;
    printf("n=");
    scanf("%d",&n);
    c = creare(n);
    afisare(c);

    return 0;
}
