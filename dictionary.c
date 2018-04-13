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

int main()
{
	pbox a = CREATE();
        char current[1000][1000];
        int j = 0;
        for(j = 0; j < 1000; ++j)
	    sprintf(current[j],"%s", "");
	int x = 0;
        int i = 0;
	int count = 0;
	while(1)
	{
		x = fgetc(stdin);    
		if(x == '\n')
		{	
			if (count != 0)
			a->insert(a, current[i]);
			break;
		}
		if(isalpha(x) || isdigit(x))
		{
			count = count + 1;
                        sprintf(current[i], "%s%c", current[i], (char)x);
		        
		}
		else
		{
			if(count != 0)
			{
				a->insert(a, current[i]);
				count = 0;
				i++;
			}
		}
	}

	sort (a, MoreString);

        pentry tmp;
	
	printf("%s\n", (char*)a->first(a)->data);

        for(tmp = a->get_next(a, a->first(a)); tmp != a->last(a); tmp = a->get_next(a, tmp))
        {
		if(strcmp(tmp->data, a->get_prev(a, tmp)->data) != 0)
            printf("%s\n", (char*)tmp->data);
        }

	if(strcmp(tmp->data, a->get_prev(a, tmp)->data) != 0)
	printf("%s\n", (char*)a->last(a)->data);

	a->mydelete(a);

	return 0;
}
