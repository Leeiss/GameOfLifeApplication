#ifndef SLIDER_COLOR_H
#define SLIDER_COLOR_H

#include "Libs.h"

struct Slider {
  Rectangle bounds;
  float value;
};
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 720;
const int CELL_SIZE = 5;
class InterfaceManager {
 public:
  float Clamp(float value, float min, float max);
  void DrawSlider(Slider slider);
  void SliderOptions(Slider &numberOfCellsSlider, Slider &speedSlider);
  void DrawGeneralMenuItems(bool manualMode, Slider speedSlider);
  void DrawRandomModeMenuItems(Slider numberOfCellsSlider, Slider speedSlider);
  void DrawManualModeMenuItems();
  void DrawWithoutMenu();
};

#endif