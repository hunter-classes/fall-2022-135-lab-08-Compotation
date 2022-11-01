#include <iostream>

#include "imageio.h"
#include "tasks.h"

int main()
{
  std::string input = "image1.pgm";
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w); // read it from the file "inImage.pgm"

  int catImg[MAX_H][MAX_W];
  int catH, catW;
  readImage("cat.pgm", catImg, catH, catW);

  invert(img, h, w);
  invertRight(img, h, w);
  box(img, h, w);
  frame(img, h, w);
  scale(catImg, catH, catW);
  pixelate(img, h, w);
  return 0;
}
