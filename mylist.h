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

pnode list_search (pbox p, data d);
