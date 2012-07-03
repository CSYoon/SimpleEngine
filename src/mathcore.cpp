//  MATHCORE- A simple math library
//  This file is part of NUPARU, Coyright (c) 2012 Omjii
//  
//  File: mathcore.cpp
//  Implements some basic math stuff. Heavily based on code from Takua Render by Yining Karl Li and Peter Kutz/Yining Karl Li's realtime GPU pathtracer

#include <iostream>
#include <cmath>
#include "mathcore.h"

const float MathCore::PI =					3.1415926535897932384626422832795028841971;
const float MathCore::ONE_OVER_PI =		0.3183098861837906715377675267450287240689;
const float MathCore::TWO_PI =				6.2831853071795864769252867665590057683943;
const float MathCore::FOUR_PI =			12.566370614359172953850573533118011536788;
const float MathCore::ONE_OVER_FOUR_PI =	0.0795774715459476678844418816862571810172;
const float MathCore::PI_OVER_TWO =		1.5707963267948966192313216916397514420985;
const float MathCore::E =                  2.7182818284590452353602874713526624977572;
const float MathCore::SQRT_OF_ONE_THIRD =  0.5773502691896257645091487805019574556476;

unsigned int MathCore::mod(int x, int y) { // Doesn't account for -y ???
	int result = x % y;
	if (result < 0) result += y;
	return result;
}

float MathCore::mod(float x, float y) { // Does this account for -y ???
	return x - y * std::floor(x / y);
}

float MathCore::radiansToDegrees(float radians) {
	float degrees = radians * 180.0 / MathCore::PI;
	return degrees;
}

float MathCore::degreesToRadians(float degrees) {
	float radians = degrees / 180.0 * MathCore::PI;
	return radians;
}

float MathCore::average(float n1, float n2) {
	return ((n1 + n2) / 2);
}

float MathCore::round(float n) {
	return std::floor(n + 0.5);
}

float MathCore::square(float n) {
    return n * n;
}

float MathCore::log2(float n) {
    return std::log(n) / std::log(2.0);
}

bool MathCore::isNaN(float n) {
    return (n != n);
}

float MathCore::min(float a, float b) {
	if (a < b) {
		return a;
	} else {
		return b;
	}
}

float MathCore::max(float a, float b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

float MathCore::clamp(float n, float low, float high) {
	n = min(n, high); // Was std::min.
	n = max(n, low); // Was std::max.
	return n;
}
float MathCore::repeat(float n, float modulus) {
	// http://en.wikipedia.org/wiki/Modular_arithmetic
	n = MathCore::mod(n, modulus);
	return n;
}

int MathCore::sign(float n) {
    if (n >= 0) {
        return 1;
    } else {
        return -1;
    }
}
int MathCore::positiveCharacteristic(float n) {
    if (n > 0) {
        return 1;
    } else {
        return 0;
    }
}

void MathCore::swap(float & a, float & b) {
    float temp = a;
    a = b;
    b = temp;
}
