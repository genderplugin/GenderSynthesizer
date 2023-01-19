/*
  ==============================================================================

    AdsrData.cpp
    Created: 30 Dec 2022 6:36:00pm
    Author:  Ethan Starcher

  ==============================================================================
*/

#include "AdsrData.h"

void AdsrData::updateADSR(const float attack, const float decay, const float sustain, const float release)
{
    adsrParams.attack = attack;
    adsrParams.decay = decay;
    adsrParams.sustain = sustain;
    adsrParams.release = release;

    setParameters(adsrParams);
}