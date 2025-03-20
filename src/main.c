#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <raylib.h>

#define WINW 800
#define WINH 600
#define FPS 60

#define ARRAY_LEN(xs) sizeof(xs) / sizeof(xs[0])

uint32_t global_frames[1024] = {0};
size_t global_frames_count = 0;

void callback(void *bufferData, unsigned int frames)
{
  if (frames > ARRAY_LEN(global_frames))
  {
    frames = ARRAY_LEN(global_frames);
  }
  memcpy(global_frames, bufferData, sizeof(int32_t) * frames);
  global_frames_count = frames;
}

int main(void)
{
  /*------------------Initialization-------------------------*/

  float volume = 1.0f;
  InitWindow(WINW, WINH, "Musializer");
  SetTargetFPS(FPS);

  InitAudioDevice();
  Music music = LoadMusicStream("src/Valentine.ogg");

  assert(music.stream.sampleSize == 16);
  assert(music.stream.channels == 2);
  printf("music.frameCount = %u\n", music.frameCount);
  printf("music.stream.sampleRate = %u\n", music.stream.sampleRate);
  printf("music.stream.sampleSize = %u\n", music.stream.sampleSize);
  printf("music.stream.channels = %u\n", music.stream.channels);

  PlayMusicStream(music);
  SetMusicVolume(music, volume);
  AttachAudioStreamProcessor(music.stream, callback);

  while (!WindowShouldClose())
  {
    UpdateMusicStream(music);

    if (IsKeyPressed(KEY_SPACE))
    {
      if (IsMusicStreamPlaying(music))
      {
        PauseMusicStream(music);
      }
      else
      {
        ResumeMusicStream(music);
      }
    }
    else if (IsKeyPressed(KEY_Q))
    {
      CloseWindow();
    }

    int w = GetRenderWidth();
    int h = GetRenderHeight();

    BeginDrawing();
    ClearBackground(CLITERAL(Color){0x18, 0x18, 0x18, 0xff});
    float cellWidth = (float)w / global_frames_count;
    for (size_t i = 0; i < global_frames_count; i++)
    {
      int16_t sample = *(uint16_t *)&global_frames[i];
      if (sample > 0)
      {
        float t = (float)sample / INT16_MAX;
        DrawRectangle(i * cellWidth, h / 2 - h / 2 * t, cellWidth, h / 2 * t, RED);
      }
      else
      {
        float t = (float)sample / INT16_MIN;
        DrawRectangle(i * cellWidth, h / 2, cellWidth, h / 2 * t, RED);
      }
    }
    // if (global_frames_count > 0)
    //   exit(1);
    EndDrawing();
  }

  return 0;
}
