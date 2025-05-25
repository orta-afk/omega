#include "entity.h"

void initEntity(entity *entity){
  entity->step = 16;
  entity->positions = (Vector2){GetScreenWidth()/2.0f,GetScreenHeight()/2.0f};
}

void initEntityTexture(entityTexture *et){
  et->texture = LoadTexture("../assest/top_down_transparent_packed.png");
  et->indexX = 24;
  et->indexY = 7;
  et->source = (Rectangle){
    .x = SIZE * et->indexX,
    .y = SIZE * et->indexY,
    .width = SIZE,
    .height = SIZE,
  };
}

void move(entity* entity) {
  if (IsKeyPressed(KEY_W)) {
      entity->positions.y -= entity->step;
  } else if (IsKeyPressed(KEY_S)) {
      entity->positions.y += entity->step;
  } else if (IsKeyPressed(KEY_A)) {
      entity->positions.x -= entity->step;
  } else if (IsKeyPressed(KEY_D)) {
      entity->positions.x += entity->step;
  }
}

void updateEntity(entity *entity, entityTexture *et){
  move(entity);
  et->dest = (Rectangle){
    .x = entity->positions.x,
    .y = entity->positions.y,
    .width = SIZE,
    .height = SIZE,
  };
}

void drawEntity(entityTexture* et){
  DrawTexturePro(et->texture, et->source, et->dest, (Vector2){0,0}, 0.0f, RAYWHITE);
}

void destroyEntity(entityTexture *et){
  UnloadTexture(et->texture);
}
