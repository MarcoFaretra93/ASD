LISTE(A) //A rappresentato tramite matrice di adiacenza, e ritorna un grafo rappresentato come array di liste, complessità teta(n^2)
	//B nuovo array di liste
	for i=0 to A.length
		B[i]=NULL
	for i=0 to A.length
		for j=0 to A[i].length
			if A[i][j]==1
				ADD-TESTA(B[i],j)
ADD-TESTA(l,i)	//complessita teta(1)
	nodo.info=i
	nodo.prev=NULL
	i.next=l.head
	l.head=i

GRADO-USCITA(A,u) //complessità teta(n)
	cont=0
	for i=0 to A[u].length
		if(A[u][i]==1)
			cont++
	return cont

GRADO-INGRESSO(A,u)	//complessità teta(n)
	cont=0
	for i=0 to A.length
		if(A[i][u]==1)
			cont++
	return cont

GRADO-USCITA-MEDIO(A)	//complessita teta(n^2)
	totale=0
	for i=0 to A.length
		totale+=GRADO-USCITA(A,i)/A[i].length
	return totale

GRAFO-SEMPLICE(A)	//complessità teta(n)
	j=0
	for i=0 to A.length
		if(A[i][j]==1)
			return false
		j++
	return true

//INIZIO ESERCIZI LISTE DI ADIACENZA
MATRICE(A)	//Complessità teta(n^2)
	//Dichiaro una matrice B
	for i=0 to A.length
		for j=0 to A.length
			A[i][j]=0
	for i=0 to A.length
		x=A[i]
		while(x!=NULL)
			B[i][x.info]=1
			x=x.next
	return B

GRADO-USCITA(A,u)	//Complessità teta(n)
	x=A[u]
	cont=0
	while(x!=NULL)
		cont++
		x=x.next
	return cont 

GRADO-INGRESSO(A,u)	//Complessità teta(n^2)
	cont=0
	for i=0 to A.length
		x=A[i]
			while(x!=NULL)
				if(x.info==u)
					cont++
				x=x.next
	return cont

GRAFO-SEMPLICE(A)	//Complessità teta(n^2)
	for i=0 to A.length
		x=A[i]
		while(x!=NULL)
			if(x.info==i)
				return false
			x=x.next
	return true

VERIFICA-ARCO(A,u,v)	//Torna true se esiste arco da u a v Complessità teta(n)
	x=A[u]
	while(x!=NULL)
		if(x.info==v)
			return true
		x=x.next
	return false

VERIFICA-NON-ORIENTATO(A)	//Complessità teta(n^2)
	for i=0 to A.length
		for j=0 to A.length
			if((VERIFICA-ARCO(A,i,j)==false && VERIFICA-ARCO(A,j,i)==true) || (VERIFICA-ARCO(A,i,j)==true && VERIFICA-ARCO(A,j,i)==false))
				return false
	return true

VERIFICA-POZZO(A,u)	//complessità teta(1)
	x=A[u]
	if(x==NULL)
		return true
	else 
		return false

VERIICA-SORGENTE(A,u) //Complessità teta(n^2)
	for i=0 to A.length
		x=A[i]
		while(x!=NULL)
			if(x.info==u)
				return false
			x=x.next
	return true

VERIFICA-UNIONE(A1,A2)	//complessità teta(n^2)
	for i=0 to A1.length
		for j=1 to A1.length
			if(VERIFICA-ARCO(A1,i,j)==false && VERIFICA-ARCO(A2,i,j)==false)
				return false
	return true

VERIFICA-POZZI-E-SORGENTI(A1,A2)	//Complessità teta(n)
	for i=0 to A1.length
		if( (VERIFICA-POZZO(A1,i)==true && VERIFICA-SORGENTE(A2,i)==false) || 
			(VERIFICA-POZZO(A2,i)==true && VERIFICA-SORGENTE(A1,i)==false) ||
			(VERIFICA-SORGENTE(A1,i)==true && VERIFICA-POZZO(A2,i)==false) ||
			(VERIFICA-SORGENTE(A2,i)==true && VERIFICA-POZZO(A1,i)==false))
				return false
	return true

GRAFO-CONNESSO(A)
	return BFS(A,0)
BFS(A,v)
	for i=0 to A.length-1
		color[i]=0
	QUEUE-EMPTY(q)
	color[v]=1
	ENQUEUE(q,v)
	while(!QUEUE-VOID(q))
		u=DEQUEUE(q)
		x=A[u]
		while(x!=NULL)
			k=x.key
			if(color[k]==0)
				color[k]=1
				ENQUEUE(q,k)
			x=x.next
		color[u]=2
	for i=0 to A.length-1
		if color[i]==0
			return false
	return true

STESSA-COMPONENTE-FORTEMENTE-CONNESSA(A,u,v)
	X=BFS(A,u)
	Y=BFS(A,v)
	return X[v]!=0 && Y[u]!=0
BFS(A,v)
	for i=0 to A.length-1
		color[i]=0
	QUEUE-EMPTY(q)
	color[v]=1
	ENQUEUE(q,v)
	while(!QUEUE-VOID(q))
		u=DEQUEUE(q)
		x=A[u]
		while(x!=NULL)
			k=x.key
			if color[k]==0
				color[k]=1
				ENQUEUE(q,k)
			x=x.next
		color[u]=2
	return color

COMPONENTI-CONNESSE(A)
	cont=0
	for i=0 to A.length-1
		color[i]=0
	for i=0 to A.length-1
		if color[i]==0
			cont++
			DFS-VISIT(A,i,color)
	return cont
DFS-VISIT(A,i,color)
	color[i]=1
	x=A[i]
	while x!=NULL
		v=x.key
		if color[v]==0
			DFS-VISIT(A,v,color)
		x=x.next
	color[i]=2

ALBERO-RICOPRENTE(A,u)
	for i=0 to A.length-1
		color[i]=0
		parent[i]=0
	parent[u]=-1
	DFS-VISIT(A,u,color,parent)
	return parent
DFS-VISIT(A,i,color,parent)
	color[i]=1
	x=A[i]
	while x!=NULL
		v=x.key
		if color[v]=0
			parent[v]=i
			DFS-VISIT(A,v,color,parent)
		x=x.next
	color[i]=2

//Variante
ALBERO-RICOPRENTE-VARIANTE(A,u)
	//t albero vuoto
	for i=0 to A.length-1
		color[i]=0
		parent[i]=0
	parent[u]=-1
	DFS-VISIT(A,u,color,parent)
	nodo.info=u
	nodo.left=NULL
	nodo.right=NULL
	nodo.parent=NULL
	t.root=nodo
	COSTRUISCI-ALBERO-RIC(parent,t)
	return t
COSTRUISCI-ALBERO-RIC(parent,x)
	if x!=NULL
		for i=0 to parent.length
			if parent[i]=x.info
				AGGIUNGI-FIGLIO(x,i)
		COSTRUISCI-ALBERO-RIC(parent,x.left)
		COSTRUISCI-ALBERO-RIC(parent,x.right)
AGGIUNGI-FIGLIO(x,i)
	nodo.info=i
	nodo.parent=x
	nodo.left=NULL
	if x.left==NULL
		x.left=nodo
		nodo.right=NULL
	else
		nodo.right=x.left.right
		x.left.right=nodo

DFS(A,v) //Nel caso di matrice di adiacenza
	for i=0 to A.length-1
		color[i]=0
	DFS-VISIT(A,v,color)
DFS-VISIT(A,i,color)
	color[i]=1
	x=A[i]
	for j=0;j<x.length;j++
		v=x[j]
		if color[v]==0
			DFS-VISIT(A,v,color)
	color[i]=2

ADD-TESTA(l,u)
	nodo.info=u
	nodo.prev=NULL
	nodo.next=l.head
	l.head=nodo
CAMMINO-MINIMO(A,u,v)	//Devo trovare il cammino minimo da u a v nel grafo A
	//l lista vuota
	parent=BFS(A,u)
	x=parent[v]
	while(x==-1)
		ADD-TESTA(l,x)
		x=parent[x]
	return l
BFS(A,v)
	for i=0 to A.length-1
		color[i]=0
		parent[i]=0
	EMPTY-QUEUE(q)
	color[v]=1
	parent[v]=-1
	ENQUEUE(q,v)
	while(!(QUEUE-VOID(q)))
		u=DEQUEUE(q)
		x=A[u]
		while(x!=NULL)
			k=x.key
			if color[k]==0
				color[k]=1
				parent[k]=u
				ENQUEUE(q,k)
			x=x.next
		color[v]=2
	return parent
