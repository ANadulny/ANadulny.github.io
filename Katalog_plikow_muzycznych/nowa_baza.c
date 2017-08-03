//******************FUNKCJA TWORZY NOWA BAZE W NOWYM DOKUMENCIE***********************

void nowa_baza() //dokonczyc
{
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

  do
  {
  system("clear");
  if(wyswietl() == 2)
  {
     do
    {
      while(getchar()!='\n');
      system("clear");
      printf("Wybrales opcje 2. Stworzenia nowej bazy plikow muzycznych.\n\n");
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
            while(getchar()!='\n');         // komenda czyszczaca bufor
            edytowanie();
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


