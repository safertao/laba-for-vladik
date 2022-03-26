
#include"prot.h"

int num()
{
	int n, k;                                            //k - ���������� ��� ������������
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
	char** st = (char**)calloc(l, sizeof(char*));     //��������� ������ ��� ������ ���������� �� ������
	if (!st)
	{
		printf("������, ������ �� ���� ��������");
		exit(1);
	}
	for (int i = 0; i < l; i++)                       //��������� ������ ��� ��������� �� �������
		*(st + i) = (char*)calloc(m, sizeof(char));
	return st;
}

void vvod(char** st, int l, int m)
{
	char c;
	int j;
	for (int i = 0; i < l; i++)                            //���� ������
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
					printf("������, ������ ������� �������� �����.\n");
					printf("������� ������ ��� ���.\n");
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
			do                                                //������ �� ������ �����
			{
				while ((' ' <= *(*(text + i) + j)) && (*(*(text + i) + j) <= '/') ||
					((':' <= *(*(text + i) + j)) && (*(*(text + i) + j) <= '@')) && *(*(text + i) + j))
					j++;
				if (*(*(text + i) + j) == '\0') //������� �� ���� ������ ������ ���� ��� ����
				{
					i++;
					j = 0;
					continue;
				}
				break;
			} while (i < n);
			if (i == n) break;
			n1 = j;
			while ((('@' < (*(*(text + i) + j + 1))) || ((*(*(text + i) + j + 1)) < ' ')   //������ �� �����
				|| (((*(*(text + i) + j + 1)) >= '0') && ((*(*(text + i) + j + 1)) <= '9'))) && *(*(text + i) + j + 1))
				j++;
			n2 = j;
			*(text + i) = recurs_word(*(text + i), n1, n2);
			j++;
		}
	}
}


//
// ������������� �������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
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
//		do                                                          //���� ������ ������� �����
//		{
//			while ((' ' <= *(*(text + i) + j)) && (*(*(text + i) + j) <= '/') ||
//				((':' <= *(*(text + i) + j)) && (*(*(text + i) + j) <= '?')) && *(*(text + i) + j))
//				for (k = j; *(*(text + i) + k); k++)
//					*(*(text + i) + k) = *(*(text + i) + k + 1);
//			if (*(*(text + i) + j) == '\0') //������� �� ���� ������ ������ ���� ��� ����
//			{
//				i++;
//				continue;
//			}
//			break;
//		} while (i < *l);
//		if (i == *l) break;
//		n1 = j;
//		while ((('?' < (*(*(text + i) + j + 1))) || ((*(*(text + i) + j + 1)) < ' ')   //������ �� �����
//			|| (((*(*(text + i) + j + 1)) >= '0') && ((*(*(text + i) + j + 1)) <= '9'))) && *(*(text + i) + j + 1))
//			j++;
//		n2 = j;
//		x = 0;
//		len = str_len(*(text + i)) + 1;
//		word_len = n2 - n1 + 1;
//		word = (char*)calloc((word_len + 1), sizeof(char));
//		assert(word);
//		for (k = n1; k <= n2; k++)              //���������� �����
//			*(word + x++) = *(*(text + i) + k);
//		*(word + x) = '\0';
//		for (k = n1; *(*(text + i) + k + word_len - 1); k++)
//			*(*(text + i) + k) = *(*(text + i) + k + word_len);
//		char* tmp = (char*)realloc(*(text + i), (len -= word_len) * sizeof(char));
//		if (tmp)
//			*(text + i) = tmp;
//		num = 1;
//		while (i < *l)                                        //���� ��������� �� �������
//		{
//			len = str_len(*(text + i)) + 1;
//			for (j = 0; *(*(text + i) + j); )
//			{
//				while ((' ' <= *(*(text + i) + j)) && (*(*(text + i) + j) <= '/') ||
//					((':' <= *(*(text + i) + j)) && (*(*(text + i) + j) <= '?')) && *(*(text + i) + j))
//					j++;
//				if (*(*(text + i) + j) == '\0' && (i + 1) < *l) //������� �� ���� ������ ������ ���� ��� ����
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
//					if (*(*(text + i) + k) == *(word + x))//��������� ����
//					{
//						x++;
//						k++;
//						continue;
//					}
//					break;
//				}
//				if ((k - n1 == word_len) && (((' ' <= *(*(text + i) + k)) && (*(*(text + i) + k) <= '/') ||
//					((':' <= *(*(text + i) + k)) && (*(*(text + i) + k) <= '?'))) || !*(*(text + i) + k)))
//					//���� ����� ���������
//				{
//					for (k = n1; *(*(text + i) + k + word_len - 1); k++) //����� �� ����� �����
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
//		for (i = 0; i < *l; ) //���� �������� �� ������ ������
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
//		for (x = 0; *(word + x); x++)      //������� �����
//			*(*(table + str) + x) = *(word + x);  
//		*(*(table + str) + x) = '\0';
//		*(a + str) = num;                 //������� ���������� ����������
//		i = 0;
//		j = 0;
//		word = nullptr;
//		free(word);
//		str++;
//	}
//	*l = str;
//	for (k = 0; k < *l - 1; k++) //����������
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
		for (int i = 0; i < k; i++)                            // ����� ���������������� ������ �� �����
		{
			for (j = 0; *(*(text + i) + j); j++)
				printf("%c", *(*(text + i) + j));
			printf("%5d\n", *(a + i) + 1);

		}
		break;
	}


}



char** algorythm(char** text, int* a, int l, int max_words_num, int m, int reg, int* kol)  // table - ����� � �������� ����� �������������� �������,
																		  // a - ������ � ������ ���������� �������� ����� ������������� ����																		  // l - ����� ����� � ������, max_words_num - ���������� ��������� �����
{                                                                         // �������� ����� ������������� ����, reg - ���������� ��� ������� ��������
	char** table = mem(max_words_num, m);                                 // ������� ��������� ������ ��� �����
	int i, k, j;                                                          // i, j, k, x, n - ��������, n1 - ������ ������ �����,
	int n1, n2, n = 1, x;                                                 // n2 - ������ ����� �����.
	for (i = 0; i < l; i++)											      // ���� ���� �� ������ �� ��������� ������
	{
		j = 0;
		while (*(*(text + i) + j))										  // ���� �� �������� ������ ������
		{
			do
			{
				while ((' ' <= *(*(text + i) + j)) && (*(*(text + i) + j) <= '/') ||                      // ����� �����
					((':' <= *(*(text + i) + j)) && (*(*(text + i) + j) <= '@')) && *(*(text + i) + j))
					j++;
				if (!*(*(text + i) + j))                                  //������� �� ������ ��������� ������ ������, ���� � ��������������� ��� ����
				{
					i++;
					j = 0;
					continue;
				}
				else break;
			} while (i < l);
			if (i == l) break;                                            // ���� ��������� ������
			n1 = j;                                                       // ���������� ������ �����
			while ((('@' < (*(*(text + i) + j + 1))) || ((*(*(text + i) + j + 1)) < ' ')   //������ �� �����
				|| (((*(*(text + i) + j + 1)) >= '0') && ((*(*(text + i) + j + 1)) <= '9'))) && *(*(text + i) + j + 1))
				j++;
			n2 = j;                                                       // ���������� ����� �����
			int b;                                                        // �������
			int word_len;                                                 // ����� �����



			if (!reg)                                                      // ���� �� ����� ��������� �������
				if ((*(*(text + i) + n1) >= 'A' && *(*(text + i) + n1) <= 'Z')       // ���� ������ ������ ����� - ��������� �����,
					|| (*(*(text + i) + n1) >= '�' && *(*(text + i) + n1) <= '�'))   // �� ������ �� ��������
					*(*(text + i) + n1) += ' ';

			for (k = 0; k < n; k++)                                       // ���� ��������� ����� �� ������� �� table
			{
				x = n1;                                                   // ���������� ������ �����
				b = 0;
				while (x <= n2)
				{
					if (*(*(table + k) + b) == *(*(text + i) + x))        //��������� ����
					{
						x++;
						b++;
						continue;
					}
					else break;
				}
				if (((x - n1 == b) && ((((' ' <= *(*(text + i) + x)) && (*(*(text + i) + x) <= '/')) ||   // ���� ����� ���������
					((':' <= *(*(text + i) + x)) && (*(*(text + i) + x) <= '@')))                       // � ��������� ������ � ������ - ���� ����������
					|| !*(*(text + i) + x))) && !*(*(table + k) + b))
					break;
			}


			if ((x - n1 == b) && (((' ' <= *(*(text + i) + x)) && (*(*(text + i) + x) <= '/') ||        // ���� ����� ���������
				((':' <= *(*(text + i) + x)) && (*(*(text + i) + x) <= '@'))) || !*(*(text + i) + x)))  // � ��������� ������ � ������ - ���� ����������
				*(a + k) += 1;
			else                                                   // ����� ������� ����� ������ ��� ����� � table
			{
				word_len = n2 - n1 + 1;
				for (b = 0; b < word_len; b++)
				{
					*(*(table + n - 1) + b) = *(*(text + i) + n1); // ������������ ������� ����� � table
					n1++;
				}
				*(*(table + n - 1) + b) = '\0';
				n++;                                               // ����������� ����� ���� � table
			}
			j++;
		}
	}
	n--;

	//���������� ��������

	int  rev, stop, left, right;
	left = 1;
	stop = 1;   //����� �������� �� ������� ��������� 
	right = n - 1;                //����� ���������� �������� ��� ���������� ������ ������ 


	do
	{
		for (i = left; i <= right; i++)    // ���� ��������� ��������� ���������  
		{                           // ������ ������ �� ������� 
			if (*(a + i - 1) < *(a + i))    // ����������� ������� ������������  
			{                       // (i-1)-��� � i-�� ��������  
				rev = *(a + i - 1);
				*(a + i - 1) = *(a + i);
				*(a + i) = rev;
				char* word = *(table + i - 1);
				*(table + i - 1) = *(table + i);
				*(table + i) = word;
				stop = i;              // ���������� ������� ����� ������������� ������� 
			}
		}
		right = stop - 1;                  // ����� ���������� �������� ��� ���������� ����� ������� 
		for (i = right; i >= left; --i)    // ���������� ����������� �����, �� �������� 
		{                           // ����� ������� �� ������� 
			if (*(a + i - 1) < *(a + i))
			{
				rev = *(a + i - 1);
				*(a + i - 1) = *(a + i);
				*(a + i) = rev;
				char* word = *(table + i - 1);
				*(table + i - 1) = *(table + i);
				*(table + i) = word;
				stop = i;            // ������� ����� ������������� ������� 
			}
		}
		left = stop + 1;
	} while (left <= right);


	if (*kol > n && **table)
	{
		*kol = n;
		char** tmp = (char**)realloc(table, n * sizeof(char*));        // ������������� ������
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
		free(*(st + i));                                //������������ ������ ���������� �� ������    
	}
	st = nullptr;
	free(st);                                          //������������ ������ ��������� �� ������ �����
}
