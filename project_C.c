#define _CRT_SECURE_NO_WARNINGS // <-- директива для scanf отключающая предупреждения безопасности -->
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <locale.h>

	// === ПРОТОТИПЫ ФУНКЦИЙ ===
void set_localization();

int main()
{
	set_localization(); // функция локализации.

	double matrix[3][3];
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("Введите число: ");
			scanf("%lf", &matrix[i][j]);
		}
		printf("Столбец %d заполнен.\nЗаполняем следующий столбец.\n", i + 1);
	}

	printf("\n\n\nМатрица заполнена.\nВаша матрица выглядит следующим образом:\n");

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%.2lf\t", matrix[i][j]);
		}
		printf("\n");
	}
}

// <=== ОПРЕДЕЛЕНИЯ ФУНКЦИЙ ===>
void set_localization()
{
	// <-- Устанпвливаем кодовую страницу консоли в UTF-8 -->
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	// <-- Устанавливаем локаль CRT в UTF-8 -->
	setlocale(LC_ALL, ".UTF8");
}