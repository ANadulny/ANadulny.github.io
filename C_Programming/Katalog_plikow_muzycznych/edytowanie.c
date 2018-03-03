
//****************FUNKCJA DO EDYTOWANIA UTWOROW Z OBECNEJ BAZY***********************************

void edytowanie()
{
 char autor[31]="\0",tytul[31] = "\0",nazwa_albumu[31]="\0", wybor;
    int typ_bitrate, czas_utworu;
    float rozmiar_pliku;
    int trafienia;

 int nr_edytowania;
    system("clear");
    printf("Edytowanie pliku muzycznego\n");
    wyswietl();
    //if(wyswietl() == 2) return;
    puts("Podaj nr utworu ktory chcesz edytowac");
    if(scanf("%i",&nr_edytowania)!=1 || nr_edytowania<=0 || nr_edytowania>=nr)  // petla sprawdzajaca czy zostal podany poprawny numer
    {
        do
        {
            system("clear");
            while(getchar()!='\n');             // petla czyszczaca bufor
            if(nr_edytowania>=nr) puts ("baza nie zawiera utworu o podanym numerze");
            puts("\n[1]Cofnij");
        }while(getchar()!='1');
        return;
    }

    struct utwor *edyt=glowa;
    while(edyt != NULL)
    {
       if(edyt->id==nr_edytowania)   //sprawdzenie czy podany numer znajduje sie w bazie
       {
          do
          {
            while(getchar()!='\n');
            printf("Czy chcesz edytowac autora?\n");
            puts("[1]Tak");
            puts("[2]Nie");
            wybor=getchar();
          }while(wybor!='1' && wybor!='2');
         if(wybor=='1')
         {
            do                                          // petla sprawdzajaca czy nazwa autora utworu  nie jest pusta
            {
                system("clear");
                //wyswietl();
                puts("Podaj nazwe autora utworu: ");
                scanf("%30[^\n]", autor);
                if(autor[0]==0 || strchr(autor, '1') != NULL || strchr(autor, '2') != NULL || strchr(autor, '3') != NULL || strchr(autor, '4') != NULL || strchr(autor, '5') != NULL
           || strchr(autor, '6') != NULL|| strchr(autor, '7') != NULL|| strchr(autor, '8') != NULL || strchr(autor, '9') != NULL || strchr(autor, '0') != NULL)
                {
                    system("clear");
                    getchar();                          // komenda czyszczaca bufor ze znaku nowe lini
                }
            }while(autor[0]==0|| strchr(autor, '1') != NULL || strchr(autor, '2') != NULL || strchr(autor, '3') != NULL || strchr(autor, '4') != NULL || strchr(autor, '5') != NULL
           || strchr(autor, '6') != NULL|| strchr(autor, '7') != NULL|| strchr(autor, '8') != NULL || strchr(autor, '9') != NULL || strchr(autor, '0') != NULL);
            edyt->nazwa_autora=malloc(sizeof(char) * (strlen(autor)+1));
            strcpy( edyt->nazwa_autora, autor );
         }


          do
          {
            system("clear");
            wyswietl();
            while(getchar()!='\n');
            printf("Czy chcesz edytowac tytul utworu?\n");
            puts("[1]Tak");
            puts("[2]Nie");
            wybor=getchar();
          }while(wybor!='1' && wybor!='2');
         if(wybor=='1')
         {
            do                                      // petla sprawdzajaca czy utwor o podanym tytule nie znajduje sie juz w bazie
            {
                trafienia=0;
                do                                  // petla sprawdzajaca czy nazwa autora nie jest pusta
                {
                    wyswietl();
                    puts("Podaj tytul utworu: ");
                    scanf("%30[^\n]", tytul);
                    if(tytul[0]==0|| strchr(tytul, '1') != NULL || strchr(tytul, '2') != NULL || strchr(tytul, '3') != NULL || strchr(tytul, '4') != NULL || strchr(tytul, '5') != NULL
           || strchr(tytul, '6') != NULL|| strchr(tytul, '7') != NULL|| strchr(tytul, '8') != NULL || strchr(tytul, '9') != NULL || strchr(tytul, '0') != NULL)
                    {
                        system("clear");
                        getchar();                  // komenda czyszczaca bufor ze znaku nowe lini
                    }
                }while(tytul[0]==0|| strchr(tytul, '1') != NULL || strchr(tytul, '2') != NULL || strchr(tytul, '3') != NULL || strchr(tytul, '4') != NULL || strchr(tytul, '5') != NULL
           || strchr(tytul, '6') != NULL|| strchr(tytul, '7') != NULL|| strchr(tytul, '8') != NULL || strchr(tytul, '9') != NULL || strchr(tytul, '0') != NULL);

                struct utwor *tmp;
                tmp=glowa;
                while(tmp != NULL)
                {
                    if(!strcmp(tmp->tytul,tytul))
                    {
                        system("clear");
                        puts("Tytul o takiej nazwie znajduje sie juz w bazie, sproboj jescze raz");
                        trafienia =1;
                    }
                    tmp = tmp -> next;
                }
            }while(trafienia==1);

            edyt->tytul=malloc(sizeof(char) * (strlen(tytul)+1));
            strcpy( edyt->tytul, tytul );
         }

         do
          {
            system("clear");
            wyswietl();
            while(getchar()!='\n');
            printf("Czy chcesz edytowac nazwe albumu?\n");
            puts("[1]Tak");
            puts("[2]Nie");
            wybor=getchar();
          }while(wybor!='1' && wybor!='2');
         if(wybor=='1')
         {

            do                                          // petla sprawdzajaca czy nazwa albumu utworu  nie jest pusta
            {
                wyswietl();
                puts("Podaj nazwe albumu utworu(MB): ");
                scanf("%30[^\n]", nazwa_albumu);
                if(nazwa_albumu[0]==0|| strchr(nazwa_albumu, '1') != NULL || strchr(nazwa_albumu, '2') != NULL || strchr(nazwa_albumu, '3') != NULL || strchr(nazwa_albumu, '4') != NULL || strchr(nazwa_albumu, '5') != NULL
           || strchr(nazwa_albumu, '6') != NULL|| strchr(nazwa_albumu, '7') != NULL|| strchr(nazwa_albumu, '8') != NULL || strchr(nazwa_albumu, '9') != NULL || strchr(nazwa_albumu, '0') != NULL)
                {
                    system("clear");
                    getchar();                          // komenda czyszczaca bufor ze znaku nowe lini
                }
            }while(nazwa_albumu[0]==0|| strchr(nazwa_albumu, '1') != NULL || strchr(nazwa_albumu, '2') != NULL || strchr(nazwa_albumu, '3') != NULL || strchr(nazwa_albumu, '4') != NULL || strchr(nazwa_albumu, '5') != NULL
           || strchr(nazwa_albumu, '6') != NULL|| strchr(nazwa_albumu, '7') != NULL|| strchr(nazwa_albumu, '8') != NULL || strchr(nazwa_albumu, '9') != NULL || strchr(nazwa_albumu, '0') != NULL);
            edyt->nazwa_albumu=malloc(sizeof(char) * (strlen(nazwa_albumu)+1));
            strcpy( edyt->nazwa_albumu, nazwa_albumu );

         }

         do
          {
            system("clear");
            wyswietl();
            while(getchar()!='\n');
            printf("Czy chcesz edytowac czas trwania utworu?\n");
            puts("[1]Tak");
            puts("[2]Nie");
            wybor=getchar();
          }while(wybor!='1' && wybor!='2');
        if(wybor=='1')
            {
                puts("Podaj czas trwania utworu w sekundach:");
                while(scanf("%d", &czas_utworu)!=1 || czas_utworu<=0 || czas_utworu>1200)
                {
                    system("clear");
                    wyswietl();
                    puts("Bledne dane! Sproboj jescze raz");
                    puts("Podaj czas trwania utworu: ");
                    while(getchar()!='\n');
                }
                edyt->czas_utworu=czas_utworu;

            }

          do
          {
            system("clear");
            wyswietl();
            while(getchar()!='\n');
            printf("Czy chcesz edytowac typ bitrate?\n");
            puts("[1]Tak");
            puts("[2]Nie");
            wybor=getchar();
          }while(wybor!='1' && wybor!='2');
            if(wybor=='1')
            {
                do                                          // petla wykonujaca sie w przypadku gdy uzytkownik bedzie chcial poprawic podany typ bitrate
                {
                    system("clear");
                    wyswietl();
                    while(getchar()!='\n');
                    do                                      // petla sprawdzajaca czy typ bitrate nie jest pusty
                    {
                        puts("Podaj typ bitrate z zakresy od 32 do 320 kbps: ");
                        typy_bitrate();
                        scanf("%d", &typ_bitrate);
                        if(typ_bitrate<32 || typ_bitrate>320)
                        {
                            system("clear");
                            getchar();                      // komenda czyszczaca bufor ze znaku nowe lini
                        }
                    }while(typ_bitrate<32 || typ_bitrate>320);

                    trafienia=0;
                    int i;
                    for(i=0; i<wolny_typ; i++)                // petla sprawdzajaca czy podany typ bitrate znajduje sie na dozwolonej liscie
                    {
                        if(bitrate[i] == typ_bitrate)
                        {
                            edyt->typ_bitrate= bitrate[i];
                            trafienia=1;
                            wybor='2';
                        }
                    }
                    if(!trafienia)
                    {
                        do
                        {
                            system("clear");
                            puts("Podany typ bitrate nie znajduje sie w bazie");
                            puts("[1]Popraw wpis");
                            puts("[2]Dodaj wpisany typ do bazy");
                            while(getchar()!='\n');                 // petla czyszczaca bufor
                            wybor=getchar();
                            system("clear");
                            while(getchar()!='\n');                 // petla czyszczaca bufor
                        }while(wybor!='1' && wybor!='2');

                        if(wybor=='2')
                        {
                            edyt->typ_bitrate=typ_bitrate;
                            bitrate[wolny_typ]=typ_bitrate;    // dodanie podanego typu do listy dozwolonych
                            wolny_typ++;
                        }
                    }
                }while(wybor=='1');
            }

            do
          {
            system("clear");
            wyswietl();
            while(getchar()!='\n');
            printf("Czy chcesz edytowac rozmiar utworu?\n");
            puts("[1]Tak");
            puts("[2]Nie");
            wybor=getchar();
          }while(wybor!='1' && wybor!='2');
            system("clear");
            wyswietl();
            if(wybor=='1')
            {
                while(getchar()!='\n');
                puts("Podaj rozmiar utworu: ");          // petla sprawdzajaca czy rozmiar_pliku jest wartoscia liczbowa i czy jest dodatnia
            while(scanf("%f", &rozmiar_pliku)!=1 || rozmiar_pliku<=0 || rozmiar_pliku >= 30)
            {
                system("clear");
                wyswietl();
                puts("Bledne dane! Sproboj jescze raz");
                puts("Podaj rozmiar utworu: ");
                while(getchar()!='\n');
            }
            rozmiar_pliku=(float)( (int)(rozmiar_pliku*100) ) /100;
            edyt->rozmiar=rozmiar_pliku;
            }
       }
       edyt = edyt -> next;
    }


}

