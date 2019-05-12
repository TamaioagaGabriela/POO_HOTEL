#ifndef POO3_H_INCLUDED
#define POO3_H_INCLUDED

#include <cstring>
using namespace std;

class Incapere
{
protected: //deerivate si friend
    int numar;
    int capacitate;
    long int status[400]={0};
    int nr_mese_oc;
   int zi;

public:


    friend ostream & operator << (ostream &out, const Incapere &incap);
    friend istream & operator >> (istream &in, Incapere &incap);


    virtual void Set_Nr(int i)                         // alocare dinamica vector de tip int
    {
        numar = i;
    }

    virtual void Set_Capacitate(int j)
    {
        capacitate=j;
    }

    void Set_status(int i, int j)
    {
        status[i]=j;
    }

    long int Get_Status(int i)                                         // returnez dimensiunea vectorului
    {
        return status[i];
    }

    int Get_Capac()                                         // returnez dimensiunea vectorului
    {
        return capacitate;
    }

    int Get_Numar()                                         // returnez dimensiunea vectorului
    {
        return numar;
    }

    virtual void Set_Nr_Mese_Oc(int i){};

    virtual int Get_Nr_Mese_Oc()
    {
        return nr_mese_oc;
    };

    int Get_zi()
    {
        return zi;
    };

    void Set_zi(int i)
    {
        zi=i;
    };

    Incapere & operator = (Incapere *incap)
    {
        Incapere *nou;
        nou->capacitate = incap->capacitate;
        nou->numar = incap->numar;
        for (int i=0; i<=367; i++)
            nou->status[i] = incap->status[i];
        return *nou;
    }

    Incapere()
    {
        capacitate =0;
        nr_mese_oc=0;
      //  for (int i=0; i<=367; i++)
        //    status[i] = 0; // libera
        numar = 0;
        zi=1;
    };

    Incapere(int i): nr_mese_oc(0), numar(0), zi(1)
    {
        capacitate=i;
    }

    virtual ~Incapere(){}
};

class Camera : public Incapere
{
    int numar;
    int capacitate;
    int status[400];
    int zi;
public:

    friend ostream & operator << (ostream &out, const Camera &cam);
    friend istream & operator >> (istream &in, Camera &cam);

    Camera():Incapere(2){};
    virtual ~Camera(){};
};

class Apartament : public Incapere
{
    int numar;
    int capacitate;
    int status[400];
    int zi;
public:

    friend ostream & operator << (ostream &out, const Apartament &ap);
    friend istream & operator >> (istream &in, Apartament &ap);

    Apartament():Incapere(4){};
    virtual ~Apartament(){};
};

class Restaurant : public Incapere
{
    int nr_mese_oc;
    int numar;
    int capacitate;

public:

    friend ostream & operator << (ostream &out, const Restaurant &res);
    friend istream & operator >> (istream &in, Restaurant &res);

    void Set_Nr_Mese_Oc(int i)
    {
        nr_mese_oc=i;
    }

    int Get_Nr_Mese_Oc()
    {
        return nr_mese_oc;
    }

    Restaurant(): Incapere(10)
    {
        capacitate = 10;
        nr_mese_oc = 0;
    };
    virtual ~Restaurant(){};

};

class Sala_Conf : public Incapere
{
    int nr_mese;
    int numar;
    int capacitate;
    int status[367];
    int zi;
public:

    friend ostream & operator << (ostream &out, const Sala_Conf &sala);
    friend istream & operator >> (istream &in, Sala_Conf &sala);

    int Get_Mese()                                         // returnez dimensiunea vectorului
    {
        return nr_mese;
    }
    Sala_Conf():Incapere()
    {
        nr_mese=10;
    };
    virtual ~Sala_Conf(){};
};


class Rezervare
{
    string nume;
    int nr_cam;
    int perioada;
    int prima_zi;
    int mic_dejun;
    int sala_conf;
    int nr_res;

public:

    friend ostream & operator << (ostream &out, const Rezervare &rez);
    friend istream & operator >> (istream &in, Rezervare &rez);

    int Get_nr_cam()                                         // returnez dimensiunea vectorului
    {
        return nr_cam;
    }
    int Get_Perioada()                                         // returnez dimensiunea vectorului
    {
        return perioada;
    }
    int Get_Prima_zi()                                         // returnez dimensiunea vectorului
    {
        return prima_zi;
    }
    int Get_Dejun()                                         // returnez dimensiunea vectorului
    {
        return mic_dejun;
    }
    int Get_Sala_Conf()                                         // returnez dimensiunea vectorului
    {
        return sala_conf;
    }

    int Get_Nr_Res()
    {
        return nr_res;
    }

    string Get_nume()
    {
        return nume;
    }

    void Set_Nr_Res(int i)
    {
        nr_res=i;
    }

    void Set_nume(char *num)                         // alocare dinamica vector de tip int
    {
        nume= num;
    }

    void Set_cam(int cam)                         // alocare dinamica vector de tip int
    {
        nr_cam=cam;
    }

    void Set_per(int per)                         // alocare dinamica vector de tip int
    {
        perioada=per;
    }

    void Set_zi(int zi)                         // alocare dinamica vector de tip int
    {
        prima_zi=zi;
    }

    void Set_dejun(int dejun)                         // alocare dinamica vector de tip int
    {
        mic_dejun=dejun;
    }

    void Set_sala(int sala)                         // alocare dinamica vector de tip int
    {
        sala_conf=sala;
    }

    void Sterge_Rez()
    {
        nume.clear();
        nr_cam=0;
        perioada=0;
        prima_zi=0;
        mic_dejun=0;
        sala_conf=0;
        nr_res=0;
    }

    Rezervare()
    {
        nr_cam=0;
        perioada=0;
        prima_zi=0;
        sala_conf=0;
        mic_dejun=0;
        nr_res=0;

    };

    Rezervare(string q, int cam, int per, int zi, int dejun, int conf, int restaurant)
    {
        nume=q;
       // strcpy(nume, q);
        nr_cam=cam;
        perioada=per;
        prima_zi=zi;
        sala_conf=conf;
        mic_dejun=dejun;
        nr_res=restaurant;
    }

    Rezervare(const Rezervare &rez)
    {
        nume=rez.nume;
    }

    Rezervare & operator = (Rezervare rez)
    {
        Rezervare nou;
        nou.nume = rez.nume;
        //strcpy(nou->nume,rez->nume);
        nou.nr_cam = rez.nr_cam;
        nou.perioada = rez.perioada;
        nou.prima_zi = rez.prima_zi;
        nou.sala_conf = rez.sala_conf;
        nou.mic_dejun = rez.mic_dejun;
        nou.nr_res = rez.nr_res;
        return nou;
    }

    ~Rezervare()
    {
    }

};


#endif // POO3_H_INCLUDED
