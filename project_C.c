#define _CRT_SECURE_NO_WARNINGS // <-- директива для scanf отключающая предупреждения безопасности -->
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <locale.h>

/*==================== СПЕЦИФИКАТОРЫ ФОРМАТА ============================//
				<-- %d или &i - целые числа со знаком	 (int) -->
				<-- %c - одиночный символ				 (char) -->
				<-- %f - числа с плавающей точкой		 (float, double) -->
				<-- %s - для строк						 (string) -->
 =========================================================================
*/

int main() //<=== определяем функцию main ===>
{
	// <=== БЛОК ЛОКАЛИЗАЦИИ ===>
	// <-- Устанпвливаем кодовую страницу консоли в UTF-8 -->
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	// <-- Устанавливаем локаль CRT в UTF-8 -->
	setlocale(LC_ALL, ".UTF8");

	// <=== БЛОК ПЕРЕМЕННЫХ ===>

	int shirina, visota;

	// <=== БЛОК КОДА ===>

	printf("Вычисляем S и P прямоугольника.\n");

	printf("ВВЕДИТЕ ШИРИНУ: ");
	scanf("%d", &shirina); // Используем %d как стандарт

	printf("ВВЕДИТЕ ВЫСОТУ: ");
	scanf("%d", &visota);  // Используем %d как стандарт

	printf("S прямоугольника равна: %d * %d = %d\n", shirina, visota, shirina * visota);
	printf("P прямоугольника равен: 2 * (%d + %d) = %d\n", shirina, visota, 2 * (shirina + visota));

	if (shirina * visota > 100) {
		printf("Ого, какой большой прямоугольник");
	}
	else if (shirina * visota < 10) {
		printf("Какой маленький прямоугольник");
	}
	return 0;
}












/*
	// int хранит целые числа
    int a = 1;
	// char хранит одиночный символ, !!!ТОЛЬКО ОДИН и не более.
    char b = 'A';
    // float хранит числа с дробной частью
    float c = 3.14;

	//спецификаторы формата говорят функции printf, какого типа данные мы хотим вывести на экран.
	//спецификатор формата %d - целые числа
    printf("This is number: %d\n", a);
	//спецификатор формата %c - одиночный символ
	printf("this is symbol: %c\n", b);
	//спецификатор формата %f - числа с плавающей точкой
	printf("This is fractional number : %f\n", c);
        return 0;
}
*/