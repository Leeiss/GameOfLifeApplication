
#include "../headers/ApplicationElements.h"
#include "../headers/Libs.h"

float InterfaceManager::Clamp(float value, float min, float max) {
  if (value < min) {
    return min;
  } else if (value > max) {
    return max;
  } else {
    return value;
  }
}
void InterfaceManager::DrawSlider(Slider slider) {
  DrawRectangleRec(slider.bounds, GRAY);
  Rectangle filledBounds = {slider.bounds.x, slider.bounds.y,
                            slider.bounds.width * (slider.value / 500),
                            slider.bounds.height};
  DrawRectangleRec(filledBounds, Color{116, 66, 200, 255});
}

void InterfaceManager::SliderOptions(Slider &numberOfCellsSlider,
                                     Slider &speedSlider) {
  numberOfCellsSlider = {{20, static_cast<float>(SCREEN_HEIGHT) - 100, 280, 20},
                         128};
  speedSlider = {{20, static_cast<float>(SCREEN_HEIGHT) - 190, 280, 20}, 24};
}

void InterfaceManager::DrawGeneralMenuItems(bool manualMode,
                                            Slider speedSlider) {
  DrawRectangle(10, 10, 30, 30, BLACK);
  DrawText("<-", 15, 15, 20, WHITE);
  DrawRectangle(10, 10, 300, SCREEN_HEIGHT - 20, Fade(BLACK, 0.8f));
  DrawText("> press:", 20, 50, 21, Fade(Color{116, 66, 200, 255}, 0.8f));
  DrawText(TextFormat("%i", (int)speedSlider.value),
           speedSlider.bounds.x + speedSlider.bounds.width - 25,
           speedSlider.bounds.y - 20, 15, WHITE);
  DrawText("Change cell size", 20, SCREEN_HEIGHT - 220, 17,
           Color{116, 66, 200, 255});
  DrawSlider(speedSlider);
  DrawRectangle(20, SCREEN_HEIGHT - 60, 280, 40,
                (manualMode ? Color{116, 66, 200, 255} : GRAY));
  DrawText((manualMode ? "Switch to Automatic Mode" : "Switch to Manual Mode"),
           30, SCREEN_HEIGHT - 55, 20, BLACK);
}

void InterfaceManager::DrawRandomModeMenuItems(Slider numberOfCellsSlider,
                                               Slider speedSlider) {
  DrawText(">  >x<  for dumping", 30, 80, 20, WHITE);
  DrawText(
      ">  >s<  to spawn artificial\n"
      "generation\n",
      30, 110, 20, WHITE);
  DrawText(
      "\n>  >left mouse<  to spawn\n"
      "one cell",
      30, 140, 20, WHITE);
  DrawText("\n>  >esc<  to quit the game", 30, 200, 20, WHITE);

  DrawText("Change the number of\ncells added", 20, SCREEN_HEIGHT - 150, 17,
           Color{116, 66, 200, 255});
  DrawSlider(speedSlider);

  DrawSlider(numberOfCellsSlider);

  DrawText(TextFormat("%i", (int)numberOfCellsSlider.value),
           numberOfCellsSlider.bounds.x + numberOfCellsSlider.bounds.width - 25,
           numberOfCellsSlider.bounds.y - 20, 15, WHITE);
}

void InterfaceManager::DrawManualModeMenuItems() {
  DrawText(">  >x<  for dumping", 30, 80, 20, WHITE);
  DrawText(">  >g<  to go", 30, 110, 20, WHITE);
  DrawText(">  >p<  to stop", 30, 140, 20, WHITE);
  DrawText(">  >esc<  to quit the game", 30, 170, 20, WHITE);
}

void InterfaceManager::DrawWithoutMenu() { DrawText("->", 15, 15, 20, WHITE); };