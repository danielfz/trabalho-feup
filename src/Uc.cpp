#include "classes.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

char Uc::sep;

/*
* UC
*/
Uc::Uc(std::string nome,std::string sigla,std::string codigo,int ano,bool
        pSemestre,double cred) :
    mNome{nome},
    mSigla{sigla},
    mCodigo{codigo},
    mAno{ano},
    mPrimeiroSemestre{pSemestre} ,
    mCreditos{cred}
{
}

Uc* Uc::newUc(std::string line) {

    std::stringstream ss(line);

    std::string obrigatoria_str;
    std::getline(ss,obrigatoria_str,sep);
    bool uc_obrigatoria = obrigatoria_str == "OB";

    std::string ano_str;
    std::getline(ss,ano_str,sep);
    int uc_ano = std::stoi(ano_str);

    std::string semestre_str;
    std::getline(ss,semestre_str,sep);
    bool uc_sem = semestre_str == "SEG";

    std::string uc_codigo;
    std::getline(ss,uc_codigo,sep);

    std::string uc_sigla;
    std::getline(ss,uc_sigla,sep);

    std::string uc_nome;
    std::getline(ss,uc_nome,sep);

    std::string creditos_str;
    std::getline(ss,creditos_str,sep);
    double uc_cred = std::stod(creditos_str);

    Uc* uc = nullptr;
    if (uc_obrigatoria) {
        uc = new UcObrigatoria(uc_nome,uc_sigla,uc_codigo,uc_ano,uc_sem,uc_cred);
    } else {
        std::string vagas_str;
        std::getline(ss,vagas_str,sep);
        int uc_vagas = std::stoi(vagas_str);
        uc = new
            UcOptativa(uc_nome,uc_sigla,uc_codigo,uc_ano,uc_sem,uc_cred,uc_vagas);
    }
    return uc;
}

std::ostream& operator<<(std::ostream& os,Uc const& uc) {
    os << uc.toString();
    return os;
}

/*
 * UC Obrigatória
 */
UcObrigatoria::UcObrigatoria(std::string nome,std::string sigla,std::string
        codigo,int ano, bool primeiroSemestre,double creditos) :
    Uc{nome,sigla,codigo,ano,primeiroSemestre,creditos} { }

bool UcObrigatoria::addAluno(Aluno* a) {
    mAlunos.push_back(a);
    return true;
}

std::string UcObrigatoria::toString() const {
    std::stringstream ss;
    ss << mAno << "o ano; ";
    ss << (mPrimeiroSemestre ? "PRI" : "SEG") << ";";
    ss.width(7); ss << mCodigo << "\t" << mNome;
    return ss.str();
}

std::string UcObrigatoria::toCsv() const {
    std::stringstream ss;
    ss << "OB," << mAno << ",";
    ss << (mPrimeiroSemestre ? "PRI" : "SEG") << ",";
    ss << mCodigo << "," << mNome << ",";
    return ss.str();
}

/*
 * UC Optativa
 */
UcOptativa::UcOptativa(
        std::string nome,std::string sigla,std::string codigo,int ano,bool
        primeiroSemestre, double creditos,int numVagas) :
    Uc{nome,sigla,codigo,ano,primeiroSemestre,creditos},mNumVagas{numVagas} { }

bool UcOptativa::addAluno(Aluno* a)
{
    if (getNumAlunos() >= mNumVagas) {
        return false;
    }
    mAlunos.push_back(a);
    return true;
}

std::string UcOptativa::toString() const {
    std::stringstream ss;
    ss << mAno << "o ano; ";
    ss << (mPrimeiroSemestre ? "PRI" : "SEG") << ";";
    ss.width(7); ss << mCodigo << "\t" << mNome;
    return ss.str();
}

std::string UcOptativa::toCsv() const {
    std::stringstream ss;
    ss << "OP";
    ss << (mPrimeiroSemestre ? "PRI" : "SEG") << ",";
    ss << mCodigo << "," << mNome << ",";
    return ss.str();
}
