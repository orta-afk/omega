#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "entity.h"
#include "tilemap.h"

typedef struct window{
  int width;
  int height;
  char* title;
  Color color;
}window;

typedef struct game{
  entity entity;   
  entityTexture entitytexture;
  tilemap tilemap;
}game;

void init(game* game, window* window);
void update(game* game);
void draw(game* game);
void destroy(game* game);

#endif
