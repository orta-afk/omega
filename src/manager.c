#include "manager.h"

static states state = mainMenu;

void initManager(){
  state = mainMenu;
}
void updateManager(){
  switch(state){
    case mainMenu:
      state = mainMenu;
      break;
    case game:
      state = game;
      break;
    case shop:
      state = shop;
      break;
    case death:
      state = death;
      break;
  }
}

states getState(){
  return state;
}
void setUpdate(states newState){
  state = newState; 
}
