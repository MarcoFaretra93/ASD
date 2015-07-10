CONTA-NODI(x)	//teta(1)
	if x==NULL return 0
	else 
		return 1+CONTA-NODI(x.left)+CONTA-NODI(x.right)

DEPTH-RIC(x,A,v)	//teta(n)
	if x!=NULL
		A[x.info]=v
		DEPTH-RIC(x.right,A,v)
		DEPTH-RIC(x.left,A,v+1)

DEPTH(T)	//teta(n)
	for(i=0;i<CONTA-NODI(T.root);i++)
		A[i]=0
	DEPTH-RIC(T.root,A,0)
	return A

SAME(A,T,u)	//teta(n^2)
	A=DISTANCE(A,u)
	B=DEPTH(T)
	for i=0;i<A.length;i++
		if A[i]!=B[i]
			return false
	return true

DISTANCE(A,u)	//teta(n^2)
	for i=0 to A.length-1
		color[i]=0
		distanza[i]=0
	EMPTY-QUEUE(q)
	color[u]=1
	ENQUEUE(q,u)
	while(!QUEUE-VOID(q))
		v=DEQUEUE(q)
		x=A[v]
		while x!=NULL
			k=x.key
			if color[k]==0
				color[k]=1
				distanza[k]=distanza[v]+1
				ENQUEUE(q,k)
			x=x.next
		color[u]=2
	return distanza

//Variante
DEPTH-RIC(x,A,v)	//teta(n)
	if x==NULL return
	A[x.info]=v	
	y=x.left
	while y != NULL
		DEPTH-RIC(y,A,v+1)
		y=y.right
