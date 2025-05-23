#include "raylib.h"

int main(){
  InitWindow(640, 320, "omega");

  while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
