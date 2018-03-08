#include "box.h"

struct node
{
    data data;
    struct node * next;
    struct node * prev;
} typedef node, * pnode;

struct mylist
{
	BOX_DECL;
	
	pnode head;
	int count;
}typedef mylist, * pmylist;

void list_insert(pbox p, data d);

box list_create();

void list_mydelete(pbox p);

pentry list_search (pbox p, data d, int(*f)(void *, void *));

void list_delete_element (pbox p, data d, int(*f)(void *, void *));

pentry list_first(pbox p);

pentry list_last(pbox p);

pentry list_get_next(pbox p, pentry elem);

pentry list_get_prev(pbox p, pentry elem); 
