#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"

int test1(){
    int temp = getuid();
    if(temp<0) return 0;
    return 1;
}
int test2(){
    int temp = getgid();
    if(temp<0) return 0;
    return 1;
}
int test3(){
    int temp = getuid();
    int check = setuid(4);
    int changed = getuid();
    int discard = setuid(temp);
    if(check>0 && changed==4) return 1;
    return 0;
}
int test4(){
    int temp = getgid();
    int check = setgid(4);
    int changed = getgid();
    int discard = setgid(temp);
    if(check>0 && changed==4) return 1;
    return 0;
}
int test5(){
    int blah = setuid(0);
    int check = chown("",0,0);
    if(check<0) return 1;
    return 0;
}
int test6(){
    int blah = setuid(0);
    int check = chmod("",S_IRGRP | S_IWGRP);
    if(check<0) return 1;
    return 0;
}

int main(){
    int first, second, third, fourth, fifth, sixth;

    first = test1();
    second = test2();
    third = test3();
    fourth = test4();
    fifth = test5();
    sixth = test6();

    if(!first) printf("Test 1 failed, that means getuid system call is failing\n");
    else printf("Test 1 passed, that means getuid system call is working\n");

    if(!second) printf("Test 2 failed, that means getgid system call is failing\n");
    else printf("Test 2 passed, that means getgid system call is working\n");

    if(!third) printf("Test 3 failed, that means setuid system call is failing\n");
    else printf("Test 3 passed, that means setuid system call is working\n");

    if(!fourth) printf("Test 4 failed, that means setgid system call is failing\n");
    else printf("Test 4 passed, that means setgid system call is working\n");

    if(!fifth) printf("Test 5 failed, that means chown system call is failing\n");
    else printf("Test 5 passed, that means chown system call is working\n");

    if(!sixth) printf("Test 6 failed, that means chmod system call is failing\n");
    else printf("Test 6 passed, that means chmod system call is working\n");

    return 0;
}