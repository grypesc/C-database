#include "edycja.h"
#include "zapis_odczyt.h"
#include "main.h"
#include "ugrupowanie.h"


int usun_rekord (int ktory)
{
	if (ktory>liczba_wierszy_bazy || ktory<=0)
		return -1;
		
	struct t_pole_listy *aktualny, *poprzedni;
	if (poczatek==NULL) 
		return -1;
		
	int i=0;
	if (ktory==1)
	{
		aktualny=poczatek;
		poczatek=poczatek->nastepny;
		free(aktualny);
		liczba_wierszy_bazy--;
		return 0;
	}
	
	for(aktualny=poczatek;aktualny!=NULL;aktualny=aktualny->nastepny)
	{
		
		i++;
		if (i==ktory)
		{
			poprzedni->nastepny=aktualny->nastepny;
			free(aktualny);
			liczba_wierszy_bazy--;
			return 0;
		}
		poprzedni=aktualny;
	}
	return -1;
}

void wyczysc ()
{
	struct t_pole_listy *do_usuniecia, *pom;

	for (do_usuniecia=poczatek; do_usuniecia!=NULL; do_usuniecia=pom)
	{
		pom=do_usuniecia->nastepny;
		free(do_usuniecia);
	}
	liczba_wierszy_bazy=0;
	poczatek=NULL;
}

int dodaj_rekord()
{
	char pom;
	int poziom=1, i=0;
	struct t_pole_listy *aktualny = malloc(sizeof(struct t_pole_listy));
	int stary_rozmiar=liczba_wierszy_bazy;
	
	while (1)
	{
		scanf ("%c", &pom);
		if(pom=='\n') 
			break;
		switch(poziom)
            {
                case 1:
                    (aktualny->imie)[i]=pom;
                    i++;     
                    if (pom==' ')
                    {
                    (aktualny->imie)[i]='\0';
                        poziom=2, 
                        i=0;
                    }
                    if (i>=MAX_IMIE+1)
                        return -1;
                    break;
                    
                case 2:
                    (aktualny->nazwisko)[i]=pom;
                    i++;
                    if (pom==' ')
                    {
						(aktualny->nazwisko)[i]='\0';
                        poziom=3, 
                        i=0;
                    }
                    if (i>=MAX_NAZWISKO+1)
                        return -1;
                    break;
                    
                case 3:
                    (aktualny->ugrupowanie)[i]=pom;
                    i++;
                    if (pom==' ')
                    {
						(aktualny->ugrupowanie)[i]='\0';
                        poziom=4, 
                        i=0;
                    }
                    if (i>=MAX_UGRUPOWANIE+1)
                        return -1;
                    break;
                    
                case 4:
                    (aktualny->liczba_glosow)[i]=pom;
                    i++;
                    if (pom==' ')
                    {
						(aktualny->liczba_glosow)[i]='\0';
                        poziom=5, 
                        i=0;
                    }
                    if (i>=MAX_LICZBA_GLOSOW+1)
                        return -1;
                    break;
                    
                case 5:
                    (aktualny->wiek)[i]=pom;
                    i++;
                    if (pom==' ')
                    {
						(aktualny->wiek)[i]='\0';
                        poziom=6, 
                        i=0;
                    }
                    if (i>=MAX_WIEK+1)
                        return -1;
                    break;
                    
                case 6:
                    (aktualny->okreg_wyborczy)[i]=pom;
                    i++;
                    if (pom==' ')
						{
							(aktualny->okreg_wyborczy)[i]='\0';
							liczba_wierszy_bazy++;	
							poziom=7;
						}
                    if (i>=MAX_OKREG_WYBORCZY+1)
                        return -1;
                    break;
            }
	}
	
	if(liczba_wierszy_bazy==stary_rozmiar+1) 
	{
		aktualny->nastepny=poczatek;
		poczatek=aktualny;
		return 0;
	}
	else 
	{
		free(aktualny);
		return -1;
	}
}


int edytuj_rekord (char ktore[], int numer) 
{
	if (numer>liczba_wierszy_bazy || numer<=0)
		return -10;
	
	struct t_pole_listy* aktualny;
	aktualny = poczatek;
	int i=1;
	while (i!=numer)
	{
		aktualny=aktualny->nastepny;
		i++;
	}
	i=0;
	if (strcmp(ktore, "imie")==0)
	{
		puts("Podaj nowe imie");
		while(1)
		{
			scanf("%c", &((aktualny->imie)[i]));
			
			if ((aktualny->imie[i])=='\n')
			{
				(aktualny->imie)[i]=' ';
				(aktualny->imie)[i+1]='\0';
				return 0;
			}
			if ((aktualny->imie)[i]==' ')
				return -1;
			if (i>=MAX_IMIE)
				{
					((aktualny->imie)[i]=' ');
					return -1;
				}
			i++;
		}
	}
	
	if (strcmp(ktore, "nazwisko")==0)
	{
		puts("Podaj nowe nazwisko");
		while(1)
		{
			scanf("%c", &((aktualny->nazwisko)[i]));
			
			if (aktualny->nazwisko[i]=='\n')
			{
				aktualny->nazwisko[i+1]='\0';
				aktualny->nazwisko[i]=' ';
				return 0;
			}
			if (aktualny->nazwisko[i]==' ')
				return -1;
			if (i>=MAX_NAZWISKO)
				{
					(aktualny->nazwisko[i]=' ');
					return -1;
				}
			i++;
		}
	}
	
	if (strcmp(ktore, "ugrupowanie")==0) ////////////////////////Szajs
	{
		int pom;
		puts("Wybierz jedno z ponizszych ugrupowan podajac jego numer lub:\n0 Dodaj nowe ugrupowanie\n-1 Usun ugrupowanie\n-2 Edytuj ugrupowanie.\n");
		wyswietl_ugrupowania();
		if (scanf("%d", &pom)!=1)
		{
			while(getchar()!='\n');
			return -2;
		}
		while(getchar()!='\n');
		if (pom==0)
		{
			puts("Podaj nowe ugrupowanie");
			if (pobierz_komende()!=0) 
			{
				while(getchar()!='\n');

				puts("Bledna nazwa, ugrupowanie nie zostalo dodane.");
				return -999;
			}
			dodaj_ugrupowanie(komenda);
			return 1;
		}
				if (pom==-1)
					return usun_ugrupowanie();
				if (pom==-2){
					edytuj_ugrupowanie();
					return;}
				
			
		
		ugrupowanie *akt;
		int j=1;
		for (akt=u_poczatek;akt!=NULL;akt=akt->nast)
		{
			if (j==pom)
				break;
			j++;
		}
		if (akt==NULL){
			puts("Podano niewlasciwa liczbe");
			return;
		}
		strcpy(aktualny->ugrupowanie, akt->nazwa);
			
			return 0;
	}
	
	if (strcmp(ktore, "glosy")==0)
	{
		puts("Podaj nowa liczbe glosow");
		while(1)
		{
			scanf("%c", &((aktualny->liczba_glosow)[i]));
			
			if (aktualny->liczba_glosow[i]=='\n')
			{
				aktualny->liczba_glosow[i+1]='\0';
				aktualny->liczba_glosow[i]=' ';
				return 0;
			}
			if (aktualny->liczba_glosow[i]==' ')
				return 10;
			if (i>=MAX_LICZBA_GLOSOW)
				{
					((aktualny->liczba_glosow)[i]=' ');
					return -1;
				}
			i++;
		}
	}
	
	if (strcmp(ktore, "wiek")==0)
	{
		puts("Podaj nowy wiek");
		while(1)
		{
			scanf("%c", &((aktualny->wiek)[i]));
			
			if (aktualny->wiek[i]=='\n')
			{
				aktualny->wiek[i+1]='\0';
				aktualny->wiek[i]=' ';
				return 0;
			}
			if (aktualny->wiek[i]==' ')
				return 10;
			if (i>=MAX_WIEK)
				{
					((aktualny->wiek)[i]=' ');
					return -1;
				}
			i++;
		}
	}
	
	if (strcmp(ktore, "okreg")==0)
	{
		puts("Podaj nowy okreg wyborczy");
		while(1)
		{
			scanf("%c", &((aktualny->okreg_wyborczy)[i]));
			
			if ((aktualny->okreg_wyborczy)[i]=='\n')
			{
				(aktualny->okreg_wyborczy)[i+1]='\0';
				(aktualny->okreg_wyborczy)[i]=' ';
				return 0;
			}
			if ((aktualny->okreg_wyborczy)[i]==' ')
				return 10;
			if (i>=MAX_OKREG_WYBORCZY)
				{
					((aktualny->okreg_wyborczy)[i]=' ');
					return -1;
				}
			i++;
		}
	}
	
	return -2;
}
























