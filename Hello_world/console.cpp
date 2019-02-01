#include "pch.h"
#include "console.h"
#include "preferences.h"

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

void console(bool window)
{
	string input;
	string value_string;
	string command;
	int value;

	while (window)
	{
		getline(cin, input);

		istringstream stream(input);
		stream >> command >> value_string;

		if (command == "FPS")
		{
			if (value_string.size() > 0)
			{
				value = stoi(value_string);
				FPS = value;
				cout << "Game is now " << FPS << " FPS" << endl;
				OPTION = 1;
			}
		}
		if (command == "GRAVITYPOW")
		{
			if (value_string.size() > 0)
			{
				value = stoi(value_string);
				GRAVITAIONAL_CONSTANT_POW = value;
				cout << "Gravitional constant pow is now: " << GRAVITAIONAL_CONSTANT_POW << endl;
				OPTION = 2;
			}
		}
		if (command == "GROUNDPOW")
		{
			if (value_string.size() > 0)
			{
				value = stoi(value_string);
				GROUND_MASS_POW = value;
				cout << "Ground mass pow is now: " << GROUND_MASS_POW << endl;
				OPTION = 3;
			}
		}
	}
}