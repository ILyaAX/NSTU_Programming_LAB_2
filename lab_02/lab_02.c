#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

#define MAX_NAME	50
#define MAX_ADRESS	100

typedef struct
	{
		wchar_t fio[MAX_NAME];
		wchar_t adress[MAX_ADRESS];
		int date_birth;
		int month_birth;
		int year_birth;
		struct data *ptr_next;
	} data;

data *push (wchar_t fio[], wchar_t address[], int date_birth, int month_birth, int year_birth, data *head);
void print(data *head);
void fill_str (wchar_t A[], int n);

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8"); 					// locale for Cyrillic
	data *head = NULL;
	wchar_t adress[MAX_ADRESS], fio[MAX_NAME];
	int date_birth, month_birth, year_birth;
	wprintf (L"Фамилия Имя Отчество : ");
	fill_str (fio, MAX_NAME);
	wprintf (L"Адрес : ");
	fill_str (adress, MAX_ADRESS);
	wprintf (L"Число рождения : ");
	wscanf(L"%2d", &date_birth);
	wprintf (L"Месяц роджения : ");
	wscanf(L"%2d", &month_birth);
	wprintf (L"Год рождения : ");
	wscanf(L"%4d", &year_birth);
	head = push(fio, adress, date_birth, month_birth, year_birth, head);
	print(head);
}

data *push(wchar_t fio[], wchar_t adress[], int date_birth, int month_birth, int year_birth, data *head)
{
	data *tmp = (data *)malloc(sizeof(data));
	wcscpy (tmp->fio, fio);
	wcscpy (tmp->adress, adress);
	tmp->date_birth = date_birth;
	tmp->month_birth = month_birth;
	tmp->year_birth = year_birth;
	tmp->ptr_next = head;
	return tmp;
}

void print(data *head) {
    while (head) {
		wprintf(L"%S", head->fio);
		wprintf(L"%S", head->adress);
		wprintf(L"%d ", head->date_birth);
		wprintf(L"%d ", head->month_birth);
		wprintf(L"%d ", head->year_birth);
		head = head->ptr_next;
	}
    printf("\n");
}

void fill_str (wchar_t A[], int n) {
    for (int i = 0; i < n ; i++) {
    	wscanf (L"%lc", &A[i]);
    	if (A[i] == '\n') {
        	A[i] = '\0';
        	break;
    	}    
    }
}