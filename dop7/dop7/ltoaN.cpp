//Написать функцию для перевода переменной типа long в символьную строку в системе счисления, 
//которую вводит пользователь ltoaN(long num, char s[], int radix) и тестирующую программу к ней.
#include "ltoaN.h"
#include <math.h>
#include <stdlib.h>
void ltoaN(long num, char s[], int radix)
{
	char cc[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	int i, j, flag = 0;
	char number_cc[66];
	unsigned long temp = num;
	if (temp == 0) {
		s[0] = '0';
		s[1] = '\0';
		return;
	}
	else {
		if (radix != 10 && num < 0) {
			for (i = 0; temp > 0; i++) {
				number_cc[i] = cc[temp % radix];
				temp /= radix;
			}
			i--;
			for (j = 0; i >= 0; i--)
				s[j++] = number_cc[i];
			s[j] = '\0';
		}
		else {
			if (num < 0) {
				num = -num;
				flag = 1;
			}
			for (i = 0; num > 0; i++) {
				number_cc[i] = cc[num % radix];
				num /= radix;
			}
			i--;
			if (flag == 1) { //условие: ставить ли минус?
				s[0] = '-';
				for (j = 1; i >= 0; i--)
					s[j++] = number_cc[i];
			}
			else {
				for (j = 0; i >= 0; i--)
					s[j++] = number_cc[i];
			}
			s[j] = '\0';
		}
	}
}