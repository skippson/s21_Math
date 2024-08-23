#ifndef S21_POW_H
#define S21_POW_H

#include "s21_math.h"

// возводит число в заданную степень
long double s21_pow(double x, double degree);
long double fast_pow(double x, int degree);             // natural
long double pow_extra(double x, double y, bool *flag);  // extra val

#endif
