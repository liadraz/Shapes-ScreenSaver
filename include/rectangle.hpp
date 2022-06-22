//----------------------------------------------------------------------------//
//                      << Shapes ScreenSaver Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Rectangle Class - API
//	AUTHOR 			Liad Raz
//	DATE			22 Jun 2022
// 
//----------------------------------------------------------------------------//


#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"


class Rectangle : public Shape
{
public:
    explicit Rectangle(    
        const ilrd::Point& center, 
        double height,
        double width_,
        double angle = 0.0, 
        COLORS color = COLOR_WHITE);
	virtual ~Rectangle();
    // NOTE:    Using generated function CCtor.
    // NOTE:    Copy= is blocked by Shape class. Use Clone func instead.

    virtual Rectangle& Draw();
    virtual Rectangle* Clone();

private:
	double m_height; 
	double m_width;

    //
	// Utilities Funcs
    void CalcVertices(ilrd::Point* vertices);
    void CalcRotate(ilrd::Point* vertices);
};


#endif // RECTANGLE_HPP