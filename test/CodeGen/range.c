// RUN: %clang_cc1 -emit-llvm -o - %s | FileCheck %s
// END.

struct A {
        int x;
        int y __attribute__((range(100, 200)));
};

int z __attribute__((range(250, 500)));

int foo(struct A *a)
{
        return a->y + z;
}
// CHECK: load i32* %y, align 4, !range !0
// CHECK: load i32* @z, align 4, !range !1

// CHECK: !0 = metadata !{i32 100, i32 201}
// CHECK: !1 = metadata !{i32 250, i32 501}
