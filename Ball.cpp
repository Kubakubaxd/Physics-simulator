#include "pch.h"
#include "Ball.h"


#include "preferences.h"
#include<SFML/Graphics.hpp>
using namespace sf;


Ball::Ball(float radius) : currVelocity(0.f, 0.f), maxSpeed(5.f), mass(10.f)
{
	this->shape.setRadius(radius);
	this->shape.setFillColor(Color::Red);
}


//Prêdkoœæ potrzebna do obliczeñ
float Ball::velocity()
{
	return sqrt(pow(Ball::currVelocity.x, 2) + pow(Ball::currVelocity.y, 2));
}



//Wyliczanie boków
float Ball::left()
{
	return this->Ball::shape.getPosition().x;
}
float Ball::right()
{
	return this->Ball::shape.getPosition().x + 2 * Ball::shape.getRadius();
}

float Ball::top()
{
	return this->Ball::shape.getPosition().y;
}

float Ball::bottom()
{
	return this->Ball::shape.getPosition().y + 2 * Ball::shape.getRadius();
}

//Zderzenia od œcian
void Ball::update()
{
	Ball::shape.move(this->Ball::currVelocity); //przekazujemy wektor predkosci

	if (this->left() < 0)			//sprawdzanie krawedzi i zmiana wektora
	{
		Ball::shape.setPosition(0, Ball::shape.getPosition().y);
		currVelocity.x = -currVelocity.x;
	}
	else if (this->right() > WINDOW_SIZE_X)
	{
		Ball::shape.setPosition(WINDOW_SIZE_X - 2 * Ball::shape.getRadius(), Ball::shape.getPosition().y);
		Ball::currVelocity.x = -Ball::currVelocity.x;
	}

	if (this->top() < 0)
	{
		Ball::shape.setPosition(Ball::shape.getPosition().x, 0);
		Ball::currVelocity.y = -Ball::currVelocity.y;
	}
	else if (this->bottom() > WINDOW_SIZE_Y)
	{
		Ball::shape.setPosition(Ball::shape.getPosition().x, WINDOW_SIZE_Y - 2 * Ball::shape.getRadius());
		Ball::currVelocity.y = -Ball::currVelocity.y;
	}
}







