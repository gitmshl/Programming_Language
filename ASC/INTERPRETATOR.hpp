#ifndef INTERPRETATOR_HPP
#define INTERPRETATOR_HPP

#include "COMMANDS.hpp"
#include <cstring>

using namespace std;

void interpretator_sub_programm(char *file_name);

int interpretator_sub_programm(char *F, char *file_name)
{
    bool over_p = false;

    char File_name[40] = "subprograms/";
    strcat(File_name, file_name);
    strcat(File_name, ".txt");

    ifstream code(File_name);
    char s[20];
    strcat(F, ":");
    bool flag = false;

    while (code >> s && !flag)
    {
        if (!strcmp(s, F))
        {
            flag = true;
            break;
        }
    }

    if (!flag)
    {
        over_p = true;
        return 0;
    }

    char command[20];
    while (!over_p && code >> command)
    {
        if (!strcmp(command, "MOVE"))
        {
            int a, b;
            code >> a >> b;
            MOVE(a, b);
        }
        else if (!strcmp(command, "MULT_NUMBER"))
        {
            int R1, a, R3;
            code >> R1 >> a >> R3;
            MULT_NUMBER(R1, a, R3);
        }
        else if (!strcmp(command, "READ"))
        {
            int a, b;
            code >> a >> b;
            READ(a, b);
        }
        else if (!strcmp(command, "WRITE"))
        {
            int a, b;
            code >> a >> b;
            WRITE(a, b);
        }
        else if (!strcmp(command, "ADD"))
        {
            int a, b, c;
            code >> a >> b >> c;
            ADD(a, b, c);
        }
        else if (!strcmp(command, "MULT"))
        {
            int a, b, c;
            code >> a >> b >> c;
            MULT(a, b, c);
        }
        else if (!strcmp(command, "DIVIDE"))
        {
            int a, b, c;
            code >> a >> b >> c;
            DIVIDE(a, b, c);
        }
        else if (!strcmp(command, "MOD"))
        {
            int a, b, c;
            code >> a >> b >> c;
            MOD(a, b, c);
        }
        else if (!strcmp(command, "SQRT"))
        {
            int R1, R2;
            code >> R1 >> R2;
            SQRT(R1, R2);
        }
        else if (!strcmp(command, "POW"))
        {
            int a, b, R;
            code >> a >> b >> R;
            POW(a, b, R);
        }
        else if (!strcmp(command, "POW_NUMBER"))
        {
            int R, a, R1;
            code >> R >> a >> R1;
            POW_NUMBER(R, a, R1);
        }
        else if (!strcmp(command, "PRIME"))
        {
            int R1, R2;
            code >> R1 >> R2;
            PRIME(R1, R2);
        }
        else if (!strcmp(command, "JUMP"))
        {
            char F[20];
            code >> F;
            code.close();
            if (!interpretator_sub_programm(F, file_name));
        }
         else if (!strcmp(command, "SHOW"))
        {
            int a;
            code >> a;
            cout << REGISTERS[a];
        }
        else if (!strcmp(command, "SHOWLN"))
        {
            int a;
            code >> a;
            cout << REGISTERS[a] << "\n";
        }
        else if (!strcmp(command, "SHOWS"))
        {
            int a;
            code >> a;
            cout << REGISTERS[a] << " ";
        }
        else if (!strcmp(command, "INC"))
        {
            int R, b;
            code >> R >> b;
            INC(R, b);
        }
        else if (!strcmp(command, "DEC"))
        {
            int R, b;
            code >> R >> b;
            DEC(R, b);
        }
        else if (!strcmp(command, "SET"))
        {
            int a;
            double b;
            code >> a >> b;
            SET(a, b);
        }
        else if (!strcmp(command, "IF"))
        {
            char iff[10];
            code >> iff;
            if (!strcmp(iff, "MORE"))
            {
                int a, b;
                code >> a >> b;
                char T[20];
                code >> T;
                if (REGISTERS[a] > REGISTERS[b])
                {
                    code.close();
                    interpretator_sub_programm(T, file_name);
                }
            }
            else if (!strcmp(iff, "EQU"))
            {
                int a, b;
                code >> a >> b;
                char T[20];
                code >> T;

                if (REGISTERS[a] == REGISTERS[b])
                {
                    code.close();
                    interpretator_sub_programm(T, file_name);
                }
            }
            else if (!strcmp(iff, "MORE_NUMBER"))
            {
                int R, a;
                code >> R >> a;
                char T[20];
                code >> T;
                if (REGISTERS[R] > a)
                {
                    code.close();
                    interpretator_sub_programm(T, file_name);
                }
            }
            else if (!strcmp(iff, "EQU_NUMBER"))
            {
                int R, a;
                code >> R >> a;
                char T[20];
                code >> T;
                if (REGISTERS[R] == a)
                {
                    code.close();
                    interpretator_sub_programm(T, file_name);
                }
            }
        }
        else if (!strcmp(command, "ELSE"))
        {
            char T[20];
            code >> T;
            if (strcmp(T, "0"))
            {
                code.close();
                interpretator_sub_programm(T, file_name);
            }
        }
        else if (!strcmp(command, "subprogram"))
        {
            char T[20];
            code >> T;
            interpretator_sub_programm(T);
        }
    }
    over_p = true;
    return 0;
}

void interpretator_sub_programm(char *file_name)
{
    bool over_p = false;

    char File_name[40] = "subprograms/";
    strcat(File_name, file_name);
    strcat(File_name, ".txt");

    ifstream code(File_name);
    char command[20];

    while (!over_p && code >> command)
    {
        if (!strcmp(command, "MOVE"))
        {
            int a, b;
            code >> a >> b;
            MOVE(a, b);
        }
        else if (!strcmp(command, "MULT_NUMBER"))
        {
            int R1, a, R3;
            code >> R1 >> a >> R3;
            MULT_NUMBER(R1, a, R3);
        }
        else if (!strcmp(command, "READ"))
        {
            int a, b;
            code >> a >> b;
            READ(a, b);
        }
        else if (!strcmp(command, "WRITE"))
        {
            int a, b;
            code >> a >> b;
            WRITE(a, b);
        }
        else if (!strcmp(command, "ADD"))
        {
            int a, b, c;
            code >> a >> b >> c;
            ADD(a, b, c);
        }
        else if (!strcmp(command, "MULT"))
        {
            int a, b, c;
            code >> a >> b >> c;
            MULT(a, b, c);
        }
         else if (!strcmp(command, "DIVIDE"))
        {
            int a, b, c;
            code >> a >> b >> c;
            DIVIDE(a, b, c);
        }
        else if (!strcmp(command, "MOD"))
        {
            int a, b, c;
            code >> a >> b >> c;
            MOD(a, b, c);
        }
        else if (!strcmp(command, "SQRT"))
        {
            int R1, R2;
            code >> R1 >> R2;
            SQRT(R1, R2);
        }
        else if (!strcmp(command, "POW"))
        {
            int a, b, R;
            code >> a >> b >> R;
            POW(a, b, R);
        }
        else if (!strcmp(command, "POW_NUMBER"))
        {
            int R, a, R1;
            code >> R >> a >> R1;
            POW_NUMBER(R, a, R1);
        }
        else if (!strcmp(command, "PRIME"))
        {
            int R1, R2;
            code >> R1 >> R2;
            PRIME(R1, R2);
        }
        else if (!strcmp(command, "JUMP"))
        {
            char F[20];
            code >> F;
            code.close();
            if (!interpretator_sub_programm(F, file_name)) return;
        }
         else if (!strcmp(command, "SHOW"))
        {
            int a;
            code >> a;
            cout << REGISTERS[a];
        }
        else if (!strcmp(command, "SHOWLN"))
        {
            int a;
            code >> a;
            cout << REGISTERS[a] << "\n";
        }
        else if (!strcmp(command, "SHOWS"))
        {
            int a;
            code >> a;
            cout << REGISTERS[a] << " ";
        }
        else if (!strcmp(command, "INC"))
        {
            int R, b;
            code >> R >> b;
            INC(R, b);
        }
        else if (!strcmp(command, "DEC"))
        {
            int R, b;
            code >> R >> b;
            DEC(R, b);
        }
        else if (!strcmp(command, "SET"))
        {
            int a;
            double b;
            code >> a >> b;
            SET(a, b);
        }
         else if (!strcmp(command, "IF"))
        {
            char iff[10];
            code >> iff;
            if (!strcmp(iff, "MORE"))
            {
                int a, b;
                code >> a >> b;
                char T[20];
                code >> T;

                if (REGISTERS[a] > REGISTERS[b])
                {
                    code.close();
                    interpretator_sub_programm(T, file_name);
                }
            }
            else if (!strcmp(iff, "EQU"))
            {
                int a, b;
                code >> a >> b;
                char T[20];
                code >> T;

                if (REGISTERS[a] == REGISTERS[b])
                {
                    code.close();
                    interpretator_sub_programm(T, file_name);
                }
            }
            else if (!strcmp(iff, "MORE_NUMBER"))
            {
                int R, a;
                code >> R >> a;
                char T[20];
                code >> T;
                if (REGISTERS[R] > a)
                {
                    code.close();
                    interpretator_sub_programm(T, file_name);
                }
            }
            else if (!strcmp(iff, "EQU_NUMBER"))
            {
                int R, a;
                code >> R >> a;
                char T[20];
                code >> T;
                if (REGISTERS[R] == a)
                {
                    code.close();
                    interpretator_sub_programm(T, file_name);
                }
            }
        }
        else if (!strcmp(command, "ELSE"))
        {
            char T[20];
            code >> T;
            if (strcmp(T, "0"))
            {
                code.close();
                interpretator_sub_programm(T, file_name);
            }
        }
        else if (!strcmp(command, "subprogram"))
        {
            char T[20];
            code >> T;
            interpretator_sub_programm(T);
        }
    }

}

/// Сделан jump, ищем первое вхождение слова F и оттуда начинаем программу
void interpretator(char *F)
{
    ifstream code("subprograms/code.txt");
    char s[20];
    strcat(F, ":");
    bool flag = false;

    while (code >> s && !flag)
    {
        if (!strcmp(s, F))
        {
            flag = true;
            break;
        }
    }

    if (!flag)
    {
        over = true;
        return;
    }

    char command[20];
    while (!over && code >> command)
    {
        if (!strcmp(command, "MOVE"))
        {
            int a, b;
            code >> a >> b;
            MOVE(a, b);
        }
        else if (!strcmp(command, "MULT_NUMBER"))
        {
            int R1, a, R3;
            code >> R1 >> a >> R3;
            MULT_NUMBER(R1, a, R3);
        }
        else if (!strcmp(command, "READ"))
        {
            int a, b;
            code >> a >> b;
            READ(a, b);
        }
        else if (!strcmp(command, "WRITE"))
        {
            int a, b;
            code >> a >> b;
            WRITE(a, b);
        }
        else if (!strcmp(command, "ADD"))
        {
            int a, b, c;
            code >> a >> b >> c;
            ADD(a, b, c);
        }
        else if (!strcmp(command, "MULT"))
        {
            int a, b, c;
            code >> a >> b >> c;
            MULT(a, b, c);
        }
         else if (!strcmp(command, "DIVIDE"))
        {
            int a, b, c;
            code >> a >> b >> c;
            DIVIDE(a, b, c);
        }
        else if (!strcmp(command, "MOD"))
        {
            int a, b, c;
            code >> a >> b >> c;
            MOD(a, b, c);
        }
        else if (!strcmp(command, "SQRT"))
        {
            int R1, R2;
            code >> R1 >> R2;
            SQRT(R1, R2);
        }
        else if (!strcmp(command, "POW"))
        {
            int a, b, R;
            code >> a >> b >> R;
            POW(a, b, R);
        }
        else if (!strcmp(command, "POW_NUMBER"))
        {
            int R, a, R1;
            code >> R >> a >> R1;
            POW_NUMBER(R, a, R1);
        }
        else if (!strcmp(command, "PRIME"))
        {
            int R1, R2;
            code >> R1 >> R2;
            PRIME(R1, R2);
        }
        else if (!strcmp(command, "JUMP"))
        {
            char F[20];
            code >> F;
            code.close();
            interpretator(F);
        }
         else if (!strcmp(command, "SHOW"))
        {
            int a;
            code >> a;
            cout << REGISTERS[a];
        }
        else if (!strcmp(command, "SHOWLN"))
        {
            int a;
            code >> a;
            cout << REGISTERS[a] << "\n";
        }
        else if (!strcmp(command, "SHOWS"))
        {
            int a;
            code >> a;
            cout << REGISTERS[a] << " ";
        }
        else if (!strcmp(command, "INC"))
        {
            int R, b;
            code >> R >> b;
            INC(R, b);
        }
        else if (!strcmp(command, "DEC"))
        {
            int R, b;
            code >> R >> b;
            DEC(R, b);
        }
        else if (!strcmp(command, "SET"))
        {
            int a;
            double b;
            code >> a >> b;
            SET(a, b);
        }
        else if (!strcmp(command, "IF"))
        {
            char iff[10];
            code >> iff;
            if (!strcmp(iff, "MORE"))
            {
                int a, b;
                code >> a >> b;
                char T[20];
                code >> T;
                if (REGISTERS[a] > REGISTERS[b])
                {
                    code.close();
                    interpretator(T);
                }
            }
            else if (!strcmp(iff, "EQU"))
            {
                int a, b;
                code >> a >> b;
                char T[20];
                code >> T;

                if (REGISTERS[a] == REGISTERS[b])
                {
                    code.close();
                    interpretator(T);
                }
            }
            else if (!strcmp(iff, "MORE_NUMBER"))
            {
                int R, a;
                code >> R >> a;
                char T[20];
                code >> T;
                if (REGISTERS[R] > a)
                {
                    code.close();
                    interpretator(T);
                }
            }
            else if (!strcmp(iff, "EQU_NUMBER"))
            {
                int R, a;
                code >> R >> a;
                char T[20];
                code >> T;
                if (REGISTERS[R] == a)
                {
                    code.close();
                    interpretator(T);
                }
            }
        }
        else if (!strcmp(command, "ELSE"))
        {
            char T[20];
            code >> T;
            if (strcmp(T, "0"))
            {
                code.close();
                interpretator(T);
            }
        }
         else if (!strcmp(command, "subprogram"))
        {
            char T[20];
            code >> T;
            interpretator_sub_programm(T);
        }
    }

    over = true;
}

/// начинаем с начала файла
void interpretator()
{
    ifstream code("subprograms/code.txt");
    char command[20];

    while (!over && code >> command)
    {
        if (!strcmp(command, "MOVE"))
        {
            int a, b;
            code >> a >> b;
            MOVE(a, b);
        }
        else if (!strcmp(command, "MULT_NUMBER"))
        {
            int R1, a, R3;
            code >> R1 >> a >> R3;
            MULT_NUMBER(R1, a, R3);
        }
        else if (!strcmp(command, "READ"))
        {
            int a, b;
            code >> a >> b;
            READ(a, b);
        }
        else if (!strcmp(command, "WRITE"))
        {
            int a, b;
            code >> a >> b;
            WRITE(a, b);
        }
        else if (!strcmp(command, "ADD"))
        {
            int a, b, c;
            code >> a >> b >> c;
            ADD(a, b, c);
        }
        else if (!strcmp(command, "MULT"))
        {
            int a, b, c;
            code >> a >> b >> c;
            MULT(a, b, c);
        }
         else if (!strcmp(command, "DIVIDE"))
        {
            int a, b, c;
            code >> a >> b >> c;
            DIVIDE(a, b, c);
        }
        else if (!strcmp(command, "MOD"))
        {
            int a, b, c;
            code >> a >> b >> c;
            MOD(a, b, c);
        }
        else if (!strcmp(command, "SQRT"))
        {
            int R1, R2;
            code >> R1 >> R2;
            SQRT(R1, R2);
        }
        else if (!strcmp(command, "POW"))
        {
            int a, b, R;
            code >> a >> b >> R;
            POW(a, b, R);
        }
        else if (!strcmp(command, "POW_NUMBER"))
        {
            int R, a, R1;
            code >> R >> a >> R1;
            POW_NUMBER(R, a, R1);
        }
        else if (!strcmp(command, "PRIME"))
        {
            int R1, R2;
            code >> R1 >> R2;
            PRIME(R1, R2);
        }
        else if (!strcmp(command, "JUMP"))
        {
            char F[20];
            code >> F;
            code.close();
            interpretator(F);
        }
         else if (!strcmp(command, "SHOW"))
        {
            int a;
            code >> a;
            cout << REGISTERS[a];
        }
        else if (!strcmp(command, "SHOWLN"))
        {
            int a;
            code >> a;
            cout << REGISTERS[a] << "\n";
        }
        else if (!strcmp(command, "SHOWS"))
        {
            int a;
            code >> a;
            cout << REGISTERS[a] << " ";
        }
        else if (!strcmp(command, "INC"))
        {
            int R, b;
            code >> R >> b;
            INC(R, b);
        }
        else if (!strcmp(command, "DEC"))
        {
            int R, b;
            code >> R >> b;
            DEC(R, b);
        }
        else if (!strcmp(command, "SET"))
        {
            int a;
            double b;
            code >> a >> b;
            SET(a, b);
        }
         else if (!strcmp(command, "IF"))
        {
            char iff[10];
            code >> iff;
            if (!strcmp(iff, "MORE"))
            {
                int a, b;
                code >> a >> b;
                char T[20];
                code >> T;

                if (REGISTERS[a] > REGISTERS[b])
                {
                    code.close();
                    interpretator(T);
                }
            }
            else if (!strcmp(iff, "EQU"))
            {
                int a, b;
                code >> a >> b;
                char T[20];
                code >> T;

                if (REGISTERS[a] == REGISTERS[b])
                {
                    code.close();
                    interpretator(T);
                }
            }
            else if (!strcmp(iff, "MORE_NUMBER"))
            {
                int R, a;
                code >> R >> a;
                char T[20];
                code >> T;
                if (REGISTERS[R] > a)
                {
                    code.close();
                    interpretator(T);
                }
            }
            else if (!strcmp(iff, "EQU_NUMBER"))
            {
                int R, a;
                code >> R >> a;
                char T[20];
                code >> T;
                if (REGISTERS[R] == a)
                {
                    code.close();
                    interpretator(T);
                }
            }
        }
        else if (!strcmp(command, "ELSE"))
        {
            char T[20];
            code >> T;
            if (strcmp(T, "0"))
            {
                code.close();
                interpretator(T);
            }
        }
        else if (!strcmp(command, "subprogram"))
        {
            char T[20];
            code >> T;
            interpretator_sub_programm(T);
        }
    }
}

#endif // INTERPRETATOR_HPP
