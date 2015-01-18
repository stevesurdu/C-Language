/*
    Author: Igor Voloc
    Grupa:10202
    IxE: Code::Blocks IxE
    Compiler: GNU GCC Compiler
    OS: Ubuntu 14.04 LTS
*/
#include <stdio.h>
#include <string.h>

int n, result;
char s;

int prime(int a)
{
   int c;
   for ( c = 2 ; c <= a - 1 ; c++ )
   {
      if ( a%c == 0 )
	 return 0;
   }
   if ( c == a )
      return 1;
}

int main()
{
    do{
        printf("\nDati numarul:");
        scanf("%d",&n);

        if(prime(n) == 1){
            printf("%d este prim.\n", n);
        }else{
            printf("%d nu este prim.\n", n);
        }

        printf("Pentru a orpi verificarea tastati N");
        s = getchar();
    }while(s!='N');

   return 0;
}
