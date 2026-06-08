#include"header.h"
void process(FILE *ip,FILE *op,sll **dptr)
{
	char s[150] = "",ch=0;
	int len = 0;
	while((fscanf(ip,"%s",s)) != EOF)
	{
//single line comm
		if(strstr(s,"//"))
		{
			char t[100];
			strcpy(t,s);
			char *p = strstr(t,"//");
			if(p)
				*p = '\0';
			if(strlen(t)>0)
			{
				macrock(*dptr,t);
				if(strchr(t,";"))
					fprintf(op,"%s\n",t);
				else
					fprintf(op,"%s ",t);
			}
			while((ch = fgetc(ip)) != '\n' && ch != EOF);
		}
//multi line comm
		else if(strstr(s,"/*"))
		{
			char t[100];
			strcpy(t,s);
			char *p = strstr(t,"/*");
			if(p)
				*p = '\0';
			if(strlen(t)>0)
			{
				macrock(*dptr,t);
				if(strchr(t,";"))
					fprintf(op,"%s\n",t);
				else
					fprintf(op,"%s ",t);
			}
			char prev=0;
			while((ch = fgetc(ip)) != EOF)
			{
				if(prev == * && ch == '/')
					break;
				prev = ch;
			}
		}
		else if(strstr(s,"#include")||strstr(s,"#define"))
		{
			len=strlen(s);
			fseek(ip,-len,SEEK_CUR);
			ch=fgetc(ip);    
			hdrinc(ip,op,dptr);
			continue;   
		}
// spliting symbols
		else
		{
			char *sc = strchr(s,';');
			char *c1 = strchr(s,'{');
			char *c2 = strchr(s,'}');
			if(sc)
			{
				*sc = '\0';
				macrock(*dptr,s);
				fprintf(op,"%s",s);
				fprintf(op,";\n");
			}
			else if(c1)
			{
				*c1 = '\0';
				macrock(*dptr,s);
				fprintf(op,"%s",s);
				fprintf(op,"{\n");
			}
			else if(c2)
			{
				*c2 = '\0';
				macrock(*dptr,s);
				fprintf(op,"%s",s);
				fprintf(op,"}\n");
			}
			else
			{
				macrock(*dptr,s);
				fprintf(op,"%s",s);
			}
		}
	}
}