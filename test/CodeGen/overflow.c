// RUN: %clang_cc1 %s -emit-llvm -o - -triple=i686-apple-darwin9 | FileCheck %s

#include <stddef.h>

void f(void) {
  extern int r, a, b;

  // CHECK: llvm.sadd.with.overflow.i32
  __overflow_sadd(&r, a, b);

  // CHECK: llvm.uadd.with.overflow.i32
  __overflow_uadd(&r, a, b);

  // CHECK: llvm.ssub.with.overflow.i32
  __overflow_ssub(&r, a, b);

  // CHECK: llvm.usub.with.overflow.i32
  __overflow_usub(&r, a, b);

  // CHECK: llvm.smul.with.overflow.i32
  __overflow_smul(&r, a, b);

  // CHECK: llvm.umul.with.overflow.i32
  __overflow_umul(&r, a, b);
}
