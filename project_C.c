#define _CRT_SECURE_NO_WARNINGS // <-- директива для scanf отключающая предупреждения безопасности -->
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <stdlib.h>


	// === ПРОТОТИПЫ ФУНКЦИЙ ===
void set_localization();

int main()
{
	set_localization(); // функция локализации.

	int size_m;
	printf("Введите размер КВАДРАТНОЙ матрицы: ");
	scanf("%d", &size_m); 
	printf("\n(!)Задан размер квадратной матрицы: %d на %d\n", size_m, size_m);

	// выделяем область памяти для матрицы. matrix - переменная хранящая адрес памяти, куда мы запишем значения.
	double** matrix = malloc(size_m * sizeof(double*));
	// сразу сделаем проверку прежде чем выделять память под ячейки.
	if (matrix == NULL) {
		printf("Ошибка выделения памяти.");
		return 1; // завершаем с кодом ошибки.
	}
	// выделяем память под каждую ячейку в соответствии с size_m (количеством ячеек), в них запишем значения элементов матрицы.
	for (int i = 0; i < size_m; i++) {
		matrix[i] = malloc(size_m * sizeof(double));
	}
	
	// заполним матрицу значениями.
	for (int i = 0; i < size_m; i++) {
		printf("Заполняем %d столбец.\n", i + 1);
		for (int j = 0; j < size_m; j++) {
			printf("Введите значение для %d строки %d столбца: ", j + 1, i + 1);
			scanf("%lf", &matrix[i][j]);
		}
	}

	printf("\nКВАДРАТНАЯ матрица:\n");
	for (int i = 0; i < size_m; i++) {
		for (int j = 0; j < size_m; j++) {
			printf("%.2lf\t", matrix[i][j]);
		}
		printf("\n");
	}

	// 2 переменные для суммы эл-тов побочной/главной диагонали.
	double sum_glav = 0;
	double sum_poboch = 0;
	// перечислям(показываем пользователю) + сразу суммируем и записываем в соответсвтвующую переменную.
	printf("----------------------------------------\n");
	printf("Главная диагональ:\n");
	for (int i = 0; i < size_m; i++) {
		printf("%.2lf\t", matrix[i][i]);
		sum_glav = sum_glav + matrix[i][i];
	}
	printf("\n----------------------------------------\n");
	printf("Побочная диагональ:\n");
	for (int i = 0; i < size_m; i++) {
		printf("%.2lf\t", matrix[i][size_m - i - 1]);
		sum_poboch = sum_poboch + matrix[i][size_m - i - 1];
	}
	printf("\n----------------------------------------\n");

	//показываем результат вычислений.
	printf("\nСумма элементов ГЛАВНОЙ диагонали матрицы: %.2lf\n", sum_glav);
	printf("Сумма элементов ПОБОЧНОЙ диагонали матрицы: %.2lf\n", sum_poboch);
	printf("\n\n");


	// очистка памяти.
	for (int i = 0; i < size_m; i++) {
		free(matrix[i]); // чистим каждую ячейку памяти на которую ссылается переменная matrix_source.
	}
	free(matrix); // очищаем адрес на указатель.

	/*---------------------------------------------------------------------*/
	
	int size_matrix;
	printf("Введите размер матрицы: ");
	scanf("%d", &size_matrix);

	int** matrix_source = malloc(size_matrix * sizeof(int*));
	for (int i = 0; i < size_matrix; i++) {
		matrix_source[i] = malloc(size_matrix * sizeof(int));
	}

	printf("Заполняем матрицу.\n");
	for (int i = 0; i < size_matrix; i++) {
		printf("Заполняем %d столбец.\n", i + 1);
		for (int j = 0; j < size_matrix; j++) {
			printf("Введите значение для %d строки %d столбца: ", j + 1, i + 1);
			scanf("%d", &matrix_source[i][j]);
		}
	}

	printf("КВАДРАТНАЯ матрица:\n");
	for (int i = 0; i < size_matrix; i++) {
		for (int j = 0; j < size_matrix; j++) {
			printf("%d\t", matrix_source[i][j]);
		}
		printf("\n");
	}

	printf("Возводим матрицу в квадрат.\n");
	int** matrix_square = malloc(size_matrix * sizeof(int*));
	for (int i = 0; i < size_matrix; i++) {
		matrix_square[i] = malloc(size_matrix * sizeof(int));
	}


	for (int i = 0; i < size_matrix; i++) {
		for (int j = 0; j < size_matrix; j++) {
			matrix_square[i][j] = 0;
				for (int a = 0; a < size_matrix; a++) {
					matrix_square[i][j] = matrix_square[i][j] + matrix_source[i][a] * matrix_source[a][j];
				}
		}
	}

	printf("\nИТОГО\n");
	for (int i = 0; i < size_matrix; i++) {
		for (int j = 0; j < size_matrix; j++) {
			printf("%d\t", matrix_square[i][j]);
		}
		printf("\n");
	}

	// очищаем память.
	for (int i = 0; i < size_matrix; i++) {
		free(matrix_source[i]);
	}
	free(matrix_source);

	for (int i = 0; i < size_matrix; i++) {
		free(matrix_square[i]);
	}
	free(matrix_square);
	

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