#ifndef MANAGER_H
#define MANAGER_H

#include "raylib.h"

typedef enum states{
  mainMenu,
  game,
  shop,
  death,
}states;

void initManager();
void updateManager();
void draw();
states getState();
void setUpdate(states newState);

#endif
