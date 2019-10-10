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
	Point center;	// 図形中心座標
	Point start;	// 起点座標
	double range;	// 起点からの距離
	int size;		// 図形サイズ
	int angle;		// 角度
};