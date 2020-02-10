#include "Shapes.h"

void Rect::Draw(HDC hdc)
{
	Rectangle(hdc, this->Start.x, this->Start.y, this->End.x, this->End.y);
}

void Circle::Draw(HDC hdc)
{
	Ellipse(hdc, this->Start.x, this->Start.y, this->End.x, this->End.y);
}

void Poly::Draw(HDC hdc)
{
	Polygon( hdc,  )
}