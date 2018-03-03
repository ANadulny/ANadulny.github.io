//******************FUNKCJA SORTOWANIA BAZY*****************************************

void sortowanie()          // problem dokonczyc trzeba
{
    struct utwor *obecna;
    obecna=glowa;

    int trafienie=1;
    int koniec;
    char wybor;
    int licznik=0; //pomocnicza zmienna zliczajaca ile jest rekordow w strukturze
    if(obecna==NULL)
    {
        do
        {
            system("clear");
            while(getchar()!='\n');
            puts ("Baza nie zawiera ani jednego utworu");
            puts("\n[1]Cofnij");
        }while(getchar()!='1');
        return;
    }

    while(obecna!=NULL)
    {
        licznik++;
        obecna = obecna -> next;
    }
    // printf("%d", licznik); //element kontrolny
    //while(getchar()!='\n');
    //while(getchar()!='\n');
    do
    {
        system("clear");
        koniec=1;
        wyswietl();
        puts("\nJak chcesz posortowac baze?");
        puts("[1]Po nazwie autora");
        puts("[2]Po tytule utworu");
        puts("[3]Po nazwie albumu");
        puts("[4]Po czasie utworu");
        puts("[5]Po typie bitrate");
        puts("[6]Po rozmiarze utworu");
        puts("[7]Po numerze utworu");
        puts("[8]Cofnij");

        while(!isdigit(wybor=getchar()))
        {
           while(getchar()!='\n');
           break;
        }
        if(wybor != '1' && wybor != '2' && wybor != '3' && wybor != '4' && wybor != '5' && wybor != '6' && wybor != '7' && wybor != '8')
           continue;
        switch(wybor)
        {
          case '1':
              while(getchar()!='\n');         // komenda czyszczaca bufor
              printf("Chcesz posortowac nazwe autora rosnaco czy malejaco?\n");
              puts("[1]Rosnaco");
              puts("[2]Malejaco");
              do
              {
                while(!isdigit(wybor=getchar()))
                {
                    while(getchar()!='\n');
                    break;
                }
                if(wybor != '1' && wybor != '2') continue;

                if(wybor=='1')
                {
                    sortowanie_danych(porownaj_autora,1);
                    koniec=0;
                }
                else if(wybor=='2')
                {
                    sortowanie_danych(porownaj_autora,2);
                    koniec=0;
                }


              }while(koniec==1);

              while(getchar()!='\n');         // komenda czyszczaca bufor
              break;
          case '2':
              while(getchar()!='\n');         // komenda czyszczaca bufor
              printf("Chcesz posortowac tytul utworu rosnaco czy malejaco?\n");
              puts("[1]Rosnaco");
              puts("[2]Malejaco");
              do
              {
                while(!isdigit(wybor=getchar()))
                {
                    while(getchar()!='\n');
                    break;
                }
                if(wybor != '1' && wybor != '2') continue;

                if(wybor=='1')
                {
                    sortowanie_danych(porownaj_tytul,1);
                    koniec=0;
                }
                else if(wybor=='2')
                {
                    sortowanie_danych(porownaj_tytul,2);
                    koniec=0;
                }


              }while(koniec==1);

              while(getchar()!='\n');         // komenda czyszczaca bufor
              break;
          case '3':
              while(getchar()!='\n');         // komenda czyszczaca bufor
              printf("Chcesz posortowac nazwe albumu rosnaco czy malejaco?\n");
              puts("[1]Rosnaco");
              puts("[2]Malejaco");
              do
              {
                while(!isdigit(wybor=getchar()))
                {
                    while(getchar()!='\n');
                    break;
                }
                if(wybor != '1' && wybor != '2') continue;

                if(wybor=='1')
                {
                    sortowanie_danych(porownaj_album,1);
                    koniec=0;
                }
                else if(wybor=='2')
                {
                    sortowanie_danych(porownaj_album,2);
                    koniec=0;
                }


              }while(koniec==1);

              while(getchar()!='\n');         // komenda czyszczaca bufor
              break;
          case '4':
              while(getchar()!='\n');         // komenda czyszczaca bufor
              printf("Chcesz posortowac czas utworu rosnaco czy malejaco?\n");
              puts("[1]Rosnaco");
              puts("[2]Malejaco");
              do
              {
                while(!isdigit(wybor=getchar()))
                {
                    while(getchar()!='\n');
                    break;
                }
                if(wybor != '1' && wybor != '2') continue;

                if(wybor=='1')
                {
                    sortowanie_danych(porownaj_czas_trwania,1);
                    koniec=0;
                }
                else if(wybor=='2')
                {
                    sortowanie_danych(porownaj_czas_trwania,2);
                    koniec=0;
                }


              }while(koniec==1);

              while(getchar()!='\n');         // komenda czyszczaca bufor
              break;
          case '5':
              while(getchar()!='\n');         // komenda czyszczaca bufor
              printf("Chcesz posortowac typ bitrate rosnaco czy malejaco?\n");
              puts("[1]Rosnaco");
              puts("[2]Malejaco");
              do
              {
                while(!isdigit(wybor=getchar()))
                {
                    while(getchar()!='\n');
                    break;
                }
                if(wybor != '1' && wybor != '2') continue;

                if(wybor=='1')
                {
                    sortowanie_danych(porownaj_typ_bitrate,1);
                    koniec=0;
                }
                else if(wybor=='2')
                {
                    sortowanie_danych(porownaj_typ_bitrate,2);
                    koniec=0;
                }


              }while(koniec==1);

              while(getchar()!='\n');         // komenda czyszczaca bufor
              break;

          case '6':
              while(getchar()!='\n');         // komenda czyszczaca bufor
              printf("Chcesz posortowac rozmiar utworu rosnaco czy malejaco?\n");
              puts("[1]Rosnaco");
              puts("[2]Malejaco");
              do
              {
                while(!isdigit(wybor=getchar()))
                {
                    while(getchar()!='\n');
                    break;
                }
                if(wybor != '1' && wybor != '2') continue;

                if(wybor=='1')
                {
                    sortowanie_danych(porownaj_rozmiar,1);
                    koniec=0;
                }
                else if(wybor=='2')
                {
                    sortowanie_danych(porownaj_rozmiar,2);
                    koniec=0;
                }


              }while(koniec==1);

              while(getchar()!='\n');         // komenda czyszczaca bufor
              break;

          case '7':
              while(getchar()!='\n');         // komenda czyszczaca bufor
              printf("Chcesz posortowac id utworu rosnaco czy malejaco?\n");
              puts("[1]Rosnaco");
              puts("[2]Malejaco");
              do
              {
                while(!isdigit(wybor=getchar()))
                {
                    while(getchar()!='\n');
                    break;
                }
                if(wybor != '1' && wybor != '2') continue;

                if(wybor=='1')
                {
                    sortowanie_danych(porownaj_id,1);
                    koniec=0;
                }
                else if(wybor=='2')
                {
                    sortowanie_danych(porownaj_id,2);
                    koniec=0;
                }


              }while(koniec==1);

              while(getchar()!='\n');         // komenda czyszczaca bufor
              break;

          case '8':
              trafienie=0;
              break;
        }

    }while(trafienie==1);

}

//******************FUNKCJA POMOCNICZA DO SORTOWANIA BAZY*****************************************

int porownaj_autora(const void* a, const void* b)
{
    const struct utwor* _a = *(struct utwor**)a;
    const struct utwor* _b = *(struct utwor**)b;
    return strcmp(_a->nazwa_autora, _b->nazwa_autora);
}

int porownaj_tytul(const void* a, const void* b)
{
    const struct utwor* _a = *(struct utwor**)a;
    const struct utwor* _b = *(struct utwor**)b;
    return strcmp(_a->tytul, _b->tytul);
}

int porownaj_album(const void* a, const void* b)
{
    const struct utwor* _a = *(struct utwor**)a;
    const struct utwor* _b = *(struct utwor**)b;
    return strcmp(_a->nazwa_albumu, _b->nazwa_albumu);
}

int porownaj_czas_trwania(const void* a, const void* b)
{
    const struct utwor* _a = *(struct utwor**)a;
    const struct utwor* _b = *(struct utwor**)b;
    return _a->czas_utworu - _b->czas_utworu;
}

int porownaj_typ_bitrate(const void* a, const void* b)
{
    const struct utwor* _a = *(struct utwor**)a;
    const struct utwor* _b = *(struct utwor**)b;
    return _a->typ_bitrate - _b->typ_bitrate;
}

int porownaj_rozmiar(const void* a, const void* b)
{
    const struct utwor* _a = *(struct utwor**)a;
    const struct utwor* _b = *(struct utwor**)b;
    return (_a->rozmiar)*100 - (_b->rozmiar)*100;
}

int porownaj_id(const void* a, const void* b)
{
    const struct utwor* _a = *(struct utwor**)a;
    const struct utwor* _b = *(struct utwor**)b;
    return (_a->id)*100 - (_b->id)*100;
}

void sortowanie_danych(int (*comparator)(const void*, const void*),int licz)
{
if(licz==1)
{
    int i = 0;
    struct utwor * tmp;
    tmp = glowa;
    while (tmp!=NULL)
    {
        tmp=tmp->next;
        i++;
    }
    struct utwor * * Arr = malloc(sizeof(struct utwor*)*i);
    tmp = glowa;
    int k=0;
    while (k<i)
    {
        Arr[k++] = tmp;
        tmp=tmp->next;
    }
    qsort(Arr, i, sizeof(struct utwor*), comparator);
    glowa = tmp = *Arr;
    glowa->prev=NULL;
    k=1;
    while (k<i)
    {
        tmp = tmp->next = Arr[k];
        tmp->prev = Arr[k-1];
        k++;
    }
    tmp->next = NULL;
    ogon=tmp;
    free(Arr);
}


    else if(licz==2)
    {
    int i = 0;
    struct utwor * tmp;
    tmp = ogon;
    while (tmp!=NULL)
    {
        tmp=tmp->prev;
        i++;
    }
    struct utwor * * Arr = malloc(sizeof(struct utwor*)*i);
    tmp = ogon;
    int k=0;
    while (k<i)
    {
        Arr[k++] = tmp;
        tmp=tmp->prev;
    }
    qsort(Arr, i, sizeof(struct utwor*), comparator);
    ogon = tmp = *Arr;
    ogon->next=NULL;
    k=1;
    while (k<i)
    {
        tmp = tmp->prev = Arr[k];
        tmp->next = Arr[k-1];
        k++;
    }
    tmp->prev = NULL;
    glowa=tmp;
    free(Arr);

    }


}

