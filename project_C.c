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

	double matrix[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("Введите число: ");
			scanf("%lf", &matrix[i][j]);
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%.2lf ", matrix[i][j]);
		}
		printf("\n");
	}

	// главная диагональ
	printf("\nГлавная диагональ\n");

	double sum_glav = 0.0;
	for (int i = 0; i < 3; i++) {
		sum_glav = sum_glav + matrix[i][i];
		printf("%.2lf, ", matrix[i][i]);
	}

	printf("\n");

	// побочная диагональ
	printf("\nПобочная диагональ\n");
	double sum_poboch = 0.0;
	for (int i = 0; i < 3; i++) {
		sum_poboch = sum_poboch + matrix[i][3 - i - 1];
		printf("%.2lf, ", matrix[i][3 - i - 1]);
	}


	printf("\n\n");
	printf("Сумма главной диагонали: %.2lf\n", sum_glav);
	printf("Сумма главной диагонали: %.2lf\n", sum_poboch);
	printf("\n\n");
	printf("Часть 2.\n\n");


	int matrix_2[2][2];

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			printf("Введите значение: ");
			scanf("%d", &matrix_2[i][j]);
		}
	}

	printf("\n");
	printf("Матрица имеет вид: \n");

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", matrix_2[i][j]);
		}
		printf("\n");
	}

	int squad_matrix_2[2][2]; // пустой массив для будущей матрицы.

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			squad_matrix_2[i][j] = 0; 					// обнуляем т.к. в ней после цикла есть "мусор", либо до него (память не очищается сама по себе). "Вычислили - записали - обнулили" <-- и так по кругу.
			for (int a = 0; a < 2; a++) {
				// Для ячейки [i][j] результата:
				// Берём строку [i] и столбец [j] из исходной матрицы,
				// перемножаем соответствующие элементы (с индексом 'a')
				// и НАКАПЛИВАЕМ сумму в ячейке результата.
				squad_matrix_2[i][j] = squad_matrix_2[i][j] + matrix_2[i][a] * matrix_2[a][j]; // счётчик 'a' перемножает строку i на столбец j, сумма копится в [i][j]"
			}
		}
	}

	printf("\n");
	printf("Матрица возведённая в квадрат:\n");

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", squad_matrix_2[i][j]);
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