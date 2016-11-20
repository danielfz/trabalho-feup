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


Feup::Feup(const std::string fUcs,const std::string fAlunos)
{
    readUcsFile(fUcs);
    listUcs();

    /*
    readPessoasFile(fAlunos);
    listPessoas();

    readIncricoesFile(fich);
    */
}

void Feup::readUcsFile(const std::string fich) {
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

void Feup::readPessoasFile(const std::string fich) {
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


void Feup::readInscricoesFile(std::string fich) {
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

bool Feup::addAluno(Aluno* novo){
	for(unsigned int i=0; i<mAlunos.size(); i++){
		if(novo==mAlunos[i]){
			std::cout << "Este estudante já existe." <<  std::endl;
			return 0;
		}
	}
	mAlunos.push_back(novo);
}

bool Feup::addDocente(Docente* novo){
	for(unsigned int i=0; i<mDocentes.size(); i++){
		if(novo==mDocentes[i])
			std::cout << "Este docente já existe." << std::endl;
			return 0;
	}
}

Pessoa* Feup::getPessoaPorNome(std::string nome){
	for(unsigned int i=0; i<mDocentes.size(); i++){
		if(mDocentes[i]->getNome()==nome) return mDocentes[i];
	}
	for(unsigned int i=0; i<mAlunos.size(); i++){
			if(mAlunos[i]->getNome()==nome) return mAlunos[i];
		}
	return NULL;
}

Aluno* Feup::getAlunoPorNumero(int id){
	for(unsigned int i=0; i<mAlunos.size(); i++){
				if(mAlunos[i]->getId()==id) return mAlunos[i];
			}
	return NULL;
}
