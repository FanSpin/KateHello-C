//MakeKate-c hello world

#include <stdio.h>

int main()
{
    fprintf(stdout, "hello, world\n");
    return 1;
}

// Compile, then run: gcc hello.c -o hello
// Then run: ./hello
// stdout.txt should contain "hello, world"
// Your `echo $?` command should return 1

