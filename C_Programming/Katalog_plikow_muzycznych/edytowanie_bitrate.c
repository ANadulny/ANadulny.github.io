//******************FUNKCJA DO WYPISYWANIA TYPOW BITRATE*****************************************

void typy_bitrate() //wyowietla typy bitrate ktore sa juz zapisane w badzie
{
 int i;
 printf("Typy bitrate ktorych sa juz zapisane w bazie i z ktorych mozesz skorzystac:\n ");
 for(i=0; i<wolny_typ; i++)
 {
     printf("%d  ", bitrate[i]);
 }
 printf("\n\n");
}


//*******************************FUNKCJA DO EDYTOWANIA TYPU BITRATE***************************

void edytuj_btrate()
{

 int zmienna=0;
 int trafienie;
 char wybor;
 int *na_bitrate;
 na_bitrate=bitrate;
 int typ_bitrate;

  while(1)
  {
    system("clear");
    puts("\t\tEdytowanie Typu bitrate.\n\n");

    int i;
    printf("Typy bitrate ktorych sa juz zapisane w bazie i ktore mozesz zmienic:\n");
    for(i=0; i<wolny_typ; i++)
    {
       printf("[%d] %d\n",i+1, bitrate[i]);
    }
    printf("\n\n");

    printf("Mozliwe opcje do wyboru:\n");
    puts("[1]Edytowanie typu bitrate");
    puts("[2]Dodanie nowego typu bitrate");
    puts("[3]Usuniecie typu bitrate");
    puts("[4]Cofnij");

    while(!isdigit(wybor=getchar()))
      {
         while(getchar()!='\n');
         system("clear");
         break;
      }
      if(wybor != '1' && wybor != '2' && wybor != '3' && wybor != '4')
        while(getchar()!='\n');         // komenda czyszczaca bufor
      switch(wybor)
       {
        case '1':
            while(getchar()!='\n');         // komenda czyszczaca bufor
            system("clear");
            printf("\t\tEdytowanie typu bitrate\n");
            printf("Typy bitrate ktorych sa juz zapisane w bazie i ktore mozesz edytowac wybierajac odpowiedni numer.\n\t Uwaga wpisanie znaku '0' powoduje powrot do menu wyboru.\n");
            for(i=0; i<wolny_typ; i++)
            {
                printf("[%d] %d\n",i+1, bitrate[i]);
            }
            printf("\n\n");
            while(scanf("%d", &zmienna)!=1 || zmienna<0 || zmienna>wolny_typ)
            {
                system("clear");
                puts("Bledne dane! Sproboj jescze raz\n");
                printf("Typy bitrate ktorych sa juz zapisane w bazie i ktore mozesz edytowac wybierajac odpowiedni numer.\n\t Uwaga wpisanie znaku '0' powoduje powrot do menu wyboru.\n");
                for(i=0; i<wolny_typ; i++)
                {
                    printf("[%d] %d\n",i+1, bitrate[i]);
                }
                printf("\n\n");
                while(getchar()!='\n');

            }
            if(zmienna==0) break;

            do                                          // petla wykonujaca sie w przypadku gdy uzytkownik bedzie chcial poprawic podany typ bitrate
            {
                do                                      // petla sprawdzajaca czy typ bitrate nie jest pusty
                {
                    system("clear");
                    puts("Podaj typ bitrate z zakresy od 32 do 320 kbps: ");
                    typy_bitrate();
                    scanf("%d", &typ_bitrate);
                    if(typ_bitrate<32 || typ_bitrate>320)
                    {
                        system("clear");
                        getchar();                      // komenda czyszczaca bufor ze znaku nowe lini
                    }
                }while(typ_bitrate<32 || typ_bitrate>320);

                trafienie=0;
                for(i=0; i<wolny_typ; i++)                // petla sprawdzajaca czy podany typ bitrate znajduje sie na dozwolonej liscie
                {
                    if(bitrate[i] == typ_bitrate)
                    {

                        trafienie=1;
                        wybor='2';
                        //zle dane wprowadzone
                    }
                }
                if(!trafienie)
                {
                  *(na_bitrate+zmienna-1)=typ_bitrate;
                  wybor='2';
                }
            }while(wybor=='1');
            while(getchar()!='\n');         // komenda czyszczaca bufor
            break;





            case '2':
            while(getchar()!='\n');         // komenda czyszczaca bufor
            system("clear");
            printf("\tDodanie nowego typu bitrate\n\n");
            do                                          // petla wykonujaca sie w przypadku gdy uzytkownik bedzie chcial poprawic podany typ bitrate
            {
                do                                      // petla sprawdzajaca czy typ bitrate nie jest pusty
                {
                    printf("Typy bitrate ktorych sa juz zapisane w bazie\n ");
                    for(i=0; i<wolny_typ; i++)
                    {
                        printf("%d  ", bitrate[i]);
                    }
                    printf("\n\n");
                    puts("Podaj typ bitrate z zakresy od 32 do 320 kbps:");

                    scanf("%d", &typ_bitrate);
                    if(typ_bitrate<32 || typ_bitrate>320)
                    {
                        system("clear");
                        getchar();                      // komenda czyszczaca bufor ze znaku nowe lini
                    }
                }while(typ_bitrate<32 || typ_bitrate>320);

                trafienie=0;
                int i;
                for(i=0; i<wolny_typ; i++)                // petla sprawdzajaca czy podany typ bitrate znajduje sie na dozwolonej liscie
                {
                    if(bitrate[i] == typ_bitrate)
                    {
                        trafienie=1;
                        break;
                    }
                }
                if(!trafienie)
                {
                    bitrate[wolny_typ]=typ_bitrate;    // dodanie podanego typu do listy dozwolonych
                    wolny_typ++;
                }
            }while(wybor=='1');
            while(getchar()!='\n');         // komenda czyszczaca bufor
            break;



        case '3':
            if(wolny_typ==0) break;
            while(getchar()!='\n');         // komenda czyszczaca bufor
            system("clear");
            printf("Usuniecie typu bitrate\n");
            puts("Podaj nr typu bitrate, ktory chcesz usunac.\n\t Uwaga wpisanie znaku '0' powoduje powrot do menu wyboru.");
            for(i=0; i<wolny_typ; i++)
            {
                printf("[%d] %d\n",i+1, bitrate[i]);
            }
            printf("\n\n");
            while(scanf("%d", &zmienna)!=1 || zmienna<0 || zmienna>wolny_typ)
            {
                system("clear");
                puts("Bledne dane! Sproboj jescze raz\n");
                puts("Podaj nr typu bitrate, ktory chcesz usunac.\n\t Uwaga wpisanie znaku '0' powoduje powrot do menu wyboru.");
                for(i=0; i<wolny_typ; i++)
                {
                    printf("[%d] %d\n",i+1, bitrate[i]);
                }
                printf("\n\n");
                while(getchar()!='\n');

            }
            if(zmienna==0) break;


            for(i=zmienna-1; i<wolny_typ-1; i++)
                    *(na_bitrate+i)=*(na_bitrate+i+1);
            *(na_bitrate+wolny_typ-1)=0;
            wolny_typ--;
            while(getchar()!='\n');
             break;



        case '4':  //powrot
            return;
       }



  }

}
