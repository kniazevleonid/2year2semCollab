typedef void* data;
#define BOX_DECL \
void(*insert)(struct box * p, data d); \
void(*mydelete)(struct box * p); \
void*(*search)(struct box * p, data d, int(*f)(void *, void *)); \
void(*delete_element)(struct box * p, data d, int(*f)(void *, void *));

struct box
{
    BOX_DECL
}typedef box, * pbox;

