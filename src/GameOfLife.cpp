
#include "../headers/ApplicationElements.h"
#include "../headers/GameOfLife.h"
#include "../headers/Libs.h"
#include "../headers/ApplicationLogic.h"

void GameOfLifeApp::Run() {
        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game of life");
        SetTargetFPS(24);
        UpdateCamera();
        while (!WindowShouldClose()) {
            
            UpdateInteraction();
            Draw();
        }
        CloseWindow();
    }

    void  GameOfLifeApp::UpdateCamera() {
    if (IsKeyDown(KEY_RIGHT)) camera.target.x += 10;
    if (IsKeyDown(KEY_LEFT)) camera.target.x -= 10;
    if (IsKeyDown(KEY_DOWN)) camera.target.y += 10;
    if (IsKeyDown(KEY_UP)) camera.target.y -= 10;
    camera.zoom += (float)GetMouseWheelMove() * 0.05f;
    }

    void  GameOfLifeApp::UpdateInteraction() {
        if (interactionMode) {
            cellularAutomaton.generate_system(manualMode);
            cellularAutomaton.update_system(manualMode);
            if (!cellularAutomaton.generate_system(manualMode)) {
                interactionMode = false;
            }
        }

        if (IsKeyDown(KEY_R)) {
            camera.target = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
            camera.zoom = 1.0f;
        }

        if (IsKeyDown(KEY_G)) {
            interactionMode = true;
        }

        if (IsKeyDown(KEY_P)) {
            if (manualMode) {
                interactionMode = false;
            }
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mouse_position = GetMousePosition();
            cellularAutomaton.add_cell(mouse_position, manualMode);
        }

        if (IsKeyDown(KEY_S)) {
            cellularAutomaton.create_artificial_generation((int)numberOfCellsSlider.value, manualMode);
        }

        if (IsKeyPressed(KEY_X)) {
            ClearBackground(BLACK);
            cellularAutomaton = cellularAutomaton::game_of_life();  
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            if (CheckCollisionPointRec(mousePos, (Rectangle){10, 10, 30, 30})) {
                interactionMode = true;
                cellularAutomaton = cellularAutomaton::game_of_life();
                menuOpen = !menuOpen;
            }
        }
    }

    void  GameOfLifeApp::Draw() {
        BeginDrawing();
        BeginMode2D(camera);

       
        if (menuOpen) {
      interfaceManager.DrawGeneralMenuItems(manualMode, speedSlider);
      if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) &&
          CheckCollisionPointRec(GetMousePosition(), speedSlider.bounds)) {
        float mousePosX = GetMouseX() - speedSlider.bounds.x;
        float value = (mousePosX / speedSlider.bounds.width) * 500;
        speedSlider.value = interfaceManager.Clamp(
            value, 1, 500); 
        SetTargetFPS((int)speedSlider
                         .value);  
      }
      DrawText("Change speed", 20, SCREEN_HEIGHT - 220, 17,
               Color{116, 66, 200, 255});
      interfaceManager.DrawSlider(speedSlider);

      if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) &&
          CheckCollisionPointRec(GetMousePosition(),
                                 numberOfCellsSlider.bounds)) {
        float mousePosX = GetMouseX() - numberOfCellsSlider.bounds.x;
        float value = (mousePosX / numberOfCellsSlider.bounds.width) * 500;
        numberOfCellsSlider.value = interfaceManager.Clamp(value, 1, 500);
      }
      if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();
        if (CheckCollisionPointRec(
                mousePos, (Rectangle){20, SCREEN_HEIGHT - 60, 280, 40})) {
          manualMode = !manualMode;
          if (manualMode) {
            ClearBackground(BLACK);
            interactionMode = false;
            cellularAutomaton.clear_manual_cells();
          } else {
            interactionMode = true;
          }
        }
      }
      if (!manualMode) {
        interfaceManager.DrawRandomModeMenuItems(numberOfCellsSlider,
                                                 speedSlider);
      } else {
        interfaceManager.DrawManualModeMenuItems();
      }
    } else {
      interfaceManager.DrawWithoutMenu();
    }
        EndMode2D();
        EndDrawing();
    }

