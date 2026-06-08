#include"header.h"
int main(int argc,char **argv)
{
	sll *hptr = 0;
	if(argc != 2)
	{
		printf("033[32m Usage: ./prep f1.c\n 033[0m");
		return -1;
	}
	FILE *ip,*op;
	ip = fopen(argv[1],"r");
	if(ip == NULL)
	{
		printf("033[34m Error: Unable to open file\n 033[0m");
		return -1;
	}
	char oname[100];
	strcpy(oname,argv[1]);
	char *d = strchr(oname,'.');
	if(d)
		strcpy(d,".i");

	op = fopen(oname, "w");
	if(op == NULL)
	{
		printf("033[34m Error: Unable to create file\n 033[0m");
		return -1;
	}
	process(ip,op,&hptr);
	fclose(ip);
	fclose(op);
	return 0;
}