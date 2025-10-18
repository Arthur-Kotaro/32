#include <iostream>
#include <string>

//#define DEBUG

int main()
{
#ifdef DEBUG
    std::cout<< "DEBUG: ...\n";
#endif
        return 0;
}
