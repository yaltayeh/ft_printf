#include <stdio.h>
#include <unistd.h>  // For write() and close()
#include <errno.h>   // For errno and perror()

int main() {
    // إغلاق الـ stdout
    close(STDOUT_FILENO);

    // محاولة الكتابة إلى stdout المغلق
    const char text[] = "Hello, World!\n";
    ssize_t bytes_written = write(STDOUT_FILENO, text, sizeof(text));
    int ret = printf("testdfad");
    char a[4];
    a[0] = '3' + bytes_written;
    write(2, a, 1);

    return 0;
}