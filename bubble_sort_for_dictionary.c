#include"mylist.h"
#include"myvector.h"
#include<stdlib.h>
#include<stdio.h>

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
