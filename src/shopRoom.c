#include "shopRoom.h"

void initShop(shopRoom *shoproom){
  shoproom->indexX = 0;
  shoproom->indexY = 0;
  shoproom->texture = LoadTexture("../assest/shop.png");
  shoproom->source = (Rectangle){
    .x = 640,
    .y = 320,
    .width = 640,
    .height = 320,
  };
}

void updateShop(shopRoom *shoproom){}
void drawShop(shopRoom *shoproom){
  shoproom->dest = (Rectangle){
    .x = 0,
    .y = 0,
    .width = 640,
    .height = 320,
  };
  DrawTexturePro(shoproom->texture, shoproom->source, shoproom->dest, (Vector2){0,0}, 0.0f, RAYWHITE);
}

void destroyShop(shopRoom *shoproom){
  UnloadTexture(shoproom->texture);
}
