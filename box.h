typedef void* data;
#define BOX_DECL \
void(*insert)(struct box * p, data d); \
void(*mydelete)(struct box * p); \
pentry(*search)(struct box * p, data d, int(*f)(void *, void *)); \
void(*delete_element)(struct box * p, data d, int(*f)(void *, void *));\
pentry(*first)(struct box * p);\
pentry(*end)(struct box * p);\
pentry(*get_next)(struct box* p, pentry elem);\
pentry(*get_prev)(struct box* p, pentry elem);

struct entry
{

}typedef entry, * pentry;

struct box
{
    BOX_DECL
}typedef box, * pbox;

