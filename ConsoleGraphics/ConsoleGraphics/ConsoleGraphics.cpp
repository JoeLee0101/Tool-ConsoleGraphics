#include "ConsoleGraphics.h"

ConsoleGraphics::ConsoleGraphics()
{
	myConsole = GetConsoleWindow();
	myDC = GetDC(myConsole);
}

ConsoleGraphics::~ConsoleGraphics()
{
}

void ConsoleGraphics::DrawLine(COORD, COORD)
{
	throw "myFunction is not implemented yet.";
}

void ConsoleGraphics::DrawAngleLine(COORD startPoint, int angleDeg, int length)
{
	double x = startPoint.X;
	double y = startPoint.Y;
	double hyp = 0;
	double angleRad = angleDeg * (3.141 / 180);

	while (hyp < length) {

		SetPixel(myDC, x, y, COLORREF(RGB(255, 255, 255)));

		if (angleDeg == 0) {
			y -= 0.01;
			hyp += 0.01;
		}
		else if (angleDeg == 180) {
			y += 0.01;
			hyp += 0.01;
		}
		else if (angleDeg > 0 && angleDeg < 180) {
			double x1 = 0.01;
			x += x1;

			double y1 = ((1/tan(angleRad)) * 0.01);

			hyp += (sqrt(pow(x1, 2) + pow(y1, 2)));
			y = y - y1;
		}
		else if(angleDeg > 180 && angleDeg < 360)
		{
			double x1 = 0.01;
			x -= x1;

			double y1 = ((1/tan(angleRad - (180*(PI/180)))) * 0.01);

			hyp += (sqrt(pow(x1, 2) + pow(y1, 2)));
			y = y + y1;

		}
	}
}

void ConsoleGraphics::DrawAngleLine(COORD startPoint, int angleDeg, int length, COLORREF color)
{
	double x = startPoint.X;
	double y = startPoint.Y;
	double hyp = 0;
	double angleRad = angleDeg * (PI / 180);

	while (hyp < length) {

		SetPixel(myDC, x, y, color);

		if (angleDeg == 0) {
			y -= 0.01;
			hyp += 0.01;
		}
		else if (angleDeg == 180) {
			y += 0.01;
			hyp += 0.01;
		}
		else if (angleDeg > 0 && angleDeg < 180) {
			double x1 = 0.01;
			x += x1;

			double y1 = ((1 / tan(angleRad)) * 0.01);

			hyp += (sqrt(pow(x1, 2) + pow(y1, 2)));
			y = y - y1;
		}
		else if (angleDeg > 180 && angleDeg < 360)
		{
			double x1 = 0.01;
			x -= x1;

			double y1 = ((1 / tan(angleRad - (180 * (PI / 180)))) * 0.01);

			hyp += (sqrt(pow(x1, 2) + pow(y1, 2)));
			y = y + y1;

		}
	}
}

void ConsoleGraphics::DrawAngleLine(COORD startPoint, int angleDeg, int length, int startCutLength)
{
	double x = startPoint.X;
	double y = startPoint.Y;
	double hyp = 0;
	double angleRad = angleDeg * (PI / 180);

	while (hyp < length) {

		if (hyp > startCutLength) {
			SetPixel(myDC, x, y, COLORREF(RGB(255, 255, 255)));
		}		

		if (angleDeg == 0) {
			y -= 0.01;
			hyp += 0.01;
		}
		else if (angleDeg == 180) {
			y += 0.01;
			hyp += 0.01;
		}
		else if (angleDeg > 0 && angleDeg < 180) {
			double x1 = 0.01;
			x += x1;

			double y1 = ((1 / tan(angleRad)) * 0.01);

			hyp += (sqrt(pow(x1, 2) + pow(y1, 2)));
			y = y - y1;
		}
		else if (angleDeg > 180 && angleDeg < 360)
		{
			double x1 = 0.01;
			x -= x1;

			double y1 = ((1 / tan(angleRad - (180 * (PI / 180)))) * 0.01);

			hyp += (sqrt(pow(x1, 2) + pow(y1, 2)));
			y = y + y1;

		}
	}
}




void ConsoleGraphics::DrawCircle(COORD centre, int radius)
{
	for (double i = 0; i <= 360; i += 0.01) {
		int xPos = centre.X + radius * cos(i);
		int yPos = centre.Y + radius * sin(i);

		SetPixel(myDC, (int)xPos, (int)yPos, COLORREF(RGB(255, 255, 255)));
	}
}

void ConsoleGraphics::DrawCircle(COORD centre, int radius, COLORREF color)
{
	for (double i = 0; i <= 360; i += 0.01) {
		int xPos = centre.X + radius * cos(i);
		int yPos = centre.Y + radius * sin(i);

		SetPixel(myDC, (int)xPos, (int)yPos, color);
	}
}

void ConsoleGraphics::SegmentCircle(COORD centre, int radius, int segments)
{
	double segAngDeg = (360 / (double)segments);

	ConsoleGraphics::DrawCircle(centre, radius);

	for (double i = 0; i < 360; i += segAngDeg) {
		ConsoleGraphics::DrawAngleLine(centre, i, radius);
	}
}

void ConsoleGraphics::SegmentCircle(COORD centre, int radius, int segments, int startCutLength)
{
	double segAngDeg = (360 / (double)segments);

	ConsoleGraphics::DrawCircle(centre, radius);

	for (double i = 0; i < 360; i += segAngDeg) {
		ConsoleGraphics::DrawAngleLine(centre, i, radius, startCutLength);
	}
}

void ConsoleGraphics::SegmentCircle(COORD centre, int radius, int segments, int startCutLength , int offsetDeg)
{
	double segAngDeg = (360 / (double)segments);

	ConsoleGraphics::DrawCircle(centre, radius);

	for (double i = offsetDeg; i < 360; i += segAngDeg) {
		ConsoleGraphics::DrawAngleLine(centre, i, radius, startCutLength);
	}
}

COORD ConsoleGraphics::CicleCoordinate(COORD centre, int radius, double angleDeg)
{
	COORD circleCoord;
	double angleRad = angleDeg * (PI / 180);

	int xPos = centre.X + radius * cos(angleRad - (PI/2));
	int yPos = centre.Y + radius * sin(angleRad - (PI/2));

	circleCoord.X = xPos;
	circleCoord.Y = yPos;

	return circleCoord;
}
