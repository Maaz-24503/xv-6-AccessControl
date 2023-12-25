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
    int check1 = chown("", 0,0);
    int check2 = chmod("",S_IRWXU);
    int fd = open("./temp", O_CREATE);
    printf("%d  %d\n", check1, check2);
    return 0;
}