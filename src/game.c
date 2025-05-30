#include "game.h"

void init(game *game, window* window){
  window->width = 1280;
  window->height = 640;
  window->title = "omega";
  window->color = BLACK;
  InitWindow(window->width, window->height, window->title);

  initEntity(&game->entity);
  initEntityTexture(&game->entitytexture);
  initTilemap(&game->tilemap);
}

void update(game* game){
  updateEntity(&game->entity, &game->entitytexture);
  updateTilemap(&game->tilemap);
}

void draw(game* game){
  drawTilemap(&game->tilemap);
  drawEntity(&game->entitytexture);  
}

void destroy(game *game){
  destroyEntity(&game->entitytexture);
  destroyTilemap(&game->tilemap);
  CloseWindow();
}
