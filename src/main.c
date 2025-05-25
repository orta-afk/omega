#include "game.h"

int main() {
  game game;
  window window;

  init(&game, &window);

  RenderTexture2D target = LoadRenderTexture(640,320);
  SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);
  while (!WindowShouldClose()) {
    update(&game);

    BeginTextureMode(target);
    ClearBackground(BLACK);
    draw(&game);
    EndTextureMode();

    BeginDrawing();
    ClearBackground(BLACK);

    DrawTexturePro(
        target.texture,
        (Rectangle){0, 0, (float)target.texture.width,
                    -(float)target.texture.height},
        (Rectangle){0, 0, (float)window.width, (float)window.height},
        (Vector2){0, 0}, 0.0f, RAYWHITE);
    EndDrawing();
  }

  UnloadRenderTexture(target);
  destroy(&game);
  return 0;
}
