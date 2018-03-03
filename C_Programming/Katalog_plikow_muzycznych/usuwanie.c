//****************FUNKCJA USUWAJACA UTWOR Z OBECNEJ BAZY***********************************

void usun()
{
    int nr_usuwanie;
    system("clear");
    if(wyswietl() == 2) return;
    puts("Podaj nr utworu ktory chcesz usunac");
    if(scanf("%i",&nr_usuwanie)!=1 || nr_usuwanie<=0 || nr_usuwanie>=nr)  // petla sprawdzajaca czy zostal podany poprawny numer
    {
        do
        {
            system("clear");
            while(getchar()!='\n');             // petla czyszczaca bufor
            if(nr_usuwanie>=nr) puts ("baza nie zawiera utworu o podanym numerze");
            puts("\n[1]Cofnij");
        }while(getchar()!='1');
        return;
    }
    struct utwor *tmp=glowa;
    while(tmp != NULL)
    {
        if(tmp->id==nr_usuwanie)   //sprawdzenie czy podany numer znajduje sie w bazie
        {
            struct utwor *pomocnicza;
            free(tmp->nazwa_autora);
            free(tmp->tytul);
            free(tmp->nazwa_albumu);
            free(tmp);
            if(tmp==glowa && tmp==ogon)
                glowa=ogon=NULL;
            else if(tmp==glowa)
            {
                pomocnicza=tmp->next;
                glowa=pomocnicza;
                pomocnicza->prev=NULL;
            }
            else if(tmp==ogon)
            {
                pomocnicza=tmp->prev;
                ogon=pomocnicza;
                pomocnicza->next=NULL;
            }
            else
            {
                pomocnicza=tmp->prev;
                pomocnicza->next=tmp->next;
                pomocnicza=tmp;
                tmp=tmp->next;
                tmp->prev=pomocnicza->prev;
            }
            tmp=NULL;
            return;
        }
        tmp = tmp -> next;
    }
    do
    {
        while(getchar()!='\n');         // petla czyszczaca bufor
        system("clear");
        puts ("baza nie zawiera utworu o podanym numerze\n");
        puts("[1]Cofnij");
    }while(getchar()!='1');
}

//******************FUNKCJA DO USUWANIA STRUKTURY BAZY*****************************************

void usun_baze()
{
    struct utwor *tmp=glowa;
    if(tmp==NULL)
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
}
