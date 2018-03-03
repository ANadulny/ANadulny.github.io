//******************FUNKCJA WCZYTYWANIA BAZY*****************************************

int wczytanie_pliku() //dodaj funkcje wczytania
{
    char plik_nazwa[20]="\0";
    do
    {
        system("clear");
        puts("Podaj nazwe pliku z ktorego chcesz wczytac baze katalogow plikow muzycznych");
        scanf("%20[^\n]", plik_nazwa);
        if(plik_nazwa[0]==0 || strchr(plik_nazwa, '0') != NULL)
        {
            system("clear");
            getchar();                          // komenda czyszczaca bufor ze znaku nowe lini
        }
    }while(plik_nazwa[0]==0 || strchr(plik_nazwa, '0') != NULL);

    if(strstr(plik_nazwa, ".txt") == NULL)
       strcat(plik_nazwa-1, ".txt");

    while(getchar()!='\n');         // komenda czyszczaca bufor
    FILE *odczyt;
    odczyt = fopen(plik_nazwa, "r+");
    if(odczyt==NULL)
    {
       //puts("Blad otwierania bazy danych");
       return 1;
    }


    char autor[31]="\0",tytul[31] = "\0",nazwa_albumu[31]="\0";
    int typ_bitrate, czas_utworu;
    float rozmiar_pliku;
    int trafienia;
    struct utwor *dodawaj= NULL;

    system("clear");
    char znak;

while(1)
{
    dodawaj = malloc(sizeof (baza));

    dodawaj->id=nr;
    nr++;

        znak=getc(odczyt);
        if(znak==EOF)
            break;
            //return 2; //koniec pliku
        if( !isdigit(znak) && znak != '0') //sprawdzenie czy wpis ma na poczatku nr
            break;
            //return 3;

        do
        {
            znak=getc(odczyt);
            if( !isdigit(znak) && znak != ',') //sprawdzenie czy wpis ma na poczatku nr
                 break;
                 //return 3;
        }while(znak != ',');


//puts("Nazwe autora utworu: ");
        fscanf(odczyt, "%30[^,]", autor);
        //autor[0]==0 != NULL || wyrzycone z if ponizej
        if( strchr(autor, '1') != NULL || strchr(autor, '2') != NULL || strchr(autor, '3') != NULL || strchr(autor, '4') != NULL || strchr(autor, '5') != NULL
           || strchr(autor, '6') != NULL|| strchr(autor, '7') != NULL|| strchr(autor, '8') != NULL || strchr(autor, '9') != NULL || strchr(autor, '0') != NULL)
        {
            break;
            //return 1; //zle zapisany rekord
        }
    dodawaj->nazwa_autora=malloc(sizeof(char) * (strlen(autor)+1));
    strcpy( dodawaj->nazwa_autora, autor );
    if(znak=getc(odczyt) != ',')
        break;
        //return 3;


//puts("Tytul utworu: ");
            fscanf(odczyt, "%30[^,]", tytul);
            if(tytul[0]==0 || strchr(tytul, '1') != NULL || strchr(tytul, '2') != NULL || strchr(tytul, '3') != NULL || strchr(tytul, '4') != NULL || strchr(tytul, '5') != NULL
           || strchr(tytul, '6') != NULL|| strchr(tytul, '7') != NULL|| strchr(tytul, '8') != NULL || strchr(tytul, '9') != NULL || strchr(tytul, '0') != NULL)
            {
                break;
                //return 1;                  // zly zapis rekordu
            }
        struct utwor *tmp;
        tmp=glowa;
        while(tmp != NULL)
        {
            if(!strcmp(tmp->tytul,tytul))
            {
                puts("Tytul o takiej nazwie znajduje sie juz w bazie");
                //
                //break;
                //dokoncz podaczas robienia petli wczytywania wielu utworow
                //
                break;
                //return 4; //element bazy powtarza sie;
            }
            tmp = tmp -> next;
        }
    dodawaj->tytul=malloc(sizeof(char) * (strlen(tytul)+1));
    strcpy( dodawaj->tytul, tytul );
    if(znak=getc(odczyt) != ',')
       break;
       //  return 3;


//puts("Nazwe albumu utworu: ");
        fscanf(odczyt, "%30[^,]", nazwa_albumu);
        if(nazwa_albumu[0]==0 || strchr(nazwa_albumu, '1') != NULL || strchr(nazwa_albumu, '2') != NULL || strchr(nazwa_albumu, '3') != NULL || strchr(nazwa_albumu, '4') != NULL || strchr(nazwa_albumu, '5') != NULL
           || strchr(nazwa_albumu, '6') != NULL|| strchr(nazwa_albumu, '7') != NULL|| strchr(nazwa_albumu, '8') != NULL || strchr(nazwa_albumu, '9') != NULL || strchr(nazwa_albumu, '0') != NULL)
        {
          break;
          //  return 1;                  // zly zapis rekordu
        }
    dodawaj->nazwa_albumu=malloc(sizeof(char) * (strlen(nazwa_albumu)+1));
    strcpy( dodawaj->nazwa_albumu, nazwa_albumu );
    if(znak=getc(odczyt) != ',')
         break;
         //return 3;


//puts("Czas trwania utworu w sekundach:");
    fscanf(odczyt,"%d", &czas_utworu);

    if(czas_utworu<=0 || czas_utworu>1200)
       break;
       // return 1;
    dodawaj->czas_utworu=czas_utworu;
    if(znak=getc(odczyt) != ',')
        break;
        // return 3;


//puts("Typ bitrate z zakresy od 32 do 320 kbps: ");
            fscanf(odczyt,"%d", &typ_bitrate);
            if(typ_bitrate<32 || typ_bitrate>320)
            {
                break;
                //return 1;   //zly zapis rekordu

            }

        int i;
        trafienia=1;
        for(i=0; i<wolny_typ; i++)                // petla sprawdzajaca czy podany typ bitrate znajduje sie na dozwolonej liscie
        {
            if(bitrate[i] == typ_bitrate)
            {
                dodawaj->typ_bitrate= bitrate[i];
                trafienia=0;
            }
        }
        if(trafienia==1)
        {
                dodawaj->typ_bitrate=typ_bitrate;
                bitrate[wolny_typ]=typ_bitrate;    // dodanie podanego typu do listy dozwolonych
                wolny_typ++;
        }
    if(znak=getc(odczyt) != ',')
        break;
        //return 3;


//puts("Rozmiar utworu: ");
    fscanf(odczyt,"%f", &rozmiar_pliku);
    if( rozmiar_pliku<=0 || rozmiar_pliku >= 30)
    {
        break;
        //return 1; //zly zapis rekordu
    }


    rozmiar_pliku=(float)( (int)(rozmiar_pliku*100) ) /100;
    dodawaj->rozmiar=rozmiar_pliku;

    dodawaj -> next = NULL;
    dodawaj -> prev= ogon;
    if (ogon == NULL)
        glowa = ogon = dodawaj;
    else
    {
        ogon->next = dodawaj;
        ogon = dodawaj;
    }
    if(znak=getc(odczyt) != '.')
        break;
        //return 3;
    if(znak=getc(odczyt) != '\n')
        break;
        //return 3;
}
    fclose(odczyt);
    return 5;//wszystko poszlo dobrze
}

