#include "s21_pow.h"

long double fast_pow(double x, int degree) {
  long double res = x;
  for (int i = 1; i < degree; i++) {
    res *= x;
  }
  return res;
}

long double pow_extra(double x, double y, bool *flag) {
  if (x == +0.0) {
    if (y < 0) {
      *flag = true;
      return s21_INF;
    } else if (y > 0 && s21_fmod(y, 2) != 0) {
      *flag = true;
      return x;
    } else if (y > 0 && s21_fmod(y, 2) == 0) {
      *flag = true;
      return 0;
    }
  } else if (x == -1 && (y == s21_INF || y == -s21_INF)) {
    *flag = true;
    return 1;
  } else if (x == 1) {
    *flag = true;
    return 1;
  } else if (y == 0) {
    *flag = true;
    return 1;
  } else if (x < 0) {
    *flag = true;
    return s21_NAN;
  } else if (s21_fabs(x) < 1 && y == -s21_INF) {
    *flag = true;
    return s21_INF;
  } else if (s21_fabs(x) > 1 && y == -s21_INF) {
    *flag = true;
    return +0;
  } else if (s21_fabs(x) < 1 && y == s21_INF) {
    *flag = true;
    return +0;
  }
  return 0;
}

long double s21_pow(double x, double y) {
  long double res = 0;
  bool flag = false;
  bool extra = false;
  pow_extra(x, y, &extra);
  if (x == 0) {
    flag = true;
  }
  if (y == 0.0) {
    res = 1;
  }
  if (flag == false && extra == false) {
    if (is_int(y)) {
      res = fast_pow(x, y);

    } else {
      res = s21_exp((long double)y * s21_log(x));
    }
  }
  return !extra ? res : pow_extra(x, y, &extra);
}