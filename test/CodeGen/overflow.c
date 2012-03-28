// RUN: %clang_cc1 %s -emit-llvm -o - -triple=i686-apple-darwin9 | FileCheck %s

#include <stddef.h>

void f(void) {
  extern int r, a, b;

  // CHECK: llvm.sadd.with.overflow.i32
  __builtin_sadd_with_overflow(&r, a, b);

  // CHECK: llvm.uadd.with.overflow.i32
  __builtin_uadd_with_overflow(&r, a, b);

  // CHECK: llvm.ssub.with.overflow.i32
  __builtin_ssub_with_overflow(&r, a, b);

  // CHECK: llvm.usub.with.overflow.i32
  __builtin_usub_with_overflow(&r, a, b);

  // CHECK: llvm.smul.with.overflow.i32
  __builtin_smul_with_overflow(&r, a, b);

  // CHECK: llvm.umul.with.overflow.i32
  __builtin_umul_with_overflow(&r, a, b);
}
