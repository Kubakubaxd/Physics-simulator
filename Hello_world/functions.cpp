#include "pch.h"
#include "functions.h"
#include "preferences.h"

#include <math.h>
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

float distance(CircleShape shape1, CircleShape shape2)
{
	float x = (shape1.getPosition().x + shape1.getRadius()) - (shape2.getPosition().x + shape2.getRadius());
	float y = (shape1.getPosition().y + shape1.getRadius()) - (shape2.getPosition().y + shape2.getRadius());
	float z = sqrt(pow(x, 2) + pow(y, 2));
	return z;
}

float gravityPower(float m1, float m2, float r)
{
	return GRAVITAIONAL_CONSTANT * ((m1 * m2) / pow(r, 2));
}

Vector2f reflection(CircleShape shape1, CircleShape shape2)
{
	Vector2f reflect;
	reflect.x = shape1.getPosition().x + -shape2.getPosition().x;
	reflect.y = shape1.getPosition().y + -shape2.getPosition().y;
	reflect = reflect / (sqrt(pow(reflect.x, 2) + pow(reflect.y, 2)));
	return reflect;
}

