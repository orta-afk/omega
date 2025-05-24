#include "tilemap.h"

int map[WIDTH][HEIGHT];

void initTilemap(tilemap *tilemap){
  tilemap->indexX = 0;
  tilemap->indexY = 0;
  tilemap->tile = backgroundTile;
  tilemap->texture = LoadTexture("../assest/top_down.png");
}

void updateTilemap(tilemap *tilemap){
  for(int i = 0; i < WIDTH; i++){
    for(int j = 0; j < HEIGHT; j++){
      if(i >= 0 || i <= 40){
        map[i][j] = tile;
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
          tilemap->indexX = 0;
          tilemap->indexY = 13;
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
