#include "header.h"
void cmtrmv(FILE *ip,FILE *op,char first)
{
	char next = fgetc(ip);
	if(next == '/')
	{
		char c;
		while((c=fgetc(ip)) != '\n' && c != EOF)
			fputc(' ',op);
		fputc('\n',op);
	}
	else if(next == '*')
	{
		char c,prev=0;
		while((c=fgetc(ip)) != EOF)
		{
			if(prev == '*' && c == '/')
				break;
			fputc(' ',op);
			prev = c;
		}
		if(prev == '*' && c == '/')
			fputc('\n',op);
	}
	else
	{
		fputc(first,op);
	        fputc(next,op);
	}
}