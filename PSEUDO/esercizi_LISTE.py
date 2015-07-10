MASSIMO(l)
	x=l.head
	max=x.info
	while(x!=NULL)
		if x.info>max
			max=x.info
		x=x.next
	return max

SOMMA(l)
	somma=0
	x=l.head
	while x!=NULL
		somma += x.info
		x=x.next
	return somma

SEARCH(l,u)
	x=l.head
	while(x!=NULL)
		if x.info==u
			return x
		x=x.next
	return NULL

PREV(l,i)
	prev=l.head
	curr=prev.next
	while curr!=NULL
		if curr=i
			return prev
		curr=curr.next
		prev.next=curr
	return NULL

DELETE(l,i)
	prev=l.head
	curr=prev.next
	if prev == i
		l.head = curr
	else
		while curr!=NULL
			if curr=i
				prev.next=curr.next
				return
			curr=curr.next

DELETE(l,u)
	prev=l.head
	curr=prev.next
	if prev.info == u
		l.head=curr
	else 
		while curr!=NULL
			if curr.info=u
				prev.next=curr.next
				return
			curr=curr.next

COMUNI(l1,l2)
	x=l1.head
	result=0
	while x!=NULL
		y=l2.head
		while y!=NULL
			if y.info=x.info
				result++
			y=y.next
		x=x.next
	return result

ADD-TESTA(l,u)
	nodo.info=u
	nodo.next=l.head
	l.head=nodo
INVERSA(l)
	//dichiaro una lista nuova l2 vuota
	x=l.head
	while(x!=NULL)
		ADD-TESTA(l2,x.info)
		x=x.next
	return l2

ACCODA(l1,l2)
	x=l1.head
	while(x.next!=NULL)
		x=x.next
	x.next=l2.head

//LISTE DOPPIAMENTE CONCATENATE

DELETE(l,u)
	x=l.head
	while x!=NULL
		if x.info==u
			if x.prev==NULL
				l.head=x.next
			else
				x.prev.next=x.next
			if x.next!=NULL
				x.next.prev=x.prev
			return
		x=x.next

INSERT_ORDERED(l,u)
	x=l.head
	nodo.info=u
	if l.head==NULL
		l.head=nodo
		return
	else
		while x!=NULL
			if x.info>nodo.info
				nodo.next=x
				nodo.prev=x.prev
				if x.prev!=NULL
					x.prev.next=nodo
				else 
					l.head=nodo
				x.prev=nodo
				return
			if x.info<nodo.info && x.next==NULL
				nodo.prev=x
				x.next=nodo
				nodo.next=NULL
				return
			x=x.next

MERGE(l1,l2)
	x=l2.head
	while(x!=NULL)
		INSERT_ORDERED(l1,x.info)
		x=x.next
	return l1

DOPPIONI(l)
	x=l.head
	y=l.head
	//contocc variabile che conta le occorrenze 
	while x!=NULL
		while y!=NULL
			if x.info == y.info
				contocc++
			if contocc >= 2
				return true
			y=y.next
		x=x.next
	return false

DOPPIONI-SORTED(l)
	x=l.head
	while x!=NULL
		if x.info == x.next.info
			return true
		x=x.next
	return false
