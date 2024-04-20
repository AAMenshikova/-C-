#include "head.h"
#include <iostream>
#include <cmath>

std::vector<allFigure *> all;

void add_figure() {
    std::cout << "What type of figure do you want to add?\n";
    std::cout << "1. triangle\n";
    std::cout << "2. parallelogram\n";
    std::cout << "0. No one. Exit\n";
    int fig;
    std::cin >> fig;
    switch (fig) {
        case 1: {
            Triangle *newTriangle = new Triangle();
            newTriangle->initFromDialog();
            all.push_back(newTriangle);
            break;
        }
        case 2: {
            Parallelogram *newParall = new Parallelogram();
            newParall->initFromDialog();
            all.push_back(newParall);
            break;
        }
        case 0:
            return;
        default:
            std::cout << "There is no such choice." << std::endl;
            return;
    }

}

const std::string Triangle::classname() {
    return "Triangle";
}

unsigned int Triangle::size() {
    return sizeof(*this);
}

const std::string Parallelogram::classname() {
    return "Parallelogram";
}

unsigned int Parallelogram::size() {
    return sizeof(*this);
}

void sort() {
    for (int j = 1; j < all.size(); j++) {
        allFigure *key = all[j];
        int i = j - 1;
        while (i >= 0 and key->mass < all[i]->mass) {
            all[i + 1] = all[i];
            i--;
        }
        all[i + 1] = key;
    }
}

void print() {
    bool triangles = false;
    bool parallelograms = false;
    if (!all.empty()) {
        for (allFigure *figure: all) {
            if (figure->classname() == "triangle") {
                if (!triangles) {
                    std::cout << "position of all triangles: " << figure->resPos().x << ", " << figure->resPos().y
                              << "\n";
                    std::cout << "summary area of all triangles: " << figure->sumAllArea() << "\n";
                    std::cout << "summary perimeters of all triangles: " << figure->sumALlPerimeters() << "\n";
                    std::cout << "summary memory of all triangles: " << figure->memory() << "\n";
                    triangles = true;
                }
            }
            if (figure->classname() == "parallelogram") {
                if (!parallelograms) {
                    std::cout << "position of all parallelograms: " << figure->resPos().x << ", " << figure->resPos().y
                              << "\n";
                    std::cout << "summary area of all parallelograms: " << figure->sumAllArea() << "\n";
                    std::cout << "summary perimeters of all parallelograms: " << figure->sumALlPerimeters() << "\n";
                    std::cout << "summary memory of all parallelograms: " << figure->memory() << "\n";
                    parallelograms = true;
                }
            }
            figure->draw();
        }
    } else { std::cout << "empty"; }
}

void clear_figure() {
    for (allFigure *figure: all) {
        delete figure;
    }
    all.clear();
}


void Triangle::initFromDialog() {
    std::cout << "text the side length in double" << "\n";
    std::cin >> length;
    std::cout << "text the center in double (x, y)" << "\n";
    std::cin >> center.x >> center.y;
    std::cout << "text the mass in double" << "\n";
    std::cin >> triangle_mass;
}

void Triangle::draw() {
    std::cout << "Triangle:\n" << "side length: " << length << "\n" << "center: " << center.x
              << ", " << center.y << "\n" << "mass: " << triangle_mass << "\n\n";
}

double Triangle::Area() {
    return length * length * sqrt(3) / 4;
}

double Triangle::Perimeter() {
    return 3 * length;
}

double Triangle::sumAllArea() {
    double all_sum = 0;
    for (allFigure *figure: all) {
        if (figure->classname() == "triangle") {
            all_sum += figure->Area();
        }
    }
    return all_sum;
}

double Triangle::sumALlPerimeters() {
    double all_sum = 0;
    for (allFigure *figure: all) {
        if (figure->classname() == "triangle") {
            all_sum += figure->Perimeter();
        }
    }
    return all_sum;
}

void Parallelogram::initFromDialog() {
    std::cout << "text the sides length in double" << "\n";
    std::cin >> length_1 >> length_2;
    std::cout << "text the center in double (x, y)" << "\n";
    std::cin >> center.x >> center.y;
    std::cout << "text the height in double" << "\n";
    std::cin >> height;
    std::cout << "text the mass in double" << "\n";
    std::cin >> parallelogram_mass;
}

void Parallelogram::draw() {
    std::cout << "Parallelogram:\n" << "sides length: " << length_1 << ' ' << length_2 << "\n" "height: " << height
              << "\n" "center: " << center.x
              << ", " << center.y << "\n" << "mass: " << parallelogram_mass << "\n\n";
}

double Parallelogram::Area() {
    return height * length_1;
}

double Parallelogram::Perimeter() {
    return 2 * (length_1 + length_2);
}

CVector2D CVector2D::operator+(const CVector2D &other) const {
    CVector2D tmp{};
    tmp.x = this->x + other.x;
    tmp.y = this->y + other.y;
    return tmp;
}

CVector2D CVector2D::operator-(const CVector2D &other) const {
    CVector2D tmp{};
    tmp.x = this->x - other.x;
    tmp.y = this->y - other.y;
    return tmp;
}

CVector2D CVector2D::operator/(int num) const {
    CVector2D tmp{};
    tmp.x = this->x / num;
    tmp.y = this->y / num;
    return tmp;
}

CVector2D CVector2D::operator*(int num) const {
    CVector2D tmp{};
    tmp.x = this->x * num;
    tmp.y = this->y * num;
    return tmp;
}

CVector2D Triangle::position() {
    return center;
}

CVector2D Triangle::resPos() {
    CVector2D res = {0.0, 0.0};
    int m = 0;
    for (allFigure *figure: all) {
        if (figure->classname() == "triangle") {
            res = res + figure->position() * figure->mass;
            m += figure->mass;
        }
    }
    res = res / m;
    return res;
}

unsigned int Triangle::memory() {
    unsigned int all_memory = 0;
    for (allFigure *figure: all) {
        if (figure->classname() == "triangle") {
            all_memory += figure->size();
        }
    }
    return all_memory;
}

bool Triangle::operator==(const Triangle &other) {
    return this->mass == other.mass;
}

bool Triangle::operator>(const Triangle &other) {
    return this->mass > other.mass;
}

bool Triangle::operator<(const Triangle &other) {
    return this->mass < other.mass;
}


CVector2D Parallelogram::position() {
    return center;
}

CVector2D Parallelogram::resPos() {
    CVector2D res = {0.0, 0.0};
    int m = 0;
    for (allFigure *figure: all) {
        if (figure->classname() == "parallelogram") {
            res = res + figure->position() * figure->mass;
            m += figure->mass;
        }
    }
    res = res / m;
    return res;
}

unsigned int Parallelogram::memory() {
    unsigned int all_memory = 0;
    for (allFigure *figure: all) {
        if (figure->classname() == "parallelogram") {
            all_memory += figure->size();
        }
    }
    return all_memory;
}

double Parallelogram::sumAllArea() {
    double all_sum = 0;
    for (allFigure *figure: all) {
        if (figure->classname() == "parallelogram") {
            all_sum += figure->Area();
        }
    }
    return all_sum;
}

double Parallelogram::sumALlPerimeters() {
    double all_sum = 0;
    for (allFigure *figure: all) {
        if (figure->classname() == "parallelogram") {
            all_sum += figure->Perimeter();
        }
    }
    return all_sum;
}

bool Parallelogram::operator==(const Parallelogram &other) const {
    return this->mass == other.mass;
}

bool Parallelogram::operator>(const Parallelogram &other) const {
    return this->mass > other.mass;
}

bool Parallelogram::operator<(const Parallelogram &other) const {
    return this->mass < other.mass;
}
