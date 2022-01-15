#pragma once
#include "Vector.h"

Vec2 *create_Vec2(const float x, const float y);
iVec2 *create_iVec2(const int x, const int y);
Vec3 *create_Vec3(const float x, const float y, const float z);
iVec3 *create_iVec3(const int x, const int y, const int z);

void print_Vec2(const Vec2 v);
void print_iVec2(const iVec2 v);
void print_Vec3(const Vec3 v);
void print_iVec3(const iVec3 v);

float length_Vec2(const Vec2 v);
int length_iVec2(const iVec2 v);
float length_Vec3(const Vec3 v);
int length_iVec3(const iVec3 v);

void norm_Vec2(Vec2 *v);
void norm_Vec3(Vec3 *v);
