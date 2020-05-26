#pragma once
#include "Ball.h"

#include <SFML/Window.hpp>
#include <vector>

using namespace std;


void set_ball(int mode, Vector2f playerCenter, Vector2f aimDirNorm, Vector2f mousePosWindow, Ball b1, vector<Ball> &ball, bool &gravityMouse, Vector2f &groundDir, Keyboard::Key keyboard, Mouse::Button mouse);