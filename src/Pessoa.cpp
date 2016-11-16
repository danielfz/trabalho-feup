#include "classes.h"
#include <ostream>
#include <iostream>

using namespace std;

/*
 * Pessoa
 */

Pessoa::Pessoa(string nome, int id, string email)
{
	this->mNome=nome;
	this->mId=id;
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

/*
 * Docente
 */

Docente::Docente(string nome, int id, string email) :
    Pessoa(nome,id,email)
{
}

void Docente::mostrarAlunos() const{
	for(unsigned int i=0; i<alunos.size(); i++){
		cout << alunos[i].getNome() << endl;
	}
}

/*
 * Aluno
 */

Aluno::Aluno(string nome, int id,string email,int anoInscricao) :
    Pessoa(nome,id,email)
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

