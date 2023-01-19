/*
  ==============================================================================

    OscData.cpp
    Created: 30 Dec 2022 7:19:18pm
    Author:  Ethan Starcher

  ==============================================================================
*/

#include "OscData.h"

void OscData::prepareToPlay(juce::dsp::ProcessSpec& spec)
{
    fmOsc.prepare(spec);
    prepare(spec);
}

void OscData::setWaveType(const int choice)
{
//{return std::sin(x); } -- sine wave
// return x / MathConstants<float>::pi // Saw wave
// return x < 0.0f ? -1.0f : 1.0f; // Square Wave

    switch (choice)
    {
    case 0:
        //sine wave
        initialise([](float x) {return std::sin(x); });
        break;

    case 1:
        //saw wave
        initialise([](float x) {return x / juce::MathConstants<float>::pi; });
        break;

    case 2:
        //sqaure wave
        initialise([](float x) {return x < 0.0f ? -1.0f : 1.0f; });
        break;

    default:
        jassertfalse;
        break;
    }
	
}

void OscData::getNextAudioBlock(juce::dsp::AudioBlock<float>& block)
{

    for (int channel = 0; channel < block.getNumChannels(); ++channel)
    {
        for (int sample = 0; sample < block.getNumSamples(); ++sample)
        {
            fmMod = fmOsc.processSample(block.getSample(channel, sample)) * fmDepth;
        }
    }
    process(juce::dsp::ProcessContextReplacing<float>(block));

}

void OscData::setWaveFrequency(const int midiNoteNumber)
{
    setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber) + fmMod);
    lastMidiNote = midiNoteNumber;
}

void OscData::setFmParams(const float depth, const float freq)
{
    fmOsc.setFrequency(freq);
    fmDepth = depth;
    auto currentFreq = juce::MidiMessage::getMidiNoteInHertz(lastMidiNote) + fmMod;
    setFrequency (currentFreq >= 0 ? currentFreq : currentFreq * -1.0f);
}

