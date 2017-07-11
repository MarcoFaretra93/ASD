//ALBERI BINARI

CREATE-TREE()
	//t nuovo albero
	return t.root

IS-EMPTY(t)
	return t.root==NULL

ROOT(t)
	return t.root

LEFT(t,n)
	return n.left

RIGHT(t,n)
	return n.right

INFO(t,n)
	return n.info

TWO_CHILDREN(n)
	return (n.left!=NULL)&&(n.right!=NULL)

ADD-ROOT(t,k)
	nodo.info=k
	nodo.parent=NULL
	nodo.left=t.root
	t.root.parent=nodo
	t.root=nodo

ADD-LEFT(t,n,z)
	/nodo nuovo nodo 
	nodo.info = z
	nodo.parent=n
	nodo.left=n.left
	n.left=nodo

ADD-RIGHT(t,n,z)
	//nodo nuovo nodo
	nodo.info=z
	nodo.parent=n
	nodo.right=n.right
	n.right=nodo

ONLY-LEFT(t)
	if(t!=NULL)
		if(t.root.right!=NULL)
			return false
		return true && ONLY-LEFT(t.root.left)
	else 
		return true

CERCA(t,n) //preordine 
	if(t!=NULL)
		if(t.root.info==n)
			return t.root.info 
		return CERCA(t.left,n) || CERCA(t.right,n)
	else 
		return false 

CERCA(t,n) //postordine
	if(t!=NULL)
		if CERCA(t.left,n) 
			return true
		if CERCA(t.right,n) 
			return true
		return t.root.info == n
	else 
		return false

CERCA(t,n) //simmetrica
	if(t!=NULL)
		if CERCA(t.left,n) 
			return true
		if t.root.info == n 
			return true
		return CERCA(t.right,n)
	else 
		return false

CONTA-NODI(t) //utilizzo postordine poiché lo richiede l'esercizio
	if(t!=NULL) 
		return CONTA-NODI(t.left)+CONTA-NODI(t.right)+1
	else 
		return 0

CAMMINO(t) //devo solo verificare che l'albero è un cammino, differentemente da quello sotto
	if(t!=NULL) 
		return (t.left==NULL) || (t.right==NULL) && CAMMINO(t.left) && CAMMINO(t.right)
	else 
		return true
MAX(a,b)
	if a>b
		return a
	else 
		return b
HEIGHT(t)
	if t.root!=NULL
		if t.root.left==NULL && t.root.right==NULL
			return 0
		return 1+MAX(HEIGHT(t.root.left),HEIGHT(t.root.right))
	else 
		return 0

SOMMA(t) //funzione di supporto per AVERAGE che somma tutti gli info dei nodi
	if(t!=NULL)
		return t.info+SOMMA(t.left)+SOMMA(t.right)
	else 
		return 0
AVERAGE(t)
	if(t==NULL)
		error
	return SOMMA(t)/CONTA-NODI(t)

COMPLETO(t)
	if(t!=NULL)
		if t.left==NULL || t.right==NULL
			return false
		return COMPLETO(t.left) && COMPLETO(t.right)
	else 
		return true

DEALLOCA(t)
	if(t!=NULL)
		DEALLOCA(t.left)
		DEALLOCA(t.right)
		t=NULL
		return

POTA(t,x)
	if t!=NULL
		if t == x
			t=NULL
		POTA(t.left)
		POTA(t.right)

POTA-RIC(t,h,i)
	if t!=NULL
		if i=h
			t=NULL
			return
		POTA(t.left,h,i+1)
		POTA(t.right,h,i+1)
POTA(t,h) //cancello tutti i nodi a profondità maggiore di h
	POTA-RIC(t,h,0)

VALORE-NONNO(t) 
	if(t!=NULL)
		if t.parent.parent!=NULL && t.info=t.parent.parent.info
			cont++
		return cont+VALORE-NONNO(t.left)+VALORE-NONNO(t.right)
	else 
		return 0

DUE-FIGLI(t)
	if t!=NULL
		if t.left!=NULL && t.right!=NULL
			cont++
		return cont+DUE-FIGLI(t.left)+DUE-FIGLI(t.right)
	else 
		return 0

QUATTRO-NIPOTI(t)
	if t!=NULL
		if t.left.left!=NULL && t.left.right!=NULL && t.right.left!=NULL && t.right.right!=NULL
			cont++
		return cont+QUATTRO-NIPOTI(t.left)+QUATTRO-NIPOTI(t.right)
	else 
		return 0

CAMMINO(t, n) //ritorno una lista con un cammino, differentemente da quello sopra, attenzione dice che posso 
				//supporre che n è un nodo di t
	l.head=NULL
	if n!=NULL
		while n!=NULL
			ADD-TESTA(l,n.info)
			n=n.parent
	else 
		return l
		
PARENTELA(t,n1,n2)
	x1=CAMMINO(t,n1)
	x2=CAMMINO(t,n2)
	if(x1>x2)
		return x1-x2
	else 
		return x2-x1

//ALBERI DI GRADO QUALSIASI

CONTA-NODI(t) //figlio sinistro-fratello destro
	if t==NULL 
		return 0
	return 1+CONTA-NODI(t.right)+CONTA-NODI(t.left)

CERCA(t,k) //torna il riferimento al nodo che contiene il valore k
	if t!=NULL
		if t.info == k 
			return t
		if CERCA(t.right,k)!=NULL
			return CERCA(t.right,k)
		if CERCA(t.left,k)!=NULL
			return CERCA(t.left,k)
	else 
		return NULL

BINARIO(t) //verifica se è binario, ovvero massimo due figli
	if t!=NULL
		if t.left!=NULL && t.right!=NULL && t.right.right!=NULL
			return false
		return BINARIO(t.right) && BINARIO(t.left)
	else 
		return true

CONTA-FIGLI(n) //n nodo è di supporto a GRADO-MASSIMO
	cont=0
	x=n.left
	while x!=NULL
		cont++
		x=x.right
	return cont
GRADO-MASSIMO(t) //difficile, ma credo funzioni
	if t!=NULL
		if CONTA-FIGLI(t)>GRADO-MASSIMO(t.right) && CONTA-FIGLI(t)>GRADO-MASSIMO(t.left)
			return CONTA-FIGLI(t)
		if GRADO-MASSIMO(t.right)>CONTA-FIGLI(t) && GRADO-MASSIMO(t.right)>GRADO-MASSIMO(t.left)
			return GRADO-MASSIMO(t.right)
		if GRADO-MASSIMO(t.left)>CONTA-FIGLI(t) && GRADO-MASSIMO(t.left)>GRADO-MASSIMO(t.right)
			return GRADO-MASSIMO(t.left)
	else 
		return 0

//questi due copiati dalle slides
COPIA-ALBERO(t)
		n=CONTA-NODI(t.root)
		/* nuovonodo è un array di dimensione n, dove nuovonodo[i] è un
	riferimento al nodo del nuovo albero che rappresenta la copia del nodo
	dell’albero t con indice i */
		for i = 0 to nuovonodo.length
	/* creo un nuovo nodo nuovonodo[i] */
	nuovonodo[i].info = i
	nuovonodo[i].parent = NULL
	nuovonodo[i].left = NULL
	nuovonodo[i].right = NULL
	/* tout è un nuovo albero */
	tout.root = NULL /* inizializzazione (non indispensabile) */
	if (t.root != NULL) tout.root = nuovonodo[t.root.info]
	COPIA(t.root, nuovonodo)
	return tout

COPIA(n,nuovonodo)
		COPIA(n, nuovonodo)
	if (n == NULL) return
	if (n.parent != NULL)
	nuovonodo[n.info].parent = nuovonodo[n.parent.info]
	if (n.left != NULL)
	nuovonodo[n.info].left = nuovonodo[n.left.info]
	if (n.right != NULL)
	nuovonodo[n.info].right = nuovonodo[n.right.info]
	COPIA(n.left, nuovonodo)
	COPIA(n.right, nuovonodo)
