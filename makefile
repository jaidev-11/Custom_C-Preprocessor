COMPILE = cc #COMPILE is a variable
target = main.o cmtrmv.o process.o hdrcmt.o hdrinc.o macro.o

prep : ${target}
	${COMPILE} ${target} -o prep

main.o : main.c
	${COMPILE} -c main.c

comment.o:  cmtrmv.c
  ${COMPILE} -c cmtrmv.c

process.o : process.c
	${COMPILE} -c process.c

header.o:  hdrcmt.c
  ${COMPILE} -c hdrcmt.c

hdrinc.o:  hdrinc.c
  ${COMPILE} -c hdrinc.c

macro.o : macro.c
	${COMPILE} -c macro.c

clear :
	@echo "cleaning up..."
	@rm -ivr *.o
