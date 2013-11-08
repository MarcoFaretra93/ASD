#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordinazione.h"


int main(int argc, const char * argv[])
{
    listaOrdinazione l;
    listaPortate a, b, c, d, e;
    
    addPortata(&a, 100, "spaghetti");
    addPortata(&a, 50, "pasta");
    addOrdinazione(&l, 1, a);
    
    addPortata(&b, 10, "pizza");
    addPortata(&b, 5, "pane");
    addOrdinazione(&l, 1, b);
    
    addPortata(&c, 20, "carne");
    addPortata(&c, 30, "bistecca");
    addOrdinazione(&l, 3, c);
    
    addPortata(&d, 500, "focaccia");
    addPortata(&d, 100, "tonno");
    addPortata(&d, 100, "tonno");
    addOrdinazione(&l, 4, d);
    
    addPortata(&e, 20, "carne");
    addPortata(&e, 30, "bistecca");
    addOrdinazione(&l, 5, e);
    
    printf("La media e' %d.\n", mediaPortate(a));
    printf("La media e' %d.\n", mediaPortate(b));
    printf("La media e' %d.\n", mediaPortate(c));
    printf("La media e' %d.\n", mediaPortate(d));
    printf("La media e' %d.\n", mediaPortate(e));
    
    return 0;
}