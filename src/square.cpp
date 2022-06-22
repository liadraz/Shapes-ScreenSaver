//----------------------------------------------------------------------------//
//                      << Shapes ScreenSaver Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Square class Implementation
//	AUTHOR 			Liad Raz
//	DATE			22 Jun 2022
// 
//----------------------------------------------------------------------------//

#include "square.hpp"


//----------------------------------------------------------------------------//
//	Square Class Definitions
//----------------------------------------------------------------------------//

Square::Square(
    const ilrd::Point& center_, double edge_, double angle_, COLORS color_) :
        Shape::Shape(center_, angle_, color_),
        m_edge(edge_)
{}

Square::~Square()
{}


// Member functions
//----------------------------------------------------------------------------//
Square& Square::Draw()
{
    const int NPOINTS = 4;

    // Create array of Points
    ilrd::Point *vertices = new ilrd::Point[NPOINTS];

    CalcVertices(vertices);
    CalcRotate(vertices);

    // Invoke Draw from glut Api
    DrawPolygon(
        GetColor(),
        NPOINTS,
        static_cast<int>(vertices[0].GetX()), static_cast<int>(vertices[0].GetY()), 
        static_cast<int>(vertices[1].GetX()), static_cast<int>(vertices[1].GetY()),
        static_cast<int>(vertices[2].GetX()), static_cast<int>(vertices[2].GetY()), 
        static_cast<int>(vertices[3].GetX()), static_cast<int>(vertices[3].GetY())
        );

    delete[] vertices;

    return *this;
}


Square* Square::Clone()
{
    return new Square(*this);
}


// Utilities Funcs
//----------------------------------------------------------------------------//
void Square::CalcVertices(ilrd::Point* vertices_)
{
    ilrd::Point centerV = GetCenter();
    double halfEdge = m_edge / 2;


    vertices_[0] = ilrd::Point(
            centerV + ilrd::Point(-halfEdge, -halfEdge));
    
    vertices_[1] = ilrd::Point(
            centerV + ilrd::Point(halfEdge, -halfEdge));

    vertices_[2] = ilrd::Point(
            centerV + ilrd::Point(halfEdge, halfEdge));

    vertices_[3] = ilrd::Point(
            centerV + ilrd::Point(-halfEdge, halfEdge));
}

void Square::CalcRotate(ilrd::Point* vertices_)
{
    ilrd::Point centerV = GetCenter();
    double angle = GetAngle();

    vertices_[0].Revolve(centerV, angle);
    vertices_[1].Revolve(centerV, angle);
    vertices_[2].Revolve(centerV, angle);
    vertices_[3].Revolve(centerV, angle);
}
