#include "entity.h"

void initEntity(entity *entity){
  entity->velocity = (Vector2){0,0};
  entity->positions = (Vector2){0,0};
}

void initEntityTexture(entityTexture *et){
  et->indexX = 24;
  et->indexY = 7;
  et->source = (Rectangle){
    .x = SIZE * et->indexX,
    .y = SIZE * et->indexY,
    .width = SIZE,
    .height = SIZE,
  };
  et->texture = LoadTexture("../assest/top_down_transparent_packed.png");
}

void updateEntity(entity *entity, entityTexture *et){
  et->dest = (Rectangle){
    .x = entity->positions.x,
    .y = entity->positions.y,
    .width = SIZE,
    .height = SIZE,
  };  
}

void drawEntity(entityTexture *et){
  DrawTexturePro(et->texture, et->source, et->dest, (Vector2){0,0}, 0.0f, RAYWHITE);
}

void destroyEntity(entityTexture *et){
  UnloadTexture(et->texture);
}
