# Custom_C-Preprocessor

This project is an implementation of how a C preprocessor works internally.
It takes a **.c** file as input and generates a processed **.i** file after handling things like macros, comments, and header files.
This project is to understand what actually happens before a C program is compiled.

---------------------------------------------------------------------------------
## 💡 What This Program Do

When you give a **.c** file as input, the program:

- Removes all comments (// and /* */)
- Processes #define macros and stores them using a linked list
- Replaces macros wherever they appear in the code
- Handles #include files both pre-defined & user-defined
- Generates an **.i** file as output

---------------------------------------------------------------------------------
## ⚙️ How It Works

The program reads the input **.c** file step by step and checks what each part of the code is:

- If it finds a comment → it removes/replaces it
- If it finds **#define** → it stores the macro
- If it finds **#include** → it opens and processes that file
- Else it checks if any macro needs to be replaced

All the logic is split into multiple files to keep things organized.

---------------------------------------------------------------------------------

## 📂 Structure of the project

- main.c	→ Handles file and starts processing
- marco.c	→ Handles #include, #define and takes action accordingly
- process.c	→ Handles scaning of files and takes action accordingly
- header.h	→ Consists all structure declaration & definitions
- cmtrmv.c	→ Removes all the comments from file
- makefile	→ Used for easier file compilation & generate output

---------------------------------------------------------------------------------

## How to Run

### Using Makefile (Recommended)
```bash
make
./prep testfile.c
```
### To clear compiled files:
```bash
make clear
```
### Manual Compilation
```bash
gcc main.c process.c macro.c hdrinc.c hdrcmt.c cmtrmv.c -o prep
./prep testfile.c
```
---------------------------------------------------------------------------------

## 📌 Example Flow

### Input(testfile.c)
```bash
#include<stdio.h>
#include<string.h>
#define abc 3456
#define pf printf
#define coding 65
int main()
{
	// delete single line comment
	int k = abc;
	/* remove multi line comment
	sdoidsioxcv
	fkdsfkjsdfjk
	sdfsfvsjsd
	sdfsdgfisdf
	dvdgfds*/
	pf("%d %d\n",k,coding );
}
```
### Ouput(testfile.i)
```bash
int main()
{
	int k = 3456;
	pf("%d %d\n",k,65);
}
```
---------------------------------------------------------------------------------

## 🧠 What I Learned

Upon working on this project, I learned

- File Handling in C
- Implemeting linked list
- String processing and parsing logic
- Macro Management
- Process of preprocessing before compilation


---------------------------------------------------------------------------------

## 🚀 Future Improvements

- Improved macro handling
- Improved parsing of string
- Improvement in error handling

---------------------------------------------------------------------------------
# 👨🏽‍🚀Author
jaidev-11
