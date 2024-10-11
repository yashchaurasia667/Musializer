#include <stdio.h>
#include <raylib.h>

#define WINW 800
#define WINH 600
#define FPS 60

int main(void)
{
  InitWindow(WINW, WINH, "Musializer");
  SetTargetFPS(FPS);

  InitAudioDevice();
  Music music = LoadMusicStream("Valentine.ogg");
  PlayMusicStream(music);

  while (!WindowShouldClose())
  {
    UpdateMusicStream(music);

    BeginDrawing();
    ClearBackground(RED);
    EndDrawing();
  }

  return 0;
}