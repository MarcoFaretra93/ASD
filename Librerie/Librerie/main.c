/*  GESTIONE LIBRERIE
 
 Lista di Librerie
 ID
 Nome
 Città
 Lista di Libri
 
 Lista di libri
 ID
 Titolo
 Autore
 Prezzo
 
 Implementare lista di librerie e di libri
 - Rimozione di un libro in una libreria in base all'autore
 - Inserimento dei libri in ordine crescente (In Base all'ID)
 - Restituire il numero di libri in comune tra due librerie
 - Restituire il numero di libri in una libreria scritti dall'autore X*/

#include <stdio.h>
#include "librerie.h"
#include <string.h>

int main(int argc, const char * argv[]) {
    listaLibri l1;
    listaLibri l2;
    listaLibrerie n1;
    libreria lib1;
    libreria lib2;
    string titolo1="Cazzetti";
    string autore1="Marco";
    string titolo2="Fregnette";
    string autore2="Federico";
    
    addLibro(&l1, 4, titolo1, autore1, 35);
    stampaLibri(l1);
    addLibro(&l1, 1, titolo2, autore2, 44);
    addLibro(&l2, 1, titolo1, autore1, 35);
    addLibro(&l2, 3, "il grande stronzo", "Alessio", 55);
    printf("%d\n",lengthLibri(l1));
    rimuoviTesta(&l1);
    stampaLibri(l1);
    printf("%d\n",libriComune(l1, l2));
    addLibreria(&n1, 1, "Elsa Morante", "Roma", l1);
    addLibreria(&n1, 2, "Biblioteca2", "Milano", l2);
    
    stampaLibrerie(n1);
    inserisciLibroCrescente(&l1, 2, "porca troia", "Pippo", 77);
    stampaLibri(l1);
    inserisciCrescente(&n1, 1, 2, "porca eva", "Luca", 88);
    stampaLibrerie(n1);
    lib1.ID=1;
    lib1.libri=l1;
    strcpy(lib1.nome, "biblioteca1");
    strcpy(lib1.città, "Roma");
    lib2.ID=4;
    lib2.libri=l2;
    strcpy(lib2.nome, "biblioteca2");
    strcpy(lib2.città, "Milano");
    printf("%d\n",libriComuniLibrerie(lib1, lib2));
    printf("%d\n",libriComuniAutore(n1, "Marco"));
    
}
