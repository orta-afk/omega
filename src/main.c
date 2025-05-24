#include "raylib.h"
#include "manager.h"
#include "entity.h"
#include "shopRoom.h"

int main(){
  states state = mainMenu;
  
  InitWindow(640, 320, "omega");

  entity entity;
  entityTexture et;
  shopRoom shoproom;

  initEntity(&entity);
  initEntityTexture(&et);
  initShop(&shoproom);
  initManager();

  while(!WindowShouldClose()){
    updateManager();

    states s = getState();
    if(s == mainMenu){
      updateMainMenu();  
    } else if(s == game){
      updateEntity(&entity, &et);
    } else if(s == shop){
      updateShop(&shoproom);
    } else if(s == death){
      updateDeath();
    }
    
    BeginDrawing();
    ClearBackground(BLACK);
    if(s == mainMenu){
      drawMainMenu();  
    } else if(s == game){
      drawEntity(&entity, &et);
    } else if(s == shop){
      drawShop(&shoproom);
    } else if(s == death){
      drawDeath();
    }
    EndDrawing();
  }

  destroyShop(&shoproom);
  destroyEntity(&et);
  CloseWindow();
  return 0;
}
