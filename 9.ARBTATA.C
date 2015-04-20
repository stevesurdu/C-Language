//arbore oarecare reprezentat static prin vector de tati
//se preteaza parcurgerii in latime

#include<conio.h>
#include<stdio.h>
#define max 50

int tata[max],coada[max];
int nr,n,i,pcap,pcoada,p;

void creare(){
  do{
    printf("\nNr de noduri(n)=");scanf("%d",&nr);
  }while((nr<1)||(nr>50));
  printf("\n\tNodurile vor avea valori 1..n");
  printf("\n\tNodul radacina va avea tatal 0 !!!\n\n");
  for(i=0;i<nr;i++){
    printf("Tatal nodului %d este ",i+1);
    scanf("%d",&tata[i]);
  }
}

void adauga(int p){
     coada[pcoada]=p;
     pcoada++;
     n++;
}

void adauga_fii(int p){
     for(i=0;i<nr;i++)
       if(tata[i]==p)
	  adauga(i+1);
}

int extrag(){
     int p;
     p=coada[pcap];
     pcap++;
     n--;
     return(p);
}

void parc_latime(){
     int gasit;
     if(nr==0) printf("\nArbore vid!!");
     else{
       printf("\n");
       pcap=0;
       pcoada=0;
       n=0;
       //adaug in coada radacina
       gasit=0;
       i=0;
       while((!gasit)&&(i<nr))
	 if(tata[i]==0){
	   gasit=1;
	   adauga(i+1);
	 }
	 else i++;
       //extrage cate un element din coada si adauga fiii sai in coada
       while(n>0){//cat timp coada nu e vida
	   p=extrag();
	   printf("%d ",p);
	   adauga_fii(p);
       }
     }
}

void main(){
  clrscr();
  creare();
  printf("\nArborele parcurs pe nivel (pe latime):");
  parc_latime();
  getch();
}
