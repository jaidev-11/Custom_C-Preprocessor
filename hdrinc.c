#include"header.h"
void hdrinc(FILE *ip,FILE *op,sll **dptr)
{
	char line[256] = "";
	fgets(line,sizeof(line),ip);
	char file[100];
	int i=0,j=0;
	if(strstr(line,"include"))
	{
		if(strstr(line,'"'))
		{
			while(line[i] && line[i] != '"')
				i++;
			i++;
			while(line[i] && line[i] != '"')
				file[j++] = line[i++];
			file[j] = '\0';
			FILE *fp = =fopen(file,"r");
			if(fp)
			{
				hdrcmt(fp,op);
				fclose(fp);
				return;
			}
		}
		else if(strstr(line,'<'))
		{
			while(line[i] && line[i] != <')
				i++;
			i++;
			while(line[i] && line[i] != '>')
				file[j++] = line[i++];
			file[j] = '\0';

			char path[200] = "/usr/include/";
			strcat(path,file);
			FILE *fp = =fopen(path,"r");
			if(fp)
			{
				hdrcmt(fp,op);
				fclose(fp);
				return;
			}
			else
			{
				printf("033[31m Error: unale to open the file\n"033[0m);
				exit(0);
			}
		}
	}
	else if(strstr(line,"define"))
	{
		char a[50] = "",val[50] = "";
		int i=0,j=0;
// skiping "#define"
		while(line[i] && line[i] != ' ')
			i++;
		while(line[i] == ' ')
			i++;
// reading macros		
		while(line[i] && line[i] != ' ')
			a[j++] = line[i++];
		a[j] = '\0';
		
		j=0;
// skiping spaces
		while(line[i] == ' ')
			i++;
// reading macros
		while(line[i] && line[i] != '\n')
			val[j++] = line[i++];
		val[j] = '\0';
		addend(dptr,a,val);
	}
	else
		printf("033[31m ERROR: File not found\n");
}
