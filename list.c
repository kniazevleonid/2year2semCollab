#include "mylist.h"

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
                tmp->next = head;
                tmp->prev = (l->head)->prev;
                ((l->head)->prev)->next = tmp;
                (l->head)->prev = tmp;
        }
        return;
}


