#include <gtest/gtest.h>
#include "../headers/ApplicationLogic.h"

using namespace cellularAutomaton;

TEST(GameOfLifeTest, UpdateSystemTest) {
  game_of_life gol;
  gol.system_init();

  gol.update_system(false);

  EXPECT_EQ(gol.system[0][0], 0); 
}


TEST(GameOfLifeTest, ClearManualCellsTest) {
  game_of_life gol;
  gol.system_init();

  gol.clear_manual_cells();

  EXPECT_EQ(gol.system[0][0], 0);
}

TEST(GameOfLifeTest, SystemInitTest) {
  game_of_life gol;

  gol.system_init();

  EXPECT_EQ(gol.system[0][0], 0);
}


TEST(GameOfLifeTest, UpdateSystemManualModeTest) {
  game_of_life gol;
  gol.system_init();

  gol.update_system(true);

  EXPECT_EQ(gol.system[0][0], 0);
}


TEST(CountAliveNeighborsTest, AllNeighborsAlive) {
  cellularAutomaton::game_of_life gol;
  std::vector<std::vector<bool>> targetSystem = {{true, true, true},
                                                 {true, true, true},
                                                 {true, true, true}};
  int alive_neighbors = gol.count_alive_neighbors(1, 1, targetSystem);
  EXPECT_EQ(alive_neighbors, 8);
}

TEST(CountAliveNeighborsTest, NoNeighborsAlive) {
  cellularAutomaton::game_of_life gol;
  std::vector<std::vector<bool>> targetSystem = {{false, false, false},
                                                 {false, false, false},
                                                 {false, false, false}};
  int alive_neighbors = gol.count_alive_neighbors(1, 1, targetSystem);
  EXPECT_EQ(alive_neighbors, 0);
}


TEST(CountAliveNeighborsTest, SomeNeighborsAlive) {
  cellularAutomaton::game_of_life gol;
  std::vector<std::vector<bool>> targetSystem = {{false, true, false},
                                                 {true, false, true},
                                                 {false, true, false}};
  int alive_neighbors = gol.count_alive_neighbors(1, 1, targetSystem);
  EXPECT_EQ(alive_neighbors, 4);
}

TEST(CountAliveNeighborsTest, BorderCell) {
  cellularAutomaton::game_of_life gol;
  std::vector<std::vector<bool>> targetSystem = {{true, true, false},
                                                 {true, false, false},
                                                 {false, false, false}};
  int alive_neighbors = gol.count_alive_neighbors(0, 0, targetSystem);
  EXPECT_EQ(alive_neighbors, 2);
}

TEST(CountAliveNeighborsTest, OneNeighborAlive) {
  cellularAutomaton::game_of_life gol;
  std::vector<std::vector<bool>> targetSystem = {{false, false, false},
                                                 {false, true, false},
                                                 {false, false, false}};
  int alive_neighbors = gol.count_alive_neighbors(1, 1, targetSystem);
  EXPECT_EQ(alive_neighbors, 0);
}






