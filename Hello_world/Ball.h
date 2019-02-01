#pragma once
#include<SFML/Graphics.hpp>
#include "preferences.h"



using namespace sf;

  class Ball 
{
public:
	Ball(float radius = 4.f);
	Ball() = delete;
	~Ball() = default;
	
	
		
	//Zmienne
	sf::CircleShape shape;
	sf::Vector2f currVelocity;
	sf::Vector2f gravityVelocity;
	float maxSpeed;
	float mass;

	//Funkcje
	float left();
	float right();
	float top();
	float bottom();
	void update();
	float velocity();
	

  };

