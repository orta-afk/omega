#include "game.h"

int main(){
  game game;
  window window;

  init(&game, &window);
  update(&game);
  draw(&game);
  destroy(&game);
}
