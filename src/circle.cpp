// Copyright 2022 UNN-CS
#include <cstdint>
#include "circle.h"

Circle::Circle(double r) { setRadius(r); }

void Circle::updateFromRadius() {
    ference = 2 * M_PI * radius;
    area = M_PI * radius * radius;
}

void Circle::updateFromFerence() {
    radius = ference / (2 * M_PI);
    area = M_PI * radius * radius;
}

void Circle::updateFromArea() {
    radius = sqrt(area / M_PI);
    ference = 2 * M_PI * radius;
}

void Circle::setRadius(double r) {
    radius = r;
    updateFromRadius();
}

void Circle::setFerence(double f) {
    ference = f;
    updateFromFerence();
}

void Circle::setArea(double a) {
    area = a;
    updateFromArea();
}

double Circle::getRadius() const { return radius; }

double Circle::getFerence() const { return ference; }

double Circle::getArea() const { return area; }
