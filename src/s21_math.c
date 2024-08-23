#include "s21_math.h"

int s21_abs(int x) {
  if (x < 0) {
    x *= -1;
  }
  return x;
}

long double s21_ceil(double x) {
  long int tmp = (long int)x;
  if (x == s21_INF) {
    return s21_INF;
  } else if (x == -s21_INF) {
    return -s21_INF;
  } else {
    if (x > 0) {
      if (is_int(x) != true) {
        tmp += 1;
      }
    } else if ((x > -1 && x < 0)) {
      tmp = 0;
    }
  }

  return tmp;
}

long double s21_exp(double x) {
  long double ans = 1;
  long double new_x = x;
  bool flag = false;
  bool znak = false;
  if (x < 0) {
    new_x *= -1;
    znak = true;
  }
  if (x == 0) {
    ans = 1;
    flag = true;
  }
  if (x == 1) {
    ans = s21_E;
    flag = true;
  }
  if (flag == false) {
    long double tmp = 1;
    long double i = 1;
    while (s21_fabs(tmp) > s21_EPS) {
      tmp *= new_x / i;
      i++;
      ans += tmp;
      if (ans > s21_MAX_DOUBLE) {
        ans = s21_INF;
        break;
      }
    }
  }
  if (znak == true) {
    if (ans == s21_INF) {
      ans = 0;
    } else
      ans = 1 / ans;
  }

  return ans;
}

bool is_int(double x) {
  bool flag = false;
  if (s21_fmod(x, (int)x) == 0.0) {
    flag = true;
  }
  return flag;
}

long double s21_log(double x) {
  long double sign = 1;
  long double pow = 0;
  long double count = 2;
  long double ans = 0;
  long double temp = 0;
  if (s21_IS_NAN(x)) {
    return s21_NAN;
  } else if (x == s21_INF) {
    return s21_INF;
  } else if (x == -s21_INF) {
    return -s21_NAN;
  }
  if (x < 0) {
    x = x * -1;
    sign = sign * -1;
  } else {
    x = x * 1;
    sign = sign * 1;
  }
  while ((x >= 10) || (x < 1 && x > 0)) {
    if (x < 1 && x > 0) {
      x = x * 10;
      pow = pow - 1;
    } else {
      x = x * 0.1;
      pow = pow + 1;
    }
  }
  x = sign * x / 10;
  if (x < 0) {
    ans = -s21_NAN;
  } else if (x == 0) {
    ans = s21_INF_NEG;
  } else {
    x--;
    ans = x;
    temp += x;
    while (s21_fabs(ans) > s21_EPS) {
      ans = ans * -x * (count - 1) / count;
      count = count + 1;
      temp = temp + ans;
    }
    ans = temp + (pow + 1) * s21_M_LN10;
  }
  return (x == 1) ? 0 : ans;
}

long double s21_fabs(double x) {
  if (x < 0) {
    x *= -1;
  }
  return x;
}

long double s21_floor(double x) {
  long int ans = (long int)x;
  if (x == s21_INF) {
    return s21_INF;
  } else if (x == -s21_INF) {
    return -s21_INF;
  } else if (s21_IS_NAN(x)) {
    return s21_NAN;
  }
  if (ans < 0) {
    ans -= 1;
  }
  return (long double)ans;
}

long double s21_fmod(double x, double y) {
  long double ans = s21_fabs(x);
  y = s21_fabs(y);
  long int i = 1;
  if (x == 0 && (y == 0.0 || s21_IS_NAN(y))) {
    return s21_NAN;
  } else if (y == 0.0 || x == s21_INF || x == -s21_INF) {
    return s21_NAN;
  } else if (y == s21_INF || y == -s21_INF) {
    return (long double)x;
  } else {
    while (ans >= y) {
      ans = s21_fabs(x) - y * i;
      i++;
    }
  }

  return (x < 0 ? -ans : ans);
}

long double s21_sqrt(double x) {
  long double ans = 0;
  if (x == -0) {
    return -0;
  }
  if (x < 0) {
    ans = s21_NAN;
  } else
    ans = s21_pow(x, 0.5);
  return ans;
}

long double s21_roundl(long double a) {
  long double b = a * 10;
  long int tmp = (long int)b;
  if (tmp < 0) {
    if (tmp % 10 <= -5) {
      a = (long int)a - 1;
    } else {
      a = (long int)a;
    }
  } else {
    if (tmp % 10 >= 5) {
      a = (long int)a + 1;
    } else {
      a = (long int)a;
    }
  }

  return (long double)a;
}