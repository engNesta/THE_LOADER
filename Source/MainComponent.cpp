#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 600);

    loadButton.setButtonText("LOAD VST3 PLUGIN");

    loadButton.setColour(juce::TextButton::buttonColourId, juce::Colour::fromRGB(250, 249, 246));
    loadButton.setColour(juce::TextButton::textColourOnId, juce::Colour::fromRGB(18, 18, 18));
    loadButton.setColour(juce::TextButton::textColourOffId, juce::Colour::fromRGB(18, 18, 18));

    loadButton.addListener(this);
    addAndMakeVisible(loadButton);

}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    juce::Colour offBlack = juce::Colour::fromRGB(18, 18, 18);
    juce::Colour offWhite = juce::Colour::fromRGB(250, 249, 246);

    g.fillAll (offBlack);

    g.setColour (offWhite);

    g.drawLine(150, 0, 155, 600);
    g.drawLine(450, 0, 455, 600);

}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    loadButton.setBounds(175 , 275, 240, 50);
}

void MainComponent::buttonClicked(juce::Button *button) {
    if (button == &loadButton)
    {
        loadButton.setButtonText("LOADING...");
    }
}