AMMINO_PIU_CORTO(T)
	return CAMMINO_PIU_CORTO_RIC(T.root,0)
CAMMINO_PIU_CORTO_RIC(x,v)
	if x==NULL return 0
	if x.left==NULL return v
	else
		if x.right!=NULL
			return MIN(CAMMINO_PIU_CORTO_RIC(x.right,v),CAMMINO_PIU_CORTO_RIC(x.left,v+1))
		else
			return CAMMINO_PIU_CORTO_RIC(x.left,v+1)
MIN(a,b)
	if a<b
		return a
	else 
		return b
