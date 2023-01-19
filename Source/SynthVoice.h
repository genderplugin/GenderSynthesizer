/*
  ==============================================================================

    SynthVoice.h
    Created: 30 Dec 2022 2:39:41pm
    Author:  Ethan Starcher

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include <../../GenderSynthesizer/Source/SynthSound.h>
#include <../../GenderSynthesizer/Source/Data/AdsrData.h>
#include <../../GenderSynthesizer/Source/Data/OscData.h>
#include <../../GenderSynthesizer/Source/Data/FilterData.h>

class SynthVoice : public juce::SynthesiserVoice
{
public:
    bool canPlaySound(juce::SynthesiserSound* sound) override;
    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
    void stopNote(float velocity, bool allowTailOff) override;
    void controllerMoved(int controllerNumber, int newControllerValue) override;
    void prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels);
    void renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;
    void pitchWheelMoved(int newPitchWheelValue) override;
    void updateAdsr(const float attack, const float decay, const float sustain, const float release);
    void updateFilter(const int filterType, const float cutoff, const float resonance);
    void updateModAdsr(const float attack, const float decay, const float sustain, const float release);
    OscData& getOscillator() { return osc; };
private:

    juce::AudioBuffer<float> synthBuffer;
    OscData osc;
    AdsrData adsr;
    FilterData filter;
    AdsrData modAdsr;
    juce::dsp::Gain<float> gain;
    bool isPrepared{ false };

};

