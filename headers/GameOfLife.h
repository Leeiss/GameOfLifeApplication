#ifndef GIME_OF_LIVE_N
#define GIME_OF_LIVE_N

#include "../headers/ApplicationElements.h"
#include "../headers/ApplicationLogic.h"
#include "../headers/Libs.h"

class GameOfLifeApp {
 private:
  Camera2D camera;
  bool manualMode;
  bool interactionMode;
  bool menuOpen;
  cellularAutomaton::game_of_life cellularAutomaton;
  InterfaceManager interfaceManager;
  Slider numberOfCellsSlider;
  Slider speedSlider;

 public:
  GameOfLifeApp()
      : camera({0}), manualMode(false), interactionMode(true), menuOpen(true) {
    camera.target = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    camera.offset = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    interfaceManager.SliderOptions(numberOfCellsSlider, speedSlider);
  }

  void Run();

 private:
  void UpdateCamera();
  void UpdateInteraction();
  void Draw();
  void ImplementMenuCommands();
  void ImplemenntGeneralCommands();
  void ImplementEventSpeedSliderChanged();
  void ImplementEventAmountOfCellsSliderChanged();
  void ImplementEventModeChanged();
  void ImplementEventMenuVisibilityChanged();
  void ImplementEventCellSelected();
  void ImplementKeyboardEvents();
};
#endif