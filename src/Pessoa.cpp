#include "classes.h"

std::string Pessoa::getNome() const  { return mNome; }
int         Pessoa::getId() const    { return mId; }
std::string Pessoa::getEmail() const { return mEmail; }

ostream& operator<<(ostream& os,const Pessoa& p) {
    return os << p.getId << ", " 
        << p.getmNome << ", "
        << p.mEmail
        << std::endl;
}

