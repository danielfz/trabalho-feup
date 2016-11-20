#ifndef FEUP_H
#define FEUP_H

#include <vector>
#include <string>

class Uc;
class Pessoa;
class Aluno;
class Docente;

class Feup
{
    public:
        Feup(std::string fUcs,std::string fAlunos);

        bool addAluno(Aluno*);
        bool addDocente(Docente*);
        bool addUc(Uc*);
        bool addInscricao(Aluno*,Uc*);
        bool addOrientador(Aluno*,Docente*);

        Pessoa* getPessoaPorNome(std::string);
        Aluno* getAlunoPorNumero(std::string);
        Uc* getUcPorNome(std::string);
        Uc* getUcPorCodigo(std::string);

        void listAlunos() const;
        void listUcs() const;

    private:
        std::vector<Uc*> mUcs;
        std::vector<Aluno*> mAlunos;
        std::vector<Docente*> mDocentes;

        void readUcsFile(std::string);
        void readPessoasFile(std::string);
        void readInscricoesFile(std::string);
};

#endif
