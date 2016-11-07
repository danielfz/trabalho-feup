#include "classes.h"
#include <string>
#include <vector>

/*
* UC
*/
Uc::Uc(std::string nome,std::string codigo,int ano,bool primeiroSemestre) :
    mNome{nome},
    mCodigo{codigo},
    mAno{ano},
    mPrimeiroSemestre{primeiroSemestre} {
}

/*
 * UC Obrigatória
 */
UcObrigatoria::UcObrigatoria(std::string nome,std::string codigo,int ano,
        bool primeiroSemestre) :
    Uc{nome,codigo,ano,primeiroSemestre} { }

bool UcObrigatoria::addAluno(Aluno* a) {
    mAlunos.push_back(a);
    return true;
}

/*
 * UC Optativa
 */
UcOptativa::UcOptativa(
        std::string nome,std::string codigo,int ano,bool primeiroSemestre,
        int numVagas) :
    Uc{nome,codigo,ano,primeiroSemestre},mNumVagas{numVagas} { }

bool UcOptativa::addAluno(Aluno* a)
{
    if (getNumAlunos() >= mNumVagas) {
        return false;
    }
    mAlunos.push_back(a);
    return true;
}
