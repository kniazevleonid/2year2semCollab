#include "box.h"

struct node
{
    data data;
	int num;
} typedef node, * pnode;

struct myvector
{
	BOX_DECL;
	
	pnode head;
	pnode end;
	int size;
}typedef myvector, * pmyvector;

void vector_insert(pbox p, data d);

pbox vector_create();

void vector_mydelete(pbox p);

pentry vector_search (pbox p, data d, int(*f)(void *, void *));

void vector_delete_element (pbox p, pentry de);

pentry vector_first(pbox p);

pentry vector_last(pbox p);

pentry vector_get_next(pbox p, pentry elem);

pentry vector_get_prev(pbox p, pentry elem);

pentry vector_get_by_num(pbox p, int num);
