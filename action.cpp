#include "pch.h"

#include"action.h"
#include "Ball.h"

#include <iostream>
#include <SFML/Window.hpp>
#include <vector>

using namespace sf;
using namespace std;




void set_ball(int mode, Vector2f playerCenter, Vector2f aimDirNorm, Vector2f mousePosWindow, Ball b1, vector<Ball> &ball,bool &gravityMouse, Vector2f &groundDir, Keyboard::Key keyboard, Mouse::Button mouse)
{
		switch (mode)
		{
			
		case 0: //Gravity
			if (keyboard == Keyboard::Z)
			{
				b1.shape.setPosition(playerCenter);
				b1.currVelocity = { 0,0 };
				b1.shape.setFillColor(Color::Yellow);
				b1.mass = 10000;
				ball.push_back(Ball(b1));
			}
			if (keyboard == Keyboard::X)
			{
				b1.shape.setPosition(playerCenter);
				b1.currVelocity = { 0,0 };
				b1.shape.setRadius(10.f);
				b1.shape.setFillColor(Color::Color(253, 106, 2, 255));
				b1.mass = 1000;
				ball.push_back(Ball(b1));
			}
			if (mouse == Mouse::Left)
			{
				gravityMouse = !gravityMouse;
				if (gravityMouse == true) cout << "Gravitymouse activated!" << endl;
				else cout << "Gravitymouse deactivated!" << endl;
			}
			break;

		case 1: //Collision
			if (keyboard == Keyboard::Z)
			{
				b1.shape.setPosition(playerCenter);
				b1.currVelocity = aimDirNorm * b1.maxSpeed;
				b1.shape.setFillColor(Color::Yellow);
				b1.mass = 10;
				ball.push_back(Ball(b1));
			}
			if (keyboard == Keyboard::X)
			{
				b1.shape.setPosition(playerCenter);
				b1.shape.setRadius(10.f);
				b1.currVelocity = aimDirNorm * b1.maxSpeed;
				b1.shape.setFillColor(Color::Color(253, 106, 2, 255));
				b1.mass = 100;
				ball.push_back(Ball(b1));
			}
			break;
			
		case 2: //Bounce
			if (mouse == Mouse::Left)
			{
				b1.shape.setPosition(mousePosWindow);
				b1.shape.setRadius(10.f);
				b1.currVelocity = { 0,0 };
				b1.shape.setFillColor(Color::Yellow);
				b1.mass = 10;
				ball.push_back(Ball(b1));
			}
			if (mouse == Mouse::Right)
			{
				b1.shape.setPosition(mousePosWindow);
				b1.shape.setRadius(30.f);
				b1.currVelocity = { 0,0 };
				b1.shape.setFillColor(Color::Yellow);
				b1.mass = 100;
				ball.push_back(Ball(b1));
			}
			if (keyboard == Keyboard::Up)
			{
				groundDir = { 0.f, -1.f };
				EARTH_CENTER_DISTANCE = (float)WINDOW_SIZE_Y;
				cout << "Gravity is now upper wall!" << endl;
			}
			if (keyboard == Keyboard::Down)
			{
				groundDir = { 0.f, 1.f };
				EARTH_CENTER_DISTANCE = (-1)*(float)WINDOW_SIZE_Y;
				cout << "Gravity is now bottom wall!" << endl;
			}
			if (keyboard == Keyboard::Left)
			{
				groundDir = { -1.f, 0.f };
				EARTH_CENTER_DISTANCE = (-1)*(float)WINDOW_SIZE_X;
				cout << "Gravity is now left wall!" << endl;
			}
			if (keyboard == Keyboard::Right)
			{
				groundDir = { 1.f, 0.f };
				EARTH_CENTER_DISTANCE = (float)WINDOW_SIZE_X;
				cout << "Gravity is now right wall!" << endl;
			}
			if (keyboard == Keyboard::Space)
			{
				groundDir = { 0.f, 0.f };
				cout << "Gravity is off" << endl;
			}
			break;
		case 3: //Antigravity
			if (keyboard == Keyboard::Z)
			{
				b1.shape.setPosition(playerCenter);
				b1.currVelocity = { 0,0 };
				b1.shape.setFillColor(Color::Yellow);
				b1.mass = 10;
				ball.push_back(Ball(b1));
			}
			if (keyboard == Keyboard::X)
			{
				b1.shape.setPosition(playerCenter);
				b1.currVelocity = { 0,0 };
				b1.shape.setRadius(10.f);
				b1.shape.setFillColor(Color::Color(253, 106, 2, 255));
				b1.mass = 100;
				ball.push_back(Ball(b1));
			}
			if (mouse == Mouse::Left)
			{
				gravityMouse = !gravityMouse;
				if (gravityMouse == true) cout << "Gravitymouse activated!" << endl;
				else cout << "Gravitymouse deactivated!" << endl;
			}
			break;
			
		default:
			b1.shape.setPosition(playerCenter);
			b1.currVelocity = { 0,0 };
			b1.shape.setRadius(10.f);
			b1.shape.setFillColor(Color::Color(253, 106, 2, 255));
			b1.mass = 100;
			ball.push_back(Ball(b1));
			break;
		}
	
}


