/*
  ==============================================================================

    AdsrData.h
    Created: 30 Dec 2022 6:36:00pm
    Author:  Ethan Starcher

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class AdsrData : public juce::ADSR {
public:
    void AdsrData::updateADSR(const float attack, const float decay, const float sustain, const float release);
private:
    juce::ADSR::Parameters adsrParams;
};
