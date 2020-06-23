#pragma once
#include <iostream>
#include <vector>
#include "Graph.h"
#include <glut.h>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru");
    glutInit(&argc, argv);

    graph = makeGraph();



    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(900, 720);
    glutCreateWindow("Граф");
    WinW = glutGet(GLUT_WINDOW_WIDTH);
    WinH = glutGet(GLUT_WINDOW_HEIGHT);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);



    glutMainLoop();

    return 0;
}