//----------------------------------------------------------------------------//
//                      << Shapes ScreenSaver Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Line class Implementation
//	AUTHOR 			Liad Raz
//	DATE			22 Jun 2022
// 
//----------------------------------------------------------------------------//

#include "line.hpp"


//----------------------------------------------------------------------------//
//	Line Class Definitions
//----------------------------------------------------------------------------//

Line::Line( 
    const ilrd::Point& center_, double length_, double angle_, COLORS color_) :
        Shape::Shape(center_, angle_, color_),
        m_length(length_)
{}

Line::~Line()
{}


// Member functions
//----------------------------------------------------------------------------//
Line& Line::Draw()
{
    const int NPOINTS = 2;

    // Create array of Points
    ilrd::Point *vertices = new ilrd::Point[NPOINTS];

    CalcVertices(vertices);
    CalcRotate(vertices);

    // Invoke Draw from glut Api
    DrawPolygon(    
        GetColor(), 
        NPOINTS, 
        static_cast<int>(vertices[0].GetX()), static_cast<int>(vertices[0].GetY()),
        static_cast<int>(vertices[1].GetX()), static_cast<int>(vertices[1].GetY())
        );

    delete[] vertices;

    return *this;
}

Line* Line::Clone()
{
    return new Line(*this);
}


// Utilities Funcs
//----------------------------------------------------------------------------//
void Line::CalcVertices(ilrd::Point* vertices_)
{
    ilrd::Point centerV = GetCenter();
    double halfLine = m_length / 2;

    vertices_[0] = ilrd::Point(
        centerV + ilrd::Point(-halfLine, 0));
    
    vertices_[1] = ilrd::Point(
        centerV + ilrd::Point(halfLine, 0));
}

void Line::CalcRotate(ilrd::Point* vertices_)
{
    vertices_[0].Revolve(GetCenter(), GetAngle());
    vertices_[1].Revolve(GetCenter(), GetAngle());
}
