#include "tasks.h"
#include "imageio.h"

void invert(int img[][MAX_W], const int &h, const int &w) {
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = invertNumber(img[row][col]);
    }
  }

  writeImage("taskA.pgm",out, h, w);
}

void invertRight(int img[][MAX_W], const int &h, const int &w) {
  int out[MAX_H][MAX_W];

  int firstRightIndex = rightHalfIndex(w);
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      if (col >= firstRightIndex) {
        out[row][col] = invertNumber(img[row][col]);
      } else {
        out[row][col] = img[row][col];
      }
    }
  }

  writeImage("taskB.pgm",out, h, w);
}

int invertNumber(int num) {
  int distFrom255 = 255 - num;
  if (num > distFrom255) {
    return distFrom255;
  }
  return 255 - num;
}

int rightHalfIndex(int width) {
  return width/2 + 1;
}

int middleStartIndex(int size) {
  return size/4;
}

int middleEndIndex(int size) {
  return size - (size/4);
}