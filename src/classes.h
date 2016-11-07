#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <vector>

/*********************
 * Pessoa
 *********************/

class Pessoa {
    public:
    Pessoa(std::string nome,int mId,std::string email);
    std::string getNome()   const;
    int         getId()     const;
    std::string getEmail()  const;

    protected:    // -------------------
    const std::string mNome;
    const int mId;
    const std::string mEmail;
};

class Docente : public Pessoa {
};

class Aluno : public Pessoa {
    public:

    private:    // -------------------
    int mAno;
    int mDataInscricao;
    std::string mEstatuto;
    Docente mDocente;
};

/*******************************
 * Unidades Curriculares
 *******************************/

class Uc {
    public:
    const std::string mNome;
    const std::string mCodigo;
    const int mAno;
    const bool mPrimeiroSemestre;

    Uc(std::string nome,std::string codigo,int ano,bool primeiroSemestre);
    ~Uc();

    virtual Uc* string2Uc(std::string linha) =0;
    virtual bool addAluno(Aluno* a) =0;
    int getNumAlunos()    const         { return mAlunos.size(); }

    private:  // -------------------

    protected:
    std::vector<Aluno*> mAlunos;
};

class UcObrigatoria : public Uc {
    public:
    UcObrigatoria(std::string,std::string,int,bool);

    virtual Uc* string2Uc(std::string linha) =0;
    bool addAluno(Aluno* a);

    private:    // -------------------
};

class UcOptativa : public Uc {
    public:
    const int mNumVagas;

    UcOptativa(std::string,std::string,int,bool,int vagas);
    bool addAluno(Aluno* a);
    
    private:    // -------------------
    std::vector<std::string> mAreasCientificas;
};

#endif
