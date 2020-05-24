#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <tgmath.h>
#include <random>
#include <cmath>
#include <complex>
#include "./../headers/PhilipsWave.h"
using namespace std;

// === Méthodes principales ===

PhilipsWave::PhilipsWave()
{
    L = 0;
    V = 0;
    w = 0;
    A = 0;
    Lx, Ly = 1, 1;
    xi_r, xi_i = 0, 0;
    dir = new Dvector(2, 1);
}

PhilipsWave::~PhilipsWave()
{
    delete dir;
}

PhilipsWave::PhilipsWave(double N, double M, double Lx, double Ly, 
                         double A, double w, double V, Dvector* dir)
{
    this->Lx = Lx;
	this->Ly = Ly;
    this->N = N;
	this->M = M;
	this-> V = V;
	this-> A = A;
	this-> w = w;
    double kx, ky;
    kx = 2 * M_PI * N / Lx;
    kx = 2 * M_PI * M / Ly;
    this->dir = dir;
    this->xi_r = generate_xi();
	this->xi_i = generate_xi(); 
    this->L = pow(V,2)/g;	
}

PhilipsWave::PhilipsWave(PhilipsWave &&model)
{
    dir = model.dir;
    model.dir = nullptr;
    L, V, w, A = model.L, model.V, model.w, model.A;
    Lx, Ly = model.Lx, model.Ly;
    xi_i, xi_r = model.xi_i, model.xi_r;
}

PhilipsWave::PhilipsWave(PhilipsWave const &model)
{
    dir = new Dvector(*model.dir);
    L, V, w, A = model.L, model.V, model.w, model.A;
    Lx, Ly = model.Lx, model.Ly;
    xi_i, xi_r = model.xi_i, model.xi_r;
}

PhilipsWave PhilipsWave::operator=(PhilipsWave &&model)
{
    delete[] dir;
    dir = model.dir;
    model.dir = nullptr;
    L, V, w, A = model.L, model.V, model.w, model.A;
    Lx, Ly = model.Lx, model.Ly;
    xi_i, xi_r = model.xi_i, model.xi_r;

    return *this;
}

PhilipsWave PhilipsWave::operator=(PhilipsWave const &model)
{
    delete[] dir;
    dir = new Dvector(*model.dir);
    L, V, w, A = model.L, model.V, model.w, model.A;
    Lx, Ly = model.Lx, model.Ly;
    xi_i, xi_r = model.xi_i, model.xi_r;

    return *this;
}


// === Méthodes utiles ===

double PhilipsWave::generate_xi()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> d(0, 1);
    return d(gen);
}

ComplexVector<complex<double>> PhilipsWave::get_height(int t)
{
	cout <<"N*M :" <<  N*M << endl;
	ComplexVector<complex<double>> height(N*M);
	int index = 0;
	Dvector k(2);
	for(int n = -N/2; n < N/2; n++){
	   for(int m = -M/2; m < M/2; m++){
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
				double Ph_k = (A * exp(-1/(pow(mod_k*L, 2))) / pow(mod_k, 2)) * pow(k.get(0)*(*dir).get(0) + k.get(1) * (*dir).get(1), 2);
				double Pmh_k = (A * exp(-1/(pow(mod_k*L, 2))) / pow(mod_k, 2)) * pow(-k.get(0)*(*dir).get(0) - k.get(1)*(*dir).get(1), 2);
				//complex<double> omega(0,0);
				//omega.real(compute_freq(&k));
				double omega = compute_freq(&k);
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

ComplexVector<complex<double>> PhilipsWave::operator()(int t)
{
    return PhilipsWave::get_height(t);
}

void PhilipsWave::show_attributes()
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
