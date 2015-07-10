ORDINE-BFS(A,u)
	for i = 0 to A.length-1
		color[i]=0
	//l nuova lista vuota
	EMPTY-QUEUE(q)
	color[u]=1
	ENQUEUE(q,u)
	while not QUEUE-VOID(q)
		v=DEQUEUE(q)
		x=A[v]
		while x!=NULL
			k=x.key
			if color [k]==0
				color[k]=1
				ADD-CODA(l,k)
				ENQUEUE(q,k)
			x=x.next
		color[v]=2
	return l

ADD-CODA(l,k)
	x=l.head
	nodo.info=k
	nodo.next=NULL
	if x!=NULL
		while x.next!=NULL
			x=x.next
		nodo.prev=x
		x.next=nodo
	else
		l.head=nodo
		nodo.prev=NULL
