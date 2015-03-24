#include <stdio.h>
#include <stdlib.h>


typedef struct stiva{
    int inf;
    struct stiva *urm;
}stiva;

stiva *st,*p;

stiva *creare(int n){
    stiva *p,*st;
    int i;
    st=NULL;

    for(i=1;i<=n;i++){
        p = (stiva *)malloc(sizeof(stiva));
        printf("inf:");scanf("%d",&p->inf);
        p->urm = st;
        st = p;
    }
    return st;
}

void afisare(stiva *st){
    stiva *p = st;
    printf("\n");
    while(p!=NULL){
        printf("%d -> ",p->inf);
        p = p->urm;
    }
    printf("NULL");
}
stiva *push(stiva *vf, int x){
    stiva *nou;
    nou = (stiva*) malloc(sizeof(stiva));

    nou -> inf = x;
    nou -> urm = vf;
    vf = nou;

    return vf;
}

stiva *pop(stiva *vf){
    stiva *s;
    if(vf == NULL)
        printf("\n Stiva este vida");
    else{
        s = vf;
        vf = vf -> urm;
    }

    return vf;
    free(s);
}

stiva *creare_push(int n){
    int i;
    st = NULL;
    srand(time(0));
    for(i=1;i<=n;i++){
        st = push(st,rand()%100);
    }
    return st;
}

int prim(int x)
{
    int pr,i;
    if(x<2)
        pr = 0;
    else{
        pr = 1;
        for(i=2;i<=x/2;i++){
            if(x%i==0)
                pr = 0;
        }
    }
    return pr;
}
void pop_prim(){

    stiva *p = st;
    while(prim(st->inf)==0){
        st = pop(st);
    }
}
int main(){
    int n;

    printf("dati n: ");scanf("%d",&n);

    st = creare_push(n);
    afisare(st);

    pop_prim();
    afisare(st);

    //printf("%d",prim(4));

    /**st = push(st,10);
    afisare(st);
    st = pop(st);
    afisare(st);
**/
    return 0;
}
