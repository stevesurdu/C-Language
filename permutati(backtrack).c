#include <stdio.h>

int st[20],n,i,k=1,as,ev;

void init(int st[],int k){
    st[k] = 0;
}

int succesor(int st[],int k){
    as = 0;
    if(st[k] < n){
        as = 1;
        st[k]++;
    }
    return as;
}
int valid(int st[],int k){
    ev = 1;
    for(i=1;i<k;i++){
        if(st[i]==st[k])
            ev = 0;
    }
    return ev;
}
int sol_finala(){
    return k==n;
}
void afisare(int st[]){
    for(k=1;k<=n;k++)
        printf("%i ",st[k]);
    printf("\n");
}
int main(){
    printf("Dati n:");
    scanf("%i",&n);

    init(st,k);
    while(k>0){
        do{
            as = succesor(st,k);
            if(as) valid(st,k);
        }
        while(as && !ev);
        if(as)
            if(sol_finala())
                afisare(st);
            else{
                k++;
                init(st,k);
            }
         else k--;
        }
    return 0;
}
