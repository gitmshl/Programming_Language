#ifndef CONSTS_H
#define CONSTS_H

const int registers_count_max = 300;
const int memory_count_max = 1000;
const int delta_time = 10; /// ���-�� ����������, �� ������� �� ��������� ��� ������
/// � �������
bool over = false; /// ����� ��������� (���������� ���������)

double REGISTERS[registers_count_max];
double MEMORY[memory_count_max];

#endif // CONSTS_H
