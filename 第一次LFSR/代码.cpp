#include <stdio.h>

unsigned long lfsr = 0x12345678; // ��ʼֵ
unsigned int bit;

int main() {
    int i;
    for (i = 0; i < 33; i++) {
        bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 31)) & 1; // ��ͷ
        lfsr = (lfsr >> 1) | (bit << 31); // ����״̬
        printf("%d", bit); // ���
    }
    return 0;
}

