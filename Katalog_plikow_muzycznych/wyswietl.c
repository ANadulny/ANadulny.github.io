//****************FUNKCJA WYSWIETLAJACA OBECNA BAZE***********************************

int wyswietl()
{
    if(glowa == NULL)
    {
        do
        {
            system("clear");
            puts("Baza danych jest pusta. Wprowadz dane.\n");
            puts("[1]Cofnij");
        }while(getchar()!='1');
        return 2;
    }
    struct utwor *tmp;

        tmp=glowa;
        system("clear");
        puts("| nr |\t      nazwa autora      \t| \t   tytul utworu   \t    |          nazwa albumu          | czas utworu | typ bitrate w kbps | rozmiar pliku w MB |\n");
        while(tmp != NULL)
        {
            if((tmp->czas_utworu)%60>9)
            {
            puts("----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
            printf("| %-3i|   %-30s |   %-30s  | %-30s |     %d:%d    |        %-7d     |     %8.2f       |\n", tmp->id, tmp->nazwa_autora, tmp->tytul, tmp->nazwa_albumu, (tmp->czas_utworu)/60, (tmp->czas_utworu)%60, tmp->typ_bitrate, tmp->rozmiar);
            tmp = tmp -> next;
            }
            else
            {
            puts("----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
            printf("| %-3i|   %-30s |   %-30s  | %-30s |     %d:0%d    |        %-7d     |     %8.2f       |\n", tmp->id, tmp->nazwa_autora, tmp->tytul, tmp->nazwa_albumu, (tmp->czas_utworu)/60, (tmp->czas_utworu)%60, tmp->typ_bitrate, tmp->rozmiar);
            tmp = tmp -> next;
            }
        }
            puts("----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    return 1;
}


