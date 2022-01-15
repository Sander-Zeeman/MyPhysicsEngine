#pragma once
#include "Vector.h"

void addn_Vec2(Vec2 *v, const float n);
void addn_iVec2(iVec2 *v, const int n);
void addn_Vec3(Vec3 *v, const float n);
void addn_iVec3(iVec3 *v, const int n);

void add_Vec2(Vec2 *v1, const Vec2 v2);
void add_iVec2(iVec2 *v1, const iVec2 v2);
void add_Vec3(Vec3 *v1, const Vec3 v2);
void add_iVec3(iVec3 *v1, const iVec3 v2);

void subn_Vec2(Vec2 *v, const float n);
void subn_iVec2(iVec2 *v, const int n);
void subn_Vec3(Vec3 *v, const float n);
void subn_iVec3(iVec3 *v, const int n);

void sub_Vec2(Vec2 *v1, const Vec2 v2);
void sub_iVec2(iVec2 *v1, const iVec2 v2);
void sub_Vec3(Vec3 *v1, const Vec3 v2);
void sub_iVec3(iVec3 *v1, const iVec3 v2);

void multn_Vec2(Vec2 *v, const float n);
void multn_iVec2(iVec2 *v, const int n);
void multn_Vec3(Vec3 *v, const float n);
void multn_iVec3(iVec3 *v, const int n);

void mult_Vec2(Vec2 *v1, const Vec2 v2);
void mult_iVec2(iVec2 *v1, const iVec2 v2);
void mult_Vec3(Vec3 *v1, const Vec3 v2);
void mult_iVec3(iVec3 *v1, const iVec3 v2);

void divn_Vec2(Vec2 *v, const float n);
void divn_iVec2(iVec2 *v, const int n);
void divn_Vec3(Vec3 *v, const float n);
void divn_iVec3(iVec3 *v, const int n);

void div_Vec2(Vec2 *v1, const Vec2 v2);
void div_iVec2(iVec2 *v1, const iVec2 v2);
void div_Vec3(Vec3 *v1, const Vec3 v2);
void div_iVec3(iVec3 *v1, const iVec3 v2);
