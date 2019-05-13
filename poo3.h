#ifndef POO3_H_INCLUDED
#define POO3_H_INCLUDED

#include <cstring>
using namespace std;

class Incapere
{
protected:
    int numar;
    int capacitate;
    long int status[400] = {0};
    int nr_mese_oc;
    int zi;

public:

    friend ostream & operator << (ostream &out, const Incapere &incap);
    friend istream & operator >> (istream &in, Incapere &incap);

    virtual void Set_Nr(int i)
    {
        numar = i;
    }

    virtual void Set_Capacitate(int j)
    {
        capacitate = j;
    }

    void Set_Status(int i, int j)
    {
        status[i] = j;
    }

    long int Get_Status(int i)
    {
        return status[i];
    }

    int Get_Capac()
    {
        return capacitate;
    }

    int Get_Numar()                   // numarul camerei/ap
    {
        return numar;
    }

    virtual void Set_Nr_Mese_Oc(int i)
    {
        nr_mese_oc = i;               // setez nr de mese ocupate din restaurant
    };

    virtual int Get_Nr_Mese_Oc()
    {
        return nr_mese_oc;
    };

    int Get_Zi()
    {
        return zi;
    };

    void Set_Zi(int i)
    {
        zi = i;                       // setez prima zi din an in care e libera o camera
    };

    Incapere & operator = (Incapere *incap)         // supraincarcarea op =
    {
        Incapere *nou;
        nou -> capacitate = incap -> capacitate;
        nou -> numar = incap -> numar;
        for (int i = 0; i <= 367; i++)
            nou -> status[i] = incap -> status[i];
        return *nou;
    };

    Incapere()
    {
        capacitate = 0;
        nr_mese_oc = 0;
        numar = 0;
        zi = 1;
    };

    Incapere(int i): nr_mese_oc(0), zi(1), numar(0)
    {
        capacitate = i;
    };

    virtual ~Incapere(){};
};


class Camera : public Incapere
{
    int numar;
    int capacitate;
    int status[400];
    int zi;
public:

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

    Apartament():Incapere(4) {};
    virtual ~Apartament() {};
};


class Restaurant : public Incapere
{
    int nr_mese_oc;
    int numar;
    int capacitate;

public:

    Restaurant(): Incapere(10){};
    virtual ~Restaurant() {};

};

class Sala_Conf : public Incapere
{
    int numar;
    int capacitate;
    int status[367];
    int zi;
public:

    Sala_Conf():Incapere(20){};
    virtual ~Sala_Conf() {};
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

    int Get_Nr_Cam()
    {
        return nr_cam;
    };
    int Get_Perioada()
    {
        return perioada;
    };
    int Get_Prima_Zi()
    {
        return prima_zi;
    };
    int Get_Dejun()
    {
        return mic_dejun;
    };
    int Get_Sala_Conf()
    {
        return sala_conf;
    };

    int Get_Nr_Res()
    {
        return nr_res;
    };

    string Get_Nume()
    {
        return nume;
    };

    void Set_Nr_Res(int i)
    {
        nr_res = i;                               // setez  nr mesei de la restaurant
    };

    void Set_Nume(char *num)
    {
        nume = num;
    };

    void Set_Cam(int cam)
    {
        nr_cam = cam;
    };

    void Set_Per(int per)                         // setez perioada in care este facuta rezervarea
    {
        perioada = per;
    };

    void Set_Zi(int zi)                           // setez prima zi in care poate fi cazat la hotel
    {
        prima_zi = zi;
    };

    void Set_Dejun(int dejun)
    {
        mic_dejun = dejun;
    };

    void Set_Sala(int sala)
    {
        sala_conf = sala;
    };

    void Sterge_Rez()                             // functie de anulare a unei rezervari
    {
        nume.clear();
        nr_cam = 0;
        perioada = 0;
        prima_zi = 0;
        mic_dejun = 0;
        sala_conf = 0;
        nr_res = 0;
    };

    Rezervare()
    {
        nr_cam = 0;
        perioada = 0;
        prima_zi = 0;
        sala_conf = 0;
        mic_dejun = 0;
        nr_res = 0;
    };

    Rezervare(string q, int cam, int per, int zi, int dejun, int conf, int restaurant)
    {
        nume = q;
        nr_cam = cam;
        perioada = per;
        prima_zi = zi;
        sala_conf = conf;                           // constructorul cu parametrii
        mic_dejun = dejun;
        nr_res = restaurant;
    };

    Rezervare(const Rezervare &rez)
    {
        nume = rez.nume;
    };

    Rezervare & operator = (Rezervare &rez)         // supraincarcarea op =
    {
        Rezervare nou;
        nou.nume = rez.nume;
        nou.nr_cam = rez.nr_cam;
        nou.perioada = rez.perioada;
        nou.prima_zi = rez.prima_zi;
        nou.sala_conf = rez.sala_conf;
        nou.mic_dejun = rez.mic_dejun;
        nou.nr_res = rez.nr_res;
        return nou;
    };

    ~Rezervare() {};

};


#endif // POO3_H_INCLUDED
