#include <stdio.h>
#include <unistd.h>  // For write() and close()
#include <errno.h>   // For errno and perror()

int main() {
    close(1);
    int ret = printf("%c", "");
    char c = '5' + ret;
    write(2, &c, 1);
    return 0;
}