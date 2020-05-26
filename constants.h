#pragma once

#include<SFML/Graphics.hpp>
using namespace sf;

//Sta³e które nigdy sie nie zmieniaj¹


Vector2f CONST_DOWN = { 0.f, 1.f };
Vector2f CONST_UP = { 0.f, -1.f };
Vector2f CONST_LEFT = { -1.f, 0.f };
Vector2f CONST_RIGHT = { 1.f, 0.f };
Vector2f CONST_ZERO = { 0.f, 0.f };


const float PLAYER_SIZE = 15.f;

enum MODE
{
	GRAVITY ,
	COLLISION,
	BOUNCE ,
	ANTI_GRAVITY 
};

