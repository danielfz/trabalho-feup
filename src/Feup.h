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
    private:
        std::vector<Uc*> mUcs;

    public:
        Feup(std::string fichDados);

        bool addAluno(Aluno);
        bool addDocente(Docente);

        void listAlunos();
};

#endif
