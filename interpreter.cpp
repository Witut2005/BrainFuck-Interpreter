#include <iostream>

using namespace std;

char code;
uint8_t code_count = 0;

uint8_t *data = new uint8_t[0xffff];
uint8_t* cell_ptr =  &data[0];

uint8_t loop_addr;

void interpreter(char x)
{
    switch (x) 
    {
        case '>':
        cell_ptr++;
        break;

        case '<':
        cell_ptr--;
        break;
        
        case '+':
        (*cell_ptr)++;
        break;
        
        case '-':
        (*cell_ptr)--;
        break;
        
        case '[':
        loop_addr = code_count;
        break;
        
        case ']':
        
            if(*cell_ptr != 0)
            {
                code_count = loop_addr;
            }
        
        break;
        
        case '.':
        cout << (char)*cell_ptr << endl; 
        break;
        
        case ',':
        cin >> *cell_ptr;
        break;


    }


}