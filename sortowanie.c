#include "main.h"
#include "zapis_odczyt.h"
#include "edycja.h"
#include "sortowanie.h"



int cmp_imie(const void * a, const void * b)
{
	struct t_pole_listy** p=(struct t_pole_listy**)a; 
	struct t_pole_listy** q=(struct t_pole_listy**)b;
	char P[MAX_IMIE];
	strcpy(P,(*p)->imie);
	char Q[MAX_IMIE];
	strcpy(Q,(*q)->imie);
	return (strcmp(P, Q));
}

int cmp_nazwisko(const void * a, const void * b)
{
	struct t_pole_listy** p=(struct t_pole_listy**)a; 
	struct t_pole_listy** q=(struct t_pole_listy**)b;
	char P[MAX_NAZWISKO];
	strcpy(P,(*p)->nazwisko);
	char Q[MAX_NAZWISKO];
	strcpy(Q,(*q)->nazwisko);
	return (strcmp(P, Q));
}

int cmp_ugrupowanie(const void * a, const void * b)
{
	struct t_pole_listy** p=(struct t_pole_listy**)a; 
	struct t_pole_listy** q=(struct t_pole_listy**)b;
	char P[MAX_UGRUPOWANIE];
	strcpy(P,(*p)->ugrupowanie);
	char Q[MAX_UGRUPOWANIE];
	strcpy(Q,(*q)->ugrupowanie);
	return (strcmp(P, Q));
}

int cmp_glosy(const void * a, const void * b)
{
	struct t_pole_listy** p=(struct t_pole_listy**)a; 
	struct t_pole_listy** q=(struct t_pole_listy**)b;
	char P[MAX_LICZBA_GLOSOW];
	strcpy(P,(*p)->liczba_glosow);
	char Q[MAX_LICZBA_GLOSOW];
	strcpy(Q,(*q)->liczba_glosow);
	
	int Q_len, P_len, i;
	
		for (i=0;i<100;i++)
		{
			if (Q[i]==' ')
				break;
		}
	Q_len=i;
	for (i=0;i<100;i++)
	{
		if (P[i]==' ')
			break;
	}
	P_len=i;
	
	if (Q_len>P_len)
		return -1;
	if (P_len>Q_len)
		return 1;
	return (strcmp(P, Q));
}

int cmp_wiek(const void * a, const void * b)
{
	struct t_pole_listy** p=(struct t_pole_listy**)a; 
	struct t_pole_listy** q=(struct t_pole_listy**)b;
	char P[MAX_WIEK];
	strcpy(P,(*p)->wiek);
	char Q[MAX_WIEK];
	strcpy(Q,(*q)->wiek);
	
	int Q_len, P_len, i;
	
		for (i=0;i<100;i++)
		{
			if (Q[i]==' ')
				break;
		}
	Q_len=i;
	for (i=0;i<100;i++)
	{
		if (P[i]==' ')
			break;
	}
	P_len=i;
	
	if (Q_len>P_len)
		return -1;
	if (P_len>Q_len)
		return 1;
	return (strcmp(P, Q));
}

int cmp_okreg(const void * a, const void * b)
{
	struct t_pole_listy** p=(struct t_pole_listy**)a; 
	struct t_pole_listy** q=(struct t_pole_listy**)b;
	char P[MAX_OKREG_WYBORCZY];
	strcpy(P,(*p)->okreg_wyborczy);
	char Q[MAX_OKREG_WYBORCZY];
	strcpy(Q,(*q)->okreg_wyborczy);
	return (strcmp(P, Q));
}

int posortuj(char jak[])
{
	if (liczba_wierszy_bazy==0)
		return -2;
		
	int i;
	struct t_pole_listy* wsk_tab[liczba_wierszy_bazy];
	struct t_pole_listy* aktualny;
	aktualny=poczatek;
	for (i=0;i<=liczba_wierszy_bazy-1;i++)
	{
		wsk_tab[i]=aktualny;
		aktualny=aktualny->nastepny;
	}
	
	int f=0;
	
	if(strcmp(jak, "imie")==0)
		qsort(wsk_tab,liczba_wierszy_bazy,sizeof(struct t_pole_listy*),cmp_imie), f=1;
	if(strcmp(jak, "nazwisko")==0)
		qsort(wsk_tab,liczba_wierszy_bazy,sizeof(struct t_pole_listy*),cmp_nazwisko), f=1;
	if(strcmp(jak, "ugrupowanie")==0)
		qsort(wsk_tab,liczba_wierszy_bazy,sizeof(struct t_pole_listy*),cmp_ugrupowanie), f=1;
	if(strcmp(jak, "glosy")==0)
		qsort(wsk_tab,liczba_wierszy_bazy,sizeof(struct t_pole_listy*),cmp_glosy), f=1;
	if(strcmp(jak, "wiek")==0)
		qsort(wsk_tab,liczba_wierszy_bazy,sizeof(struct t_pole_listy*),cmp_wiek), f=1;
	if(strcmp(jak, "okreg")==0)
		qsort(wsk_tab,liczba_wierszy_bazy,sizeof(struct t_pole_listy*),cmp_okreg), f=1;
		
		if (f==0)
			return -1;

	poczatek=wsk_tab[0];
	aktualny=poczatek;

	for (i=1;i<=liczba_wierszy_bazy-1;i++)
	{
		aktualny->nastepny=wsk_tab[i];
		aktualny=wsk_tab[i];
	}
	aktualny->nastepny=NULL;
	return 0;
}
