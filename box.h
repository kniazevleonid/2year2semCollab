typedef void* data;
#define BOX_DECL \
void(*insert)(struct box p, data d); \
void(*mydelete)(struct box p);

struct box
{
    BOX_DECL
}typedef box, * pbox;

