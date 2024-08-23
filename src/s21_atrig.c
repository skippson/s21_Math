#include "s21_atrig.h"

long double s21_asin(double x) {
  long double res = x;
  long double tmp = x;
  int num = 1;
  if (s21_fabs(x) < 1) {
    int denum = 2;
    while (s21_fabs(tmp) > s21_EPS) {
      tmp *= x * x * num / denum;
      res += (tmp / (denum + 1));
      num += 2;
      denum += 2;
    }
  } else if (x == 1) {
    res = s21_PI / 2;

  } else if (x == -1) {
    res = -s21_PI / 2;

  } else {
    res = s21_NAN;
  }
  return res;
}

long double s21_acos(double x) {
  return s21_asin(x) != s21_NAN ? (long double)(s21_PI / 2) - s21_asin(x)
                                : s21_NAN;
}

long double s21_atan(double x) {
  long double res = x;
  long double tmp = x;
  int denum = 3;
  if (x == s21_INF || x == -s21_INF) {
    res = x == -s21_INF ? -s21_PI / 2 : s21_PI / 2;
  } else if (s21_fabs(x) < 1) {
    while (s21_fabs(tmp) > s21_EPS) {
      tmp *= ((-1) * x * x);
      res += (tmp / denum);
      denum += 2;
    }
  } else if (s21_fabs(x) > 1) {
    tmp = 1 / x;
    res = 1 / x;
    while (s21_fabs(tmp) > s21_EPS) {
      tmp *= ((-1) / (x * x));
      res += (tmp / denum);
      denum += 2;
    }
    res = s21_PI * s21_fabs(x) / (2 * x) - res;
  } else if (s21_fabs(x) == 1) {
    res = x == -1 ? -s21_PI / 4 : s21_PI / 4;
  } else {
    res = s21_NAN;
  }
  return res;
}