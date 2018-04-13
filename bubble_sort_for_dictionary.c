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

void sort(pbox p, int(*f)(void *, void *))
{
        pentry cnt;
	pentry finish;

	for (finish = p->last(p); finish != p->first(p); finish = p->get_prev(p,finish))
	{
		for (cnt = p->first(p); cnt != finish; cnt = p->get_next(p, cnt))
		{
			if (f(cnt->data, (p->get_next(p, cnt))->data))
				p->myswitch(p, cnt, p->get_next(p, cnt));
		}
	}
	return;	
}

/*int main()
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
*/
