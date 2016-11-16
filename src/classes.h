#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <vector>

const char sep = ';';

/*********************
 * Pessoa
 *********************/

class Pessoa {
    public:
    const std::string mNome;
    const std::string mId;
    const std::string mEmail;

    protected:
    Pessoa(std::string nome,std::string id,std::string email);
};

class Docente : public Pessoa {
    public:
    Docente(std::string nome,std::string mId,std::string email);
};

class Aluno : public Pessoa {
    public:
    const int mAnoInscricao;
    const std::string mEstatuto;

    Aluno(std::string nome,std::string id,std::string email,int anoInscricao);
};

/*******************************
 * Unidades Curriculares
 *******************************/

class Uc {
    public:
    const std::string mNome;
    const std::string mSigla;
    const std::string mCodigo;
    const int mAno;
    const bool mPrimeiroSemestre;
    const double mCreditos;


    ~Uc();

    static Uc* newUc(std::string line);

    virtual bool addAluno(Aluno* a) =0;
    int getNumAlunos()    const         { return mAlunos.size(); }
    friend std::ostream& operator<<(std::ostream&,Uc const& uc);
    virtual std::string toCsv() const =0;

    // -------------------
    protected:
    virtual std::string toString() const =0;
    std::vector<Aluno*> mAlunos;
    Uc(std::string nome,std::string sigla,std::string codigo,int ano,bool
            primSem,double creditos);
};

class UcObrigatoria : public Uc {
    public:
    UcObrigatoria(std::string,std::string,std::string,int,bool,double);

    bool addAluno(Aluno* a);

    // -------------------
    private:
    std::string toString() const;
    std::string toCsv() const;
};

class UcOptativa : public Uc {
    public:
    const int mNumVagas;

    UcOptativa(std::string,std::string,std::string,int,bool,double,int vagas);
    bool addAluno(Aluno* a);
    
    // -------------------
    private:
    std::vector<std::string> mAreasCientificas;
    std::string toString() const;
    std::string toCsv() const;
};

#endif
