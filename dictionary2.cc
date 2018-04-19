#include <stdio.h>
#include "mylist.h"
#include "myvector.h"
#include <stdlib.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>

void sort(pbox p, int(*f)(void *, void *));

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
	char buff[1000][1000];
	int j = 0;
	for(j = 0; j < 1000; ++j)
		sprintf(buff[j],"%s", "");
	int ch = 0;
	int i = 0;
	int count = 0;
	while(1)
	{
		ch = fgetc(stdin);    
		if(ch == '\n')
		{	
			if (count != 0)
				a->insert(a, buff[i]);
			break;
		}
		if(isalpha(ch) || isdigit(ch))
		{
			count = count + 1;
			sprintf(buff[i], "%s%c", buff[i], (char)ch);

		}
		else
		{
			if(count != 0)
			{
				a->insert(a, buff[i]);
				count = 0;
				i++;
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

	for(tmp = a->first(a); tmp != a->last(a); tmp = a->get_next(a, tmp))
	{
		if(strcmp((char*)tmp->data, (char*)a->get_next(a, tmp)->data) != 0)
		{            
			printf("(%d timse) %s\n", k, (char*)tmp->data);
			k = 1;
		}
		else 
			k++;
	}

	printf("(%d timse) %s\n", k, (char*)a->last(a)->data);

	a->mydelete(a);

	return 0;
}
