//*****************FUNKCJA WYSWIETLA BAZE Z DOKUMENTU TEKSTOWEGO**********************
void wyswietl_baze() //dokonczyc
{
//puts("Podaj nazwe dokumentu z ktorego chcesz wczytac katalog plikow muzycznych");
   struct utwor *tmp=glowa; // czyszczenie bazy plikow muzycznych
    while(tmp != NULL)
    {
         struct utwor *pomocnicza;
         free(tmp->nazwa_autora);
         free(tmp->tytul);
         free(tmp->nazwa_albumu);
         free(tmp);
         if(tmp==glowa && tmp==ogon)
                glowa=ogon=NULL;
         else
            {
                pomocnicza=tmp->next;
                glowa=pomocnicza;
                pomocnicza->prev=NULL;
            }
         tmp = tmp -> next;
    }
    int *na_nr;
    na_nr=&nr;
    *na_nr=1;
   char wybor;
   int trafienie=1;


/*int sprawdzenie;
sprawdzenie=wczytanie_pliku();
printf("sprawdzenie ma wartosc: %d", sprawdzenie);
while(getchar()!='\n');
while(getchar()!='\n');
*/
if(wczytanie_pliku()!= 5)
{
    system("clear");
printf("Nie ma takiego pliku!\n");
    while(getchar()!='\n');
    return;
}
nr--;
  do
  {
  system("clear");
  if(wyswietl() == 2)
  {
     do
    {
      while(getchar()!='\n');
      system("clear");
      puts("[1]Dodaj utwor muzyczny.");
      puts("[2]Cofnij.");
       while(!isdigit(wybor=getchar()))
      {
         while(getchar()!='\n');
         system("clear");
         break;
      }
      if(wybor != '1' && wybor != '2')
        while(getchar()!='\n');         // komenda czyszczaca bufor
      switch(wybor)
       {
         case '1':
            while(getchar()!='\n');         // komenda czyszczaca bufor
            system("clear");
            printf("Dodanie utworu muzycznego\n");
            dodaj_utwor();
            trafienie=0;
            break;
        case '2':  //powrot do panelu glownego
            trafienie=0;
            return;
       }
    }while(trafienie==1);
  }
int sprawdzanie=1;
if(!trafienie)
  {
  system("clear");
  if(wyswietl() == 2) break;
  }
  trafienie=1;
  puts("\n[1]Edytowanie pliku muzycznego.");
  puts("[2]Sortowanie bazy plikow muzycznych.");
  puts("[3]Usuniecie pliku muzycznego.");
  puts("[4]Dodaj utwor muzyczny.");
  puts("[5]Usuniecie calej bazy plikow muzycznych.");
  puts("[6]Zapisz dane do pliku.");
  puts("[7]Cofnij.");
  while(!isdigit(wybor=getchar()))
      {
         while(getchar()!='\n');
         system("clear");
         break;
      }
      if(wybor != '1' && wybor != '2' && wybor != '3'&& wybor != '4' && wybor != '5' && wybor != '6'&& wybor != '7')
         while(getchar()!='\n');         // komenda czyszczaca bufor
      switch(wybor)
      {
        case '1':
             //while(getchar()!='\n');         // komenda czyszczaca bufor

             do
            {
            while(getchar()!='\n');
            system("clear");
            puts("[1]Edytuj utwor muzyczny.");
            puts("[2]Edytuj typ bitrate.");
            puts("[3]Cofnij.");
            while(!isdigit(wybor=getchar()))
            {
                while(getchar()!='\n');
                system("clear");
                break;
            }
            if(wybor != '1' && wybor != '2'&& wybor != '3')
                 {
                     while(getchar()!='\n');         // komenda czyszczaca bufor
                     continue;
                 }
            switch(wybor)
            {
            case '1':
                    while(getchar()!='\n');         // komenda czyszczaca bufor
                    edytowanie();
                    sprawdzanie=0;
                    break;

            case '2':
                    while(getchar()!='\n');         // komenda czyszczaca bufor
                    edytuj_btrate();
                    sprawdzanie=0;
                    break;

            case '3':  //powrot do panelu glownego
                    sprawdzanie=0;
            }
            }while(sprawdzanie==1);

            while(getchar()!='\n');         // komenda czyszczaca bufor
            break;

        case '2':
            while(getchar()!='\n');         // komenda czyszczaca bufor
            system("clear");
            printf("Sortowanie bazy plikow muzycznych\n");
            sortowanie();
            while(getchar()!='\n');         // komenda czyszczaca bufor
            break;

        case '3':
            while(getchar()!='\n');         // komenda czyszczaca bufor
            system("clear");
            printf("Usuniecie pliku muzycznego\n");
            usun();
            while(getchar()!='\n');         // komenda czyszczaca bufor
            break;

        case '4':
            while(getchar()!='\n');         // komenda czyszczaca bufor
            system("clear");
            printf("Dodanie utworu muzycznego\n");
            dodaj_utwor();
            break;

        case '5':
            while(getchar()!='\n');         // komenda czyszczaca bufor
            system("clear");
            printf("Usuniecie bazy plikow muzycznych\n");
            usun_baze();
            break;

       case '6':
            while(getchar()!='\n');         // komenda czyszczaca bufor
            system("clear");
            zapis_do_pliku();
            break;

        case '7':  //powrot do panelu glownego
            trafienie=0;
            break;
      }
  }while(trafienie==1);
}


