#include "check_s21_math.h"

START_TEST(test_s21_ceil) {  //
  double value1 = 1.5;
  ck_assert_float_eq(s21_ceil(value1), ceil(value1));
  double value2 = 0.45;
  ck_assert_float_eq(s21_ceil(value2), ceil(value2));
  ck_assert_float_eq(s21_ceil(-value2), ceil(-value2));
  double value3 = -3.01;
  ck_assert_float_eq(s21_ceil(value3), ceil(value3));
  double value4 = -0;
  ck_assert_float_eq(s21_ceil(value4), ceil(value4));

  double value5 = 1234567;
  ck_assert_float_eq(s21_ceil(value5), ceil(value5));
  double value6 = 0;
  ck_assert_float_eq(s21_ceil(value6), ceil(value6));

  ck_assert_ldouble_eq(s21_ceil(s21_INF), ceil(s21_INF));
  ck_assert_ldouble_eq(s21_ceil(s21_INF_NEG), ceil(s21_INF_NEG));
  // ck_assert_ldouble_eq(s21_ceil(s21_MAX_DOUBLE), ceil(s21_MAX_DOUBLE));
}
END_TEST

START_TEST(test_s21_floor) {
  double value1 = 1.5;
  ck_assert_float_eq(s21_floor(value1), floor(value1));
  double value2 = 0.45;
  ck_assert_float_eq(s21_floor(value2), floor(value2));
  double value3 = -3.01;
  ck_assert_float_eq(s21_floor(value3), floor(value3));
  double value4 = -0.;
  ck_assert_float_eq(s21_floor(value4), floor(value4));
  double value5 = -0;
  ck_assert_float_eq(s21_floor(value5), floor(value5));

  ck_assert_ldouble_infinite(s21_floor(s21_INF));
  ck_assert_ldouble_infinite(floor(s21_INF));
  ck_assert_ldouble_nan(s21_floor(s21_NAN));
  ck_assert_ldouble_nan(floor(s21_NAN));
  ck_assert_ldouble_eq(s21_floor(s21_INF_NEG), floor(s21_INF_NEG));
}
END_TEST

START_TEST(test_s21_abs) {
  int value1 = -4;
  ck_assert_int_eq(s21_abs(value1), abs(value1));
  int value2 = -123;
  ck_assert_int_eq(s21_abs(value2), abs(value2));
  for (int i = -1234567; i < 123456; i += 10) {
    ck_assert_int_eq(s21_abs(i), abs(i));
  }
  // ck_assert_int_eq(s21_abs((int)s21_NAN), abs((int)s21_NAN));
  ck_assert_int_eq(s21_abs(+0), abs(+0));
  ck_assert_int_eq(s21_abs(-0), abs(-0));
  // ck_assert_int_eq(s21_abs((int)s21_INF), abs((int)s21_INF));
  // ck_assert_int_eq(s21_abs((int)s21_INF_NEG), abs((int)s21_INF_NEG));
}
END_TEST

START_TEST(test_s21_fmod) {  // hard valuies
  ck_assert_float_eq(s21_fmod(456.87678, 3.7), fmod(456.87678, 3.7));
  ck_assert_float_eq(s21_fmod(36677.546546, 4.1), fmod(36677.546546, 4.1));
  ck_assert_float_eq(s21_fmod(23.456, 4.355), fmod(23.456, 4.355));

  ck_assert_ldouble_nan(s21_fmod(s21_INF, s21_INF));
  ck_assert_ldouble_nan(fmod(s21_INF, s21_INF));
  ck_assert_ldouble_nan(s21_fmod(s21_INF_NEG, s21_INF_NEG));
  ck_assert_ldouble_nan(fmod(s21_INF_NEG, s21_INF_NEG));
  ck_assert_ldouble_nan(s21_fmod(s21_NAN, s21_NAN));
  ck_assert_ldouble_nan(fmod(s21_NAN, s21_NAN));
  ck_assert_int_eq(s21_fmod(0, 0), fmod(0, 0));
  ck_assert_int_eq(s21_fmod(0, s21_NAN), fmod(0, s21_NAN));
  ck_assert_int_eq(s21_fmod(-0, 0), fmod(-0, 0));
  ck_assert_int_eq(s21_fmod(-0, s21_NAN), fmod(-0, s21_NAN));

  ck_assert_int_eq(s21_fmod(s21_INF, 0), fmod(s21_INF, 0));
  ck_assert_int_eq(s21_fmod(s21_INF, s21_NAN), fmod(s21_INF, s21_NAN));
  ck_assert_int_eq(s21_fmod(5, 0), fmod(5, 0));
  ck_assert_int_eq(s21_fmod(s21_INF, 5), fmod(s21_INF, 5));
  ck_assert_int_eq(s21_fmod(s21_INF, -s21_INF), fmod(s21_INF, -s21_INF));
  ck_assert_float_eq(s21_fmod(6, -s21_INF), fmod(6, -s21_INF));
}
END_TEST

START_TEST(test_s21_exp) {  // hard value
  ck_assert_float_eq(s21_exp(5), exp(5));
  ck_assert_float_eq(s21_exp(-2), exp(-2));
  ck_assert_float_eq(s21_exp(1234567), exp(1234567));
  ck_assert_float_eq(s21_exp(-1234567), exp(-1234567));
  for (double i = -10; i < 10; i++) {
    ck_assert_float_eq(s21_exp(i), exp(i));
  }

  double x = 0 / 1;
  ck_assert_int_eq(s21_exp(x), exp(x));
  ck_assert_int_eq(s21_exp(s21_NAN), exp(s21_NAN));
  ck_assert_int_eq(s21_exp(s21_INF), exp(s21_INF));
  ck_assert_int_eq(s21_exp(s21_INF_NEG), exp(s21_INF_NEG));
}
END_TEST

START_TEST(test_s21_log) {
  ck_assert_float_eq(s21_log(12356), log(12356));
  ck_assert_float_eq(s21_log(1.1), log(1.1));
  for (double i = -1.; i < 10; i += 0.1) {
    ck_assert_int_eq(s21_log(i), log(i));
  }
  for (double i = 0.; i < 2; i += 0.01) {
    ck_assert_int_eq(s21_log(i), log(i));
  }

  double x = 0 / 1;
  ck_assert_float_eq(s21_log(x), log(x));
  ck_assert_int_eq(s21_log(s21_NAN), log(s21_NAN));
  ck_assert_int_eq(s21_log(s21_INF), log(s21_INF));
  ck_assert_int_eq(s21_log(s21_INF_NEG), log(s21_INF_NEG));
}
END_TEST

START_TEST(test_s21_sqrt) {
  ck_assert_float_eq(s21_sqrt(16.0), sqrt(16.0));
  ck_assert_float_eq(s21_sqrt(45.35), sqrt(45.35));
  ck_assert_float_eq(s21_sqrt(5.0), sqrt(5.0));
  ck_assert_int_eq(s21_sqrt(-5.0), sqrt(-5.0));
  for (double i = 0; i < 1; i += 0.001) {
    ck_assert_float_eq(s21_sqrt(i), sqrt(i));
  }
  double x = 0 / 1;
  ck_assert_int_eq(s21_sqrt(x), sqrt(x));
  ck_assert_int_eq(s21_sqrt(s21_NAN), sqrt(s21_NAN));
  ck_assert_int_eq(s21_sqrt(s21_INF), sqrt(s21_INF));
  ck_assert_int_eq(s21_sqrt(s21_INF_NEG), sqrt(s21_INF_NEG));
}
END_TEST

START_TEST(test_s21_pow) {  // hard value
  ck_assert_float_eq(s21_pow(2.6, 3.45), pow(2.6, 3.45));
  ck_assert_float_eq(s21_pow(3.0, 14.0), pow(3.0, 14.0));
  ck_assert_float_eq(s21_pow(31.456, 4.3), pow(31.456, 4.3));
  ck_assert_float_eq(s21_pow(31.456, 0.3), pow(31.456, 0.3));
  ck_assert_float_eq(s21_pow(4.3, 4.3), pow(4.3, 4.3));
  ck_assert_int_eq(s21_pow(-1234, 4.3), pow(-1234, 4.3));
  ck_assert_int_eq(s21_pow(-1234, -4.3), pow(-1234, -4.3));
  ck_assert_float_eq(s21_pow(1234, -4.3), pow(1234, -4.3));
  ck_assert_float_eq(s21_pow(1234, 0), pow(1234, 0));

  ck_assert_float_eq(s21_pow(456.87678, 3.7), pow(456.87678, 3.7));

  double x = 0 / 1;
  ck_assert_int_eq(s21_pow(x, x), pow(x, x));
  ck_assert_int_eq(s21_pow(s21_NAN, s21_NAN), pow(s21_NAN, s21_NAN));
  ck_assert_int_eq(s21_pow(s21_INF, s21_INF), pow(s21_INF, s21_INF));

  ck_assert_int_eq(s21_pow(0, -5), pow(0, -5));
  ck_assert_int_eq(s21_pow(0, -6), pow(0, -6));
  ck_assert_int_eq(s21_pow(0, 5), pow(0, 5));
  ck_assert_int_eq(s21_pow(0, 6), pow(0, 6));
  ck_assert_int_eq(s21_pow(-1, s21_INF), pow(-1, s21_INF));
  ck_assert_int_eq(s21_pow(-1, -s21_INF), pow(-1, -s21_INF));
  ck_assert_int_eq(s21_pow(1, s21_NAN), pow(1, s21_NAN));
  ck_assert_int_eq(s21_pow(5, s21_NAN), pow(5, s21_NAN));
  ck_assert_int_eq(s21_pow(5, -s21_INF), pow(5, -s21_INF));
  ck_assert_int_eq(s21_pow(0.5, s21_INF), pow(0.5, s21_INF));
  ck_assert_int_eq(s21_pow(0.5, -s21_INF), pow(0.5, -s21_INF));
}
END_TEST

START_TEST(test_s21_fabs) {
  ck_assert_float_eq(s21_fabs(-612367.54783), fabs(-612367.54783));
  ck_assert_float_eq(s21_fabs(-45.345), fabs(-45.345));
  ck_assert_float_eq(s21_fabs(1.0), fabs(1.0));

  double x = 0 / 1;
  ck_assert_int_eq(s21_fabs(x), fabs(x));
  ck_assert_int_eq(s21_fabs(s21_NAN), fabs(s21_NAN));
}
END_TEST

START_TEST(test_s21_roundl) {
  ck_assert_float_eq(s21_roundl(-1.3), roundl(-1.3));
}
END_TEST

Suite *s21_math_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("S21 Math");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_ceil);
  tcase_add_test(tc_core, test_s21_floor);
  tcase_add_test(tc_core, test_s21_abs);
  tcase_add_test(tc_core, test_s21_fmod);
  tcase_add_test(tc_core, test_s21_exp);
  tcase_add_test(tc_core, test_s21_log);
  tcase_add_test(tc_core, test_s21_sqrt);
  tcase_add_test(tc_core, test_s21_pow);
  tcase_add_test(tc_core, test_s21_fabs);
  tcase_add_test(tc_core, test_s21_roundl);
  suite_add_tcase(s, tc_core);

  return s;
}

int test_math() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = s21_math_suite();
  runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}