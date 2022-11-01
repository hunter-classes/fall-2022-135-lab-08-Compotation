#pragma once
#include <string>
#include "imageio.h"

void invert(int img[][MAX_W], const int &h, const int &w);
int invertNumber(int num);
int rightHalfIndex(int width);
void invertRight(int img[][MAX_W], const int &h, const int &w);
int middleStartIndex(int size);
int middleEndIndex(int size);
void box(int img[][MAX_W], const int &h, const int &w);
void frame(int img[][MAX_W], const int &h, const int &w);
void scale(int img[][MAX_W], const int &h, const int &w);
void print2DArray(int arr[][MAX_W], int h, int w);
