// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"

TEST(CircleTest, Radius) {
    Circle c(10);
    EXPECT_NEAR(c.getRadius(), 10, 1e-6);
    EXPECT_NEAR(c.getFerence(), 62.8319, 1e-4);
    EXPECT_NEAR(c.getArea(), 314.159, 1e-3);
}

TEST(CircleTest, SetFerence) {
    Circle c(10);
    c.setFerence(62.8319);
    EXPECT_NEAR(c.getRadius(), 10, 1e-6);
    EXPECT_NEAR(c.getArea(), 314.159, 1e-3);
}

TEST(CircleTest, SetArea) {
    Circle c(10);
    c.setArea(314.159);
    EXPECT_NEAR(c.getRadius(), 10, 1e-6);
    EXPECT_NEAR(c.getFerence(), 62.8319, 1e-4);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0);
    EXPECT_NEAR(c.getFerence(), 0, 1e-6);
    EXPECT_NEAR(c.getArea(), 0, 1e-6);
}

TEST(CircleTest, SmallRadius) {
    Circle c(0.1);
    EXPECT_NEAR(c.getFerence(), 0.6283, 1e-4);
    EXPECT_NEAR(c.getArea(), 0.0314, 1e-4);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1000);
    EXPECT_NEAR(c.getFerence(), 6283.1853, 1e-4);
    EXPECT_NEAR(c.getArea(), 3141592.6535, 1e-4);
}

TEST(TasksTest, RopeGap) {
    EXPECT_NEAR(calculateRopeGap(), 0.1592, 1e-4);
}

TEST(TasksTest, PoolCost) {
    EXPECT_NEAR(calculatePoolCost(), 125600, 1);
}

TEST(CircleTest, ChangeRadius) {
    Circle c(5);
    c.setRadius(7);
    EXPECT_NEAR(c.getFerence(), 43.9823, 1e-4);
    EXPECT_NEAR(c.getArea(), 153.938, 1e-3);
}

TEST(CircleTest, ChangeFerence) {
    Circle c(5);
    c.setFerence(31.4159);
    EXPECT_NEAR(c.getRadius(), 5, 1e-6);
    EXPECT_NEAR(c.getArea(), 78.5398, 1e-4);
}

TEST(CircleTest, ChangeArea) {
    Circle c(5);
    c.setArea(78.5398);
    EXPECT_NEAR(c.getRadius(), 5, 1e-6);
    EXPECT_NEAR(c.getFerence(), 31.4159, 1e-4);
}

TEST(CircleTest, NegativeRadius) {
    Circle c(-5);
    EXPECT_GE(c.getRadius(), 0);
}

TEST(CircleTest, NegativeFerence) {
    Circle c(5);
    c.setFerence(-10);
    EXPECT_GE(c.getFerence(), 0);
}

TEST(CircleTest, NegativeArea) {
    Circle c(5);
    c.setArea(-10);
    EXPECT_GE(c.getArea(), 0);
}



