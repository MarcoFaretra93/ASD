#ifndef GestioneRistorante_portate_h
#define GestioneRistorante_portate_h

typedef char string[50];

typedef struct {
    int prezzo;
    string descrizione;
} portate;


typedef struct nodoPortate {
    portate info;
    struct nodoPortate* next;
} nodoPortate;

typedef nodoPortate* listaPortate;

void addPortata(listaPortate*, int, string);
int mediaPortate(listaPortate);
void stampaPortate(listaPortate);

#endif
