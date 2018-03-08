#include "myvector.h"
#include <stdlib.h>
#include <stdio.h>

pbox create_vector ()
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
		return;
	int i = 0;

	for (i=0; i<p->size; i++)
	{
		free(vector_get_by_num(pp, i));
	}

	free(p);
	return;
}

void vector_insert(pbox p, data d)
{
        pmyvector vec = (pmyvector)p;
        pnode tmp = (pnode)malloc(sizeof(node));
        tmp->data = d;
        if(vec->head == NULL)
        {	
		tmp->num = 0;
                vec->head = tmp;
                vec->end = tmp;
                vec->size = 1;
        }
        else
        {
		int count = vec->end->num;
		if (count == vec->size - 1)
		{
			vec->head = (pnode)realloc(vec->head, sizeof(node)*2*vec->size);
			vec->size *= 2;
			vec->end = vec->head + count;
		}
		
		tmp->num = count + 1;

		pnode temp = vec->end + 1;
		temp = tmp;
		vec->end += 1;
        }
        return;
}

void vector_delete_element(pbox pp, pentry e)
{
        pnode tmp = (pnode)e;
	pmyvector p = (pmyvector)pp;
        if(tmp == NULL)
        {
                printf("There is no element with such pointer\n");
        }
        else
        { 
		pnode temp;
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
		if (f(((pnode)vector_get_by_num(p, i))->data, d))
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

    pnode tmp = (pnode)elem;
  
    if (tmp->num == vec->end->num)
    {
	return NULL;
    }	
	
    return (pentry)(tmp + 1);
}

pentry vector_get_prev(pbox p, pentry elem)
{ 
    pmyvector vec = (pmyvector)p;
	
    pnode tmp = (pnode)elem;

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
