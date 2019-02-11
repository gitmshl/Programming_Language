#ifndef CONSTS_H
#define CONSTS_H

const int registers_count_max = 300;
const int memory_count_max = 1000;
const int delta_time = 10; /// кол-во милисекунд, на которые мы застываем при работе
/// с памятью
bool over = false; /// конец программы (выполнения программы)

double REGISTERS[registers_count_max];
double MEMORY[memory_count_max];

#endif // CONSTS_H
