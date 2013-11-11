#define TRUE 1
#define FALSE 0
typedef struct {
	int a[10];
	int top;
}pila;

pila createStack() {
	pila p;
	p.top=-1;
	return p;
}
/*Ritorna true se la pila è vuota altrimenti ritorna false*/
int isEmpty(pila p) {
	if(p.top==-1) 
		return TRUE;
	else 
		return FALSE;
}
/* funzione per caricare un elemento sulla pila*/
void push(pila* p, int x) {
	if((*p).top+1<10) {
		(*p).top++;
		(*p).a[(*p).top]=x;
	} 
	else 
		printf("Errore: overflow\n");
}
void pop(pila* p) {
	if((*p).top>-1) {
		(*p).top--;
	}
	else 
		printf("Errore: underflow \n");
}
void empty(pila* p) {
	(*p).top=-1;
}
int size(pila* p) {
	return (*p).top+1;
}