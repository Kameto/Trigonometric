#pragma once
// include(template)
#include <array>
#include <DxLib.h>
#include <math.h>
#include <string>

// include (nomal)
#include "Keyboard.h"

// define(consatant)
#define WIND_W		 960
#define WIND_H		 540
#define GRAPHSIZE	 32
#define FONTSIZE	 16
#define PI			 3.14159265359
#define White		 0xFFFFFF
#define Black		 0x00000
#define Red			 0xFF0000
#define Green		 0x00FF00
#define Blue		 0x0000FF

// define(function)
#define Release(x) { if((x) != nullptr){ delete (x); (x) = nullptr; } }

// usingspace
using namespace std;