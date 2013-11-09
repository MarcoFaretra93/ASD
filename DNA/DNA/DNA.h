#ifndef DNA_DNA_h
#define DNA_DNA_h

#include <stdio.h>

typedef struct nodoDNA {
    char info;
    struct nodoDNA* next;
} nodoDNA;

typedef nodoDNA* DNA;

// Genera una sequenza casuale di DNA con DIM caratteri.
void DNAGen(DNA*, int);

// Aggiunge un nodo al DNA
void addNodo(DNA*, char);

// Controlla che sia un nodo di DNA valido
int nodoValido(nodoDNA);

// Controlla che il DNA sia valido (A, G, C, T)
int DNATest(DNA);

// Restituisce la lunghezza del DNA
int lunghezzaDNA(DNA);

// Cancella in testa
void rimuoviInTesta(DNA*);

// Cancella in una posizione precisa
void rimuoviInPosizionePrecisa(DNA*, int);

// Cancella un carattere dal DNA
void deleteDNA(DNA*, char);

// Inverte le sequenze del DNA
void invertitoDNA(DNA*);

// Inverte le i nodi passati
void invertiNodiDNA(DNA*, char, char);

// Controlla che ad ogni nodo GA e TC o AG e CT
int matchDNA(DNA, DNA);

// Controlla che le due sequenze di DNA siano a specchio
int windowDNA(DNA, DNA);

// Confronta che ci siano almeno t nodi uguali
int confrontaDNA(DNA, DNA, int);

// Crea una terza lista che contiene i nodi uguali nelle prime due liste
void commonDNA(DNA, DNA, DNA*);

// Stampa la lista di DNA
void stampaDNA(DNA);

#endif