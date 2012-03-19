// RUN: %clang_cc1 %s -verify -fsyntax-only

// Sema tests for __overflow_*

void f(int *p, int a, int b) {
  __overflow_sadd(0);          // expected-error {{too few arguments to function call}}
  __overflow_sadd(0, 0);       // expected-error {{too few arguments to function call}}
  __overflow_sadd(0, 0, 0, 0); // expected-error {{too many arguments to function call}}

  __overflow_sadd(0, 0, 0);          // expected-error {{must be a pointer}}
  __overflow_sadd((float *)p, a, b); // expected-error {{must be a pointer to integer}}

  __overflow_sadd(p, a, b);
}
