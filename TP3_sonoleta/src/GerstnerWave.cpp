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

double GerstnerWave::operator()(Dvector x0, int t) 
{
    double z = amplitude * cos((*direction) * x0 - frequency*t + phase);
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
