#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

void my_strcpy(char *buf, char *input, int n) {
    for (int i = 0; i < n; i ++) {
        buf[i] = input[i];
    }
}

void overflow(char *input) {
    char buf[4];
    printf("normal running\n");
    my_strcpy(buf, input, 20);
}

void attack() {
    FILE *fp;
    fp = freopen("attack.out", "w", stdout);
    printf("attack!");
    fclose(fp);
}

int main() {
    char input[] = "111111111111\x06\x52\x55\x55\x55\x55\x00\x00";
    overflow(input);
}
