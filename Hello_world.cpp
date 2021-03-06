//Zrobioine przeciążenie >> na samym dole
//Threads
//


#include "pch.h"
#include "preferences.h"
#include "constants.h"
#include "Ball.h"
#include "action.h"
#include "functions.h"
#include "overload.h"
#include "console.h"

#include<SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
//#include <sstream>
//#include <string>
#include <math.h>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace sf;
using namespace std;
using namespace std::chrono;

//Zmiana trybów
void changing_Mode(char i, vector<Ball> &ball, int &mode)
{
	switch (i)
	{
	case GRAVITY:
		mode = MODE::GRAVITY;
		cout << "Gravity mode activated   ||   Z,X - Ball   ||   Arrow UP/DOWN - Increase/decrease gravity of mouse" << endl;
		ball.clear(); // Czyszczenie zawartosci 
		break;
	case COLLISION:
		mode = MODE::COLLISION;
		cout << "Collision mode activated   ||   Z,X - Ball" << endl;
		ball.clear();
		break;
	case BOUNCE:
		mode = MODE::BOUNCE;
		cout << "Bounce mode activated   || LMB,RMB - Ball   ||   Arrow UP/DOWN/LEFT/RIGHT - Direction of gravity   ||   Space - No gravity" << endl;
		ball.clear();
		break;
	case ANTI_GRAVITY:
		mode = MODE::ANTI_GRAVITY;
		cout << "Gravity mode activated   ||   Z,X - Ball   ||   Arrow UP/DOWN - Increase/decrease gravity of mouse" << endl;
		ball.clear();
		break;
	default:
		cout << "Błąd trybu!" << endl;
		break;
	}
}


int main()
{
	//Czas do klikania
	srand(time(NULL));
	steady_clock::time_point t1 = steady_clock::now();

	//Okno
	RenderWindow window{ VideoMode{WINDOW_SIZE_X, WINDOW_SIZE_Y}, "Ball Simulator" };
	window.setFramerateLimit(FPS);

	//Gracz
	CircleShape player(PLAYER_SIZE);
	player.setFillColor(Color::White);

	//Pilki
	vector<Ball> ball;
	Ball b1(4.f);

	//Vektory i zmienne
	Vector2f playerCenter;
	Vector2f mousePosWindow;
	Vector2f aimDir;
	Vector2f aimDirNorm;
	Vector2f mouseDir;
	Vector2f direction;
	float groundDistance;
	Vector2f groundDir = CONST_ZERO;
	float groundMass = GROUND_MASS;
	bool gravityMouse = false;
	float mouseDistance;
	float mouseGravity = 5 * pow(10, 9);
	int mode = 1;				//tryb


	//Wątek wprowadzania do konsoli
	thread th1(console, window.isOpen());
	th1.detach();

	//Czas
	duration<double> time_span;

	while (window.isOpen())
	{

		//Zamykanie
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
				break;
			}
		}

		//Aktualizacja opcji
		switch (OPTION)
		{
		case 1:
			window.setFramerateLimit(FPS);
			OPTION = 0;
			break;
		case 2:
			OPTION = 0;
			GRAVITAIONAL_CONSTANT = 6.67 * pow(10, GRAVITAIONAL_CONSTANT_POW);
			break;
		case 3:
			OPTION = 0;
			groundMass = 5.9 * pow(10, GROUND_MASS_POW);

		default:
			break;
		}

		//Mysz i gracz
		playerCenter = Vector2f(player.getPosition().x + player.getRadius(),
			player.getPosition().y + player.getRadius());
		mousePosWindow = sf::Vector2f(Mouse::getPosition(window));
		aimDir = mousePosWindow - playerCenter;
		aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));

		//Obsługa Input
		steady_clock::time_point t2 = steady_clock::now(); // Czas

		time_span = duration_cast<duration<double>>(t2 - t1); //Różnica czasu
		if (Keyboard::isKeyPressed(Keyboard::Z) && time_span.count() > .2f)
		{
			t1 = t2;
			set_ball(mode, playerCenter, aimDirNorm, mousePosWindow, b1, ball, gravityMouse, groundDir, Keyboard::Z, Mouse::Middle);
		}
		time_span = duration_cast<duration<double>>(t2 - t1);
		if (Keyboard::isKeyPressed(Keyboard::X) && time_span.count() > .2f)
		{
			t1 = t2;
			set_ball(mode, playerCenter, aimDirNorm, mousePosWindow, b1, ball, gravityMouse, groundDir, Keyboard::X, Mouse::Middle);
		}
		time_span = duration_cast<duration<double>>(t2 - t1);
		if (Keyboard::isKeyPressed(Keyboard::Up) && time_span.count() > .2f)
		{
			t1 = t2;
			set_ball(mode, playerCenter, aimDirNorm, mousePosWindow, b1, ball, gravityMouse, groundDir, Keyboard::Up, Mouse::Middle);
		}
		time_span = duration_cast<duration<double>>(t2 - t1);
		if (Keyboard::isKeyPressed(Keyboard::Down) && time_span.count() > .2f)
		{
			t1 = t2;
			set_ball(mode, playerCenter, aimDirNorm, mousePosWindow, b1, ball, gravityMouse, groundDir, Keyboard::Down, Mouse::Middle);
		}
		time_span = duration_cast<duration<double>>(t2 - t1);
		if (Keyboard::isKeyPressed(Keyboard::Left) && time_span.count() > .2f)
		{
			set_ball(mode, playerCenter, aimDirNorm, mousePosWindow, b1, ball, gravityMouse, groundDir, Keyboard::Left, Mouse::Middle);
			t1 = t2;
		}
		time_span = duration_cast<duration<double>>(t2 - t1);
		if (Keyboard::isKeyPressed(Keyboard::Right) && time_span.count() > .2f)
		{
			t1 = t2;
			set_ball(mode, playerCenter, aimDirNorm, mousePosWindow, b1, ball, gravityMouse, groundDir, Keyboard::Right, Mouse::Middle);
		}
		time_span = duration_cast<duration<double>>(t2 - t1);
		if (Keyboard::isKeyPressed(Keyboard::Delete) && time_span.count() > .2f)
		{
			t1 = t2;
			set_ball(mode, playerCenter, aimDirNorm, mousePosWindow, b1, ball, gravityMouse, groundDir, Keyboard::Delete, Mouse::Middle);
		}
		time_span = duration_cast<duration<double>>(t2 - t1);
		if (Mouse::isButtonPressed(Mouse::Left) && time_span.count() > .2f)
		{
			t1 = t2;
			set_ball(mode, playerCenter, aimDirNorm, mousePosWindow, b1, ball, gravityMouse, groundDir, Keyboard::B, Mouse::Left);
		}
		time_span = duration_cast<duration<double>>(t2 - t1);
		if (Mouse::isButtonPressed(Mouse::Right) && time_span.count() > .2f)
		{
			t1 = t2;
			set_ball(mode, playerCenter, aimDirNorm, mousePosWindow, b1, ball, gravityMouse, groundDir, Keyboard::B, Mouse::Right);
		}
		time_span = duration_cast<duration<double>>(t2 - t1);	//TRYBY
		if (Keyboard::isKeyPressed(Keyboard::F1) && time_span.count() > .2f)
		{
			t1 = t2;
			changing_Mode(MODE::GRAVITY, ball, mode);
		}
		if (Keyboard::isKeyPressed(Keyboard::F2) && time_span.count() > .2f)
		{
			t1 = t2;
			changing_Mode(MODE::COLLISION, ball, mode);
		}
		if (Keyboard::isKeyPressed(Keyboard::F3) && time_span.count() > .2f)
		{
			t1 = t2;
			changing_Mode(MODE::BOUNCE, ball, mode);
		}
		if (Keyboard::isKeyPressed(Keyboard::F4) && time_span.count() > .2f)
		{
			t1 = t2;
			changing_Mode(MODE::ANTI_GRAVITY, ball, mode);
		}

		if (Keyboard::isKeyPressed(Keyboard::A))	//Ruch gracza
			player.move(-10.f, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::D))
			player.move(10.f, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::W))
			player.move(0.f, -10.f);
		if (Keyboard::isKeyPressed(Keyboard::S))
			player.move(0.f, 10.f);

		//Rysowanie gracza i czyszczenie okna
		window.clear();
		window.draw(player);

		//Petla fizyki odbic i grawitacji
		for (size_t i = 0; i < ball.size(); i++)
		{
			if (mode == MODE::COLLISION || mode == MODE::BOUNCE) //Zderzenia
			{
				for (size_t j = 0; j < ball.size(); j++)
				{
					if (i != j)
					{
						if (distance(ball[i].shape, ball[j].shape) < ball[i].shape.getRadius() + ball[j].shape.getRadius())
						{
							direction = reflection(ball[i].shape, ball[j].shape); //Kierunek zderzenia kul
							ball[i].currVelocity = (direction * (((ball[i].velocity()* (ball[i].mass - ball[j].mass)) + (2 * ball[j].mass * ball[j].velocity())) / (ball[i].mass + ball[j].mass)));
						}
					}
				}
			}
			//Grawitacyjna myszka
			if (gravityMouse == true && mode == MODE::GRAVITY)
			{
				mouseDistance = sqrt(pow(mousePosWindow.x - ball[i].shape.getPosition().x, 2) + pow(mousePosWindow.y - ball[i].shape.getPosition().y, 2)); //Odległość od myszy
				mouseDir = (mousePosWindow - ball[i].shape.getPosition()) / mouseDistance; // Kierunek myszy 

				ball[i].gravityVelocity = mouseDir * gravityPower(ball[i].mass, mouseGravity, mouseDistance);
			}

			if (gravityMouse == true && mode == MODE::ANTI_GRAVITY)
			{
				mouseDistance = sqrt(pow(mousePosWindow.x - ball[i].shape.getPosition().x, 2) + pow(mousePosWindow.y - ball[i].shape.getPosition().y, 2)); //Odległość od myszy
				mouseDir = (mousePosWindow - ball[i].shape.getPosition()) / mouseDistance; // Kierunek myszy 

				ball[i].gravityVelocity = -mouseDir * gravityPower(ball[i].mass, mouseGravity, mouseDistance);
			}

			if (mode == MODE::BOUNCE)
			{
				groundDistance = (GROUND_POS - ball[i].shape.getPosition().y) + EARTH_CENTER_DISTANCE;
				ball[i].gravityVelocity = groundDir * gravityPower(ball[i].mass, groundMass, groundDistance);
			}
			//Podsumowanie
			ball[i].currVelocity = ball[i].currVelocity + ball[i].gravityVelocity; //Sumowanie sił	
			ball[i].update();  //Odbicia
			ball[i].shape.move(ball[i].currVelocity);	//Ruch kul
			window.draw(ball[i].shape);					// Rysowanie kul
			//cout << ball[i].currVelocity << endl; // Przeciążenie operatora
		}
		window.display();
	}

	return 0;
}
