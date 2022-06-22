//----------------------------------------------------------------------------//
//                      << Shapes ScreenSaver Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Square Class - API
//	AUTHOR 			Liad Raz
//	DATE			22 Jun 2022
// 
//----------------------------------------------------------------------------//


#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"

class Square : public Shape
{
public:
    explicit Square(    
        const ilrd::Point& center, 
        double edge, 
        double angle = 0.0, 
        COLORS color = COLOR_WHITE);
	virtual ~Square();
    // NOTE:    Using generated function CCtor.
    // NOTE:    Copy= is blocked by Shape class. Use Clone func instead.

    virtual Square& Draw();
    virtual Square* Clone();

private:
	double m_edge;

	//
	// Utilities Funcs
    void CalcVertices(ilrd::Point* vertices);
    void CalcRotate(ilrd::Point* vertices);
};


#endif // SQUARE_HPP