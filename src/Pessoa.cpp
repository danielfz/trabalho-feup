#include "classes.h"
#include <ostream>
#include <iostream>
#include <sstream>

using namespace std;

/*
 * Pessoa
 */

Pessoa::Pessoa(string nome, string email): mId(lastId++)
{
	this->mNome=nome;
	this->mEmail=email;
}

string Pessoa::getNome() const{
	return mNome;
}

int Pessoa::getId() const{
	return mId;
}

string Pessoa::getEmail() const{
	return mEmail;
}

string Pessoa::getInfo() const{
	std::stringstream ss;
	ss << mNome << ", " << mId << ", " << mEmail;
	return ss.str();
}

/*
 * Docente
 */

Docente::Docente(string nome, int id, string email) :
    Pessoa(nome, email)
{
}



/*
 * Aluno
 */

Aluno::Aluno(string nome, int id,string email,int anoInscricao) :
    Pessoa(nome, email)
{
	this->mAnoInscricao=anoInscricao;
	this->mCreditos=75;
}

int Aluno::getAno() const{
	return mAnoInscricao;
}

string Aluno::getEstatuto() const{
	return mEstatuto;
}

int Aluno::getCreditos() const{
	return mCreditos;
}

string Aluno::getInfo() const{
	std::stringstream ss;
	ss << Pessoa::getInfo() << "," << mAnoInscricao << ", " << mEstatuto << ", " << mCreditos << ", " << tutor;
	return ss.str();
}
