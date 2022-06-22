//----------------------------------------------------------------------------//
//                      << Shapes ScreenSaver Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Triangle class Implementation
//	AUTHOR 			Liad Raz
//	DATE			22 Jun 2022
// 
//----------------------------------------------------------------------------//

#include <cmath>             // sqrt

#include "triangle.hpp"

//----------------------------------------------------------------------------//
//	Triangle Class Definitions
//----------------------------------------------------------------------------//

Triangle::Triangle( 
    const ilrd::Point& center_, double edge_, double angle_, COLORS color_) :
        Shape::Shape(center_, angle_, color_),
        m_edge(edge_)
{}

Triangle::~Triangle()
{}


// Member functions
//----------------------------------------------------------------------------//
Triangle& Triangle::Draw()
{
    const int NPOINTS = 3;

    // Create array of Points
    ilrd::Point *vertices = new ilrd::Point[NPOINTS];

    Triangle::CalcVertices(vertices);
    Triangle::CalcRotate(vertices);

    // Invoke Draw from glut Api
    DrawPolygon(
        GetColor(),
        NPOINTS,
        static_cast<int>(vertices[0].GetX()), static_cast<int>(vertices[0].GetY()), 
        static_cast<int>(vertices[1].GetX()), static_cast<int>(vertices[1].GetY()),
        static_cast<int>(vertices[2].GetX()), static_cast<int>(vertices[2].GetY())
        );

    delete[] vertices;

    return *this;
}


Triangle* Triangle::Clone()
{
    return new Triangle(*this);
}


// Utilities Funcs
//----------------------------------------------------------------------------//
void Triangle::CalcVertices(ilrd::Point* vertices_)
{
    ilrd::Point centerV = GetCenter();
    double halfEdge = m_edge / 2;
    double sqrtThree = sqrt(3);

    vertices_[0] = centerV + ilrd::Point(0, -(m_edge * sqrtThree / 3));
    vertices_[1] = centerV + ilrd::Point(halfEdge, halfEdge * sqrtThree / 3);
    vertices_[2] = centerV + ilrd::Point(-halfEdge, halfEdge * sqrtThree / 3);
}

void Triangle::CalcRotate(ilrd::Point* vertices_)
{
    ilrd::Point centerV = GetCenter();
    double angle = GetAngle();

    vertices_[0].Revolve(centerV, angle);
    vertices_[1].Revolve(centerV, angle);
    vertices_[2].Revolve(centerV, angle);
}
