
#include"prot.h"

int num()
{
	int n, k;                                            //k - переменная для зацикливания
	k = scanf_s("%d", &n);
	while (!k || n < 1)
	{
		rewind(stdin);
		printf("error, try one more time\n");
		k = scanf_s("%d", &n);
	}
	return n;
}

char** mem(int l, int m)
{
	char** st = (char**)calloc(l, sizeof(char*));     //выделение памяти под массив указателей на строки
	if (!st)
	{
		printf("ошибка, память не была веделена");
		exit(1);
	}
	for (int i = 0; i < l; i++)                       //выделение памяти под указатели на символы
		*(st + i) = (char*)calloc(m, sizeof(char));
	return st;
}

void vvod(char** st, int l, int m)
{
	char c;
	int j;
	for (int i = 0; i < l; i++)                            //ввод текста
	{
		int num = 0;
		do
		{
			j = -1;
			rewind(stdin);
			while ((c = (char)getchar()) != '\n')
			{
				j++;
				if (j >= m)
				{
					printf("ошибка, строка длиннее заданной длины.\n");
					printf("введите строку еще раз.\n");
					break;
				}
				else
				{
					(*(*(st + i) + j) = c);
					num = 1;
				}
			}
		} while (j >= m || !num);
		*(*(st + i) + j + 1) = '\0';
	}
}

int str_len(char* st)
{
	int n;
	for (n = 0; *(st + n); n++);
	return n;
}

char* recurs_word(char* st, int n1, int n2)
{
	char tmp;
	if (n1 < n2)
	{
		tmp = *(st + n1);
		*(st + n1) = *(st + n2);
		*(st + n2) = tmp;
		recurs_word(st, n1 + 1, n2 - 1);
	}
	return st;
}

void perevorot(char** text, int n)
{
	int i, j;
	int n1, n2;
	for (i = 0; i < n; i++)
	{
		j = 0;
		while (*(*(text + i) + j))
		{
			do                                                //защита от пустых строк
			{
				while ((' ' <= *(*(text + i) + j)) && (*(*(text + i) + j) <= '/') ||
					((':' <= *(*(text + i) + j)) && (*(*(text + i) + j) <= '@')) && *(*(text + i) + j))
					j++;
				if (*(*(text + i) + j) == '\0') //переход на след строку текста если нет слов
				{
					i++;
					j = 0;
					continue;
				}
				break;
			} while (i < n);
			if (i == n) break;
			n1 = j;
			while ((('@' < (*(*(text + i) + j + 1))) || ((*(*(text + i) + j + 1)) < ' ')   //проход по слову
				|| (((*(*(text + i) + j + 1)) >= '0') && ((*(*(text + i) + j + 1)) <= '9'))) && *(*(text + i) + j + 1))
				j++;
			n2 = j;
			*(text + i) = recurs_word(*(text + i), n1, n2);
			j++;
		}
	}
}


//
// неэффективная функция!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
// 
// 
//char** alg(char** text,int* a, int* l, int* n, int m, int max_words_num)
//{
//	int i = 0, j = 0, n1, n2, x;
//	int k, num, len, word_len;
//	int str = 0;
//	char** table = mem(max_words_num, m);
//	char* word;
//	while (*(*(text + i) + j))
//	{
//		do                                                          //блок поиска первого слова
//		{
//			while ((' ' <= *(*(text + i) + j)) && (*(*(text + i) + j) <= '/') ||
//				((':' <= *(*(text + i) + j)) && (*(*(text + i) + j) <= '?')) && *(*(text + i) + j))
//				for (k = j; *(*(text + i) + k); k++)
//					*(*(text + i) + k) = *(*(text + i) + k + 1);
//			if (*(*(text + i) + j) == '\0') //переход на след строку текста если нет слов
//			{
//				i++;
//				continue;
//			}
//			break;
//		} while (i < *l);
//		if (i == *l) break;
//		n1 = j;
//		while ((('?' < (*(*(text + i) + j + 1))) || ((*(*(text + i) + j + 1)) < ' ')   //проход по слову
//			|| (((*(*(text + i) + j + 1)) >= '0') && ((*(*(text + i) + j + 1)) <= '9'))) && *(*(text + i) + j + 1))
//			j++;
//		n2 = j;
//		x = 0;
//		len = str_len(*(text + i)) + 1;
//		word_len = n2 - n1 + 1;
//		word = (char*)calloc((word_len + 1), sizeof(char));
//		assert(word);
//		for (k = n1; k <= n2; k++)              //запоминаем слово
//			*(word + x++) = *(*(text + i) + k);
//		*(word + x) = '\0';
//		for (k = n1; *(*(text + i) + k + word_len - 1); k++)
//			*(*(text + i) + k) = *(*(text + i) + k + word_len);
//		char* tmp = (char*)realloc(*(text + i), (len -= word_len) * sizeof(char));
//		if (tmp)
//			*(text + i) = tmp;
//		num = 1;
//		while (i < *l)                                        //блок сравнения со словами
//		{
//			len = str_len(*(text + i)) + 1;
//			for (j = 0; *(*(text + i) + j); )
//			{
//				while ((' ' <= *(*(text + i) + j)) && (*(*(text + i) + j) <= '/') ||
//					((':' <= *(*(text + i) + j)) && (*(*(text + i) + j) <= '?')) && *(*(text + i) + j))
//					j++;
//				if (*(*(text + i) + j) == '\0' && (i + 1) < *l) //переход на след строку текста если нет слов
//				{
//					j = 0;
//					i++;
//					len = str_len(*(text + i)) + 1;
//					continue;
//				}
//				if (i == *l) break;
//				n1 = j;
//				while ((('?' < (*(*(text + i) + j + 1))) || ((*(*(text + i) + j + 1)) < ' ')
//					|| (((*(*(text + i) + j + 1)) >= '0') && ((*(*(text + i) + j + 1)) <= '9'))) && *(*(text + i) + j + 1))
//					j++;
//				n2 = j;
//				x = 0;
//				k = n1;
//				while (k <= n2)
//				{
//					if (*(*(text + i) + k) == *(word + x))//сравнение слов
//					{
//						x++;
//						k++;
//						continue;
//					}
//					break;
//				}
//				if ((k - n1 == word_len) && (((' ' <= *(*(text + i) + k)) && (*(*(text + i) + k) <= '/') ||
//					((':' <= *(*(text + i) + k)) && (*(*(text + i) + k) <= '?'))) || !*(*(text + i) + k)))
//					//если слова совпадают
//				{
//					for (k = n1; *(*(text + i) + k + word_len - 1); k++) //сдвиг на длину слова
//						*(*(text + i) + k) = *(*(text + i) + k + word_len);
//					char* ptr = (char*)realloc(*(text + i), (len -= word_len) * sizeof(char));
//					if (ptr)
//						*(text + i) = ptr;
//					num++;
//					j = n1;
//				}
//				else j++;
//			}
//			i++;
//		}
//		for (i = 0; i < *l; ) //блок проверки на пустую строку
//		{
//			if (!**(text + i))
//			{
//				for (int b = i; b < *l; b++)
//					*(text + b) = *(text + b + 1);
//				(*l)--;
//				char** tmp = (char**)realloc(text, (*l) * sizeof(char*));
//				if (tmp != NULL)
//					text = tmp;
//				continue;
//			}
//			i++;
//		}
//		for (x = 0; *(word + x); x++)      //вставка слова
//			*(*(table + str) + x) = *(word + x);  
//		*(*(table + str) + x) = '\0';
//		*(a + str) = num;                 //вставка количества повторений
//		i = 0;
//		j = 0;
//		word = nullptr;
//		free(word);
//		str++;
//	}
//	*l = str;
//	for (k = 0; k < *l - 1; k++) //сортировка
//	{
//		word= (char*)calloc(40, sizeof(char));
//		for (x = *l - 1; x > k; x--)
//			if (*(a + x) > *(a + x - 1))
//			{
//				int tmp = *(a + x);
//				*(a + x) = *(a + x - 1);
//				*(a + x - 1) = tmp;
//				word = *(table + x);
//				*(table + x) = *(table + x - 1);
//				*(table + x - 1) = word;
//			}
//		word = nullptr;
//		free(word);
//	}
//	return table;
//}

void Printer(int n, ...)
{
	int* a;
	char** text;
	int k;
	va_list p;
	va_start(p, n);
	int j = 0;
	switch (n)
	{
	case 0:
		a = va_arg(p, int*);
		k = va_arg(p, int);
		for (int i = 0; i < k; i++)
			printf("%5d", *(a + i) + 1);
		break;
	case 1:
		text = va_arg(p, char**);
		k = va_arg(p, int);
		for (int i = 0; i < k; i++)
			puts(*(text + i));
		break;
	case 2:
		text = va_arg(p, char**);
		a = va_arg(p, int*);
		k = va_arg(p, int);
		for (int i = 0; i < k; i++)                            // вывод преобразованного текста на экран
		{
			for (j = 0; *(*(text + i) + j); j++)
				printf("%c", *(*(text + i) + j));
			printf("%5d\n", *(a + i) + 1);

		}
		break;
	}


}



char** algorythm(char** text, int* a, int l, int max_words_num, int m, int reg, int* kol)  // table - текст с наиболее часто повторяющимися словами,
																		  // a - массив с числом повторения наиболее часто встречающихся слов																		  // l - число строк в тексте, max_words_num - наибольшее возможное число
{                                                                         // наиболее часто встречающихся слов, reg - переменная для учтения регистра
	char** table = mem(max_words_num, m);                                 // функция выделения памяти под текст
	int i, k, j;                                                          // i, j, k, x, n - счетчики, n1 - индекс начала слова,
	int n1, n2, n = 1, x;                                                 // n2 - индекс конца слова.
	for (i = 0; i < l; i++)											      // цикл пока не дойдем до последней строки
	{
		j = 0;
		while (*(*(text + i) + j))										  // пока не кончится строка текста
		{
			do
			{
				while ((' ' <= *(*(text + i) + j)) && (*(*(text + i) + j) <= '/') ||                      // поиск слова
					((':' <= *(*(text + i) + j)) && (*(*(text + i) + j) <= '@')) && *(*(text + i) + j))
					j++;
				if (!*(*(text + i) + j))                                  //переход на начало следующей строки текста, если в просматриваемой нет слов
				{
					i++;
					j = 0;
					continue;
				}
				else break;
			} while (i < l);
			if (i == l) break;                                            // если кончились строки
			n1 = j;                                                       // запоминаем начало слова
			while ((('@' < (*(*(text + i) + j + 1))) || ((*(*(text + i) + j + 1)) < ' ')   //проход по слову
				|| (((*(*(text + i) + j + 1)) >= '0') && ((*(*(text + i) + j + 1)) <= '9'))) && *(*(text + i) + j + 1))
				j++;
			n2 = j;                                                       // запоминаем конец слова
			int b;                                                        // счетчик
			int word_len;                                                 // длина слова



			if (!reg)                                                      // если не нужно учитывать регистр
				if ((*(*(text + i) + n1) >= 'A' && *(*(text + i) + n1) <= 'Z')       // если первый символ слова - прописная буква,
					|| (*(*(text + i) + n1) >= 'А' && *(*(text + i) + n1) <= 'Я'))   // то меняем на строчную
					*(*(text + i) + n1) += ' ';

			for (k = 0; k < n; k++)                                       // цикл сравнения слова со словами из table
			{
				x = n1;                                                   // запоминаем начало слова
				b = 0;
				while (x <= n2)
				{
					if (*(*(table + k) + b) == *(*(text + i) + x))        //сравнение слов
					{
						x++;
						b++;
						continue;
					}
					else break;
				}
				if (((x - n1 == b) && ((((' ' <= *(*(text + i) + x)) && (*(*(text + i) + x) <= '/')) ||   // если слова совпадают
					((':' <= *(*(text + i) + x)) && (*(*(text + i) + x) <= '@')))                       // и следующий символ в тексте - знак препинания
					|| !*(*(text + i) + x))) && !*(*(table + k) + b))
					break;
			}


			if ((x - n1 == b) && (((' ' <= *(*(text + i) + x)) && (*(*(text + i) + x) <= '/') ||        // если слова совпадают
				((':' <= *(*(text + i) + x)) && (*(*(text + i) + x) <= '@'))) || !*(*(text + i) + x)))  // и следующий символ в тексте - знак препинания
				*(a + k) += 1;
			else                                                   // иначе создаем новую строку для слова в table
			{
				word_len = n2 - n1 + 1;
				for (b = 0; b < word_len; b++)
				{
					*(*(table + n - 1) + b) = *(*(text + i) + n1); // посимвольный перенос слова в table
					n1++;
				}
				*(*(table + n - 1) + b) = '\0';
				n++;                                               // увеличиваем число слов в table
			}
			j++;
		}
	}
	n--;

	//сортировка шейкером

	int  rev, stop, left, right;
	left = 1;
	stop = 1;   //номер элемента на котором остановка 
	right = n - 1;                //номер стартового элемента для сортировки справа налево 


	do
	{
		for (i = left; i <= right; i++)    // цикл попарного сравнения элементов  
		{                           // справа налево по массиву 
			if (*(a + i - 1) < *(a + i))    // выполняется условие перестановки  
			{                       // (i-1)-ого и i-го элемента  
				rev = *(a + i - 1);
				*(a + i - 1) = *(a + i);
				*(a + i) = rev;
				char* word = *(table + i - 1);
				*(table + i - 1) = *(table + i);
				*(table + i) = word;
				stop = i;              // запоминаем крайний слева упорядоченный элемент 
			}
		}
		right = stop - 1;                  // номер стартового элемента для сортировки слева направо 
		for (i = right; i >= left; --i)    // аналогично предыдущему циклу, но движение 
		{                           // слева направо по массиву 
			if (*(a + i - 1) < *(a + i))
			{
				rev = *(a + i - 1);
				*(a + i - 1) = *(a + i);
				*(a + i) = rev;
				char* word = *(table + i - 1);
				*(table + i - 1) = *(table + i);
				*(table + i) = word;
				stop = i;            // крайний слева упорядоченный элемент 
			}
		}
		left = stop + 1;
	} while (left <= right);


	if (*kol > n && **table)
	{
		*kol = n;
		char** tmp = (char**)realloc(table, n * sizeof(char*));        // перевыделение памяти
		if (tmp)
			table = tmp;
		int* temp = (int*)realloc(a, n * sizeof(int));
		if (temp)
			a = temp;
	}


	for (int i = 0; i < n; i++)
	{
		int len = str_len(*(table + i)) + 1;
		char* tmp = (char*)realloc(*(table + i), len * sizeof(int));
		if (tmp)
			 *(table + i) = tmp;
	}


	return table;
}

void free_mem(char** st, int l)
{
	for (int i = 0; i < l; i++)
	{
		*(st + i) = nullptr;
		free(*(st + i));                                //освобождение памяти указателей на строки    
	}
	st = nullptr;
	free(st);                                          //освобождение памяти указателя на массив строк
}
