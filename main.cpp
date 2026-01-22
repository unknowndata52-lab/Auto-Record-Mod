#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

// Global variable to track if we finished the level
bool g_levelFinished = false;

class $modify(MyPlayLayer, PlayLayer) {
    
    // 1. Logic for STARTING the recording
    bool init(GJGameLevel* level, bool useReplay, bool dontSave) {
        if (!PlayLayer::init(level, useReplay, dontSave)) return false;

        g_levelFinished = false; // Reset the win flag
        
        log::info("Level Started: Starting Recording...");
        // PLACEHOLDER: CallYourRecordingLibrary::start();

        return true;
    }

    // 2. Logic for COMPLETING the level
    void levelComplete() {
        PlayLayer::levelComplete();
        g_levelFinished = true;
        log::info("Level Completed! Video will be saved.");
    }

    // 3. Logic for EXITING/SAVING the video
    void onQuit() {
        PlayLayer::onQuit();
        
        bool keepAll = Mod::get()->getSettingValue<bool>("keep-all");

        if (g_levelFinished || keepAll) {
            log::info("Saving recording to gallery...");
            // PLACEHOLDER: CallYourRecordingLibrary::save();
        } else {
            log::info("Level failed. Deleting temporary recording...");
            // PLACEHOLDER: CallYourRecordingLibrary::delete();
        }
    }
};
