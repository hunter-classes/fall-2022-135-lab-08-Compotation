#include <iostream>

#include "imageio.h"
#include "tasks.h"

int main()
{
  std::string input = "taskB-input.pgm";
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w); // read it from the file "inImage.pgm"

  invert(img, h, w);
  invertRight(img, h, w);
  box(img, h, w);
  frame(img, h, w);
  scale(img, h, w);
  pixelate(img, h, w);
  return 0;
}
