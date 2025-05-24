#ifndef TILEMAP_H
#define TILEMAP_H

#include "raylib.h"

#define SIZE 16
#define WIDTH 40
#define HEIGHT 20

extern int map[WIDTH][HEIGHT];

typedef enum tiles{
  backgroundTile,
  tile,
}tiles;

typedef struct tilemap{
  int indexX;
  int indexY;
  tiles tile;
  Rectangle source;
  Rectangle dest;  
  Texture2D texture;
}tilemap;

void initTilemap(tilemap* tilemap);
void updateTilemap(tilemap* tilemap);
void drawTilemap(tilemap* tilemap);
void destroyTilemap(tilemap* tilemap);

#endif
