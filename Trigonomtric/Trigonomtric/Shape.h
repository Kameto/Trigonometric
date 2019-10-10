#pragma once
#include "DefSetting.h"

typedef enum ShapeForm
{
	mCircle, mTriangle, mBox
}SF;

struct Point
{
	double x;
	double y;
};

class Shape
{
public:
	Shape();
	Shape(SF form, int _size);
	~Shape();
	void Update();
	void Draw();

	// Shape Form
	SF thisForm;

	// triangle
	array<Point, 3>tPoint;

	// box
	array<Point, 4>bPoint;

	// general
	Point center;	// �}�`���S���W
	Point start;	// �N�_���W
	double range;	// �N�_����̋���
	int size;		// �}�`�T�C�Y
	int angle;		// �p�x
};