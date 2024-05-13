#ifndef SLIDER_COLOR_H
#define SLIDER_COLOR_H

#include "Libs.h"

#define CELL_SIZE 10
#define SCREEN_HEIGHT 720
#define SCREEN_WIDTH 1024

struct Slider {
  Rectangle bounds;
  float value;
};

class InterfaceManager {
 public:
  float Clamp(float value, float min, float max);
  void SliderOptions(Slider &numberOfCellsSlider, Slider &speedSlider);
  void DrawGeneralMenuItems(bool manualMode, Slider speedSlider);
  void DrawRandomModeMenuItems(Slider numberOfCellsSlider, Slider speedSlider);
  void DrawManualModeMenuItems();
  void DrawWithoutMenu();

  private:
  void DrawSlider(Slider slider);

};

#endif