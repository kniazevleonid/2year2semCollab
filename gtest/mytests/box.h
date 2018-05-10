#ifdef __cplusplus
extern "C" {
#endif

#ifndef BOX_H
#define BOX_H

typedef void* data;
#define BOX_DECL \
	void(*insert)(struct box * p, data d); \
void(*mydelete)(struct box * p); \
pentry(*search)(struct box * p, data d, int(*f)(void *, void *)); \
void(*delete_element)(struct box * p, pentry d);\
pentry(*first)(struct box * p);\
pentry(*last)(struct box * p);\
pentry(*get_next)(struct box* p, pentry elem);\
pentry(*get_prev)(struct box* p, pentry elem);\
pentry(*get_by_num)(struct box* p, int i);\
void(*myswitch)(struct box * p, pentry elem1, pentry elem2);


struct entry
{
	::data data;
}typedef entry, * pentry;

struct box
{
	BOX_DECL
}typedef box, * pbox;

#endif

#ifdef __cplusplus
};
#endif
