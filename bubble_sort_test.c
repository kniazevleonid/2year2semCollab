#include"mylist.h"
#include"myvector.h"
#include<stdlib.h>
#include<stdio.h>

int MoreInt(void * x, void * y)
{
	int * a = (int *)x;
	int * b = (int *)y;
	if (* a > * b)
		return 1;
	return 0;
}

int main()
{

	pbox a = CREATE();

	int mass[4];
	mass[0] = 2;
	mass[1] = 1;
	mass[2] = 3;
	mass[3] = 1;

	pentry temp;

	data d = &mass[0];

	a->insert(a, d);

	a->insert(a, d+4);

	a->insert(a, d+8);

	a->insert(a, d + 12);

	for (temp = a->first(a); temp!=a->last(a); temp = a->get_next(a, temp))
		printf ("%d\n", *(int*)temp->data);
	printf ("%d\n\n", *(int*)temp->data);

	sort(a, MoreInt);

	for (temp = a->first(a); temp!=a->last(a); temp = a->get_next(a, temp))
                printf ("%d\n", *(int*)temp->data);
	printf ("%d\n\n", *(int*)temp->data);

	a->mydelete(a);
	
	return 0;
}
