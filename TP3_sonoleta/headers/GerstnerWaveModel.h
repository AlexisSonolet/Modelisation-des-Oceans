#pragma once

#include "Dvector.h"
#include "GerstnerWave.h"
#include "WaveModel.h"
/*!
 * \file GerstnerWaveModel.h
 * Classe du modèle des vagues de Gerstner, sert à stocker une liste de vagues
 *
 */
class GerstnerWaveModel:
    public WaveModel
    {
        public:
            // Méthodes de base
            GerstnerWaveModel();
            GerstnerWaveModel(int n);
            ~GerstnerWaveModel();
            GerstnerWaveModel(GerstnerWaveModel &&model);
            GerstnerWaveModel(GerstnerWaveModel const &model);
            GerstnerWaveModel& operator=(GerstnerWaveModel &&model);
            GerstnerWaveModel& operator=(GerstnerWaveModel const &model);
            void setGerstnerWave(int i, GerstnerWave wave);
        private:
            GerstnerWave* listGerstnerWaves; /*< Liste des vagues */
            int size;
    };
