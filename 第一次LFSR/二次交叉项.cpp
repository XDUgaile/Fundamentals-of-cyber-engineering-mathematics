#include <iostream>
#include <bitset>
using namespace std;

int main() {
    bitset<16> reg(0xACE1); // ��ʼ�Ĵ���ֵ
    bitset<16> mask(0x8005); // ����ʽ
    bitset<16> cross_mask(0x8000); // ���ν�����
    bitset<16> output;
    for (int i = 0; i < 16; i++) {
        cout << "Round " << i+1 << ": ";
        output[i] = reg[0];
        bool cross = reg[15] & reg[12]; // ���ν�����ļ���
        reg >>= 1;
        if (cross) reg ^= (mask ^ cross_mask); // ��Ӷ��ν�����
        else reg ^= mask;
        cout << output[i] << endl;
    }
    return 0;
}

