#include "Feup.h"
#include "classes.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <regex>

void runAllTests(int argc, char const *argv[]);

const std::string PROG_TEST_NAME = "FeupTest";

Feup::Feup(std::string fich)
{
    std::cout << "construtor" << std::endl;
    std::ifstream fs;
    fs.open(fich);
    std::string linha;
    std::getline(fs,linha);
    std::cout << linha;
    fs.close();
}

int main(int argc, char const *argv[]){
    std::cout << argv[0];
    std::string pat = "*."+PROG_TEST_NAME+"$";
    if (std::regex_match(argv[0],std::regex(pat))) {
        runAllTests(argc,argv);
    }
    return 0;
}
