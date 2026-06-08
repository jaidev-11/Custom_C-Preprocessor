#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct macro
{
	char name[51];
	char value[51];
	struct macro *next;
}sll;
//sll *headptr=0;

void cmtrmv(FILE *,FILE *,char);
void hdrinc(FILE *,FILE *,sll **);
void process(FILE *,FILE *,sll **);
void addend(sll **pptr,char *name1,char *value1);
void macrock(sll *,char *s1);
void hdrcmt(FILE *,FILE *);
