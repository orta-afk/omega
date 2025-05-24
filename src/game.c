#include "game.h"
#include "entity.h"

void init(game *game, window* window){
  window->width = 640;
  window->height = 320;
  window->title = "omega";
  window->color = BLACK;
  InitWindow(window->width, window->height, window->title);

  initEntity(&game->entity);
  initEntityTexture(&game->entitytexture);
}

void update(game* game){
  updateEntity(&game->entity, &game->entitytexture);
  while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(BLACK);
    draw(game);
    EndDrawing();
  }
}

void draw(game* game){
  drawEntity(&game->entitytexture);  
}

void destroy(game *game){
  destroyEntity(&game->entitytexture);
  CloseWindow();
}
