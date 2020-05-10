#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <math.h>
#include "./../headers/GerstnerWave.h"

using namespace std;

// === Classe abstraite ===

// === Méthodes de base ===

GerstnerWave::GerstnerWave()
{
    direction = new Dvector();
    amplitude = 0;
    phase = 0;
    frequency = 0;
}

GerstnerWave::GerstnerWave(double A, double Phi, Dvector* dir, double freq)
{
    direction = new Dvector(*dir);
    amplitude = A;
    phase = Phi;
    frequency = freq;
}

GerstnerWave::~GerstnerWave()
{
    delete direction;
}

GerstnerWave::GerstnerWave(GerstnerWave &&model)
{
    direction = model.direction;
    model.direction = nullptr;

    amplitude = model.amplitude;
    phase = model.phase;
    frequency = model.frequency;
}

GerstnerWave::GerstnerWave(GerstnerWave const &model)
{
    direction = new Dvector(*model.direction);

    amplitude = model.amplitude;
    phase = model.phase;
    frequency = model.frequency;
}

GerstnerWave GerstnerWave::operator=(GerstnerWave &&model)
{
    delete[] direction;
    direction = model.direction;
    model.direction = nullptr;

    amplitude = model.amplitude;
    phase = model.phase;
    frequency = model.frequency;

    return *this;
}

GerstnerWave GerstnerWave::operator=(GerstnerWave const &model)
{
    delete[] direction;
    direction = new Dvector(*model.direction);

    amplitude = model.amplitude;
    phase = model.phase;
    frequency = model.frequency;

    return *this;
}

double GerstnerWave::operator()(Dvector x, int t) 
{
    double z = amplitude * cos((*direction) * x - frequency*t + phase);
    return z;
}

// === Setters & Getters ===

double GerstnerWave::getAmplitude() {
    return amplitude;
}

void GerstnerWave::setAmplitude(double value) {
    amplitude = value;
}

double GerstnerWave::getPhase() {
    return phase;
}

void GerstnerWave::setPhase(double value) {
    phase = value;
}

Dvector* GerstnerWave::getDirection() {
    return direction;
}

void GerstnerWave::setDirection(Dvector* value) {
    direction = value;
}

double GerstnerWave::getFrequency() {
    return frequency;
}

void GerstnerWave::setFrequency(double value) {
    frequency = value;
}


// === Calcul de la fréquence ===

double module(Dvector* dir)
{
    return sqrt((*dir) * (*dir));
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
double compute_freq(Dvector* dir, int type, double D, double L, double T)
{
    double k = module(dir);
    double w, w_0;
    switch (type)
    {
        case 0:
            w = sqrt(G * k);
            break;
        case 1:
            w = sqrt(G * k * tanh(k * D));
            break;
        case 2:
            w = sqrt(G * k * (1 + k*k*L*L));
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