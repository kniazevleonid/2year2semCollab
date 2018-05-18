#include <stdio.h>
#include "mylist.h"
//#include "myvector.h"
#include <stdlib.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>

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


int MoreString (void * x, void * y)
{
	char * a = (char *)x;
	char * b = (char *)y;
	if (strcmp(a, b) > 0)
		return 1;
	return 0;
}

void myread(pbox a)
{
	char* buff = (char*)malloc(1000*sizeof(char));
	sprintf(buff,"%s", "");
	int ch = 0;
	int count = 0;
	while(1)
	{
		ch = fgetc(stdin);    
		if(ch == EOF)
		{	
			if (count != 0)
                        {
			    a->insert(a, buff);
                        } 
                        else
                        {
                            free(buff);
                        }
			break;
		}
		if(isalpha(ch) || isdigit(ch))
		{
			count = count + 1;
			sprintf(buff, "%s%c", buff, (char)ch);
		}
		else
		{
			if(count != 0)
			{
				a->insert(a, buff);
                                buff = (char*)malloc(1000*sizeof(char));
                                sprintf(buff,"%s", "");
				count = 0;
			}
		}
	}

}

int main()
{
	pbox a = CREATE();

	myread(a);

	sort (a, MoreString);

	pentry tmp;

	int k = 1;

	for(tmp = a->first(a); tmp != NULL; tmp = a->get_next(a, tmp))
	{
		if(tmp == a->last(a))
		{
			printf("(%d timse) %s\n", k, (char*)tmp->data);
		}
		else
		{
			if(strcmp((char*)tmp->data, (char*)a->get_next(a, tmp)->data) != 0)
			{            
				printf("(%d timse) %s\n", k, (char*)tmp->data);
				k = 1;
			}
			else 
				k++;
		}
	}

        
        for(tmp = a->first(a); tmp != NULL; tmp = a->get_next(a, tmp))
	{
		free(tmp->data);
	}
	
        a->mydelete(a);

	return 0;
}
