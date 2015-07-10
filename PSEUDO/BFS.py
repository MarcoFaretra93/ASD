BFS(A,v) //A è un array di liste di adiacenza, v è un indice
	for i=0 to A.length-1
		color[i]=0 		//0=white non raggiunto
	QUEUE-EMPTY(q) 		//creo una coda vuota
	color[v]=1 			//il nodo di indice v è stato raggiunto 1=grigio
	ENQUEUE(q,v)		//carico l'indice v
	while not QUEUE-VOID(q) //finchè la coda non è vuota
		u=DEQUEUE(q)	//estraggo un indice dalla coda
		x=A[u]			//mi preparo per esplorare gli adiacenti di u, x sarà una lista
		while x!=NULL	//finchè c'è un nodo adiacente ad u
			k=x.key
			if(color[k] == 0)
				color[k] = 1
				ENQUEUE(q,k)
			x=x.next
		color[u]=2 		//completamente esplorato 2=black
