#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

#define WINW 800
#define WINH 600
#define FPS 60

int main(void)
{
  // Initialization
  //--------------------------------------------------------------------------------------
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "raylib [audio] example - music playing (streaming)");

  InitAudioDevice(); // Initialize audio device

  Music music = LoadMusicStream("src/test.ogg");

  PlayMusicStream(music);

  float timePlayed = 0.0f; // Time played normalized [0.0f..1.0f]
  bool pause = false;      // Music playing paused

  SetTargetFPS(30); // Set our game to run at 30 frames-per-second
  //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    UpdateMusicStream(music); // Update music buffer with new stream data

    // Restart music playing (stop and play)
    if (IsKeyPressed(KEY_SPACE))
    {
      StopMusicStream(music);
      PlayMusicStream(music);
    }

    // Pause/Resume music playing
    if (IsKeyPressed(KEY_P))
    {
      pause = !pause;

      if (pause)
        PauseMusicStream(music);
      else
        ResumeMusicStream(music);
    }

    // Get normalized time played for current music stream
    timePlayed = GetMusicTimePlayed(music) / GetMusicTimeLength(music);

    if (timePlayed > 1.0f)
      timePlayed = 1.0f; // Make sure time played is no longer than music
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("MUSIC SHOULD BE PLAYING!", 255, 150, 20, LIGHTGRAY);

    DrawRectangle(200, 200, 400, 12, LIGHTGRAY);
    DrawRectangle(200, 200, (int)(timePlayed * 400.0f), 12, MAROON);
    DrawRectangleLines(200, 200, 400, 12, GRAY);

    DrawText("PRESS SPACE TO RESTART MUSIC", 215, 250, 20, LIGHTGRAY);
    DrawText("PRESS P TO PAUSE/RESUME MUSIC", 208, 280, 20, LIGHTGRAY);

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  UnloadMusicStream(music); // Unload music stream buffers from RAM

  CloseAudioDevice(); // Close audio device (music streaming is automatically stopped)

  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}