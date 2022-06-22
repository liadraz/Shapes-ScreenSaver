//----------------------------------------------------------------------------//
//                      << Shapes ScreenSaver Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Rectangle class Implementation
//	AUTHOR 			Liad Raz
//	DATE			22 Jun 2022
// 
//----------------------------------------------------------------------------//

#include "rectangle.hpp"


//----------------------------------------------------------------------------//
//	Rectangle Class Definitions
//----------------------------------------------------------------------------//

Rectangle::Rectangle(
    const ilrd::Point& center_, double height_, double width_,
    double angle_, COLORS color_) :
        Shape::Shape(center_, angle_, color_),
        m_height(height_),
        m_width(width_)
{}

Rectangle::~Rectangle()
{}


// Member functions
//----------------------------------------------------------------------------//
Rectangle& Rectangle::Draw()
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


Rectangle* Rectangle::Clone()
{
    return new Rectangle(*this);
}


// Utilities Funcs
//----------------------------------------------------------------------------//
void Rectangle::CalcVertices(ilrd::Point* vertices_)
{
    ilrd::Point centerV = GetCenter();
    double halfHeight = m_height / 2;
    double halfWidth = m_width / 2;


    vertices_[0] = ilrd::Point(
            centerV + ilrd::Point(-halfWidth, -halfHeight));
    
    vertices_[1] = ilrd::Point(
            centerV + ilrd::Point(halfWidth, -halfHeight));

    vertices_[2] = ilrd::Point(
            centerV + ilrd::Point(halfWidth, halfHeight));

    vertices_[3] = ilrd::Point(
            centerV + ilrd::Point(-halfWidth, halfHeight));
}

void Rectangle::CalcRotate(ilrd::Point* vertices_)
{
    ilrd::Point centerV = GetCenter();
    double angle = GetAngle();

    vertices_[0].Revolve(centerV, angle);
    vertices_[1].Revolve(centerV, angle);
    vertices_[2].Revolve(centerV, angle);
    vertices_[3].Revolve(centerV, angle);
}
