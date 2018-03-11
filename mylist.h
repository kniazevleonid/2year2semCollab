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

pbox list_create();

void list_mydelete(pbox p);

pentry list_search (pbox p, data d, int(*f)(void *, void *));

void list_delete_element (pbox p, pentry d);

pentry list_first(pbox p);

pentry list_last(pbox p);

pentry list_get_next(pbox p, pentry elem);

pentry list_get_prev(pbox p, pentry elem); 

void list_myswitch(pbox p, pentry elem1, pentry elem2);
