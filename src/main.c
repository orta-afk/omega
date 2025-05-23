#include "raylib.h"
#include "shopRoom.h"

int main(){
  InitWindow(640, 320, "omega");

  shopRoom shoproom;

  initShop(&shoproom);

  while(!WindowShouldClose()){
    updateShop(&shoproom);

    BeginDrawing();
    ClearBackground(BLACK);
    drawShop(&shoproom);
    EndDrawing();
  }

  destroyShop(&shoproom);
  CloseWindow();
  return 0;
}
