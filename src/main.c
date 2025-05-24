#include "raylib.h"
#include "entity.h"
#include "shopRoom.h"

int main(){
  InitWindow(640, 320, "omega");

  entity entity;
  entityTexture et;
  shopRoom shoproom;

  initEntity(&entity);
  initEntityTexture(&et);
  initShop(&shoproom);

  while(!WindowShouldClose()){
    updateEntity(&entity, &et);
    updateShop(&shoproom);

    BeginDrawing();
    ClearBackground(BLACK);
    drawShop(&shoproom);
    drawEntity(&et);
    EndDrawing();
  }

  destroyShop(&shoproom);
  destroyEntity(&et);
  CloseWindow();
  return 0;
}
