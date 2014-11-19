#include <iostream>
#include <random>
#include <string>

#include <unistd.h>


int ParseCmdLine(int argc, char *argv[]);
std::string GenerateString(int length);

int main(int argc, char *argv[])
{
    int length(ParseCmdLine(argc, argv));
    std::string password(GenerateString(length));
    std::cout << "Your randomly generated password of length " << length << " is:\n" << password << '\n';
    return 0;
}

int ParseCmdLine(int argc, char *argv[])
{
    std::string lvalue;
    int optreturn = 0;
    if (argc < 2)
    {
        std::cerr << "Invalid usage. -l option required.\n";
        exit(1);
    }
    while ((optreturn = getopt(argc, argv, "l:")) != -1)
    {
        switch(optreturn)
        {
            case 'l':
                lvalue += std::string(optarg);
                break;
            default:
                abort();
        }    
    }
    return stoi(lvalue, nullptr, 10);
}

std::string GenerateString(int length)
{
    std::string ciphertext;
    std::random_device rd;
//  std::mt19937 mtengine(rd()); Less secure (PRNG) alternative.
//  std::uniform_int_distribution<int> uintdist(0,61); Less secure (PRNG) alternative.

    for(auto i = 0; i < length; ++i)
    {
//      char randchar = uintdist(mtengine); Less secure (PRNG) alternative.
        char randchar = rd() % 61;
        if (randchar < 10)
        {
            randchar += 48;
        }
        else if (randchar > 9 && randchar < 35)
        {
            randchar += 55;
        }
        else if (randchar > 34)
        {
            randchar += 62;
        }
        ciphertext += (randchar);
    }
    return ciphertext;
}
