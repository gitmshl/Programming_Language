#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <cmath>

void MOVE(int R1, int R2)
{
    REGISTERS[R2] = REGISTERS[R1];
}

void READ(int M1, int R2)
{
    REGISTERS[R2] = MEMORY[M1];
    Sleep(delta_time);
}

void WRITE(int R1, int M2)
{
    MEMORY[M2] = REGISTERS[R1];
    Sleep(delta_time);
}

void ADD(int R1, int R2, int R3)
{
    REGISTERS[R3] = REGISTERS[R1] + REGISTERS[R2];
}

void INC(int R, int b)
{
    REGISTERS[R] = REGISTERS[R] + b;
}

void DEC(int R, int b)
{
     REGISTERS[R] = REGISTERS[R] - b;
}

void SQRT(int R1, int R3)
{
    REGISTERS[R3] = sqrt(REGISTERS[R1]);
}

void POW_NUMBER(int R1, int n, int R3)
{
    int result = REGISTERS[R1];

    for (int i = 0; i < n; i++)
        result *= REGISTERS[R1];

    REGISTERS[R3] = result;
}

void POW(int R1, int R2, int R3)
{
    POW_NUMBER(R1, REGISTERS[R2], R3);
}

void PRIME(int R1, int R3)
{
    if (REGISTERS[R1] == 2) { REGISTERS[R3] = 1; return; }
    if ((REGISTERS[R1] < 2) || ((int) REGISTERS[R1] % 2 == 0)) { REGISTERS[R3] = 0; return;}  /// не простое

    int a = REGISTERS[R1]/2;

    for (int i = 3; i <= a; i += 2)
        if ((int) REGISTERS[R1] % i == 0) {REGISTERS[R3] = 0; return;}

    REGISTERS[R3] = 1;
}

void SET(int a, double b)
{
     REGISTERS[a] = b;
}

void MULT_NUMBER(int R1, double a, int R3)
{
    REGISTERS[R3] = REGISTERS[R1] * a;
}

void MULT(int R1, int R2, int R3)
{
    REGISTERS[R3] = REGISTERS[R1] * REGISTERS[R2];
}

void DIVIDE(int R1, int R2, int R3)
{
    if (REGISTERS[R2])
    {
        REGISTERS[R3] = REGISTERS[R1]/REGISTERS[R2];
    }
    else
    {
        std::cout << "Error. Divide 0\n";
    }
}


void MOD(int R1, int R2, int R3)
{
    if (REGISTERS[R2])
    {
        REGISTERS[R3] = ((int) REGISTERS[R1]) % ((int) REGISTERS[R2]);
    }
    else
    {
        std::cout << "Error. Divide 0\n";
    }
}
#endif // COMMANDS_HPP
