//----------------------------------------------------------------------------//
//                      << Shapes ScreenSaver Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Run ScreenSaver
//	AUTHOR 			Liad Raz
//	DATE			22 Jun 2022
// 
//  CPYCOMPILE
//  gdp test/screensaver.cpp src/shape.cpp src/circle.cpp -I ./include -Wl,-rpath=. ./lib/libglut_utils.so ./lib/libpoint.a
//----------------------------------------------------------------------------//

#include <cstdio>           // printf
#include <mcheck.h>

#include "glut_utils.h"     // DrawInit, DrawSetTimerFunc, DrawMainLoop
#include "shape.hpp"

#include "group.hpp"
#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "square.hpp"
#include "rectangle.hpp"


static void DrawFunction();
static int TimerFunction();
double DegToRad(double degree_);


// Global Shapes
static Square g_sq(ilrd::Point(250, 400), 85.0, 0, COLOR_MAGENTA);
static Line g_line(ilrd::Point(300, 420), 160.0, 0, COLOR_YELLOW);
static Circle g_circ(ilrd::Point(300, 420), 62.0, 0, COLOR_RED);
static Triangle g_tri(ilrd::Point(290, 320), 100.0, 0, COLOR_CYAN);
static Rectangle g_rec(ilrd::Point(240, 400), 80.0, 45.0, 0, COLOR_GREEN);

static Square g_base(ilrd::Point(200, 400), 75.0, 0, COLOR_RED);
static Triangle g_roof(ilrd::Point(200, 337), 90.0, 0, COLOR_RED);
static Group g_house(&g_base);


int main(int argc, char** argv)
{
    g_house.AddShape(&g_roof);

    // Render the Board
    DrawInit(argc, argv, 1000, 1000, DrawFunction);

    DrawSetTimerFunc(TimerFunction, 20);

    // Start Event Loop
    DrawMainLoop();

    return 0;
}


static void DrawFunction()
{
    // Create line
    g_line.Draw();

    // Create Circle
    g_circ.Draw();
    
    // Create triangle
    g_tri.Draw();

    // Create square
    g_sq.Draw();

    // Create Rectangle
    g_rec.Draw();


    // Test Group
    g_house.Draw();


    // Test Clone

}

static int TimerFunction()
{
    // Manipulate line
    // g_line.Move(ilrd::Point(2, 2));
    g_line.Rotate(DegToRad(2));
    g_line.Revolve(ilrd::Point(500, 450), DegToRad(2));
    
    // Manipulate Circle
    // g_circ.Move(ilrd::Point(1, 2));
    g_circ.Revolve(ilrd::Point(500, 500), DegToRad(3));

    // Manipulate triangle
    g_tri.Rotate(DegToRad(-2));
    g_tri.Revolve(ilrd::Point(500, 500), DegToRad(2));

    // Manipulate square
    g_sq.Rotate(DegToRad(-3));
    g_sq.Revolve(ilrd::Point(500, 500), DegToRad(1));

    // Manipulate Rectangle
    g_rec.Rotate(DegToRad(-8));
    g_rec.Revolve(ilrd::Point(500, 500), DegToRad(2));

    // Manipulate Group
    // g_house.Move(ilrd::Point(5, 5));
    g_house.Revolve(ilrd::Point(500, 500), 0.05);
    g_house.Rotate(DegToRad(10));
    g_house.SetColor(COLOR_YELLOW);

    // g_house.RemoveShape(&g_base);

    return 1;
}



//----------------------------------------------------------------------------//
// Utilities Funcs
//----------------------------------------------------------------------------//
double DegToRad(double degree_)
{
    const double PI = 3.141592653589793;

    return degree_ * (PI / 180);
}
