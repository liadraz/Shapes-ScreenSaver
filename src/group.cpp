//----------------------------------------------------------------------------//
//                      << Shapes ScreenSaver Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Group class Implementation
//	AUTHOR 			Liad Raz
//	DATE			22 Jun 2022
// 
//----------------------------------------------------------------------------//

#include "group.hpp"


//----------------------------------------------------------------------------//
//	Group Class Definitions
//----------------------------------------------------------------------------//

Group::Group(Shape* shape_) :
    Shape::Shape(shape_->GetCenter(), shape_->GetAngle(), shape_->GetColor())
{
    m_shapes.push_back(shape_);
}

Group::~Group()
{}



// Basic Functionality
//----------------------------------------------------------------------------//
Group& Group::Draw()
{
    std::vector<Shape*>::iterator runner = m_shapes.begin();
    std::vector<Shape*>::iterator end = m_shapes.end();

    while (runner != end)
    {
        (*runner)->Draw();
        ++runner;
    }

    return *this;
}

Group& Group::Move(const ilrd::Point& offset_)
{
    std::vector<Shape*>::iterator runner = m_shapes.begin();
    std::vector<Shape*>::iterator end = m_shapes.end();

    while (runner != end)
    {
        (*runner)->Move(offset_);
        ++runner;
    }

    return *this;
}

Group& Group::Rotate(double angle_)
{
    std::vector<Shape*>::iterator runner = m_shapes.begin();
    std::vector<Shape*>::iterator end = m_shapes.end();

    while (runner != end)
    {
        (*runner)->Revolve(GetCenter(), angle_);
        (*runner)->Rotate(angle_);
        ++runner;
    }

    return *this;
}

Group& Group::Revolve(const ilrd::Point& pivot_, double angle_)
{
    std::vector<Shape*>::iterator runner = m_shapes.begin();
    std::vector<Shape*>::iterator end = m_shapes.end();

    while (runner != end)
    {
        (*runner)->Revolve(pivot_, angle_);
        (*runner)->Rotate(angle_);
        ++runner;
    }

    return *this;
}

Group& Group::SetColor(COLORS color_)
{
    std::vector<Shape*>::iterator runner = m_shapes.begin();
    std::vector<Shape*>::iterator end = m_shapes.end();

    while (runner != end)
    {
        (*runner)->SetColor(color_);
        ++runner;
    }

    return *this;
}


// Extra Functionality
//----------------------------------------------------------------------------//
Group* Group::Clone()
{
    return new Group(*this);
}


Group& Group::AddShape(Shape* shape_)
{
    m_shapes.push_back(shape_);

    return *this;
}

Group& Group::RemoveShape(Shape* shape_)
{
    std::vector<Shape*>::iterator runner = m_shapes.begin();
    std::vector<Shape*>::iterator end = m_shapes.end();

    while (runner != end)
    {
        if (*runner == shape_)
        {
            m_shapes.erase(runner);
            break;
        }
        ++runner;
    }

    return *this;
}
