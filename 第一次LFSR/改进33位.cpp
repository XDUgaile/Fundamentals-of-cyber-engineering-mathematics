#include <iostream>

#define LFSR_LENGTH 33

class LFSR {
public:
    LFSR(unsigned int state[LFSR_LENGTH], unsigned int taps[LFSR_LENGTH]) {
        for (int i = 0; i < LFSR_LENGTH; i++) {
            this->state[i] = state[i];
            this->taps[i] = taps[i];
        }
    }

    void shift() {
        unsigned int feedback = 0;
        for (int i = 0; i < LFSR_LENGTH; i++) {
            if (taps[i] == 1) {
                feedback ^= state[i];
            }
        }
        for (int i = 0; i < LFSR_LENGTH-1; i++) {
            state[i] = state[i+1];
        }
        state[LFSR_LENGTH-1] = feedback;
    }

    void generate(unsigned int output[64]) {
        for (int i = 0; i < 66; i++) {
            shift();
        }
        for (int i = 0; i < 64; i++) {
            output[i] = state[0];
            shift();
        }
    }

private:
    unsigned int state[LFSR_LENGTH];
    unsigned int taps[LFSR_LENGTH];
};

int main() {
    unsigned int state[LFSR_LENGTH] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    unsigned int taps[LFSR_LENGTH] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    LFSR lfsr(state, taps);
    unsigned int output[64];
    lfsr.generate(output);
    for (int i = 0; i < 64; i++) {
        std::cout << output[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

