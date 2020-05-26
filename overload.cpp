#include "overload.h"
#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
//using namespace sf;

ostream & operator<<(ostream & s, const sf::Vector2f & v)
{
	return s << v.x << ' ' << v.y;
}
