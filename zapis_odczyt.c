#include "zapis_odczyt.h"
#include "main.h"
#include "edycja.h"
#include "sortowanie.h"

int wczytaj_baze(char nazwa_pliku[])
{
    FILE *f=fopen(nazwa_pliku,"r");
	if (f==NULL) return -1;
    char pom;
    int i=0, poziom=1;
    liczba_wierszy_bazy=1;
   	poczatek = malloc(sizeof(struct t_pole_listy)); 
	struct t_pole_listy *aktualny=poczatek, *poprzedni=NULL;

    while(fscanf(f,"%c", &pom)!=EOF)
    {
		if (pom=='\n')
		{
			poprzedni=aktualny;
			aktualny->nastepny=malloc(sizeof(struct t_pole_listy));
			aktualny=aktualny->nastepny;
			i=0;
			poziom=1;
			liczba_wierszy_bazy++;
		}
		else
		{
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
						poziom=7;
					}
						
                    if (i>=MAX_OKREG_WYBORCZY+1)
							return -1;
                    break;
            }
			
		}
	}
	
	if (poziom!=7)
	{
		free(aktualny);
		aktualny=poprzedni;
		liczba_wierszy_bazy--;
	}
	if(poprzedni==NULL)
	{
		fclose(f);
		poczatek=NULL;
		return -1;
	}
	aktualny->nastepny=NULL;
    fclose(f);
    return 0;
}


int zapisz (char nazwa[])
{
	FILE* f;
	f=fopen(nazwa,"w");
	if(f==NULL) return -1;
	
	struct t_pole_listy* aktualny;
	for(aktualny=poczatek; aktualny!=NULL; aktualny=aktualny->nastepny)
		fprintf(f, "%s%s%s%s%s%s\n", aktualny->imie, aktualny->nazwisko, aktualny->ugrupowanie, aktualny->liczba_glosow, aktualny->wiek, aktualny->okreg_wyborczy);

	fclose(f);
	return 0;
}



