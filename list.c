#include "mylist.h"
#include <stdlib.h>
#include<stdio.h>

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
        return;
}

void list_delete_element(pbox p, data d)
{
        pnode tmp = list_search(p, d);
        if(tmp == NULL)
        {
                printf("There is no element with such data\n");
        }
        else
        {
                (tmp->prev)->next = tmp->next;
                (tmp->next)->prev = tmp->prev;
                tmp->next = NULL;
                tmp->prev = NULL;
                free(tmp);
        }
        return;
}

pnode list_search (pbox p, data d, int(*f)(void *, void *))
{
        pmylist l = (pmylist)p;
        pnode tmp = l->head;
	pnode temp = tmp;
        while(tmp->next != temp)
        {
                if (f(tmp->data, data))
                        return tmp; 
                tmp = tmp->next;
        }
	
	if (f(tmp->data, data))
                        return tmp;
	
        return NULL;

}

