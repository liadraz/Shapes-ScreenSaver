//----------------------------------------------------------------------------//
//                      << Shapes ScreenSaver Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Triangle Class - API
//	AUTHOR 			Liad Raz
//	DATE			22 Jun 2022
// 
//----------------------------------------------------------------------------//


#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"


class Triangle : public Shape
{
public:
    explicit Triangle(    
        const ilrd::Point& center, 
        double edge, 
        double angle = 0.0, 
        COLORS color = COLOR_WHITE);
	virtual ~Triangle();
    // NOTE:    Using generated function CCtor.
    // NOTE:    Copy= is blocked by Shape class. Use Clone func instead.

    virtual Triangle& Draw();
    virtual Triangle* Clone();

private:
	double m_edge;

    //
	// Utilities Funcs
    void CalcVertices(ilrd::Point* vertices);
    void CalcRotate(ilrd::Point* vertices);
};


#endif // TRIANGLE_HPP