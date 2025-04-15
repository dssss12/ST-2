// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double EPSILON = 1e-6;

TEST(CircleTest, BasicOperations) {
    Circle c(10);
    EXPECT_NEAR(c.getRadius(), 10, EPSILON);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 10, EPSILON);
    EXPECT_NEAR(c.getArea(), M_PI * 100, EPSILON);

    c.setFerence(100);
    EXPECT_NEAR(c.getRadius(), 100 / (2 * M_PI), EPSILON);
    EXPECT_NEAR(c.getArea(), M_PI * pow(100 / (2 * M_PI), 2), EPSILON);

    c.setArea(200);
    EXPECT_NEAR(c.getRadius(), sqrt(200 / M_PI), EPSILON);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * sqrt(200 / M_PI), EPSILON);
}

TEST(CircleTest, NegativeRadius) {
    Circle c(-10);
    EXPECT_NEAR(c.getRadius(), 0, EPSILON);
    EXPECT_NEAR(c.getFerence(), 0, EPSILON);
    EXPECT_NEAR(c.getArea(), 0, EPSILON);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0);
    EXPECT_NEAR(c.getRadius(), 0, EPSILON);
    EXPECT_NEAR(c.getFerence(), 0, EPSILON);
    EXPECT_NEAR(c.getArea(), 0, EPSILON);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1e6);
    EXPECT_NEAR(c.getRadius(), 1e6, EPSILON);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1e6, EPSILON);
    EXPECT_NEAR(c.getArea(), M_PI * 1e12, EPSILON);
}

TEST(CircleTest, SetNegativeFerence) {
    Circle c(10);
    c.setFerence(-100);
    EXPECT_NEAR(c.getFerence(), 0, EPSILON);
    EXPECT_NEAR(c.getRadius(), 0, EPSILON);
    EXPECT_NEAR(c.getArea(), 0, EPSILON);
}

TEST(CircleTest, SetNegativeArea) {
    Circle c(10);
    c.setArea(-200);
    EXPECT_NEAR(c.getArea(), 0, EPSILON);
    EXPECT_NEAR(c.getRadius(), 0, EPSILON);
    EXPECT_NEAR(c.getFerence(), 0, EPSILON);
}

TEST(CircleTest, SetZeroFerence) {
    Circle c(10);
    c.setFerence(0);
    EXPECT_NEAR(c.getFerence(), 0, EPSILON);
    EXPECT_NEAR(c.getRadius(), 0, EPSILON);
    EXPECT_NEAR(c.getArea(), 0, EPSILON);
}

TEST(CircleTest, SetZeroArea) {
    Circle c(10);
    c.setArea(0);
    EXPECT_NEAR(c.getArea(), 0, EPSILON);
    EXPECT_NEAR(c.getRadius(), 0, EPSILON);
    EXPECT_NEAR(c.getFerence(), 0, EPSILON);
}

TEST(TaskTest, RopeGap) {
    double gap = ropeGap(6378.1 * 1000);
    EXPECT_NEAR(gap, 1 / (2 * M_PI), EPSILON);
}

TEST(TaskTest, PoolCost) {
    double cost = poolCost(3, 1, 1000, 2000);
    double expected_cost = (M_PI * (16 - 9) * 1000) +
                           (8 * M_PI * 2000);
    EXPECT_NEAR(cost, expected_cost, EPSILON);
}

TEST(TaskTest, PoolCostZeroRadius) {
    double cost = poolCost(0, 1, 1000, 2000);
    double expected_cost = (M_PI * (1) * 1000) +
                           (2 * M_PI * 1 * 2000);
    EXPECT_NEAR(cost, expected_cost, EPSILON);
}

TEST(TaskTest, PoolCostZeroPathWidth) {
    double cost = poolCost(3, 0, 1000, 2000);
    double expected_cost = 0 + (6 * M_PI * 2000);
    EXPECT_NEAR(cost, expected_cost, EPSILON);
}

TEST(TaskTest, PoolCostZeroConcreteCost) {
    double cost = poolCost(3, 1, 0, 2000);
    double expected_cost = 0 + (8 * M_PI * 2000);
    EXPECT_NEAR(cost, expected_cost, EPSILON);
}

TEST(TaskTest, PoolCostZeroFenceCost) {
    double cost = poolCost(3, 1, 1000, 0);
    double expected_cost = (M_PI * (16 - 9) * 1000) + 0;
    EXPECT_NEAR(cost, expected_cost, EPSILON);
}

TEST(TaskTest, PoolCostAllZero) {
    double cost = poolCost(0, 0, 0, 0);
    double expected_cost = 0;
    EXPECT_NEAR(cost, expected_cost, EPSILON);
}

TEST(TaskTest, RopeGapZeroRadius) {
    double gap = ropeGap(0);
    EXPECT_NEAR(gap, 1 / (2 * M_PI), EPSILON);
}

TEST(TaskTest, RopeGapSmallRadius) {
    double gap = ropeGap(1);
    EXPECT_NEAR(gap, 1 / (2 * M_PI), EPSILON);
}

TEST(TaskTest, RopeGapLargeRadius) {
    double gap = ropeGap(1e6);
    EXPECT_NEAR(gap, 1 / (2 * M_PI), EPSILON);
}

TEST(TaskTest, RopeGapNegativeRadius) {
    double gap = ropeGap(-6378.1 * 1000);
    EXPECT_NEAR(gap, 1 / (2 * M_PI), EPSILON);
}

TEST(TaskTest, PoolCostLargeValues) {
    double cost = poolCost(1e6, 1e5, 5000, 3000);
    double expected_cost = (M_PI * ((1.1e6) * (1.1e6) - 1e6 * 1e6) * 5000) +
                           (2 * M_PI * 1.1e6 * 3000);
    EXPECT_NEAR(cost, expected_cost, 1.0);
}

TEST(TaskTest, RopeGapTinyRadius) {
    double gap = ropeGap(1e-6);
    EXPECT_NEAR(gap, 1 / (2 * M_PI), EPSILON);
}

TEST(TaskTest, PoolCostSmallValues) {
    double cost = poolCost(0.01, 0.005, 200, 100);
    double expected_cost = (M_PI * (0.015 * 0.015 - 0.01 * 0.01) * 200) +
                           (2 * M_PI * 0.015 * 100);
    EXPECT_NEAR(cost, expected_cost, EPSILON);
}

TEST(TaskTest, PoolCostExtremeConcreteCost) {
    double cost = poolCost(10, 5, 1e9, 100);
    double expected_cost = (M_PI * (15 * 15 - 10 * 10) * 1e9) +
                           (2 * M_PI * 15 * 100);
    EXPECT_NEAR(cost, expected_cost, EPSILON);
}

TEST(TaskTest, PoolCostExtremeFenceCost) {
    double cost = poolCost(10, 5, 100, 1e9);
    double expected_cost = (M_PI * (15 * 15 - 10 * 10) * 100) +
                           (2 * M_PI * 15 * 1e9);
    EXPECT_NEAR(cost, expected_cost, EPSILON);
}
