#include "classes.h"
#include <ostream>

std::ostream& operator<<(std::ostream& os,const Pessoa& p) {
    return os << p.mId << ", " << p.mNome << ", " << p.mEmail << std::endl;
}


Pessoa::Pessoa(std::string nome,std::string id,std::string email) :
    mNome{nome},mId{id},mEmail{email}
{
}

Aluno::Aluno(std::string nome,std::string id,std::string email,int anoInscricao) :
    Pessoa(nome,id,email),mAnoInscricao{anoInscricao}
{
}

Docente::Docente(std::string nome,std::string id,std::string email) :
    Pessoa{nome,id,email}
{
}
