//in un grafo connesso
DFS(A,v)
	for i=0 to A.length-1
		color[i]=0
	DFS-VISIT(A,v,color) //comincia una DFS da v

//grafo non connesso
DFS(A)
	for i=0 to A.length-1
		color[i]=0
	for i=0 to A.length-1
		if(color[i]==0)				//se i non ancora visitato
			DFS-VISIT(A,i,color)

DFS-VISIT(A,i,color)
	color[i]=1
	x=A[i]
	while x!=NULL
		v=x.key
		if color[v]==0
			DFS-VISIT(A,v,color)
		x=x.next
	color[i]=2
