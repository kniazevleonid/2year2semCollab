#include "mylist.h"
#include <stdlib.h>

pbox create_list ()
{
	pbox p =(pbox)malloc(sizeof(mylist));
	p->insert = list_insert;
	p->mydelete = list_mydelete;
	
	pmylist create_list = (pmylist) p;

	
	create_list->count = 0;
	create_list->head = NULL;
	return p;
}

void list_mydelete(pbox pp)
{
	pmylist p = (pmylist) pp;
	if(p == NULL)
		return;
	pnode tmp = p->head;
	pnode temp;
	while (tmp != NULL)
	{
		temp = tmp;
		tmp = tmp->next;
		free(temp);
	}
	free(p);
	return;
}
