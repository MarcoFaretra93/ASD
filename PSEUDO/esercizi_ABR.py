NO-MAGGIORE(x,v)
	if x==NULL return true
	else 
		return x.key<=v && NO-MAGGIORE(x.left) && NO-MAGGIORE(x.right)
NO-MINORE(x,v)
	if x==NULL return true
	else 
		return x.key>=v && NO-MINORE(x.left) && NO-MINORE(x.right)
IS-ABR-PRE
	return IS-ABR-PRE-RIC(t.root)
IS-ABR-PRE-RIC(x)
	if x!=NULL
		return (NO-MAGGIORE(x.left,x.key)) && (NO-MINORE(x.right,x.key)) && IS-ABR-PRE-RIC(x.left) && IS-ABR-PRE-RIC(x.right)
	else
		return true
//Nel caso peggiore è un albero completamente sbilanciato T(n)=T(n-1)+teta(n) -> T(n)=teta(n^2)

IS-ABR-POST(t)
	return IS-ABR-POST-RIC(t.root).is_abr
IS-ABR-POST-RIC(x) //ritorna un oggetto con tre valori is_abr che mi dice se è un abr, min e max
	if x==NULL 	return true
	l=IS-ABR-POST-RIC(x.left)
	r=IS-ABR-POST-RIC(x.right)
	if(l==NULL && r=NULL)
		return (TRUE, x.key, x.key)
	if(r!=NULL && l==NULL)
		out=r.is_abr && (x.key<=r.min)
		return (out,x.key,r.max)
	if(r==NULL && l!=NULL)
		out=r.is_abr && (x.key>=l.max)
		return (out,l.min,x.key)
	out=l.is_abr && r.is_abr 
	out= out && (x.key<=r.min) && (x.key>=l.max)
	return (out, l.min, r.max)
//Come tutte le visite in postordine, questa ha complessità teta(n)

TREE-SORT(A)	//INSERISCI E TREE-TO-ARRAY hanno complessità lineare teta(n)
	//t nuovo albero nullo
	for i=0 to A.length
		INSERISCI(t,A[i])
	TREE-TO-ARRAY(A,t,0)
//La complessita in questo caso avendo INSERISCI dentro un for è teta(n^2)
//Se l'albero fosse bilanciato, la complessità di INSERISCI sarebbe teta(log n) e quindi la complessità totale //sarà teta(n*log n)
