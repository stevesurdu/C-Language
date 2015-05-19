#include <stdio.h>

int st[20],n,i,j,k=1,as,ev,nr;

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
        if(st[i]==st[k] || abs(k-i) == abs(st[k]-st[i]))
            ev = 0;
    }
    return ev;
}
int sol_finala(){
    return k==n;
}
void afisare(int st[]){
    printf("<---------------------->\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            if(j==st[i])
                printf(" X ");
            else
                printf(" O ");
        printf("\n");
    }
}
int main(){
    printf("Dati n:");
    scanf("%i",&n);

    init(st,k);
    nr =0;
    while(k>0){
        do{
            as = succesor(st,k);
            if(as) valid(st,k);
        }
        while(as && !ev);
        if(as)
            if(sol_finala()){
                afisare(st);
                nr++;
            }else{
                k++;
                init(st,k);
            }
         else k--;
        }
    printf("\n %i solutii",nr);
    return 0;
}
