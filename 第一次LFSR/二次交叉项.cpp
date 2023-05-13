#include <iostream>
#include <bitset>
using namespace std;

int main() {
    bitset<16> reg(0xACE1); // 初始寄存器值
    bitset<16> mask(0x8005); // 多项式
    bitset<16> cross_mask(0x8000); // 二次交叉项
    bitset<16> output;
    for (int i = 0; i < 16; i++) {
        cout << "Round " << i+1 << ": ";
        output[i] = reg[0];
        bool cross = reg[15] & reg[12]; // 二次交叉项的计算
        reg >>= 1;
        if (cross) reg ^= (mask ^ cross_mask); // 添加二次交叉项
        else reg ^= mask;
        cout << output[i] << endl;
    }
    return 0;
}

