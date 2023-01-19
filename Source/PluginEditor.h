/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include <../../GenderSynthesizer/Source/UI/ADSRComponent.h>
#include <../../GenderSynthesizer/Source/UI/OscComponent.h>
#include <../../GenderSynthesizer/Source/UI/FilterComponent.h>

//==============================================================================
/**
*/
class GenderSynthesizerAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    GenderSynthesizerAudioProcessorEditor (GenderSynthesizerAudioProcessor&);
    ~GenderSynthesizerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:  
    GenderSynthesizerAudioProcessor& audioProcessor;
    OscComponent osc;
    ADSRComponent adsr;
    FilterComponent filter;
    ADSRComponent modAdsr;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GenderSynthesizerAudioProcessorEditor)
};
