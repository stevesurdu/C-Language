#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct arbore{
    int inf;
    struct arbore *st,*dr;
}arb;
int s=0,k=0,h=0,max = INT_MIN;
arb *creare(){
    arb *a;
    char r;
    printf("\n Nod NULL?(D?N)");
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
int suma(arb *a){
    if(a){
        s+=a->inf;
        s=suma(a->st);
        s=suma(a->dr);
    }
    return s;
}
int maxim(arb *a){
    if(a){
        if(a->inf>max)max=a->inf;
        max=maxim(a->st);
        max=maxim(a->dr);
    }
    return max;
}
int frunze(arb *a){
    if(a){
        if(a->st==NULL && a->dr==NULL) k++;
        k=frunze(a->st);
        k=frunze(a->dr);
    }
    return k;
}
int inaltime(arb *a){
    int hs,hd;
    if(a){
        hs = inaltime(a->st);
        hs = inaltime(a->st);
        if(hs>hd) return hs+=1;
        else return hd+=1;
    }else{
        return 0;
    }
}
int main(){
    arb *a;

    a = creare();
    printf("\nRSD:");RSD(a);
    printf("\nSRD:");SRD(a);
    printf("\nSDR:");SDR(a);

    printf("\nSuma:%d",suma(a));
    printf("\nMaxim:%d",maxim(a));
    printf("\nNr frunze:%d",frunze(a));
    printf("\nInaltimea:%d",inaltime(a));

    return 0;
}
