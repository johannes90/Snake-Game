#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "highscore.h"
#include "player.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  // Init Player and highscore
  HighScore highScore;
  Player player;
  player.enter_name();
  std::cout << "Game Starts! \n \n";

  // Game loop
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);

  // Update Hihgscore before game closes
  highScore.Read();
  highScore.Update(player.getName(), game.GetScore());
  highScore.Write();

  //  Print current score and last highscores
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n\n";
  highScore.Print();

  return 0;
}
