#include "Header.h"

using namespace std;

Tree::Tree(string dt)
{
    country = dt;
    left = NULL;
    right = NULL;
    parent = NULL;
    cursor = false;
}

Tree::~Tree()
{
    delete this->left;
    delete this->right;
}

int Tree::height(Tree* node)  //получение высоты ид. баланс. дерева
{
    int level = 1;
    while (node->left != NULL)
    {
        node = node->left;
        level++;
    }
    return level;
}

Tree* Tree::balancedTree(int n) //создание дерева
{
    if (n == 0)
        return NULL;
    Tree* tree = new Tree(V[ii]);
    ii++;
    tree->addLeftTree(balancedTree(n / 2));
    tree->addRightTree(balancedTree(n - n / 2 - 1));
    return tree;
}

void Tree::addLeftTree(Tree* tree) //добавление левого поддерева
{
    if (tree != NULL) {
        tree->parent = this;
        left = tree;
    }
}

void Tree::addRightTree(Tree* tree)//добавление правого поддерева
{
    if (tree != NULL) {
        tree->parent = this;
        right = tree;
    }
}

int Tree::getLevelUtil(Tree* node, string data, int level) //получение текущего уровня узла (высоты)
{
    if (node == NULL)
        return 0;

    if (node->country == data)
        return level;

    int downlevel = getLevelUtil(node->left, data, level + 1);
    if (downlevel != 0)
        return downlevel;

    downlevel = getLevelUtil(node->right, data, level + 1);
    return downlevel;
}

int Tree::getLevel(Tree* node, string data) //вызов того что выше
{
    return getLevelUtil(node, data, 1);
}

void Tree::reorderSetCoords(Tree* tree, char dir) //расстановка координат и типов узлов на основе
{                                                  //размеров окна
    if (tree != NULL)
    {
        int curLevel = getLevel(gc.tree, tree->getCountry());
        if (dir == '0')
        {
            tree->x = gc.winW / 2;
            tree->y = gc.winH - (gc.winH / gc.treeH / 2);
        }
        else if (dir == 'l') //левый
        {
            tree->x = tree->parent->x - gc.winW / pow(2, curLevel);

            if (curLevel == ((gc.treeH / 2) + 1) and gc.treeH % 2 == 1)
                tree->y = gc.winH / 2;
            else
                tree->y = tree->parent->y - gc.winH / gc.treeH;
        }
        else if (dir == 'r') //правый
        {
            tree->x = tree->parent->x + gc.winW / pow(2, curLevel);
            if (curLevel == ((gc.treeH / 2) + 1) and gc.treeH % 2 == 1)
                tree->y = gc.winH / 2;
            else
                tree->y = tree->parent->y - gc.winH / gc.treeH;

        }
        reorderSetCoords(tree->left, 'r'); //дерево рисуется зеркально
        reorderSetCoords(tree->right, 'l');//поэтому меняем узлы местами
    }
}

void Tree::reorderAtributes(Tree* tree) //печать всех атрибутов
{
    if (tree != NULL)
    {
        string str1 = tree->country;
        string buf;
        const char* file_name = "RUSENG.txt";
        long cnt = 0;

        ifstream ifs(file_name);
        if (!ifs.is_open()) {
            cout << "Can't open file!" << endl;
        }

        while (getline(ifs, buf)) {
            if (buf.find(str1) != string::npos) {
                cout << "Начальный узел: " << setw(18) << buf << endl;
                ++cnt;
            }
        }
        ifs.close();
        if (!cnt)
            cout << "No words found." << endl;
    }
    if (tree != NULL)
    {
        if (tree->left != NULL) //заркально
        { 
            string str1 = tree->left->country;
            string buf;
            const char* file_name = "RUSENG.txt";
            long cnt = 0;

            ifstream ifs(file_name);
            if (!ifs.is_open()) {
                cout << "Can't open file!" << endl;
            }

            while (getline(ifs, buf)) {
                if (buf.find(str1) != string::npos) {
                    cout << "Правый потомок: " << setw(18) << buf << endl;
                    ++cnt;
                }
            }
            ifs.close();
            if (!cnt)
                cout << "No words found." << endl;
        }
        else
            cout << "Правый потомок: " << setw(18) << "–" << endl;
        if (tree->right != NULL)//заркально
        {
            string str1 = tree->right->country;
            string buf;
            const char* file_name = "RUSENG.txt";
            long cnt = 0;

            ifstream ifs(file_name);
            if (!ifs.is_open()) {
                cout << "Can't open file!" << endl;
            }

            while (getline(ifs, buf)) {
                if (buf.find(str1) != string::npos) {
                    cout << "Левый потомок: " << setw(19) << buf << endl;
                    ++cnt;
                }
            }
            ifs.close();
            if (!cnt)
                cout << "No words found." << endl;
        }
        else
            cout << "Левый потомок: " << setw(19) << "–" << endl;
        if (tree->parent != NULL)
        {
            string str1 = tree->parent->country;
            string buf;
            const char* file_name = "RUSENG.txt";
            long cnt = 0;

            ifstream ifs(file_name);
            if (!ifs.is_open()) {
                cout << "Can't open file!" << endl;
            }

            while (getline(ifs, buf)) {
                if (buf.find(str1) != string::npos) {
                    cout << "Родитель: " << setw(24) << buf << endl << endl;
                    ++cnt;
                }
            }
            ifs.close();
            if (!cnt)
                cout << "No words found." << endl;
        }
        else
            cout << "Родитель: " << setw(24) << "–" << endl << endl;
        reorderAtributes(tree->left);
        reorderAtributes(tree->right);
    }
}

void drawButton1() //кнопка +
{
    if (gc.b1_state == 1)
        glColor3f(0.6f, 0.6f, 0.6f);
    else
        glColor3f(0.902f, 0.902f, 0.980f);
    glBegin(GL_QUADS);
    glVertex2i(1, gc.winH - 1);
    glVertex2i(1, gc.winH - gc.winH / 8);
    glVertex2i(gc.winW / 10, gc.winH - gc.winH / 8);
    glVertex2i(gc.winW / 12, gc.winH - 1);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2i(1, gc.winH - 1);
    glVertex2i(1, gc.winH - gc.winH / 8);
    glVertex2i(gc.winW / 10, gc.winH - gc.winH / 8);
    glVertex2i(gc.winW / 12, gc.winH - 1);
    glEnd();

    glRasterPos2i(58, gc.winH - 52);
    string but40 = "Add";
    for (int i = 0; i < but40.length(); i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, but40[i]);

    gc.b1_x = gc.winW / 10;  //ставим координаты для мыши другие
    gc.b1_y = gc.winH / 8;  //так как там другия сисетема координат
}

void drawButton2() //кнопка -
{
    if (gc.b2_state == 1)
        glColor3f(0.6f, 0.6f, 0.6f);
    else
        glColor3f(0.902f, 0.902f, 0.980f);
    glBegin(GL_QUADS);
    glVertex2i(1, gc.winH - (3 / 2) * gc.b1_y);
    glVertex2i(1, (gc.winH - gc.winH / 8) - (3 / 2) * gc.b1_y);
    glVertex2i(gc.winW / 10, (gc.winH - gc.winH / 8) - (3 / 2) * gc.b1_y);
    glVertex2i(gc.winW / 10, (gc.winH - (3 / 2) * gc.b1_y));
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);

    glVertex2i(1, gc.winH - (3 / 2) * gc.b1_y);
    glVertex2i(1, (gc.winH - gc.winH / 8) - (3 / 2) * gc.b1_y);
    glVertex2i(gc.winW / 10, (gc.winH - gc.winH / 8) - (3 / 2) * gc.b1_y);
    glVertex2i(gc.winW / 10, (gc.winH - (3 / 2) * gc.b1_y));
    glEnd();

    glRasterPos2i(50, gc.winH - (3 / 2) * gc.b1_y - 52);
    string but41 = "Delete";
    for (int i = 0; i < but41.length(); i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, but41[i]);

    gc.b2_x = gc.winW / 10; //ставим координаты для мыши другие
    gc.b2_y = gc.winH / 8 + (3 / 2) * gc.b1_y;//так как там другия сисетема координат
}

void drawButton3() //кнопка вывода атрибутов в консоль
{
    if (gc.b3_state == 1)
        glColor3f(0.6f, 0.6f, 0.6f);
    else
        glColor3f(0.902f, 0.902f, 0.980f);
    glBegin(GL_QUADS);
    glVertex2i(1, gc.winH - (3 / 2) * gc.b2_y);
    glVertex2i(1, (gc.winH - gc.winH / 8) - (3 / 2) * gc.b2_y);
    glVertex2i(gc.winW / 12, (gc.winH - gc.winH / 8) - (3 / 2) * gc.b2_y);
    glVertex2i(gc.winW / 10, (gc.winH - (3 / 2) * gc.b2_y));
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);

    glVertex2i(1, gc.winH - (3 / 2) * gc.b2_y);
    glVertex2i(1, (gc.winH - gc.winH / 8) - (3 / 2) * gc.b2_y);
    glVertex2i(gc.winW / 12, (gc.winH - gc.winH / 8) - (3 / 2) * gc.b2_y);
    glVertex2i(gc.winW / 10, (gc.winH - (3 / 2) * gc.b2_y));
    glEnd();

    glRasterPos2i(42, gc.winH - (3 / 2) * gc.b2_y - 52);
    string but31 = "Console";
    for (int i = 0; i < but31.length(); i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, but31[i]);

    gc.b3_x = gc.winW / 10;//ставим координаты для мыши другие
    gc.b3_y = gc.winH / 8 + (3 / 2) * gc.b2_y;//так как там другия сисетема координат
}

void drawCircle(int x, int y) //рисуем круг в заданных координатах
{
    glColor3f(0.902f, 0.902f, 0.980f);
    float x1, y1;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(360);
        y1 = gc.R * cos(theta) + y;
        x1 = gc.R * sin(theta) + x;;

        glVertex2f(x1, y1);
    }
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    float x2, y2;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(360);
        y2 = gc.R * cos(theta) + y;
        x2 = gc.R * sin(theta) + x;;

        glVertex2f(x2, y2);
    }
    glEnd();
}

void drawBorderedCircle(int x, int y) //круг если мышь в зоне узла
{
    glColor3f(0.6f, 0.6f, 0.6f);
    float x1, y1;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(360);
        y1 = gc.R * cos(theta) + y;
        x1 = gc.R * sin(theta) + x;;

        glVertex2f(x1, y1);
    }
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    float x2, y2;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(360);
        y2 = gc.R * cos(theta) + y;
        x2 = gc.R * sin(theta) + x;;

        glVertex2f(x2, y2);
    }
    glEnd();
}

void drawLine(int x0, int y0, int x1, int y1) //соединяющие линии
{
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2i(x0, y0);
    glVertex2i(x1, y1);
    glEnd();
}

Tree* checkCircle(Tree* node, int x, int y) //проверяем входит ли мышь в зону круга
{
    if (pow(x - node->getX(), 2) + pow(y - node->getY(), 2) <= pow(gc.R, 2))
        return node;
    Tree* temp = NULL;
    if (node->getLeft() != NULL)
        temp = checkCircle(node->getLeft(), x, y);
    if (temp != NULL)
        return temp;
    if (node->getRight() != NULL)
        temp = checkCircle(node->getRight(), x, y);
    return temp;
}

Tree* Tree::getNode(int x, int y) //и получаем этот узел
{
    Tree* node = this;
    node = checkCircle(node, x, y);
    return node;
}

void display() //функция отображения
{
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, gc.winW, 0, gc.winH); //ставим начало координат в левый нижний угол
    glViewport(0, 0, gc.winW, gc.winH);
    glClearColor(0.941, 0.973, 1.000, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Tree* tree = gc.tree;
    int R = 3 * (gc.winH / gc.treeH) / 4;   //высчитываем нужный радиус
    gc.R = (R / 2) / (gc.winH / gc.winW + 1) - gc.shift;
    tree->reorderSetCoords(tree, '0'); //проставляем координаты
    queue<Tree*> Q; //очередь для записи DATA
    Tree* current = NULL;; //текущий элемент

    Q.push(tree);
    int x0, y0, x1, y1;

    drawButton1();  //отрисовка кнопок
    drawButton2();
    drawButton3();

    while (!Q.empty())
    {
        tree = Q.front();   //1 элемент очереди
        Q.pop();
        x0 = tree->getX();  //получаем его координаты
        y0 = tree->getY();
        if (tree->getLeft())    //если у него есть левый потомок
        {
            current = tree->getLeft();
            Q.push(current);    //записываем в очередь
            x1 = current->getX();   //и получаем его координаты
            y1 = current->getY();
            drawLine(x0, y0, x1, y1);   //отрисовка соед. линии
        }
        if (tree->getRight()) //и то же самое с правым
        {
            current = tree->getRight();
            Q.push(current);
            x1 = current->getX();
            y1 = current->getY();
            drawLine(x1, y1, x0, y0);
        }
        drawCircle(x0, y0);		//отрисока круга 
        drawText(tree->getCountry(), x0, y0, false);    //и текста

        if (tree->getCursor())  //если курсор в зоне круга
        {
            drawBorderedCircle(x0, y0); //рисуем другой круг
            drawText(tree->getCountry(), x0, y0, true);//и текст
            tree->setCursor(false);
        }
    }
    glutSwapBuffers();
}

void mouseMove(int x, int y) //функция отслеживания движения мыши
{
    Tree* node = gc.tree->getNode(x, gc.winH - y);

    if (node != NULL)
    {
        node->setCursor(true);
    }

    if (x <= gc.b1_x and y <= gc.b1_y)  //если входит в одну из кнопок
        gc.b1_state = 1;
    else
        gc.b1_state = 0;

    if (x <= gc.b2_x and y <= gc.b2_y && y >= gc.b1_y)
        gc.b2_state = 1;
    else
        gc.b2_state = 0;

    if (x <= gc.b3_x and y <= gc.b3_y && y >= gc.b2_y)
        gc.b3_state = 1;
    else
        gc.b3_state = 0;
    glutPostRedisplay(); //перерисовка
}

void mouseClick(int button, int state, int x, int y) //отслеживание нажатий
{
    if (x <= gc.b1_x and y <= gc.b1_y) //1 кнопка +
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) //если нажато
        {
            ii = 0;
            drawTree(gc.winW, gc.winH, 10, 1);//добавляем 1 узел
        }
    }
    if (x <= gc.b2_x and y <= gc.b2_y and y >= gc.b1_y) //2 кнопка -
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
        {
            if (gc.nodes == 1)
                cout << "\nYou can't delete root!\n";   //корень удалить нельзя
            else
            {
                string dt;
                ii = 0;
                cout << "\nDelete: ";
                getline(cin, dt);

                for (vector<string>::iterator i = V.begin(); i != V.end(); i++) //ищем заданный ключ
                {
                    if (dt == *i)
                    {
                        vector<string>::iterator j = i;
                        V.erase(j); //и удаляем его
                        gc.nodes--;
                        break;
                    }
                }
                drawTree(gc.winW, gc.winH, 10, 0); //перерисовываем дерево
            }
        }
    }
    if (x <= gc.b3_x and y <= gc.b3_y and y >= gc.b2_y) //3 кнопка атрибуты
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
        {
            gc.tree->reorderAtributes(gc.tree); //печать атрибутов
        }
    }
}

void reshape(int w, int h) //решейп))
{
    gc.winW = w;
    gc.winH = h;
    glViewport(0, 0, (GLsizei)gc.winW, (GLsizei)gc.winH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, (GLdouble)gc.winW, 0, (GLdouble)gc.winH);
    glutPostRedisplay();
}

void drawText(string data, int x0, int y0, bool state) //отрисовка текста на узлах
{
    if (gc.winH < 375 or gc.winW < 375)
        return;

    GLvoid* font_style;
    int counter = 0;
    vector<string> v;
    string temp;
    int strX;
    int strY = 12;

    if (state == true) //если мышь в зоне кнопки
    {
        font_style = GLUT_BITMAP_9_BY_15;
        glColor3f(0.0f, 0.0f, 0.0f);
        strX = 8;
    }
    else   //иначе
    {
        glColor3f(0.0f, 0.0f, 0.0f);
        font_style = GLUT_BITMAP_9_BY_15;
        strX = 8;
    }
    for (int i = 0; i < data.length() + 1; i++) //если несколько слов делим строку
    {
        temp += data[i];
        if (data[i] == ' ' or data[i] == '\0')
        {
            counter++;
            v.push_back(temp);
            temp = "";
        }
    }
    int y = y0 + ((strY * counter / 2)) - 5; // первоначальный отступ по Y вверх
    for (int i = 0; i < v.size(); i++) //кол-во слов
    {
        int ka = v[i].length() / 2;    //отступ влево
        glRasterPos2i(x0 - ka * strX, y - (strY * i)); //ставим координаты
        for (int j = 0; j < v[i].length(); j++)
            glutBitmapCharacter(font_style, v[i][j]);
    }
}

void drawTree(int window_width, int window_height, int shift, int n) // функция пересобирания дерева
{
    string word;
    string* arr = new string[n];
    int size = 0;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ") Word: ";
        cin >> word;

        arr[size++] = word;  // Запись слова в массив
        sort(arr, arr + size); // Сортируем 
    }
    size = 0;
    for (int i = 0; i < n; i++)
    {
        V.push_back(arr[size++]);
        gc.nodes++;
    }
    Tree* tree = Tree::balancedTree(gc.nodes);
    gc.tree = tree;
    gc.winW = window_width;
    gc.winH = window_height;
    gc.shift = shift;
    gc.treeH = tree->height(tree);
    gc.treeW = pow(2, gc.treeH - 1); //макс. ширина дерева
    tree->reorderSetCoords(tree, '0'); //ставим координаты
    glViewport(0, 0, gc.winW, gc.winH);
}