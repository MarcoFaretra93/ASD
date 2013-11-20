/* Programma per la gestione di studenti e delle
 * rispettive votazioni e varie funzioni*/

#include <stdio.h>
#include "studenti.h"
#include <string.h>

int main(int argc, const char * argv[])    {
    string matricola;
    listaVoti voti = NULL;
    int voto = 0;
    char c ;
    listaStudenti l=NULL;
    
    printf("Inserire la matricola: ");
    scanf("%s",matricola);
    
    do {
        printf("inserire un voto");
        scanf("%d", &voto);
        printf("si vuole continuare Y/N\t");
        scanf(" %c", &c);
        addVoto(&voti, voto);
    }   while(c=='Y' || c=='y');
    
    
    addStudente(&l, matricola, voti);
    
    
    listaVoti l1=NULL;
    listaVoti l2=NULL;
    listaVoti l3=NULL;
    listaVoti l4=NULL;
    listaVoti l5=NULL;
    listaStudenti s1=NULL;
    listaStudenti s2=NULL;
    
    string matricola1;
    string matricola2;
    string matricola3;
    string matricola4;
    string matricola5;
    
    addVoto(&l1, 18);
    addVoto(&l1, 24);
    addVoto(&l1, 28);
    
    addVoto(&l2, 19);
    addVoto(&l2, 30);
    addVoto(&l2, 28);
    
    addVoto(&l3, 20);
    addVoto(&l3, 26);
    addVoto(&l3, 30);
    
    addVoto(&l4, 18);
    addVoto(&l4, 18);
    addVoto(&l4, 18);
    
    addVoto(&l5, 23);
    addVoto(&l5, 25);
    addVoto(&l5, 26);
    
    strcpy(matricola1, "46057e");
    strcpy(matricola2, "543655");
    strcpy(matricola3, "435435");
    strcpy(matricola4, "676576");
    strcpy(matricola5, "thtrht");
    
    addStudente(&s1, matricola1, l1);
    addStudente(&s1, matricola2, l2);
    addStudente(&s1, matricola3, l3);
    addStudente(&s2, matricola4, l4);
    addStudente(&s2, matricola5, l5);
    
    stampaVoti(l1);
    stampaStudente(s1);
    
    printf("La media dei voti è %f \n", mediaVoti(l1));
    printf("%f\n",mediaStudente(s1, matricola2));
    deleteInTesta(&s1);
    stampaStudente(s1);
    deleteInPosizionePrecisa(&s1, 3);
    stampaStudente(s1);
    deleteStudentePerMedia(&s1, 18);
    stampaStudente(s1);
    
}


