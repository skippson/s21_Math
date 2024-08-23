#include "s21_atrig.h"
#include "s21_pow.h"
#include "s21_trig.h"

#ifndef S21_MATH_H
#define S21_MATH_H
#define s21_E 2.71828182845904523536028747
#define s21_PI 3.14159265358979323846264338327950288
#define s21_PI_NEG -3.14159265358979323846264338327950288
#define s21_NAN 0.0 / 0.0
#define s21_INF +1.0 / 0.0L
#define s21_INF_NEG -1.0 / 0.0L
#define s21_IS_NAN(x) x != x
#define s21_MAX_DOUBLE 1.7976931348623157e308
#define s21_M_LN10 2.30258509299404568402

#define s21_EPS 1e-35
#define true 1
#define false 0

typedef int bool;

// вычисляет абсолютное значение целого числа
int s21_abs(int x);

// возвращает ближайшее целое число, не меньшее заданного значения
long double s21_ceil(double x);

// возвращает значение e, возведенное в заданную степень
long double s21_exp(double x);

// вычисляет абсолютное значение числа с плавающей точкой
long double s21_fabs(double x);

// возвращает ближайшее целое число, не превышающее заданное значение
long double s21_floor(double x);

// остаток операции деления с плавающей точкой
long double s21_fmod(double x, double y);

// вычисляет натуральный логарифм
long double s21_log(double x);

// вычисляет квадратный корень
long double s21_sqrt(double x);

bool is_int(double x);

// округляет
long double s21_roundl(long double a);

#endif