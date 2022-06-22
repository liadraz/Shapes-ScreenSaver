//----------------------------------------------------------------------------//
//                      << Shapes ScreenSaver Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Circle class Implementation
//	AUTHOR 			Liad Raz
//	DATE			22 Jun 2022
// 
//----------------------------------------------------------------------------//

#include "circle.hpp"


//----------------------------------------------------------------------------//
//	Circle Class Definitions
//----------------------------------------------------------------------------//

Circle::Circle(
    const ilrd::Point& center_, double radius_, double angle_, COLORS color_) :
        Shape::Shape(center_, angle_, color_),
        m_radius(radius_)
{}

Circle::~Circle()
{}


// Member functions
//----------------------------------------------------------------------------//
Circle& Circle::Draw()
{
    ilrd::Point centerPivot = GetCenter();

    DrawCircle(GetColor(), centerPivot.GetX(), centerPivot.GetY() ,m_radius);

    return *this;
}

Circle* Circle::Clone()
{
    return new Circle(*this);
}
