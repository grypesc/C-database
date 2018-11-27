#include <stdio.h>
#include <stdlib.h>

int main();

struct t_pole_listy 
{	
	char imie[14];
	char nazwisko[20];
	char ugrupowanie[32];
    char liczba_glosow[17];
	char wiek[7];
	char okreg_wyborczy[22];
	struct t_pole_listy *nastepny;
	
} ; 
struct t_pole_listy* poczatek;

typedef struct Ugrupowanie
{
	char nazwa[32];
	struct Ugrupowanie *nast;
} ugrupowanie;

ugrupowanie *u_poczatek;

#define MAX_IMIE 12
#define MAX_NAZWISKO 18
#define MAX_UGRUPOWANIE 30
#define MAX_LICZBA_GLOSOW 15
#define MAX_WIEK 5
#define MAX_OKREG_WYBORCZY 20
#define MAX_KOMENDA 30

int liczba_wierszy_bazy;
char komenda[32];

int pobierz_komende();