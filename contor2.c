#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int i = 0;
char c = 0;
int stop = 0;
HANDLE thread = NULL;

DWORD WINAPI incrementeaza_contor(LPVOID unused) {
   while( ! stop) {
          printf("%4d", i++);
          Sleep(100);
   }
}

int main() {
   printf("\nla apasarea tastei S contorul sa inceapa numararea, de la ultima valoare afisata;");
   printf("\nla apasarea tastei E sa se iasa din program.");
   printf("\nTastati caracterul:");

   while(c != 'E'){ 
          c = getchar();
          switch(c) {
                 case 'S': 
                        thread = CreateThread(NULL, 0, incrementeaza_contor, NULL, 0,  NULL);
                        break;
                 case 'E':
                        stop = 1;
                        break;
          }
   }

   WaitForSingleObject(thread, INFINITE);
   return 0;
}
