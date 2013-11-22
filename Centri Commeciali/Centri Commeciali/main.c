/*CENTRI_COMMERCIALI
 ID
 NOME
 LUOGO
 LISTA_PRODOTTI
 
 PRODOTTI
 (i prodotti per ipotesi ordinati per ID in maniera crescente)
 ID
 NOME
 CATEGORIA (es: cucina, casa, elettronica ecc..)
 PREZZO
 
 1) Data una categoria, contare quanti prodotti appartenenti a quella categoria sono presenti in tutti i centri commerciali.
 
 1 AUCHAN ROMA:
 1-cucina-aspirapolvere-222
 2-elettronica-pc-999
 
 2 EUROMA ROMA:
 1-elettronica-cuffie-333
 2-casa-cazzo-333
 
 metodo(listaCentri, "elettronica")
 
 restituirà 2
 
 
 2) Implementare una funzione per inserire un prodotto (mantenendo ordinata la lista per ID).
 
 3) Dati gli ID di due centri commerciali, contare il numero di prodotti in comune
 
 1 AUCHAN ROMA:
 1-cucina-aspirapolvere-222
 2-elettronica-pc-999
 
 2 EUROMA ROMA:
 1-cucina-aspirapolvere-222
 2-casa-cazzo-333
 
 RISULTATO: 1*/

#include <stdio.h>
#include <string.h>
#include "centriCommerciali.h"

int main(int argc, const char * argv[]) {
    listaProdotti l1=NULL;
    listaProdotti l2=NULL;
    listaCentri c1=NULL;
    
    addProdottoTesta(&l1, 4, "Cellulare", "Elettronica", 400);
    addProdottoTesta(&l1, 3, "Pasta", "Alimentari", 10);
    addProdottoTesta(&l1, 1, "Cavoli", "Frutteria", 400);
    //stampaProdotti(l1);
    
    //printf("%d\n",lengthListaProdotti(l1));
    
    //inserisciOrdinato(&l1, 2, "Camicia", "Abbigliamento", 50);
    //stampaProdotti(l1);
    
    //printf("%d\n",contaProdotti(l1, "Elettronica"));
    
    addProdottoTesta(&l2, 1, "Cellulare", "Elettronica", 400);
    addProdottoTesta(&l2, 2, "Gelato", "Bar", 400);
    //printf("%d\n",prodottiComuni(l1, l2));
    
    addTesta(&c1, 2, "Parco Leonardo", "Roma", l1);
    addTesta(&c1, 1, "Lallalero", "Milano", l2);
    //stampaCentri(c1);
    
    //printf("%d\n",contaProdottiCentri(c1, "Elettronica"));
    
    //inserisciProdottoOrd(&c1, 2, 2, "Computer", "Elettronica", 1000);
    //stampaCentri(c1);
    
    printf("%d\n",prodottiCentroComuni(c1, 1, 2));
    return 0;
}

