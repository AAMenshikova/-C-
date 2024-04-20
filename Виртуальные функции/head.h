#ifndef INC_4____HEAD_H
#define INC_4____HEAD_H

#include <iostream>
#include <cmath>
#include <vector>

void add_figure();

void clear_figure();

void print();

void sort();

class CVector2D {
public:
    double x, y;

    CVector2D operator+(const CVector2D &other) const;

    CVector2D operator-(const CVector2D &other) const;

    CVector2D operator/(int num) const;

    CVector2D operator*(int num) const;
};

class allFigure {
public:
    int mass = 1;

    virtual const std::string classname() = 0;

    virtual unsigned int size() = 0;

    virtual void initFromDialog() = 0;

    virtual void draw() = 0;

    virtual double Area() = 0;

    virtual double Perimeter() = 0;

    virtual double sumAllArea() = 0;

    virtual double sumALlPerimeters() = 0;

    virtual CVector2D position() = 0;

    virtual CVector2D resPos() = 0;

    virtual unsigned int memory() = 0;
};

class Triangle : public allFigure {
private:
    double length;
    double triangle_mass;
    CVector2D center;
public:
    bool operator==(const Triangle &other);

    bool operator>(const Triangle &other);

    bool operator<(const Triangle &other);

    const std::string classname() override;

    unsigned int size() override;

    void initFromDialog() override;

    void draw() override;

    double Area() override;

    double Perimeter() override;

    double sumAllArea() override;

    double sumALlPerimeters() override;

    CVector2D position() override;

    CVector2D resPos() override;

    unsigned int memory() override;


};

class Parallelogram : public allFigure {
private:
    double length_1;
    double length_2;
    double height;
    double parallelogram_mass;
    CVector2D center;
public:

    bool operator==(const Parallelogram &other) const;

    bool operator>(const Parallelogram &other) const;

    bool operator<(const Parallelogram &other) const;

    const std::string classname() override;

    unsigned int size() override;

    void initFromDialog() override;

    void draw() override;

    double Area() override;

    double Perimeter() override;

    double sumAllArea() override;

    double sumALlPerimeters() override;

    CVector2D position() override;

    CVector2D resPos() override;

    unsigned int memory() override;

};

#endif //INC_4____HEAD_H
