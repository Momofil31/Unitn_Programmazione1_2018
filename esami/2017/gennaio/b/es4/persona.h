#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_DIM = 40;

struct persona {
	char nome[MAX_DIM];
	char cognome[MAX_DIM];
	char indirizzo[MAX_DIM];
	int ntel;
};

persona * crea_persona(char * nome,char *, char *,int);
persona * leggi_persona();
void stampa_persona(persona * p);

#endif
