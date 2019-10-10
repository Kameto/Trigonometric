#include "Shape.h"

Shape::Shape()
{
	// shapeform
	thisForm = SF::mCircle;

	// triangle
	for (int i = 0; i < 3; i++)
	{
		tPoint[i].x = 0;
		tPoint[i].y = 0;
	}

	// box
	for (int i = 0; i < 4; i++)
	{
		bPoint[i].x = 0;
		bPoint[i].y = 0;
	}

	// deneral
	start.x	 = WIND_W / 2;
	start.y	 = WIND_H / 2;
	range	 = 0.0;
	center.x = start.x;
	center.y = start.y;
	size	 = 10;
	angle	 = 0;
}

Shape::Shape(SF form, int _size)
{
	// shapeform
	thisForm = form;

	// triangle
	for (int i = 0; i < 3; i++)
	{
		tPoint[i].x = 0;
		tPoint[i].y = 0;
	}

	// box
	for (int i = 0; i < 4; i++)
	{
		bPoint[i].x = 0;
		bPoint[i].y = 0;
	}

	// deneral
	start.x	 = 960 / 2;
	start.y	 = 540 / 2;
	center.x = 960 / 2;
	center.y = 540 / 2;
	range	 = 0.0;
	size	 = _size;
	angle	 = 0;
	
	// shapeSet
	switch (form)
	{
	case SF::mCircle:
		// Not Setting
		break;
	case SF::mTriangle:
		tPoint[0].x = start.x;
		tPoint[0].y = start.y - (size / 2);
		tPoint[1].x = start.x + (size / 2);
		tPoint[1].y = start.y + (size / 2);
		tPoint[2].x = start.x - (size / 2);
		tPoint[2].y = start.y + (size / 2);
		break;
	case SF::mBox:
		bPoint[0].x = start.x - (size / 2);
		bPoint[0].y = start.y - (size / 2);
		bPoint[1].x = start.x - (size / 2);
		bPoint[1].y = start.y + (size / 2);
		bPoint[2].x = start.x + (size / 2);
		bPoint[2].y = start.y - (size / 2);
		bPoint[3].x = start.x + (size / 2);
		bPoint[3].y = start.y + (size / 2);
		break;
	default:
		break;
	}
}

Shape::~Shape()
{
	// shapeform
	thisForm = SF::mCircle;

	// triangle
	for (int i = 0; i < 3; i++)
	{
		tPoint[i].x = 0;
		tPoint[i].y = 0;
	}

	// box
	for (int i = 0; i < 4; i++)
	{
		bPoint[i].x = 0;
		bPoint[i].y = 0;
	}

	// deneral
	start.x	 = 0;
	start.y	 = 0;
	range	 = 0.0;
	center.x = 0;
	center.y = 0;
	size	 = 00;
	angle	 = 0;
}

void Shape::Update()
{
	// angle’²®
	if (Keyboard::GetKey(KEY_INPUT_RIGHT) > 0)
	{
		angle++;
		if (angle == 360)
		{
			angle = 0;
		}
	}
	else if (Keyboard::GetKey(KEY_INPUT_LEFT) > 0)
	{
		angle--;
		if (angle == -1)
		{
			angle = 359;
		}
	}
	else {}

	// range’²®
	if (Keyboard::GetKey(KEY_INPUT_UP) > 0 && range < 100)
	{
		range++;
	}
	else if (Keyboard::GetKey(KEY_INPUT_DOWN) > 0 && range > 0)
	{
		range--;
	}
	else {}

	center.x = start.x + cos(range + PI * (angle / 360));
	center.y = start.y + sin(range + PI * (angle / 360));
	
	switch (thisForm)
	{
	case SF::mCircle:
		break;
	case SF::mTriangle:
		tPoint[0].x = center.x;
		tPoint[0].y = center.y - (size / 2);
		tPoint[1].x = center.x + (size / 2);
		tPoint[1].y = center.y + (size / 2);
		tPoint[2].x = center.x - (size / 2);
		tPoint[2].y = center.y + (size / 2);
		break;
	case SF::mBox:
		bPoint[0].x = center.x - (size / 2);
		bPoint[0].y = center.y - (size / 2);
		bPoint[1].x = center.x - (size / 2);
		bPoint[1].y = center.y + (size / 2);
		bPoint[2].x = center.x + (size / 2);
		bPoint[2].y = center.y - (size / 2);
		bPoint[3].x = center.x + (size / 2);
		bPoint[3].y = center.y + (size / 2);
		break;
	default:
		break;
	}
}

void Shape::Draw()
{
	switch (thisForm)
	{
	case SF::mCircle:
		DrawCircle(center.x, center.y, size * 2, White, true);
		break;
	case SF::mTriangle:
		DrawTriangle(	tPoint[0].x, tPoint[0].y,
						tPoint[1].x, tPoint[1].y,
						tPoint[2].x, tPoint[2].y,
						White, true);
		break;
	case SF::mBox:
		DrawBox(center.x - (size / 2), center.y - (size / 2),
				center.x + (size / 2), center.y + (size / 2),
				White,true);
		break;
	default:
		break;
	}

	DrawFormatString(	0,	0, White, "center.x : %.1f\ncenter.y : %.1f", center.x, center.y);
	DrawFormatString( 160,	0, White, "size : %d\nangle : %d\nrange : %.1f", size, angle, range);
	DrawFormatString( 270,	0, White, "radian : %.2f\nsin : %.2f\ncin : %.2f", PI * (angle / 360), sin(PI * (angle / 360)), cos(PI * (angle / 360)));
	DrawFormatString( 410,	0, White, "start.x : %.1f\nstart.y : %.1f", start.x, start.y);
}