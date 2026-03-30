#define _CRT_SECURE_NO_WARNINGS // <-- директива для scanf отключающая предупреждения безопасности -->
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <locale.h>

#define m1 3 // константна для хранения размера массива для матрицы_1. Правим, в случае если хотим задать размер квадратной матрицы.
#define m2 2 // константна для хранения размера массива для матрицы_2. Правим, в случае если хотим задать размер квадратной матрицы.

	// === ПРОТОТИПЫ ФУНКЦИЙ ===
void set_localization();

int main()
{
	set_localization(); // функция локализации.

	double matrix_1[m1][m1]; // Объявляем массив данных типа double размера 3 на 3, поскольку #define m1 = 3.

	printf("Заполняем массив данных. \n\n");

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("Введите число: ");
			scanf("%lf", &matrix_1[i][j]);
		}
	}

	printf("\nМассив заполнен.\nВыводим итоговую таблицу(матрицу).\n\n");

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%.1lf\t", matrix_1[i][j]);
		}
		printf("\n");
	}

	printf("\nПроизводим расчёты...\n");

	double sum_glav = 0;
	double sum_poboch = 0;

	for (int i = 0; i < 3; i++) {
		sum_glav = sum_glav + matrix_1[i][i];
	}
	printf("\nСумма значений главной диагонали матрицы равна: %.2lf", sum_glav);

	for (int i = 0; i < 3; i++) {
		sum_poboch = sum_poboch + matrix_1[i][3 - 1 - i];
	}
	printf("\nСумма значений побочной диагонали матрицы равна: %.2lf\n", sum_poboch);
	

	printf("\n==============================================================");
	printf("\n==================Вторая часть лабораторной===================\n");
	printf("==============================================================\n");


	int matrix_2[m2][m2]; // Объявляем массив данных типа int размера 2 на 2.

	printf("Заполняем матрицу... \nРазмер КВАДРАТНОЙ матрицы: %d \n", m2);
	for (int i = 0; i < m2; i++) {
		for (int j = 0; j < m2; j++) {
			printf("Введите число: ");
			scanf("%d", &matrix_2[i][j]);
		}
	}

	printf("Матрица имеет вид: \n");
	for (int i = 0; i < m2; i++) {
		for (int j = 0; j < m2; j++) {
			printf("%d ", matrix_2[i][j]);
		}
		printf("\n");
	}

	printf("\nПеремножим матрицу саму на себя (квадрат матрицы).\n");
	int squad_matrix[m2][m2];
	for (int i = 0; i < m2; i++) {
		for (int j = 0; j < m2; j++) {
			squad_matrix[i][j] = 0;
			for (int a = 0; a < m2; a++) {
				squad_matrix[i][j] = squad_matrix[i][j] + matrix_2[i][a] * matrix_2[a][j];
			}
		}
	}

	printf("\nКвадрат матрицы:\n");
	for (int i = 0; i < m2; i++) {
		for (int j = 0; j < m2; j++) {
			printf("%d ", squad_matrix[i][j]);
		}
		printf("\n");
	}



	return 0;
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