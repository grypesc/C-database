#include "main.h"
#include "zapis_odczyt.h"
#include "edycja.h"
#include "sortowanie.h"

/////////////////////////////////////////////////

void wypisz_rekord (int numer, struct t_pole_listy *aktualny)
{
    if(numer>=10)
        printf("%d. " , numer); 
    else
        printf(" %d. " , numer);
        
    int i=0;
    while((aktualny->imie)[i]!=' ')
    {   
        printf("%c", (aktualny->imie)[i]);
        i++;
    }
    for(i=MAX_IMIE-i+2;i>=1;i--)
        printf(" ");
        
    while((aktualny->nazwisko)[i]!=' ')
    {   
        printf("%c", (aktualny->nazwisko)[i]);
        i++;
    }
    for(i=MAX_NAZWISKO-i+2;i>=1;i--)
        printf(" ");

    while((aktualny->ugrupowanie)[i]!=' ')
    {   
        printf("%c", (aktualny->ugrupowanie)[i]);
        i++;
    }
    for(i=MAX_UGRUPOWANIE-i+2;i>=1;i--)
        printf(" ");       
    
    while((aktualny->liczba_glosow)[i]!=' ')
    {   
        printf("%c", (aktualny->liczba_glosow)[i]);
        i++;
    }
    for(i=MAX_LICZBA_GLOSOW-i+2;i>=1;i--)
        printf(" ");

    while((aktualny->wiek)[i]!=' ')
    {   
        printf("%c", (aktualny->wiek)[i]);
        i++;
    }
    for(i=MAX_WIEK-i+2;i>=1;i--)
        printf(" ");
        
    while((aktualny->okreg_wyborczy)[i]!=' ')
    {   
        printf("%c", (aktualny->okreg_wyborczy)[i]);
        i++;
    }
    for(i=MAX_OKREG_WYBORCZY-i+2;i>=1;i--)
        printf(" ");
        
    printf("\n");
}

void wypisz_baze ()
{
	if (liczba_wierszy_bazy==0) {
		puts("Baza jest pusta"); 
		return;}
	puts("Imie              Nazwisko            Ugrupowanie                     Liczba glosow    Wiek   Okreg wyborczy\n");
	struct t_pole_listy *aktualny;
	int i=1;
	for (aktualny=poczatek; aktualny!=NULL; aktualny=aktualny->nastepny)
	{
		wypisz_rekord(i, aktualny);
		i++;
	}
	puts("");
}

int pobierz_komende()
{
    char pom;
    int i=0;
    while(1)
    {
        scanf("%c", &pom);
        if (pom=='\n')
        {
            komenda[i]='\0';
            return 0;
        }
            
        if (i>=MAX_KOMENDA)
            return -1;
        komenda[i]=pom;
        i++;
    }
}

void czysc_ekran()
{
	printf("\033[2J"); 
	printf("\033[0;0f"); 
}


int main()
{
	int pom;
    liczba_wierszy_bazy=0;
	poczatek=NULL;
	czysc_ekran();
	puts("Grzegorz Rypesc Grupa 2\nProjekt nr 3\nDynamiczna baza danych - Lista Wyborcza");
	wczytaj_ugrupowanie();
////////////////////////////////////////////////////////////////////////////
    while(1)
    {
        if(pobierz_komende()==-1)
            while(getchar()!='\n');
////////////////////////////////////////////////////////////////////////////     
        if(strcmp(komenda, "pomoc" )==0) 
			{
				czysc_ekran();
				puts("Dostepne komendy:\n\nwczytaj   zapisz\ndodaj   usun   edytuj\nsortuj   wyczysc\nwyswietl   rozmiar\nwyjdz\n");
				continue;
			}
////////////////////////////////////////////////////////////////////////////     
        if(strcmp(komenda, "wczytaj" )==0) 
        {
            puts("Podaj sciezke do pliku txt zawierajacego nowa baze, stara baza zostanie wymazana z pamieci");
            pobierz_komende(); 
			wczytaj_baze(komenda)?puts("Pliku nie udalo sie otworzyc, lub zawiera on niepoprawne dane."), wyczysc():puts("Baze wczytano pomyslnie");
			continue;
        }
///////////////////////////////////////////////////////////////////////////
        if(strcmp(komenda, "wyswietl")==0) 
		{
			czysc_ekran();
			wypisz_baze();
			continue;
		}
///////////////////////////////////////////////////////////////////////////
		if(strcmp(komenda, "usun")==0)
		{
			puts("Podaj numer rekordu, ktory chcesz usunac");
			if (scanf("%d", &pom)==1 && usun_rekord(pom)==0)
				puts("Rekord usuniety");
			else
				puts ("Wprowadzono zla liczbe");
			while(getchar()!='\n');
			continue;
		}
////////////////////////////////////////////////////////////////////////////
		if(strcmp(komenda, "wyjdz")==0)
			return 0;
////////////////////////////////////////////////////////////////////////////
		if(strcmp(komenda, "wyczysc")==0)
		{
			wyczysc();
			puts ("Baza usunieta z pamieci");
			continue;
		}
////////////////////////////////////////////////////////////////////////////
		if(strcmp(komenda, "rozmiar")==0)
		{
			printf("Baza ma %d rekordow\n", liczba_wierszy_bazy);
			continue;
		}
////////////////////////////////////////////////////////////////////////////
		if(strcmp(komenda, "dodaj")==0)
		{
			puts("Wpisz tresc rekordu");
			if(dodaj_rekord()==0) puts("Wiersz dodany do bazy");
			else puts ("Podany wiersz nie jest poprawny i nie zostal dodany do bazy");
			continue;
		}
/////////////////////////////////////////////////////////////////////////////
		if(strcmp(komenda, "sortuj")==0)
		{
			puts("Wpisz wg. jakiego klucza chcesz posortowac rekordy");
			if(pobierz_komende()==-1)
			{
				while(getchar()!='\n');
				puts("Podano zly ciag znakow");
				continue;
			}
				if(posortuj(komenda)==0)
					puts("Baze posortowano");
				if(posortuj(komenda)==-1)
					puts("Podana komenda nie jest kluczem");
				if(posortuj(komenda)==-2)
					puts("Baza jest pusta, nie mozna posortowac");
			continue;
		}
/////////////////////////////////////////////////////////////////////////////
		if(strcmp(komenda, "edytuj")==0)
		{
			puts("Ktory rekord chcesz edytowac?");
			if(scanf ("%d", &pom)!=1)
			{
				while(getchar()!='\n');
				puts("Podano zly numer");
				continue;
			}
			while(getchar()!='\n');
			puts("Ktore pole?");
			if(pobierz_komende()==-1)
				{
					while(getchar()!='\n');
					puts ("Podane pole nie istnieje, rekord nie zostanie zmieniony");
				}
			else
			{
				switch(edytuj_rekord(komenda, pom))
				{
					case 0:
						puts("Rekord zostal zmieniony");
						break;
					case 1:
						puts("Nowe ugrupowanie dodane");
						break;
					case -1:
						puts("Podano zly ciag znakow");
						break;
					case -2:
						puts("Podane pole nie istnieje");
						break;
					case 2:
						puts("Ugrupowanie usuniete");
						break;
					case -10:
						puts("Baza jest pusta. Nie mozna edytowac");
						break;
					case -4:
						puts("Nie ma ugrupowan do usuniecia ");
						break;
				}
			}
			continue;
		}
/////////////////////////////////////////////////////////////////////////////
		if(strcmp(komenda, "zapisz")==0)
		{
			puts("Podaj sciezke do pliku, w ktorym baza zostanie zapisana");
			if(pobierz_komende()==-1)
				{
					while(getchar()!='\n');
					puts ("Bledna nazwa");
				}
				zapisz(komenda);
				puts("Zapisano");
			continue;
		}
////////////////////////////////////////////////////////////////////////////
       puts("Niewlasciwa komenda, wpisz pomoc, aby wyswietlic dostepne komendy");     
    }
    return 0;
}
