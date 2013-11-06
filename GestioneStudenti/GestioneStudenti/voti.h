#ifndef GestioneStudenti_voti_h
#define GestioneStudenti_voti_h

typedef struct nodoVoto {
    int info;
    struct nodoVoto* next;
} nodoVoto;

typedef nodoVoto* listaVoti;

void addVoto(listaVoti*, int);
void printVoti(listaVoti);
float mediaVoti(listaVoti);

#endif