#include "tilemap.h"

int map[WIDTH][HEIGHT];

void initTilemap(tilemap *tilemap){
  tilemap->indexX = 0;
  tilemap->indexY = 0;
  tilemap->tile = backgroundTile;
  tilemap->texture = LoadTexture("../assest/top_down.png");
}

void updateTilemap(tilemap *tilemap){
  int screenTilesX = WIDTH;  
  int screenTilesY = HEIGHT;

  int left   = (screenTilesX / 2) - 1;
  int right  = (screenTilesX / 2) + 1;
  int top    = (screenTilesY / 2) - 1; 
  int bottom = (screenTilesY / 2) + 1;

  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      if (i >= 6 && i <= 35 && j >= 2 && j <= 17) {
        if(i >= left && i <= right && j >= top && j <= bottom){
          map[i][j] = backgroundTile;
        }else{
          map[i][j] = tile;
        }
      } else {
        map[i][j] = backgroundTile;  
      }
    }
  }
}


void drawTilemap(tilemap *tilemap) {
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      int currentTile = map[i][j];
      tilemap->tile = currentTile;
      switch (currentTile) {
        case backgroundTile:
          tilemap->indexX = 0;
          tilemap->indexY = 0;
          break;
        case tile:
          tilemap->indexX = 17;
          tilemap->indexY = 0;
          break;
      }
      tilemap->source = (Rectangle){
        .x = SIZE * tilemap->indexX,
        .y = SIZE * tilemap->indexY,
        .width = SIZE,
        .height = SIZE,
      };

      tilemap->dest = (Rectangle){
        .x = SIZE * i,
        .y = SIZE * j,
        .width = SIZE,
        .height = SIZE,
      };

      DrawTexturePro(tilemap->texture, tilemap->source, tilemap->dest, (Vector2){0, 0}, 0.0f, RAYWHITE);
    }
  }
}

void destroyTilemap(tilemap *tilemap){
  UnloadTexture(tilemap->texture);
}
