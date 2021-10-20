#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>


typedef struct
	{
		char fio[50];
		char adress [100];
		int date_birth;
		int month_birth;
		int year_birth;
		struct data *ptr_next;
	} data;

data *push (char fio[], char address[], int date_birth, int month_birth, int year_birth, data *head);
void print(data *head);


int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8"); 					// locale for Cyrillic
	data *head = NULL;
	char adress [100], fio[50];
	int date_birth, month_birth, year_birth;
	printf ("Фамилия Имя Отчество : ");
	fgets(fio, 50, stdin);
	fflush(stdin);
	printf ("Адрес : ");
	fgets(adress, 100, stdin);
	fflush(stdin);
	printf ("Число рождения : ");
	scanf("%d", &date_birth);
	printf ("Месяц роджения : ");
	scanf("%d", &month_birth);
	printf ("Год рождения : ");
	scanf("%d", &year_birth);
	head = push(fio, adress, date_birth, month_birth, year_birth, head);
	print(head);
}

data *push(char fio[], char adress[], int date_birth, int month_birth, int year_birth, data *head)
{
	data *tmp = (data *)malloc(sizeof(data));
	strlсpy (tmp->fio, fio, 50);
	strlсpy (tmp->adress, adress, 100);
	tmp->date_birth = date_birth;
	tmp->month_birth = month_birth;
	tmp->year_birth = year_birth;
	tmp->ptr_next = head;
	return tmp;
}

void print(data *head) {
    while (head) {
		fputs(head->fio, stdout);
		fputs(head->adress, stdout);
		printf("%d ", head->date_birth);
		printf("%d ", head->month_birth);
		printf("%d ", head->year_birth);
		head = head->ptr_next;
	}
    printf("\n");
}