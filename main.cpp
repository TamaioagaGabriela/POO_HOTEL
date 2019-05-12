#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include "poo3.h"

using namespace std;

istream & operator >> (istream &in,  Rezervare &rez)
{
    in >> rez.nume >> rez.nr_cam >> rez.perioada >>rez.prima_zi>> rez.mic_dejun>>rez.sala_conf >>rez.nr_res;
    return in;
    return in;
}

ostream & operator << (ostream &out, const Rezervare &rez)
{
    out << "Rezervarea este facuta pe numele: "<< rez.nume <<endl;
    out << "Nr camera: "<<rez.nr_cam <<endl;
    out<< "Perioada: "<<rez.perioada<<endl;
    out <<"Prima zi: "<<rez.prima_zi<<endl;
    out<<"Mic dejun: "<< rez.mic_dejun<<endl;
    out<<"Sala conf: "<<rez.sala_conf <<endl;
    out<<"Nr masa restaurant: "<<rez.nr_res<<endl;
    out << endl;
    return out;
}

/*
istream & operator >> (istream &in,  Incapere &incap)
{
    in >> incap->numar >> incap->capacitate >> incap->status;
    return in;
}

ostream & operator << (ostream &out, const Incapere &incap)
{
    out << incap->numar << incap->capacitate << incap->status;
    out << endl;
    return out;
}

istream & operator >> ( istream &in, Apartament &ap )
{
    in >> ap->numar >> ap->capacitate >> ap->status;
    return in;
}

ostream & operator << (ostream &out, const Apartament &ap)
{
    out << ap->numar << ap->capacitate << ap->status;
    out << endl;
    return out;
}

istream & operator >> ( istream &in, Camera &cam )
{
    in >> cam->numar >> cam->capacitate >> cam->status;
    return in;
}

ostream & operator << (ostream &out, const Camera &cam)
{
    out << cam->numar << cam->capacitate << cam->status;
    out << endl;
    return out;
}

istream & operator >> ( istream &in, Restaurant &res )
{
    in >> res->numar >> res->capacitate >> res->status >> res->nr_mese_oc;
    return in;
}

ostream & operator << (ostream &out, const Restaurant &res)
{
    out << res->numar << res->capacitate << res->status << res->nr_mese_oc;
    out << endl;
    return out;
}

istream & operator >> ( istream &in, Sala_Conf &sala )
{
    in >> sala->numar >> sala->capacitate >> sala->status >> sala->nr_mese >> sala->proiector >> sala->scena;
    return in;
}

ostream & operator << (ostream &out, const Sala_Conf &sala)
{
    out << sala->numar << sala->capacitate << sala->status << sala->nr_mese << sala->proiector << sala->scena;
    out << endl;
    return out;
}
*/
int main()
{
    // 15 7  23 2 3 6
   // int v[200]= {0};
    Rezervare *rez[200];
    int nr_cam,nr_ap, nr_mese, nr_sali_proiector, nr_sali_scena, nr_sala_mese, nr_rezervari;
    cin >> nr_cam >> nr_ap >> nr_mese >> nr_sali_proiector >> nr_sali_scena >> nr_sala_mese;

    Incapere *ptr[200];

    for(int i=1; i<=15; i++)
    {
        ptr[i] = new Camera;
        ptr[i]->Set_Nr(i);
    }

    for (int i=16; i<=22; i++)
    {
        ptr[i] = new Apartament;
        ptr[i]->Set_Nr(i);
    }

    int j=23;
    ptr[j] = new Restaurant;

    for (int i=24; i<=28; i++)
    {
        ptr[i] = new Sala_Conf;
        ptr[i]->Set_Nr(i);
        cout <<endl << "sala : "<< ptr[i]->Get_Numar()<<endl;
    }

    int ok=1;
    int k=1;

    while(ok)
    {

        string nume;
        int r, rr, rrr, rrrr;
        int nr_cam, perioada, prima_zi, nr_res, sala_conf, mic_dejun;

        cout<<"Numele dvs este: "<<endl;
        cin.ignore();
        getline(cin, nume);
        cout<<nume<<endl;

        cout<<"Cate zile doriti sa stati? (1-10 zile): ";
        cin>>perioada;

        cout<<"Ce doriti sa rezervati? (1-camera, 2-apartament): ";
        cin>>r;
        if (r==1)
        {
            int minim, nr_camera=1, total,zi;
            minim=ptr[1]->Get_zi();
            for (int i=2; i<=15; i++)
            {
                zi=ptr[i]->Get_zi();
                if (zi<minim)
                {
                    minim=zi;
                    nr_camera=i;
                }
            }
            total=zi+perioada-1;
            for (int i=zi; i<=total; i++)
                {
                    ptr[nr_camera]->Set_status(total);
                }
            ptr[nr_camera]->Set_zi(total+1);
            prima_zi=zi;
            nr_cam=nr_camera;
            cout<<ptr[nr_camera]->Get_Capac();


        }
        else if(r==2)
        {
            int minim, nr_ap=16, total,zi;
            minim=ptr[16]->Get_zi();
            for (int i=16; i<=22; i++)
            {
                zi=ptr[i]->Get_zi();
                if (zi<minim)
                {
                    minim=zi;
                    nr_ap=i;
                }
            }
            total=zi+perioada-1;
            for (int i=zi; i<=total; i++)
                ptr[nr_ap]->Set_status(total);
            ptr[nr_ap]->Set_zi(total+1);
            prima_zi=zi;
            nr_cam=nr_ap;
        }

        cout<<"Doriti sa mergeti la restaurant? (0-nu, 1-da): ";
        cin>>rr;
        if(rr==0)
            nr_res=0;
        else if(rr==1)
        {
            int a,b,c;
            a=ptr[23]->Get_Capac();
            b=ptr[23]->Get_Nr_Mese_Oc();
            cout<<b;
            cout<<a;
            c=a-b;
            if( c == 0 )
            {
                cout<<"Restaurantul este plin";
            }
            else
            {
                //int nr;
                // nr=ptr[23]->Get_Nr_Mese_Oc();
                ptr[23]->Set_Nr_Mese_Oc(b+1);
                nr_res=b+1;
            }
        }

        cout<<"Doriti sa rezervati o sala de conf? (0-nu, 1-sala cu proiector, 2-sala cu scena)";
        cin>>rrr;
        if(rrr==0)
            sala_conf=0;
        else if (rrr==1)
        {
            int verif, i=24, gasit=1;
            while (gasit && i<=25)
            {
                verif=ptr[i]->Get_zi();
                if (verif<=prima_zi)
                {
                    int total;
                    total=prima_zi+perioada-1;
                    gasit=0;
                    for (int j=1; j<=total; j++)
                        ptr[i]->Set_status(total);
                    ptr[i]->Set_zi(total+1);
                    sala_conf=i;
                }
                i++;
            }
        }
        else if (rrr==2)
        {
            int verif, i=26, gasit=1;
            while (gasit && i<=28)
            {
                verif=ptr[i]->Get_zi();
                      if (verif<=prima_zi)
                {
                    int total;
                    total=prima_zi+perioada-1;
                    gasit=0;
                    for (int j=1; j<=total; j++)
                        ptr[i]->Set_status(total);
                    ptr[i]->Set_zi(total+1);
                    sala_conf=i;
                }
                i++;
            }
        }

        cout<<"Doriti sa luati micul dejun in camera sau la restaurant? (0-camera, 1-restaurant): ";
        cin>>mic_dejun;

        rez[k]= new Rezervare(nume, nr_cam,perioada,prima_zi,mic_dejun,sala_conf,nr_res);

        cout<< *rez[k];

        cout<<"Inca o rezervare? (1-da, 0-nu): ";
        cin>>rrrr;
        if (rrrr==0)
            ok=0;
        else k++;

    }
        int anulare;
        nr_rezervari=k;
        cout<<"Doriti sa anulati o rezervare? (1-da, 0-nu): ";
        cin>> anulare;
        if (anulare==1)
        {
            string nume_rez;
            cout<<"Pe ce nume este facuta rezervarea?";
            cin.ignore();
            getline(cin, nume_rez);
            for (int i=1; i<=nr_rezervari; i++)
            {
                if (nume_rez == rez[i]->Get_nume())
                {
                    cout<<"blabla";
                    rez[i]->Sterge_Rez();
                    for (int j=i; j<nr_rezervari; j++)
                    {
                        rez[j]=rez[j+1];
                    }
                   // delete rez[nr_rezervari];
                   // nr_rezervari--;
                   // cout<<endl;
                }
            }
            cout<<"afisare: "<<endl;
            for (int i=1; i<=nr_rezervari-1; i++)
                {cout<< *rez[i];
                cout<<endl<<i<<endl;
                }
        }

    return 0;
}
