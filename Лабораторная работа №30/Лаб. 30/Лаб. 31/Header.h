#pragma once
#include <glut.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <iterator>
#include <string>
#include <fstream>

using namespace std;

class Tree
{
private:
    string country;
    Tree* left;
    Tree* right;
    Tree* parent;
    char b;
    int x;
    int y;
    bool cursor;
public:
    Tree(string);
    ~Tree();
    static Tree* balancedTree(int n);
    void addLeftTree(Tree* tree);
    void addRightTree(Tree* tree);
    int height(Tree*);
    void reorderSetCoords(Tree* tree, char dir);
    void reorderAtributes(Tree* tree);
    void drawAtribute();

    int getX() { return this->x; }
    int getY() { return this->y; }
    char getB() { return this->b; }
    Tree* getLeft() { return this->left; }
    Tree* getRight() { return this->right; }
    string getCountry() { return this->country; }
    Tree* getParent() { return this->parent; }
    bool getCursor() { return this->cursor; }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void setB(char b) { this->b = b; }
    void setLeft(Tree* left) { this->left = left; }
    void setRight(Tree* right) { this->right = right; }
    void setCountry(string country) { this->country = country; }
    void setParent(Tree* parent) { this->parent = parent; }
    void setCursor(bool c) { cursor = c; }

    int getLevelUtil(Tree* node, string data, int level);
    int getLevel(Tree* node, string data);
    Tree* getNode(int x, int y);
};

struct SGlutContextStruct
{
    Tree* tree;
    int winW, winH, treeH, treeW, shift, R;
    int b1_x, b1_y, b1_state = 0; //коорды кнопки и состо€ие при наведении мыши
    int b2_x, b2_y, b2_state = 0;
    int b3_x, b3_y, b3_state = 0;
    int nodes = 0;
};

static SGlutContextStruct gc;
static vector<string> V; //элементы дерева
static int ii = 0; //счетчик

Tree* checkCircle(Tree* node, int x, int y);
void drawTree(int window_width, int window_height, int shift, int n);
void display();
void drawCircle(int x, int y);
void reshape(int, int);
void drawButton1();
void drawButton2();
void drawButton3();
void drawText(string data, int x0, int y0, bool state);
void drawLine(int x1, int y1, int x2, int y2);
void mouseMove(int x, int y);
void mouseClick(int button, int state, int x, int y);
