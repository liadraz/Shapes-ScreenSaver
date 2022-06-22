//----------------------------------------------------------------------------//
//                      << Shapes ScreenSaver Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Group Class - API
//	AUTHOR 			Liad Raz
//	DATE			22 Jun 2022
// 
//----------------------------------------------------------------------------//

#ifndef GROUP_HPP
#define GROUP_HPP

#include <vector>       // vector
#include "shape.hpp"


class Group : public Shape
{
public:
	explicit Group(Shape* shape);
	virtual ~Group();
    // NOTE:    Using generated function CCtor.
    // NOTE:    Copy= is blocked by Shape class. Use Clone func instead.

    //
    // Basic Functionality
    virtual Group& Draw();
    virtual Group& Move(const ilrd::Point& offset);
    virtual Group& Rotate(double angle);
    virtual Group& Revolve(const ilrd::Point& pivot, double angle);
    virtual Group& SetColor(COLORS color);
	
    //
    // Extra Functionality
    virtual Group* Clone();
    
	Group& AddShape(Shape* shape);
    // IMPORTANT    Undefined behavior when shape does not exist in Group
	Group& RemoveShape(Shape* shape);

private:
	std::vector<Shape*> m_shapes; 
};


#endif // GROUP_HPP
