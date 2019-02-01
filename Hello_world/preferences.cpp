#include "pch.h"
#include "preferences.h"
#include <math.h>


unsigned int OPTION = 0;
//Zmienne ustawiane przez u¿ytkowania
unsigned int WINDOW_SIZE_X = 800;
unsigned int WINDOW_SIZE_Y = 600;
unsigned int FPS = 60;
int GROUND_MASS_POW = 12;
float GROUND_MASS = 5.9 * pow(10, GROUND_MASS_POW);

int GRAVITAIONAL_CONSTANT_POW = -11;
float GRAVITAIONAL_CONSTANT = 6.67 * pow(10, GRAVITAIONAL_CONSTANT_POW);

//Zmienne nie ustawiane przez u¿ytkownika, zale¿ne od ustawieñ powy¿ej
float GROUND_POS = (float)WINDOW_SIZE_Y;
float EARTH_CENTER_DISTANCE = (float)WINDOW_SIZE_Y;


