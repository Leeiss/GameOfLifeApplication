#include "../headers/ApplicationElements.h"
#include "../headers/GameOfLife.h"
#include "../headers/Libs.h"
#include "../headers/ApplicationLogic.h"

void GameOfLifeApp::Run() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "manager of - game of life");
        SetTargetFPS(24);
        while (!WindowShouldClose()) {
            SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
            UpdateCamera();
            UpdateInteraction();
            Draw();
        }
        CloseWindow();
    }
    
    void  GameOfLifeApp::UpdateCamera() {
    if (IsKeyDown(KEY_RIGHT)) {camera.target.x += 10,  DrawText("<-", 15, 15, 20, WHITE);}
    if (IsKeyDown(KEY_LEFT)) camera.target.x -= 10;
    if (IsKeyDown(KEY_DOWN)) camera.target.y += 10;
    camera.zoom += (float)GetMouseWheelMove() * 0.05f;
    }

    void  GameOfLifeApp::UpdateInteraction() {
        if (interactionMode) {
            
            cellularAutomaton.update_system(manualMode);
            if (!cellularAutomaton.generate_system(manualMode)) interactionMode = false;
            BeginDrawing();
            ClearBackground(BLACK);
            BeginMode2D(camera);
             if (interactionMode) {
            cellularAutomaton.generate_system(manualMode);
            
            if (!cellularAutomaton.generate_system(manualMode)) interactionMode = false;
        }
        ImplementGeneralCommands();
        }
        
    }

    void  GameOfLifeApp::Draw() {
        BeginDrawing();
        
        if (menuOpen) {
            interfaceManager.DrawGeneralMenuItems(manualMode, speedSlider);
            ImplementMenuCommands();
            if (!manualMode) interfaceManager.DrawRandomModeMenuItems(numberOfCellsSlider,
                                                 speedSlider);
            else interfaceManager.DrawManualModeMenuItems();
        }else interfaceManager.DrawWithoutMenu();
        
        EndMode2D();
        EndDrawing();
    }

    void GameOfLifeApp::ImplementGeneralCommands()
    {   ImplementKeyboardEvents();
        ImplementEventCellSelected();
        ImplementEventMenuVisibilityChanged();
    }

    void GameOfLifeApp::ImplementMenuCommands() {
        ImplementEventSpeedSliderChanged();
        ImplementEventAmountOfCellsSliderChanged();
        ImplementEventModeChanged();
        }


    //commands
     void GameOfLifeApp::ImplementEventSpeedSliderChanged(){
         if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) &&
          CheckCollisionPointRec(GetMousePosition(), speedSlider.bounds)) {
        float mousePosX = GetMouseX() - speedSlider.bounds.x;
        float value = (mousePosX / speedSlider.bounds.width) * 500;
        speedSlider.value = interfaceManager.Clamp(
            value, 1, 500); 
        SetTargetFPS((int)speedSlider
                         .value);  
      }
     }
  void GameOfLifeApp::ImplementEventAmountOfCellsSliderChanged(){
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) &&
          CheckCollisionPointRec(GetMousePosition(),
                                 numberOfCellsSlider.bounds)) {
        float mousePosX = GetMouseX() - numberOfCellsSlider.bounds.x;
        float value = (mousePosX / numberOfCellsSlider.bounds.width) * 500;
        numberOfCellsSlider.value = interfaceManager.Clamp(value, 1, 500);
      }
  }
  void GameOfLifeApp::ImplementEventModeChanged(){
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();
        if (CheckCollisionPointRec(mousePos, (Rectangle){20, SCREEN_HEIGHT - 60, 280, 40})) {
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
  }

  void GameOfLifeApp::ImplementEventMenuVisibilityChanged(){
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            if (CheckCollisionPointRec(mousePos, (Rectangle){10, 10, 30, 30})) {
                menuOpen = !menuOpen;
            }
            if (manualMode) DrawRectangle(10, 10, 300, SCREEN_HEIGHT - 20, Fade(BLACK,1));  
           
        }
  }
  void GameOfLifeApp::ImplementEventCellSelected(){
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mouse_position = GetMousePosition();
            cellularAutomaton.add_cell(mouse_position, manualMode);
        }
  }

  void GameOfLifeApp::ImplementKeyboardEvents(){
        if (IsKeyDown(KEY_R)) {
            camera.target = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
            camera.zoom = 1.0f;
        }
        if (IsKeyDown(KEY_G)) {
            interactionMode = true;
        }
        if (IsKeyDown(KEY_P)) {
            if (manualMode) interactionMode = false;
        }
        if (IsKeyPressed(KEY_X)) {
            ClearBackground(BLACK);
            cellularAutomaton = cellularAutomaton::game_of_life();  
        }
        if (IsKeyDown(KEY_S)) cellularAutomaton.create_artificial_generation((int)numberOfCellsSlider.value, manualMode);
        
  }