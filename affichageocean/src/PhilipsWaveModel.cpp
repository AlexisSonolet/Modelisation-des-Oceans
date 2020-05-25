#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <tgmath.h>
#include <random>
#include <cmath>
#include "./../headers/PhilipsWaveModel.h"
using namespace std;


// === Méthodes de base ===

PhilipsWaveModel::PhilipsWaveModel()
{
    L = 0;
    V = 0;
    w = 0;
    A = 0;
    Lx, Ly = 1, 1;
    xi_r, xi_i = 0, 0;
    dir = Dvector(2, 1);
}

PhilipsWaveModel::PhilipsWaveModel(int N, int M, double Lx, double Ly, 
                                   double A, double w, double V, Dvector dir)
{
    this->Lx = Lx;
	this->Ly = Ly;
    this->N = N;
	this->M = M;
	this->V = V;
	this->A = A;
	this->w = w;
    double kx, ky;
    kx = 2 * M_PI * N / Lx;
    kx = 2 * M_PI * M / Ly;
    this->dir = Dvector(dir);
    this->xi_r = generate_xi();
	this->xi_i = generate_xi(); 
    this->L = pow(V,2)/g;
}

PhilipsWaveModel::~PhilipsWaveModel() {}

PhilipsWaveModel::PhilipsWaveModel(PhilipsWaveModel &&model)
{
    dir = model.dir;
	
    L = model.L;
	V = model.V;
	w = model.w;
	A = model.A;
    Lx = model.Lx;
	Ly = model.Ly;
    xi_i = model.xi_i;
	xi_r = model.xi_r;
}

PhilipsWaveModel::PhilipsWaveModel(PhilipsWaveModel const &model)
{
    dir = Dvector(model.dir);
	
    L = model.L;
	V = model.V;
	w = model.w;
	A = model.A;
    Lx = model.Lx;
	Ly = model.Ly;
    xi_i = model.xi_i;
	xi_r = model.xi_r;
}

PhilipsWaveModel& PhilipsWaveModel::operator=(PhilipsWaveModel &&model)
{
    dir = model.dir;
    
	L = model.L;
	V = model.V;
	w = model.w;
	A = model.A;
    Lx = model.Lx;
	Ly = model.Ly;
    xi_i = model.xi_i;
	xi_r = model.xi_r;

    return *this;
}

PhilipsWaveModel& PhilipsWaveModel::operator=(PhilipsWaveModel const &model)
{
    dir = Dvector(model.dir);
    
	L = model.L;
	V = model.V;
	w = model.w;
	A = model.A;
    Lx = model.Lx;
	Ly = model.Ly;
    xi_i = model.xi_i;
	xi_r = model.xi_r;

    return *this;
}


// === Méthodes utiles ===

double PhilipsWaveModel::generate_xi()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> d(0, 1);
    return d(gen);
}

ComplexVector<complex<double>> PhilipsWaveModel::get_height(double t)
{
    // cout <<"N*M :" <<  N*M << endl;
	ComplexVector<complex<double>> height(N*M);
	int index = 0;
	Dvector k(2);
	for(int n = 0; n < N; n++){
	   for(int m = 0; m < M; m++){
			k.set(0,2*M_PI*n/Lx);
			k.set(1,2*M_PI*m/Ly);		
			if (k.isnull()) {
				height.set(index, complex<double>(0,0));
				index++;				
			}
			else{
				complex<double> i = -1;
				i = sqrt(i);
				double mod_k = sqrt(pow(k.get(0),2) + pow(k.get(1),2));
				//pow(k*(*dir),2)
				double Ph_k = (A * exp(-1/(pow(mod_k*L, 2))) / pow(mod_k, 2)) * pow(k.get(0)*(dir).get(0) + k.get(1) * (dir).get(1), 2);
				double Pmh_k = (A * exp(-1/(pow(mod_k*L, 2))) / pow(mod_k, 2)) * pow(-k.get(0)*(dir).get(0) - k.get(1)*(dir).get(1), 2);
				//complex<double> omega(0,0);
				//omega.real(compute_freq(&k));
				double omega = compute_freq(k);
				complex<double> height_1 = sqrt(Ph_k/2)*((xi_r + i*xi_i)) * exp(i*omega*(double)t);
				complex<double> height_2 = sqrt(Pmh_k/2)*((xi_r - i*xi_i)) * exp(-i*omega*(double)t);
				//height_1 *= ((xi_r + i*xi_i)) * exp(i*omega*t);
				//height_2 *= ((xi_r - i*xi_i)) * exp(-i*omega*t);
				height.set(index, height_1 + height_2);
				index++;	
			}	
	   }
	}
	fft(height, true);
    return height;
}


// === Compute height ===
Dvector PhilipsWaveModel::get_waves_height(double t)
{
	Dvector height = Dvector(N*M);
    ComplexVector<complex<double>> h = PhilipsWaveModel::get_height(t);
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			height.set(n*M + m, h.get(n*M + m).real());
		}
	}
	return height;
}


// === For debug ===

void PhilipsWaveModel::show_attributes()
{
	cout << "L :"<< L << endl;
	cout << "V :"<< V << endl;
	cout << "w :"<< w << endl;
	cout << "A :"<< A << endl;
	cout << "dir :"<< dir << endl;
	cout << "Lx :"<< Lx << " Ly : "<< Ly << endl;
	cout << "xi_r :"<< xi_r << endl;
	cout << "xi_i :"<< xi_i << endl;
	cout << "N :"<< N << endl;
	cout << "M :"<<M<<endl;
}


// === Autres fonctions ===

double module(Dvector dir)
{
    return sqrt(dir * dir);
}

/**
 * Renvoie la fréquence en fonction de plusieurs paramètres
 * @param dir : vecteur d'ondes
 * @param type :
 *      0 : cas de la houle
 *      1 : eau peu profonde
 *      2 : avec la tension de surface
 *      3 : NaNi
 * @param D : distance du sol au niveau moyen
 * @param L : tension de surface (?)
 * @param T : période de répétition des variations de hauteur
 */
double compute_freq(Dvector dir, int type, double D, double L, double T)
{
    double k = module(dir);
    double w, w_0;
    switch (type)
    {
        case 0:
            w = sqrt(g * k);
            break;
        case 1:
            w = sqrt(g * k * tanh(k * D));
            break;
        case 2:
            w = sqrt(g * k * (1 + k*k*L*L));
            break;
        case 3:
            if (W_TYPE == 3) {
                cout << "ERREUR : W_TYPE ne peut pas être égal à 3 (récursion infinie)" << endl;
                exit(EXIT_FAILURE);
            }
            w_0 = 2 * M_PI / T;
            w = ((int) (compute_freq(dir, W_TYPE, D, L, T) / w_0)) * w_0;
            break;
        default:
            cout << "ERREUR : type de fréquence inconnue" << endl;
            exit(EXIT_FAILURE);
    }
    return w;
}