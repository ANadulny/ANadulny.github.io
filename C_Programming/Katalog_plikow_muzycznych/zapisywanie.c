
//******************FUNKCJA ZAPISU BAZY*****************************************

int zapis_do_pliku()  //sprawdz ta funkcje
{
   char plik_nazwa[20]="\0";
    do
    {
        system("clear");
        puts("Podaj nazwe pliku do ktorego chcesz zapisac baze katalogow plikow muzycznych");
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
   FILE *plik;
   plik = fopen(plik_nazwa, "w+");
   if(plik==NULL)
   {
       //puts("Blad otwierania bazy danych");
       return 2;
   }
   struct utwor *wska;
   wska=glowa;
   while(wska!=NULL)
   {
       fprintf(plik, "%i,%s,%s,%s,%d,%d,%.2f.\n", wska->id, wska->nazwa_autora, wska->tytul, wska->nazwa_albumu, wska->czas_utworu,
               wska->typ_bitrate, wska->rozmiar);
        wska = wska -> next;
   }
   fclose(plik);

}

