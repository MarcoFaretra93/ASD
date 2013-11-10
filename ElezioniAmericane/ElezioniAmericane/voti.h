#ifndef ElezioniAmericane_voti_h
#define ElezioniAmericane_voti_h

#include "lista.h"

/*  Restituisce 1 se il voto è valido
 e 0 se non lo è */
int isVotoValido(plist, plist);

/*  Restituisce il numero di voti non validi in una
 lista di voti */
int votiValidi(plist, plist);

/*  Restituisce il codice di una persona dal nome
    e dal cognome */
char* getCodiceByNomeECognome(plist, string, string);

/*  Dati nome e cognome di un candidato restituisce
 il numero di voti ottenuti da un candidato */
int votiCandidato(plist, plist, string, string);

#endif
