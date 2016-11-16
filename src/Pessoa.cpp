#include "classes.h"
#include <ostream>

using namespace std;

ostream& operator<<(ostream& os,const Pessoa& p) {
    return os << p.mId << ", " << p.mNome << ", " << p.mEmail << endl;
}




Pessoa::Pessoa(string nome,string id,string email) :
    mNome{nome},mId{id},mEmail{email}
{
}

Aluno::Aluno(string nome,string id,string email,int anoInscricao) :
    Pessoa(nome,id,email),mAnoInscricao{anoInscricao}
{
}

Docente::Docente(string nome,string id,string email) :
    Pessoa{nome,id,email}
{
}
