#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"
#define SIZE 16

extern bool isCollided;
typedef struct entity{
  int step;
  Vector2 positions; 
}entity;


typedef struct entityTexture{
  int indexX;
  int indexY;
  Rectangle dest;
  Rectangle source;
  Texture2D texture;
}entityTexture;


void initEntity(entity* entity);
void initEntityTexture(entityTexture* et);
void updateEntity(entity* entity, entityTexture* et);
void drawEntity(entityTexture* et);
void destroyEntity(entityTexture* et);

#endif
