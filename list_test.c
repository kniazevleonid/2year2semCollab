#include "mylist.h"
#include<stdio.h>
//#include "myvector.h"

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

        int mass[3];
        mass[0] = 0;
        mass[1] = 1;
	mass[2] = 2;

        data d = &mass[0];

        a->insert(a, d);

        a->insert(a, d+4);

	a->insert(a, d+8);
        
        int tmp = 1;
        data temp = &tmp; 
        printf ("%d\n", *((int*)((a->get_next(a, a->first(a)))->data)));
        
        printf("%d\n", *((int*)((a->search(a, temp, CmpInt))->data)));

	printf("%d\n", *((int*)((a->get_prev(a, a->last(a)))->data)));

	a->delete_element(a, a->first(a));
        a->mydelete(a);
	return 0;
}
