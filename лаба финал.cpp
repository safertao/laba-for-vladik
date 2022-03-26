#include"f.h"
#define m 80                                                       // m - длина строки, max_words_num - наибольшее 
#define max_words_num 40                                           // возможное число повторяющихся слов
int main()
{
	int  l, n;                                                     // l - количество строк , n - число наиболее часто повторяющихся слов, 
	char x;                                                        // которое выведется на экран, x - переменная для зацикливания,
	char** text;										           //  text - исходный текст, reg - переменная для учтения регистра
	char** table;
	int reg;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do
	{
		system("CLS");
		hello();                                                   // функция, которая выводит условие задачи
		printf("введите количество строк:\n");
		l = num();                                                 // функция ввода количества строк с проверкой
		printf("введите число n:\n");
		n = num();                                                 // функция ввода числа наиболее часто повторяющихся слов
		printf("введите текст:\n");
		text = mem(l, m);                                          // функция выделения памяти под текст
		vvod(text, l, m);                                          // функция ввода текста
		printf("вы хотите учитывать регистр?(1/0)\n");
		scanf_s("%d", &reg);
		system("CLS");
		int kol = n;
		int* a = (int*)calloc(max_words_num, sizeof(int));          // выделение памяти под массив с числом повторения втречающихся слов
		table = algorythm(text, a, l, max_words_num, m, reg, &kol); // основная функция программы, которая создает текст с наиболее
		if (**table)                                                // часто повторяющимися словами
		{
			printf("наиболее часто повторяющиеся %d слов(а) и число их появлений:\n", n);
			Printer(2, table, a, kol);								// функция вывода числа появлений cлов в тексте
			printf("\nисходный текст:\n\n");
			Printer(1, text, l);
			printf("\nпреобразованный рекурсией текст:\n\n");
			perevorot(text, l);
			Printer(1, text, l);
		}
		else printf("no words in the text\n");                      // если в тексте нет cлов
		free_mem(text, kol);                                        // функции освобождения памяти
		free_mem(table, kol);
		a = nullptr;
		free(a);
		printf("\nвведите цифру, чтобы продолжить:\n");
		rewind(stdin);
		x = getchar();
	} while (x >= '0' && x <= '9');                                 // зацикливание программы
	return 0;
}