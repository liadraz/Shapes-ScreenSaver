//----------------------------------------------------------------------------//
//                      << Shapes ScreenSaver Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Circle Class - API
//	AUTHOR 			Liad Raz
//	DATE			22 Jun 2022
// 
//----------------------------------------------------------------------------//


#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"


class Circle : public Shape
{
public:
    explicit Circle(    
        const ilrd::Point& center,
        double radius, 
        double angle = 0.0, 
        COLORS color = COLOR_WHITE);
	virtual ~Circle();
    // NOTE:    Using generated function CCtor.
    // NOTE:    Copy= is blocked by Shape class. Use Clone func instead.

    virtual Circle& Draw();
    virtual Circle* Clone();

private:
	double m_radius;
};


#endif // CIRCLE_HPP