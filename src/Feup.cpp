#include "Feup.h"
#include "classes.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <regex>

void runAllTests(int argc, char const *argv[]);

int main(int argc, char const *argv[]){
    std::string progName{argv[0]};
    std::regex re("Test$");
    std::smatch match;
    if (std::regex_search(progName,match,re)) {
        std::cout << "Running tests:\n";
        runAllTests(argc,argv);
    }
    return 0;
}

/*******************************
 * FEUP
 *******************************/

static std::ifstream& getlineSkipEmptyLines(std::ifstream& fs,std::string& l) {
    static std::smatch match;
    static std::regex blank("^[ ]*$");
    while (std::getline(fs,l) && (std::regex_search(l,blank) || l[0]=='#'))
        ;
    return fs;
}


Feup::Feup(std::string fich)
{
    readUcFile(fich);
    listUcs();

    /*
    readPessoasFile(fich);
    listPessoas();

    readIncricoesFile(fich);
    */
}

void Feup::readUcFile(std::string fich) {
    Uc::setSeparator(Feup::SEP);

    std::ifstream fs;
    fs.open(fich);
    std::cout << "feup: opening " << fich << std::endl;
    if (!fs.is_open()) {
        std::cout << "error opening file\n";
        return;
    }

    std::string line;
    while (getlineSkipEmptyLines(fs,line)) {
        Uc* ucp = Uc::newUc(line);
        addUc(ucp);
    }
    fs.close();
}

void Feup::readPessoasFile(std::string fich) {
}

void Feup::readInscricoesFile(std::string fich) {
}


bool Feup::addUc(Uc* uc) {
    mUcs.push_back(uc);
    return true;
}


void Feup::listUcs() const {
    std::cout << "Unidades curriculares:\n";
    for (Uc* uc : mUcs) {
        std::cout << (*uc) << std::endl;
    }
}
