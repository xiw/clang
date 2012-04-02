// RUN: %clang_cc1 %s -emit-llvm -o - -triple=i686-apple-darwin9 | FileCheck %s

#include <stddef.h>

void f(void) {
  extern int c, a, b;
  extern unsigned z, x, y;

  // CHECK: llvm.sadd.with.overflow.i32
  __builtin_add_with_overflow(&c, a, b);

  // CHECK: llvm.uadd.with.overflow.i32
  __builtin_add_with_overflow(&z, x, y);

  // CHECK: llvm.ssub.with.overflow.i32
  __builtin_sub_with_overflow(&c, a, b);

  // CHECK: llvm.usub.with.overflow.i32
  __builtin_sub_with_overflow(&z, x, y);

  // CHECK: llvm.smul.with.overflow.i32
  __builtin_mul_with_overflow(&c, a, b);

  // CHECK: llvm.umul.with.overflow.i32
  __builtin_mul_with_overflow(&z, x, y);
}
