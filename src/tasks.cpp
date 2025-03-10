// Copyright 2025 Sorochkin
#include "tasks.h"
#include "circle.h"

double calculateRopeGap() {
    Circle earth(6378100); // Радиус в метрах
    earth.setFerence(earth.getFerence() + 1);
    return earth.getRadius() - 6378100;
}

double calculatePoolCost() {
    Circle pool(3);
    Circle walkway(4);
    double walkwayArea = walkway.getArea() - pool.getArea();
    double fenceCost = walkway.getFerence() * 2000;
    double concreteCost = walkwayArea * 1000;
    return fenceCost + concreteCost;
}
