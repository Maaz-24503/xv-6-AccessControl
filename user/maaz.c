#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"

int main(){
    int temp = getuid();
    printf("%d\n", temp);
    setuid(12);
    temp = getuid();
    printf("%d\n", temp);
    return 0;
}