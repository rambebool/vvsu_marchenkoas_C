#define _CRT_SECURE_NO_WARNINGS // <-- директива для scanf отключающая предупреждения безопасности -->
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <locale.h>

/*==================== СПЕЦИФИКАТОРЫ ФОРМАТА ============================//
				<-- %d или &i - целые числа со знаком	 (int) -->
				<-- %c - одиночный символ				 (char) -->
				<-- %f - числа с плавающей точкой		 (float) -->
				<-- %lf -								 (double) -->
				<-- %s - для строк						 (string) -->
 =========================================================================
*/

void set_localization()
{
	// <-- Устанпвливаем кодовую страницу консоли в UTF-8 -->
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	// <-- Устанавливаем локаль CRT в UTF-8 -->
	setlocale(LC_ALL, ".UTF8");
}

/*============================== ФУНКЦИИ ==============================//
// тип ф-ии _ имя(что принимает) {тело функции, что выполняет}
//
=========================================================================
*/


void print_square(int number)
{
	int square = number * number;
	printf("ИТОГ: %d в квадрате = %d\n", number, square);
}

int main()
{
	// <=== БЛОК ЛОКАЛИЗАЦИИ ===>
	set_localization(); // функция локализации.

	// <=== БЛОК ПЕРЕМЕННЫХ ===>

	int random_number;

	// <=== БЛОК КОДА ===>

	printf("Введите число: ");
	scanf("%d", &random_number);

	print_square(random_number);


	return 0;
}