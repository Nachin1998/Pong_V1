#include "endScreen.h"
#include "gameManager.h"

namespace Ignacio {
	void endScreen() {

		PlayMusicStream(endScreenMusic); //Wont load
		
		while (!WindowShouldClose())
		{

			UpdateMusicStream(endScreenMusic); //Wont load

			BeginDrawing();
			ClearBackground(WHITE);

			if (players[0].points >= win) {
				DrawText(FormatText("Winner: Player 1: %i points", players[0].points), GetScreenWidth() / 2 - 150, screenHeight / 2 - 130, 20, BLACK);
				DrawText(FormatText("Loser: Player 2: %i points", players[1].points), GetScreenWidth() / 2 - 150, screenHeight / 2 - 80, 20, BLACK);
			}

			if (players[1].points >= win) {
				DrawText(FormatText("Winner: Player 2: %i points", players[1].points), GetScreenWidth() / 2 - 150, screenHeight / 2 - 130, 20, BLACK);
				DrawText(FormatText("Loser: Player 1: %i points", players[0].points), GetScreenWidth() / 2 - 150, screenHeight / 2  - 80, 20, BLACK);
			}

			DrawText("Press Enter to play again.", GetScreenWidth() / 2 - 150, screenHeight / 2 + 50 , 20, BLACK);
			DrawText("Press Escape to leave the game.", GetScreenWidth() / 2 - 150, screenHeight / 2 + 70 , 20, BLACK);

			if (IsKeyPressed(KEY_ENTER)) {
				players[0].points = 0;
				players[1].points = 0;
				game();
			}
			EndDrawing();
		}
	}
}