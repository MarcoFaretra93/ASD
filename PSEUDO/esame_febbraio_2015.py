//Scrivi lo pseudocodice della procedura COMPONENTI-CONNESSE(A) che accetti in input un grafo non orientato A
//e produca in output il numero delle componenti connesse di A che sono grafi completi 
//(una componente connessa di k nodi è un grafo completo se ci sono (k-1)*k/2 archi)
CONNESSE-COMPLETE(A)
	for i=0 to A.length-1
		color[i]=0
	cont = 0
	for i=0 to A.length-1 
		if color[i]==0
			cont++
			DFS-VISIT(A,i,color,cont)
	output = 0
	for compo=1 to cont
		nodi_componente = 0
		archi_componente = 0
		for k=0 to color.length-1
			if color[k]==compo
				nodi_componente++
				archi_componente = archi_componente + ARCHI(A,k)
		if (archi_componente = (nodi_componente-1)*nodi_componente)	//non divido per due, perché ho i doppi perché sono in un grafo non orientato
			output++
	return output


DFS-VISIT(A,i,color,cont)
	color[i]=cont
	x=A[i]
	while x!=NULL
		v=x.key
		if color[v]==0
			DFS-VISIT(A,v,color,cont)
		x=x.next

ARCHI(A,k)
	x=A[k]
	cont=0
	while x!=NULL
		cont++
		x=x.next
	return cont
