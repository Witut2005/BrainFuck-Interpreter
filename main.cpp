#include <iostream>
#include <fstream>
#include <cstdlib>
#include <inttypes.h>

#include "interpret.cpp"
#include "input.cpp"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << "Usage: " << argv[0] << " filename" << endl;
        exit(1);
    }

    fstream fs;

    fs.open(argv[1],fstream::in);
    if(!fs.good())
    {
        cout << "File error: " << argv[1] << endl;
    }

  

    while(true)
    {
        
        fs.seekg(code_count,fs.beg);
        fs.read(&code,1);

        if(fs.eof())
        {
            exit(0);
        }

        interpreter(code);

        code_count++;


    }


}