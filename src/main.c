#include "game.h"

int main() {
    game game;
    window window;

    init(&game, &window);

    while (!WindowShouldClose()) {
        update(&game);   
        BeginDrawing();
        ClearBackground(BLACK);
        draw(&game);     
        EndDrawing();
    }

    destroy(&game);
    return 0;
}
