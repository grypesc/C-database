#include "ugrupowanie.h"
#include "main.h"

void wczytaj_ugrupowanie()
{
	ugrupowanie* aktualny;
	u_poczatek=malloc(sizeof(ugrupowanie));
	strcpy(u_poczatek->nazwa,"KWW_Sczesc_Boze ");
	u_poczatek->nast=malloc(sizeof(ugrupowanie));
	aktualny=u_poczatek->nast;
	strcpy(aktualny->nazwa,"Kolo_Gospodyn_Wiejskich ");
	
	aktualny->nast=malloc(sizeof(ugrupowanie));
	aktualny=aktualny->nast;
	strcpy(aktualny->nazwa,"Kandydat_niezalezny ");
	
	aktualny->nast=malloc(sizeof(ugrupowanie));
	aktualny=aktualny->nast;
	strcpy(aktualny->nazwa,"Unia_Wolnosci ");
	
	aktualny->nast=malloc(sizeof(ugrupowanie));
	aktualny=aktualny->nast;
	strcpy(aktualny->nazwa,"Staroswiecka.de ");
	
	aktualny->nast=NULL;
	
}


void wyswietl_ugrupowania()
{
	ugrupowanie* aktualny;
	int i=1;
	for(aktualny=u_poczatek;aktualny!=NULL;aktualny=aktualny->nast)
	{
		printf ("%d. %s\n",i,aktualny->nazwa);
		i++;
	}
	
}

void dodaj_ugrupowanie (char napis[])
{
	int a=strlen(napis);
	napis[a]=' ';
	napis[a+1]='\0';
	ugrupowanie *nowy;
	nowy=malloc(sizeof(ugrupowanie));
	nowy->nast=u_poczatek;
	u_poczatek=nowy;
	strcpy(nowy->nazwa, napis);
}

int usun_ugrupowanie()
{
	puts("Podaj numer ugrupowania ktory chcesz usunac");
	int i=1,pom;
	ugrupowanie *aktualny=u_poczatek, *poprzedni=u_poczatek;
	if (scanf("%3d", &pom)!=1)
		{
			while(getchar()!='\n');
			puts ("Podano zla liczbe");
			return -999;
		}
		while(getchar()!='\n');
	if(liczba_wierszy_bazy==0)
		return -4;
	
	if (pom==1)
	{
		u_poczatek=u_poczatek->nast;
		free(aktualny);
		return 2;
	}
	
	for(aktualny=u_poczatek;aktualny!=NULL;aktualny=aktualny->nast)
	{
		if (i>=pom)
		{
			poprzedni->nast=aktualny->nast;
			free(aktualny);
			return 2;
		}
		i++;
		poprzedni=aktualny;
	}
		return -2;
}

void edytuj_ugrupowanie()
{
	puts("Podaj numer ugrupowania, które chcesz edytowac");
	int pom,i=1;
	if (scanf("%d", &pom)!=1 || pom<1)
	{
		puts("Podane ugrupowanie nie istnieje");
		while(getchar()!='\n');
		return;
	}
	while(getchar()!='\n');	 
	ugrupowanie *aktualny;
	for(aktualny=u_poczatek;aktualny!=NULL;aktualny=aktualny->nast)
	{
		if (pom==i)
			break;
		i++;
	}
	if (aktualny==NULL)
	{
		puts ("Podane ugrupowanie nie istnieje");
		return;
	}
	puts("Podaj nowa nazwe ugrupowania");
	if(pobierz_komende()!=0){
		puts("Podano niedozwolony ciag znakow");
		return;}
	strcpy(aktualny->nazwa,komenda);
	int a=strlen(aktualny->nazwa);
	(aktualny->nazwa)[a]=' ';
	(aktualny->nazwa)[a+1]='\0';	
	puts("Ugrupowanie zostalo zmienione");
}
				
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	