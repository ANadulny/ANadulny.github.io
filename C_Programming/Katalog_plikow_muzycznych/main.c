#include <stdio.h>
#include <stdlib.h>
#include <string.h> //f strlen()
#define Gwiazdki "*******************************************************************************"
#include "naglowek.h"
int nr=1;         // zmienna sluzaca do iterowania utworow w bazie
//void sortujpo(struct utwor *t,int a);
#include "dodawanie.c"
#include "sortowanie.c"
#include "usuwanie.c"
#include "wczytywanie.c"
#include "edytowanie.c"
#include "zapisywanie.c"
#include "wyswietl.c"
#include "wyswietl_baze.c"
#include "nowa_baza.c"
#include "edytowanie_bitrate.c"
int main()
{
  char wybor;
  while(1)
  {
    system("clear");
    puts("\t\tProjekt 3. Zrobiony przez Adriana Nadulnego.\nPodczas zapisywania danych do bazy plikow muzycznych prosze nie uzywac polskich"
           " znakow diakrytycznych.\n\n\n");
    puts("\t\tWitam w katalogu plikow MP3\n\n");
    printf("Masz do wyboru nastepujace opcje:\n%s\n",Gwiazdki);
    puts("[1] Wczytanie bazy wczesniej zapisanych utworow muzycznych.\n"
           "\t\tNalezy wpisac: 1\n\n");
    puts("[2] Stworzenie nowej bazy plikow muzycznych.\n"
            "\t\tNalezy wpisac: 2\n\n");
    printf("[3] Zakonczenie pracy programu.\n"
           "\t\tNalezy wpisac: 3\n%s\n",Gwiazdki);
      while(!isdigit(wybor=getchar()))
      {
         while(getchar()!='\n');
         break;
      }
      if(wybor != '1' && wybor != '2' && wybor != '3')
         continue;
      switch(wybor)
      {
        case '1':
            while(getchar()!='\n');         // komenda czyszczaca bufor
// printf("Wczytanie pliku\n");
            wyswietl_baze(); //funkcja do wczytania pliku musi byc dodana

            while(getchar()!='\n');         // komenda czyszczaca bufor
            break;
        case '2':
            while(getchar()!='\n');         // komenda czyszczaca bufor
//printf("Stworzenie nowej bazy plikow muzycznych\n");
            nowa_baza();
            while(getchar()!='\n');         // komenda czyszczaca bufor
            break;
        case '3':
            system("clear"); printf("\t\tKoniec programu!\n\n");
            return 0;
      }
  }
}


