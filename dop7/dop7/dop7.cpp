//Написать функцию для перевода переменной типа long в символьную строку в системе счисления, 
//которую вводит пользователь ltoaN(long num, char s[], int radix) и тестирующую программу к ней.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ltoaN.h"
#include <time.h>
int main() {
	int m = 0, rad = 0;
	printf("Enter number system (from 2 to 36): ");
	m = scanf("%d", &rad);
	while (!(rad>=2 && rad<=36)) {
		printf("Incorrect number! You should enter 2...36! Try again: ");
		m = scanf("%d", &rad);
	}
	double res = 0;
	int power = 64, val = 2;
	res = power * log10(val) / log10(rad);
	int len = (int)res;
	char* str = (char*)malloc((len + 2) * sizeof(char));
	char* tester = (char*)malloc((len + 2) * sizeof(char));
	long number = 0;
	printf("Enter the number: ");
	m = scanf("%i", &number);
	ltoaN(number, str, rad);
	if (str)
		printf("Result:\n%s\nTest program result:\n", str);
	if (tester)
		_ltoa(number, tester, rad);
	printf("%s\n", tester);
	free(str);
	free(tester);
	return 0;
}