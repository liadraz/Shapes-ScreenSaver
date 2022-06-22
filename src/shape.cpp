//----------------------------------------------------------------------------//
//                      << Shapes ScreenSaver Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Shape class Implementation
//	AUTHOR 			Liad Raz
//	DATE			22 Jun 2022
// 
//----------------------------------------------------------------------------//

#include "shape.hpp"


//----------------------------------------------------------------------------//
//	Shape Class Definitions
//----------------------------------------------------------------------------//

Shape::Shape(const ilrd::Point& center_, double angle_, COLORS color_) : 
            m_center(center_), 
            m_angle(angle_), 
            m_color(color_)
{}

Shape::~Shape()
{}


// Basic Functionality
//----------------------------------------------------------------------------//
Shape& Shape::Move(const ilrd::Point& offset_)
{
    m_center += offset_;

    return *this;
}

Shape& Shape::Rotate(double angle_)
{
    m_angle += angle_;

    return *this;
}

Shape& Shape::Revolve(const ilrd::Point& pivot_, double angle_)
{
    m_center.Revolve(pivot_, angle_);
    
    return *this;
}

Shape& Shape::SetColor(COLORS color_)
{
    m_color = color_;

    return *this;
}


// Extra Functionality
//----------------------------------------------------------------------------//
ilrd::Point Shape::GetCenter()
{
    return m_center;
}

double Shape::GetAngle()
{
    return m_angle;
}

COLORS Shape::GetColor()
{
    return m_color;
}
