//----------------------------------------------------------------------------//
//                      << Shapes ScreenSaver Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Shape class API
//	AUTHOR 			Liad Raz
//	DATE			22 Jun 2022
//----------------------------------------------------------------------------//

#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <cstddef>			// size_t

#include "glut_utils.h"
#include "point.hpp"


//----------------------------------------------------------------------------//
//  DESCRIPTION     Shapes Project based on 
//                  Composite Design Pattern, Shape is an abstract Class.
//                  Solves whole-part problem with the same API.
//----------------------------------------------------------------------------//
class Shape
{
public:
    explicit Shape(
        const ilrd::Point& center, 
        double angle = 0.0, 
        COLORS color = COLOR_WHITE);
    virtual ~Shape() = 0;
    // NOTE: Using generated function CCtor.

    //
    // Basic Functionality
    virtual Shape& Draw() = 0;
    virtual Shape& Move(const ilrd::Point& offset);
    // NOTE:    angle format radian.
    virtual Shape& Rotate(double angle);
    virtual Shape& Revolve(const ilrd::Point& pivot, double angle);
    virtual Shape& SetColor(COLORS color);

    //
    // Extra Functionality
    virtual ilrd::Point GetCenter();
    virtual double GetAngle();
    virtual COLORS GetColor();
    
    virtual Shape* Clone() = 0;

private:
    // NOTE:    Copy= is blocked. Use Clone func instead.
    Shape& operator=(const Shape&);
    
    ilrd::Point m_center;
    double m_angle;
    COLORS m_color;
};


#endif // SHAPES_HPP
