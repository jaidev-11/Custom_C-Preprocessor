#include"header.h"
//adding macros
void addend(sll **pptr,char *name1,char *value1)
{
	sll * new;
	new = malloc(sizeof(sll));
	strcpy(new->name,name1);
	strcpy(new->value->value1);
	new->next = 0;
	
	if(*pptr == 0)
		*pptr = new;
	else
	{
		sll * last = *pptr;
		while(last->next)
			last = last->next;
		last->next = new;
	}
}
//macrocheck function
void macrock(sll *ptr,char *s1)
{
	char *p = 0;
	while(ptr)
	{
		while((p = strstr(s1,ptr->name)) != NULL)
		{
			if((p == s1 || !isalnum(*(p-1))) && !isalnum(*(p+strlen(ptr->name))))
			{
				if(strcmp(s1,ptr->ame) == 0)
				{
					strcpy(s1,ptr->value);
					break;
				}
				else
				{
					if(strlen(ptr->name) == strlen(ptr->value))
					{
						int i=0,j=0;
						while(ptr->value[i])
							p[i++]=ptr->value[j++];
					}
					else if(strlen(ptr->name) < strlen(ptr->value))
					{
						int l=strlen(ptr->value)-strlen(ptr->name);
						for(int k=0;k<l;k++)
						{
							char *q=p;
							while(*q)
								q++;
							while(q>=p)
							{
								*(q+1)=*q;
								q--;
							}
						}
						int i=0,j=0;
						while(ptr->value[j])
							p[i++]=ptr->value[j++];
					}
					else if(strlen(ptr->name) > strlen(ptr->value))
					{
						int l=strlen(ptr->name)-strlen(ptr->value);
						for(int k=0;k<l;k++)
						{
							char *q=p+1;
							strcpy(p,q);
						}
						int i=0,j=0;
						while(ptr->value[j])
							p[i++]=ptr->value[j++];
					}
				}
				p = p+strlen(ptr->vale);
			}
			else
				p = p+1;
		}
		ptr = ptr->next;
	}
}