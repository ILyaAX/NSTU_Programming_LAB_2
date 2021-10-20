#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

int main () {
	int a;
	setlocale(LC_ALL, "ru_RU.UTF-8");
	wchar_t fio[50], str[50];
	wprintf(L"строка : ");
	wscanf (L"%ls", fio);
	wprintf (L"значение: %ls", fio);
	wscanf (L"%d", &a);
	wprintf (L"число: %d", a);
	wcscpy(str, fio);
	wprintf(L"значение str: %ls", str);
	return 0;
}