#include "mylist.h"
#include<stdio.h>
//#include "myvector.h"

#define CREATE list_create
#define INSERT insert
#define SEARCH search
#define DELETE_ELEMENT
#define DELETE
#define ENTRY


int CmpInt(void * x, void * y)
{
        int * a = (int *)x;
        int * b = (int *)y;
        if (* a == * b)
                return 1;
        return 0;
}

int main()
{
        pbox a = CREATE();

        int mass[2];
        mass[0] = 0;
        mass[1] = 1;

        data d = &mass[0];

        a->INSERT(a, d);

        a->INSERT(a, d+4);
        
        int tmp = 1;
        data temp = &tmp; 
        printf ("%d\n", *((int*)((a->get_next(a, a->first(a)))->data)));
        
        printf("%d\n", *((int*)((a->search(a, temp, CmpInt))->data)));
       // a->mydelete(a);
	return 0;
}
