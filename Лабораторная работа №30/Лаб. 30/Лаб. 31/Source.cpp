#include <glut.h>
#include "Header.h"
#include <iostream>
#include <Windows.h>
using namespace std;
int winW = 1600;
int winH = 720;

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    glutInit(&argc, argv);
    cout << "¬ведите количество узлов: ";
    cin >> n;
    drawTree(winW, winH, 5, n);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(winW, winH);
    glutCreateWindow("јнгло-русский словарь");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(mouseMove);
    glutMouseFunc(mouseClick);
    glutMainLoop();
}