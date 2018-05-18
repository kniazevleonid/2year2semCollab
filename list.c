#include "mylist.h"
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
		{return;}
        if(p->head == NULL)
        {
            free(p);
            return;
        }
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
    if(l->head == NULL)
    {
        return NULL;
    }
    return (pentry)l->head->prev;
}

pentry list_get_next(pbox p, pentry elem)
{
    if(elem == p->last(p))
    {
        return NULL;
    }
    pnode tmp = (pnode)elem;
    return (pentry)tmp->next;
}

pentry list_get_prev(pbox p, pentry elem)
{
    if(elem == p->first(p))
    {
        return NULL;
    }
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
