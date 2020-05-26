#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.h"

using namespace std;
using namespace sf;

float distance(CircleShape shape1, CircleShape shape2);
float gravityPower(float m1, float m2, float r);
Vector2f reflection(CircleShape shape1, CircleShape shape2);
//void changing_Mode(char i, vector<Ball> &ball, int &mode);
