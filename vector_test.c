#include <stdio.h>
#include "myvector.h"

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
	pbox a = vector_create();

	int mass[4];
	mass[0] = 0;
	mass[1] = 1;
	mass[2] = 2;
	mass[3] = 3;

	data d = &mass[0];

	a->insert(a, d);

	a->insert(a, d+4);

	a->insert(a, d+8);

	a->insert(a, d + 12);

	int tmp = 2;
	data temp = &tmp; 
	printf ("%d\n", *((int*)((a->first(a))->data)));

	printf("%d\n", *((int*)((a->search(a, temp, CmpInt))->data)));

	printf("%d\n", *((int*)((a->last(a))->data)));

	printf("%d\n", *((int*)((a->get_by_num(a, 1))->data)));

	a->delete_element(a, a->first(a));
	a->delete_element(a, NULL);
	printf("%d\n", *((int*)((a->get_prev(a, a->get_next(a, a->first(a))))->data)));
	if (a->get_next(a, a->last(a)) != NULL)
		printf("Wrong.");
	else
		printf("OK.");
	if (a->get_prev(a, a->first(a)) != NULL)
                printf("Wrong.");
        else
                printf("OK.");
	a->mydelete(a);
	a->mydelete(NULL);
	return 0;
}
