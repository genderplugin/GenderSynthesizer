/*
  ==============================================================================

    SynthSound.h
    Created: 30 Dec 2022 2:39:49pm
    Author:  Ethan Starcher

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>



class SynthSound : public juce::SynthesiserSound
{
public:
    bool appliesToNote(int midiNoteNumber) override { return true; };
    bool appliesToChannel(int midiChannel) override { return true; };
};
