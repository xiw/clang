// RUN: %clang_cc1 %s -verify -fsyntax-only

// Sema tests for __builtin_*_with_overflow

void f(int *p, int a, int b) {
  __builtin_sadd_with_overflow(0);          // expected-error {{too few arguments to function call}}
  __builtin_sadd_with_overflow(0, 0);       // expected-error {{too few arguments to function call}}
  __builtin_sadd_with_overflow(0, 0, 0, 0); // expected-error {{too many arguments to function call}}

  __builtin_sadd_with_overflow(0, 0, 0);          // expected-error {{must be a pointer}}
  __builtin_sadd_with_overflow((float *)p, a, b); // expected-error {{must be a pointer to integer}}

  __builtin_sadd_with_overflow(p, a, b);
}
