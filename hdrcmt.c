#include"header.h"
void hdrcmt(FILE *ip,FILE *op)
{
	char ch=0,prev=0,next=0;
	while((ch=fgetc(ip))!=EOF)
	{
		if(ch=='/')
		{
			next=fgetc(ip);
			if(next=='/')
			{
				while((ch=fgetc(ip))!='\n' && ch!=EOF)
              				fputc(' ',op);
		                fputc('\n',op);
			}
			else if(next=='*')
			{
				while((ch=fgetc(ip))!=EOF)
				{
					if(prev=='*'&&ch=='/')
						break;
					fputc(' ',op);
					prev=ch;
				}
			}
			else
			{
				fputc(ch,op);
				fputc(next,op);
			}
		}
	        else
			fputc(ch,op);
	}
}
