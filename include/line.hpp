//----------------------------------------------------------------------------//
//                      << Shapes ScreenSaver Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Line Class - API
//	AUTHOR 			Liad Raz
//	DATE			22 Jun 2022
// 
//----------------------------------------------------------------------------//


#ifndef LINE_HPP
#define LINE_HPP

#include "shape.hpp"


class Line : public Shape
{
public:
    explicit Line(    
        const ilrd::Point& center, 
        double length, 
        double angle = 0.0, 
        COLORS color = COLOR_WHITE);
	virtual ~Line();
    // NOTE:    Using generated function CCtor.
    // NOTE:    Copy= is blocked by Shape class. Use Clone func instead.

    virtual Line& Draw();
    virtual Line* Clone();

private:
	double m_length;
    
    //
	// Utilities Funcs
    void CalcVertices(ilrd::Point* vertices);
    void CalcRotate(ilrd::Point* vertices);
};


#endif // LINE_HPP