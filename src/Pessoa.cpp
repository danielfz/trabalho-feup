#include "classes.h"
#include <ostream>

using namespace std;

/*
 * Pessoa
 */

Pessoa::Pessoa(string nome,string id,string email) :
    mNome{nome},mId{id},mEmail{email}
{
}

string Pessoa:getNome() const{
	return mNome;
}

string Pessoa:getId() const{
	return mId;
}

string Pessoa:getEmail() const{
	return mEmail;
}

/*
 * Docente
 */

Docente::Docente(string nome,string id,string email) :
    Pessoa{nome,id,email}
{
}

void mostrarAlunos(){
	for(unsigned int i=0; i<alunos.size(); i++){
		cout << alunos[i].getNome() << endl;
	}
}

/*
 * Aluno
 */

Aluno::Aluno(string nome,string id,string email,int anoInscricao) :
    Pessoa(nome,id,email),mAnoInscricao{anoInscricao}
{
}

int Aluno::getAno() const{
	return mAno;
}

string Aluno::getEstatuto() const{
	return mEstatuto;
}

int Aluno::getCreditos() const{
	return mCreditos;
}
