#include "mylist.h"
#include "myvector.h"
#include <stdlib.h>
#include <stdio.h>

pbox list_create ()
{
	pbox p =(pbox)malloc(sizeof(mylist));
	p->insert = list_insert;
	p->mydelete = list_mydelete;
	p->search = list_search;
	p->delete_element = list_delete_element;
	p->first = list_first;
        p->last = list_last;
        p->get_next = list_get_next;
        p->get_prev = list_get_prev;
	p->myswitch = list_myswitch;	
	
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
	pnode last = p->head->prev;
	pnode temp;
	while (tmp != last)
	{
		temp = tmp;
		tmp = tmp->next;
		free(temp);
	}
	free (last);
	free(p);
	return;
}

void list_insert(pbox p, data d)
{
        pmylist l = (pmylist)p;
        pnode tmp = (pnode)malloc(sizeof(node));
        tmp->data = d;
        if(l->head == NULL)
        {
                l->head = tmp;
                tmp->next = tmp;
                tmp->prev = tmp;
        }
        else
        {
                tmp->next = l->head;
                tmp->prev = (l->head)->prev;
                ((l->head)->prev)->next = tmp;
                (l->head)->prev = tmp;
        }
        l->count = l->count + 1;
        return;
}

void list_delete_element(pbox p, pentry el)
{ 
	pmylist l = (pmylist)p;
        pnode tmp = (pnode)el;
        if(tmp == NULL)
        {
                printf("There is no element with such pointer\n");
        }
        else
        {
                (tmp->prev)->next = tmp->next;
                (tmp->next)->prev = tmp->prev;
		if(tmp == l->head)
		{
			l->head = l->head->next;
		}
                free(tmp);
                l->count = l->count - 1;
        }
        return;
}

pentry list_search (pbox p, data d, int(*f)(void *, void *))
{
        pmylist l = (pmylist)p;
        pnode tmp = l->head;
        pnode temp = tmp;
        while(tmp->next != temp)
        {
                if (f(tmp->data, d))
                        return (pentry)tmp;
                tmp = tmp->next;
        }

        if (f(tmp->data, d))
                        return (pentry)tmp;

        return NULL;

}

pentry list_first(pbox p)
{
    pmylist l = (pmylist)p;
    return (pentry)l->head;
}

pentry list_last(pbox p)
{
    pmylist l = (pmylist)p;
    return (pentry)l->head->prev;
}

pentry list_get_next(pbox p, pentry elem)
{
    pnode tmp = (pnode)elem;
    return (pentry)tmp->next;
}

pentry list_get_prev(pbox p, pentry elem)
{
    pnode tmp = (pnode)elem;
    return (pentry)tmp->prev;
}

void list_myswitch(pbox pp, pentry elem1, pentry elem2)
{
	pmylist p = (pmylist)p;
	pnode tmp1 = (pnode)elem1;
	pnode tmp2 = (pnode)elem2;
	
	
	data temp = tmp1->data;
	tmp1->data = tmp2->data;
	tmp2->data = temp;

	return;
}

pbox vector_create ()
{
	pbox p =(pbox)malloc(sizeof(myvector));
	p->insert = vector_insert;
	p->mydelete = vector_mydelete;
	p->search = vector_search;
	p->delete_element = vector_delete_element;
	p->first = vector_first;
	p->last = vector_last;
	p->get_next = vector_get_next;
	p->get_prev = vector_get_prev;
	p->get_by_num = vector_get_by_num;
	p->myswitch = vector_myswitch;


	pmyvector vec = (pmyvector) p;


	vec->head = NULL;
	vec->end = NULL;
	vec->size = 0;

	return p;
}

void vector_mydelete(pbox pp)
{
	pmyvector p = (pmyvector) pp;

	if(p == NULL)
	{
		return;
	}

	if(p->head != NULL)
	{
		free(p->head);
	}

	free(p);
	return;
}

void vector_insert(pbox p, data d)
{
	pmyvector vec = (pmyvector)p;
	if(vec->head == NULL)
	{
		pvnode tmp = (pvnode)malloc(sizeof(vnode));
		tmp->data = d;
		tmp->num = 0;
		vec->head = tmp;
		vec->end = tmp;
		vec->size = 1;
	}
	else
	{
		int count = vec->end->num;
		int size = vec->size;
		if (count == size - 1)
		{
			pvnode t = (pvnode)realloc(vec->head, sizeof(vnode)*2*vec->size);
			if (t==NULL)
				return;
			vec->head = t;
			vec->size *= 2;
			vec->end = vec->head + count;
		}


		pvnode tmp = ((pvnode)vec->end) + 1;
		tmp->num = count + 1;
		tmp->data = d;
		vec->end = tmp;
	}
	return;
}

void vector_delete_element(pbox pp, pentry e)
{
	pvnode tmp = (pvnode)e;
	pmyvector p = (pmyvector)pp;
	if(tmp == NULL)
	{
		printf("There is no element with such pointer\n");
	}
	else
	{ 
		pvnode temp;
		int count = tmp->num;
		int finish = p->end->num;
		int i = count;
		for (i = count; i<finish; i++)
		{
			temp = p->head + i;
			temp->data = (temp + 1)->data;
		}

		p->end = p->end - 1; 		

	}
	return;
}

pentry vector_search (pbox p, data d, int(*f)(void *, void *))
{
	pmyvector vec = (pmyvector)p;

	int i = 0;

	for (i = 0; i <= vec->end->num; i++)
	{
		if (f(((pvnode)vector_get_by_num(p, i))->data, d))
		{
			return vector_get_by_num(p, i);
		}
	}
	return NULL;

}

pentry vector_first(pbox p)
{
	pmyvector vec = (pmyvector)p;
	return (pentry)vec->head;
}

pentry vector_last(pbox p)
{
	pmyvector vec = (pmyvector)p;
	return (pentry)vec->end;
}

pentry vector_get_next(pbox p, pentry elem)
{
	pmyvector vec = (pmyvector)p;

	pvnode tmp = (pvnode)elem;

	if (tmp->num == vec->end->num)
	{
		return NULL;
	}	

	return (pentry)(tmp + 1);
}

pentry vector_get_prev(pbox p, pentry elem)
{ 
	pmyvector vec = (pmyvector)p;

	pvnode tmp = (pvnode)elem;

	if (tmp->num == vec->head->num)
	{
		return NULL;
	}

	return (pentry)(tmp - 1);
}

pentry vector_get_by_num(pbox p, int i)
{
	pmyvector vec = (pmyvector) p; 
	return (pentry)(vec->head + i);
}

void vector_myswitch(pbox pp, pentry elem1, pentry elem2)
{
	pmyvector p = (pmyvector)pp;
	pvnode el1 = (pvnode)elem1;
	pvnode el2 = (pvnode)elem2;

	data temp = el1->data;

	el1->data = el2->data;
	el2->data = temp;

	return;
}

