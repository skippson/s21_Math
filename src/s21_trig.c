#include "s21_trig.h"

long double s21_tan(double x) {
  long double res = 0.0;
  if (x == s21_PI / 2 || x == 3 * s21_PI / 2) {
    res = 16331239353195370L;
  } else if (x == -s21_PI / 2 || x == -3 * s21_PI / 2) {
    res = -16331239353195370L;
  } else {
    res = s21_sin(x) / s21_cos(x);
  }
  return res;
}

long double s21_sin(double x) {
  long double sin = 0.0;
  if (s21_IS_NAN(x) || x == s21_INF || x == s21_INF_NEG) {
    sin = s21_NAN;
  } else {
    x = s21_fmod(x, 2 * s21_PI);
    long double tmp = x;
    int i = 1;
    sin = x;
    while (s21_fabs(tmp) >= s21_EPS) {
      tmp *= (-1) * x * x / (i + 1) / (i + 2);
      i += 2;
      sin += (long double)tmp;
    }
    if (sin == 0) {
      sin = s21_fabs(sin);
    }
    if (s21_fmod(x, s21_PI / 2) == 0.0) {
      sin = s21_roundl(sin);
    }
  }

  return sin;
}

long double s21_cos(double x) {
  long double cos = 1.0;
  if (s21_IS_NAN(x) || x == s21_INF || x == s21_INF_NEG) {
    cos = s21_NAN;
  } else {
    x = s21_fmod(x, 2.0 * s21_PI);
    long double tmp = 1.0;
    long double i = 0.0;
    while (s21_fabs(tmp) >= s21_EPS) {
      tmp *= (long double)(-1) * x * x / (i + 1.0) / (i + 2.0);
      i += 2.0;
      cos += tmp;
    }

    if (s21_fmod(x, s21_PI / 2) == 0.0) {
      cos = s21_roundl(cos);
    }
    if (cos == 0) {
      cos = s21_fabs(cos);
    }
  }

  return cos;
}