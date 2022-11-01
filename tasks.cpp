#include "tasks.h"
#include "imageio.h"
#include <iostream>
#include <cmath>

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

void box(int img[][MAX_W], const int &h, const int &w) {
  int startCol = middleStartIndex(w);
  int endCol = middleEndIndex(w);
  int startRow = middleStartIndex(h);
  int endRow = middleEndIndex(h);

  int out[MAX_H][MAX_W];
  for (int row = 0; row < h; row++) {
    for (int col = 0; col < w; col++) {
      if (row < endRow && row >= startRow && col < endCol && col >= startCol) {
        out[row][col] = 255;
      } else {
        out[row][col] = img[row][col];
      }
    }
  }
  writeImage("taskC.pgm",out, h, w);
}

void frame(int img[][MAX_W], const int &h, const int &w) {
  int startCol = middleStartIndex(w);
  int endCol = middleEndIndex(w);
  int startRow = middleStartIndex(h);
  int endRow = middleEndIndex(h);

  int out[MAX_H][MAX_W];
  for (int row = 0; row < h; row++) {
    for (int col = 0; col < w; col++) {
      if ((row <= endRow && row >= startRow && col <= endCol && col >= startCol) && (row == startRow || row == endRow || col == startCol || col == endCol)) {
          out[row][col] = 255;
      } else {
        out[row][col] = img[row][col];
      }
    }
  }
  writeImage("taskD.pgm", out, h, w);
}

void scale(int img[][MAX_W], const int &h, const int &w) {
  int out[MAX_H][MAX_W];
  int originalRow = 0;
  int originalColumn = 0;
  int newHeight = h*2;
  int newWidth = w*2;
  for (int row = 0; row < h; row++) {
    for (int col = 0; col < w; col++) {
      out[2*row][2*col] = img[row][col];
      out[2*row][2*col + 1] = img[row][col];
      out[2*row + 1][2*col] = img[row][col];
      out[2*row + 1][2*col + 1] = img[row][col];
    }
  }
  writeImage("taskE.pgm", out, newHeight, newWidth);
}

void pixelate(int img[][MAX_W], const int &h, const int &w) {
  int out[MAX_H][MAX_W];
  for (int row = 0; row < h; row+=2) {
    for (int col = 0; col < w; col+=2) {
      int avg = average4(img[row][col], img[row][col+1], img[row+1][col], img[row+1][col+1]);
      out[row][col] = avg;
      out[row][col+1] = avg;
      out[row+1][col] = avg;
      out[row+1][col+1] = avg;
    }
  }
  writeImage("taskF.pgm", out, h, w);
}

int average4(int a, int b, int c, int d) {
  return round((a + b + c + d)/4.0);
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

void print2DArray(int arr[][MAX_W], int h, int w) {
  for (int row = 0; row < h; row++) {
    for (int col = 0; col < w; col++) {
      std::cout << arr[row][col] << " ";
    }
    std::cout << "\n";
  }
}