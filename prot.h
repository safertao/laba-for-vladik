#pragma once
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<windows.h>
#include<assert.h>
#include<stdarg.h>
int num();
void hello();
char** mem(int n, int m);
void vvod(char** st, int n, int m);
int str_len(char* st);
void Printer(int n, ...);
//char** alg(char** text,int* a, int* l, int* n, int m, int max_word_num);
char** algorythm(char** text, int* a, int l, int max_words_num, int m, int reg, int* kol);
//void show(char** st,int* a, int n);
void free_mem(char** st, int l);