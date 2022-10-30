#include "tasks.h"
#include "imageio.h"

void invert(const std::string& fileName) {
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(fileName, img, h, w);
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = invertNumber(img[row][col]);
    }
  }

  writeImage("taskA.pgm",out, h, w);
}

int invertNumber(int num) {
  int distFrom255 = 255 - num;
  if (num > distFrom255) {
    return distFrom255;
  }
  return 255 - num;
}