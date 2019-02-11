#include <iostream>
#include <fstream>
#include <windows.h>

#include "CONSTS.hpp"
#include "INTERPRETATOR.hpp"

using namespace std;

void initialize_memory()
{
    ifstream fin ("memory.txt");
    int n, start;
    fin >> n >> start;
   double a;

   for (int i = 0; i < memory_count_max; i++)
   {
       MEMORY[i] = 0;
   }

    for (int i = 0; i < registers_count_max; i++)
   {
       REGISTERS[i] = 0;
   }

    for (int i = start; i < n + start; i++)
    {
        fin >> a;
        MEMORY[i] = a;
    }
    fin.close();
}

int main()
{
    initialize_memory();
    interpretator();

    ofstream fout("memory.txt");

    fout << memory_count_max << " " << 0 << "\n";

    for (int i = 0; i < memory_count_max; i++)
    {
        fout << MEMORY[i] << " ";
    }

    return 0;
}
