//
// Created by Nesta on 2023-06-15.
//
#define CATCH_CONFIG_MAIN
#include "../Source/MainComponent.h"
#include <juce_core/juce_core.h>
#include <juce_graphics/juce_graphics.h>
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_audio_processors/juce_audio_processors.h>
#include "Catch2/src/catch2/catch_test_macros.hpp"

TEST_CASE("Button Callback Test")
{
    SECTION("Button Text Change Test")
    {
        MainComponent mainComponent;
        mainComponent.buttonClicked(&mainComponent.loadButton);
        REQUIRE(mainComponent.loadButton.getButtonText() == "LOADING...");
    }


}

TEST_CASE("File Loading Test")
{
    MainComponent mainComponent;
    SECTION("Vst3 data retrieval Test")
    {
        juce::File file = juce::File::getSpecialLocation(juce::File::SpecialLocationType::currentExecutableFile);
        mainComponent.retrieveVST3data(file);
        REQUIRE(mainComponent.infoLabel.getText() == file.getFileNameWithoutExtension() + "\n" +
                file.getFileExtension() + "\n" +
                file.getFullPathName());
        // Additional assertions
    }
}
