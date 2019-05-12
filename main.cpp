#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include "poo3.h"

using namespace std;

istream & operator >> (istream &in,  Rezervare &rez)
{
    in >> rez.nume >> rez.nr_cam >> rez.perioada >> rez.prima_zi >> rez.mic_dejun >> rez.sala_conf >> rez.nr_res;
    return in;
}

ostream & operator << (ostream &out, const Rezervare &rez)
{
    out << "Rezervarea este facuta pe numele: " << rez.nume <<  endl;
    out << "Nr. camera: " << rez.nr_cam << endl;
    out << "Perioada: "<< rez.perioada << " zile " << endl;
    out << "Prima zi in care va puteti caza este: " << rez.prima_zi << endl;
    if (rez.mic_dejun == 0)
        out << "Micul dejun - in camera " << endl;
    else if (rez.mic_dejun == 1)
        out << "Micul dejun - la restaurant " << endl;
    if (rez.sala_conf == 0)
        out << "Sala conferinta: NU ati rezervat" << endl;
        else if (rez.sala_conf == -1)
            out << "Nu este nicio sala de conferinta libera. " << endl;
        else if (rez.sala_conf == 24 || rez.sala_conf == 25)
            out << "Nr. sala de conferinta cu proiector: " << rez.sala_conf << endl;
        else if (rez.sala_conf == 26 || rez.sala_conf == 27 || rez.sala_conf == 28)
            out << "Nr. sala de conferinta cu scena: " << rez.sala_conf << endl;
    if (rez.nr_res != 0)
        out << "Nr. masa restaurant: " << rez.nr_res << endl;
        else out << "Nu doriti sa mergeti la restaurant. " << endl;
    out << endl;
    return out;
}

int main()
{
    // 15 7 23 2 3 6
    Rezervare *rez[200];
    //int nr_cam = 15, nr_ap = 7, nr_mese = 23, nr_sali_proiector = 2, nr_sali_scena = 3;
    int nr_rezervari;

    Incapere *ptr[200];             // vectorul in care memorez  obiectele de tip camera, apartament, restaurant si sala de conf

    for(int i = 1; i <= 15; i++)
    {
        ptr[i] = new Camera;        // in hotel am 15 camere; setez nr. fiecarei camere
        ptr[i] -> Set_Nr(i);
    }

    for (int i = 16; i <= 22; i++)
    {
        ptr[i] = new Apartament;    // in hotel am 7 apartamente, setez nr. fiecarui ap.
        ptr[i] -> Set_Nr(i);
    }

    int j=23;
    ptr[j] = new Restaurant;        // aloc memorie pt restaurant

    for (int i = 24; i <= 28; i++)
    {
        ptr[i] = new Sala_Conf;     // in hotel am 5 sali de conf, setez nr. fiecarei sali
        ptr[i] -> Set_Nr(i);
    }

    int ok = 1;
    int k = 1;

    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "Rezervari Hotel: " << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;

    while(ok)
    {
        string nume;
        int r, rr, rrr, rrrr;
        int nr_cam, perioada, prima_zi, nr_res, sala_conf, mic_dejun;

        cout << endl << "Numele dvs. este: " << endl;
        getline(cin, nume);

        cout << "Cate zile doriti sa stati? (1-10 zile): ";
        cin >> perioada;

        cout << "Ce doriti sa rezervati? (1-camera pt 2 persoane, 2-apartament pt 4 persoane): ";
        cin >> r;
        if (r == 1)
        {
            int minim, nr_camera = 1, total, zi;
            minim = ptr[1] -> Get_Zi();

            for (int i = 2; i <= 15; i++)
            {
                zi = ptr[i] -> Get_Zi();
                if (zi < minim)
                {
                    minim = zi;
                    nr_camera = i;
                }
            }
            total = zi + perioada -1;
            for (int i = zi; i <= total; i++)
                {
                    ptr[nr_camera] -> Set_Status(i,1);
                }
            ptr[nr_camera] -> Set_Zi(total+1);
            prima_zi = zi;
            nr_cam = nr_camera;

        }
        else if(r == 2)
        {
            int minim, nr_ap = 16, total, zi;
            minim = ptr[16] -> Get_Zi();

            for (int i = 16; i <= 22; i++)
            {
                zi = ptr[i] -> Get_Zi();
                if (zi < minim)
                {
                    minim = zi;
                    nr_ap = i;
                }
            }
            total = zi + perioada - 1;
            for (int i = zi; i <= total; i++)
                ptr[nr_ap] -> Set_Status(i,1);
            ptr[nr_ap] -> Set_Zi(total+1);
            prima_zi = zi;
            nr_cam = nr_ap;
        }

        cout << "Doriti sa mergeti la restaurant? (0-nu, 1-da): ";
        cin >> rr;
        if(rr == 0)
            nr_res = 0;
        else if(rr == 1)
        {
            int a,b,c;
            a = ptr[23] -> Get_Capac();
            b = ptr[23] -> Get_Nr_Mese_Oc();
            c = a - b;
            if( c == 0 )
            {
                cout << "Restaurantul este plin." << endl;
            }
            else
            {
                ptr[23] -> Set_Nr_Mese_Oc(b+1);
                nr_res = b + 1;
            }
        }

        cout << "Doriti sa rezervati o sala de conf? (0-nu, 1-sala cu proiector, 2-sala cu scena): ";
        cin >> rrr;
        if(rrr == 0)
            sala_conf = 0;
        else if (rrr == 1)
        {
            int verif, i = 24, gasit = 1;
            while (gasit && i <= 25)
            {
                verif = ptr[i] -> Get_Zi();
                if (verif <= prima_zi)
                {
                    int total;
                    total = prima_zi + perioada -1;
                    gasit = 0;
                    for (int j = 1; j <= total; j++)
                        ptr[i] -> Set_Status(j,1);
                    ptr[i] -> Set_Zi(total+1);
                    sala_conf = i;
                }
                i++;
            }
            if (gasit == 1)
            {
                sala_conf = -1;
            }
        }
        else if (rrr == 2)
        {
            int verif, i = 26, gasit = 1;
            while (gasit && i <= 28)
            {
                verif = ptr[i] -> Get_Zi();
                if (verif <= prima_zi)
                {
                    int total;
                    total = prima_zi + perioada - 1;
                    gasit = 0;
                    for (int j = 1; j <= total; j++)
                        ptr[i] -> Set_Status(j,1);
                    ptr[i] -> Set_Zi(total + 1);
                    sala_conf = i;
                }
                i++;
            }
            if (gasit == 1)
            {
                sala_conf = -1;
            }
        }

        cout << "Doriti sa luati micul dejun in camera sau la restaurant? (0-camera, 1-restaurant): ";
        cin >> mic_dejun;

        rez[k] = new Rezervare(nume, nr_cam, perioada, prima_zi, mic_dejun, sala_conf, nr_res);

        cout << endl << "Inca o rezervare? (1-da, 0-nu): ";
        cin >> rrrr;
        if (rrrr == 0)
            ok=0;
        else
        {
            k++;
            cin.ignore();
        }
    }

        int anulare;
        nr_rezervari = k;
        cout << endl << endl << "Doriti sa anulati o rezervare? (1-da, 0-nu): ";
        cin >> anulare;
        if (anulare == 1)
        {
            string nume_rez;
            int okk = 1, i = 1;
            cout << "Pe ce nume este facuta rezervarea? " << endl;
            cin.ignore();
            getline(cin, nume_rez);
            cout<< nume_rez;
            while (okk && i <= nr_rezervari)
            {
                if (nume_rez == rez[i] -> Get_Nume())
                {
                    int cam, per, primazi, conferinta, restaurant;
                    cam = rez[i] -> Get_Nr_Cam();
                    per = rez[i] -> Get_Perioada();
                    primazi = rez[i] -> Get_Prima_Zi();
                    conferinta = rez[i] -> Get_Sala_Conf();
                    restaurant = ptr[23] -> Get_Nr_Mese_Oc();
                    for (int k = primazi; k <= primazi + per - 1; k++)         //camera
                        ptr[cam] -> Set_Status(k,0);
                    ptr[23] -> Set_Nr_Mese_Oc(restaurant-1);               //restaurant
                    rez[i] -> Sterge_Rez();
                    for (int k = primazi; k <= primazi + per - 1; k++)
                        ptr[conferinta] -> Set_Status(k,0);
                    for (int j = i; j < nr_rezervari; j++)
                    {
                        rez[j] = rez[j + 1];
                    }
                    nr_rezervari --;
                    okk = 0;
                }
                i++;
            }
        }

    cout << endl  << endl << "Rezervarile sunt: " << endl;
    for (int i = 1; i <= nr_rezervari; i++)
        {
            cout << endl << "Rezervarea " << i <<": " << endl;
            cout << *rez[i];
        }
    for (int i = nr_rezervari; i >= 1; i--)
    {
        delete rez[i];
    }

    for (int i = 28; i >= 1; i--)
    {
        delete ptr[i];
    }

    return 0;
}
