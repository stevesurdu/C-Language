//arbore binar de cautare
#include<conio.h>
#include<stdio.h>
#include<alloc.h>

struct arb{
  int x;
  struct arb *ss,*sd;
}*a;
int x,gasit;

struct arb* adauga(struct arb* a, int x){
  if(a==NULL){
     a=(struct arb*)malloc(sizeof(struct arb));
     a->x=x;
     a->ss=NULL;
     a->sd=NULL;
  }
  else{
     if(x==a->x) printf("%d exista deja",x);
     else
       if(x<a->x) a->ss=adauga(a->ss,x);
       else a->sd=adauga(a->sd,x);
  }
  return a;
}

void creare(){
   printf("Cheile se dau in orice ordine. Se va crea un arbore binar de cautare! \nPt final se da -1");
   printf("Inf=");scanf("%d",&x);
   while(x!=-1){
      a=adauga(a,x);
      printf("Inf=");scanf("%d",&x);
   }
}

void RSD(struct arb* a){
  if(a){
     printf("%d ",a->x);
     RSD(a->ss);
     RSD(a->sd);
  }
}

void SRD(struct arb* a){
  if(a){
     SRD(a->ss);
     printf("%d ",a->x);
     SRD(a->sd);
  }
}
