#ifndef SHOPROOM_H
#define SHOPROOM_H

#include "raylib.h"

typedef enum shopStuff{
  item1,
  item2,
  item3,
  item4,
}shopStuff;

typedef struct shopRoom{
  int indexX;
  int indexY;
  Rectangle dest;
  Rectangle source;
  Texture2D texture;
}shopRoom;

void initShop(shopRoom* shoproom);
void updateShop(shopRoom* shoproom);
void drawShop(shopRoom* shoproom);
void destroyShop(shopRoom* shoproom);

#endif
