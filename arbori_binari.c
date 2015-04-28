#include <stdio.h>
#include <stdlib.h>
typedef struct arbore{
    int inf;
    struct arbore *st,*dr;
}arb;
arb *creare(){
    arb *a;
    char r;
    printf("\n Nod NULL?(D?N");
    r = getch();
    if(r=='n'||r=='N'){
            a = (arb*)malloc(sizeof(arb));
            printf("info:");
            scanf("%d",&a->inf);
            printf("\nCiteste stinga lui %d",a->inf);
            a->st = creare();
            printf("\nCiteste dreapta lui %d",a->inf);
            a->dr = creare();
            return a;
    }else{
        return NULL;
    }
}
void RSD(arb *a){
    if(a){
        printf("%d ",a->inf);
        RSD(a->st);
        RSD(a->dr);
    }
}
void SRD(arb *a){
    if(a){
        RSD(a->st);
        printf("%d ",a->inf);
        RSD(a->dr);
    }
}
void SDR(arb *a){
    if(a){
        RSD(a->st);
        RSD(a->dr);
        printf("%d ",a->inf);
    }
}
int mian(){
    arb *a;

    a = creare();
    printf("\nRSD:");RSD(a);
    printf("\nSRD:");SRD(a);
    printf("\nSDR:");SDR(a);

    return 0;
}
