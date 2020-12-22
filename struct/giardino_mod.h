#ifndef __GIARDINO_H_
#define __GIARDINO_H_

const int NUMERO_SPECIE = 5;

enum Specie {PINO, ROVERE, FAGGIO, ABETE, NOCE};
const char nomiSpecie[NUMERO_SPECIE] = {'P', 'R', 'F', 'A', 'N'};

struct Albero {
	Specie nome_specie;
	int numero_id;
};

typedef Albero* puntAlbero;

puntAlbero** preparaGiardino(int, int );
void riempiGiardino(puntAlbero**, int, int, int [] );
void stampaGiardino(puntAlbero**, int, int );
void eliminaGiardino(puntAlbero**, int, int );

#endif
