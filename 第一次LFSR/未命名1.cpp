#include <stdio.h>

unsigned long lfsr = 0x12345678; // 初始值
unsigned int bit;

int main() {
    int i;
    for (i = 0; i < 33; i++) {
        bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 31)) & 1; // 抽头
        lfsr = (lfsr >> 1) | (bit << 31); // 更新状态
        printf("%d", bit); // 输出
    }
    return 0;
}

