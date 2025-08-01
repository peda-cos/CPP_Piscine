/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 09:42:26 by peda-cos          #+#    #+#             */
/*   Updated: 2025/08/01 14:27:12 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
#include <string>

/**
 * Helper function to run and display BSP test results
 * @param testName The name/description of the test
 * @param a First triangle vertex
 * @param b Second triangle vertex
 * @param c Third triangle vertex
 * @param point The point to test
 * @param expected The expected result (true/false)
 */
void runBspTest(const std::string& testName, const Point& a, const Point& b,
                const Point& c, const Point& point, bool expected)
{
    bool result = bsp(a, b, c, point);
    bool passed = (result == expected);

    std::cout << "TEST: " << testName << std::endl;
    std::cout << "  Result: " << (result ? "TRUE" : "FALSE");
    std::cout << " | Expected: " << (expected ? "TRUE" : "FALSE");
    std::cout << " | " << (passed ? "PASS" : "FAIL") << std::endl;
    std::cout << std::endl;
}

int main(void)
{
    std::cout << "========== BSP FUNCTION TEST SUITE ==========\n" << std::endl;

    // Standard triangle for most tests (0,0), (10,30), (20,0)
    Point stdA(0, 0);
    Point stdB(10, 30);
    Point stdC(20, 0);

    std::cout << "STANDARD TRIANGLE VERTICES:" << std::endl;
    std::cout << "  A: (0, 0)" << std::endl;
    std::cout << "  B: (10, 30)" << std::endl;
    std::cout << "  C: (20, 0)" << std::endl;
    std::cout << std::endl;

    //===== CATEGORY 1: INSIDE POINTS =====
    std::cout << "===== CATEGORY 1: INSIDE POINTS =====" << std::endl;

    // Test 1.1: Point clearly inside the triangle
    // Logic: A point well within the boundaries should return true
    runBspTest("1.1 - Clear inside point",
               stdA, stdB, stdC, Point(10, 10), true);

    // Test 1.2: Another inside point
    // Logic: Different location inside the triangle
    runBspTest("1.2 - Another inside point",
               stdA, stdB, stdC, Point(5, 5), true);

    // Test 1.3: Point very close to edge but still inside
    // Logic: Tests accuracy with points near boundaries
    runBspTest("1.3 - Point close to edge (inside)",
               stdA, stdB, stdC, Point(10, 0.1), true);

    //===== CATEGORY 2: OUTSIDE POINTS =====
    std::cout << "===== CATEGORY 2: OUTSIDE POINTS =====" << std::endl;

    // Test 2.1: Point clearly outside the triangle
    // Logic: Point is far from triangle boundaries
    runBspTest("2.1 - Clear outside point",
               stdA, stdB, stdC, Point(30, 15), false);

    // Test 2.2: Point outside but close to an edge
    // Logic: Tests accuracy with points near boundaries
    runBspTest("2.2 - Outside point close to edge",
               stdA, stdB, stdC, Point(10, -0.1), false);

    // Test 2.3: Point in the same general area but outside
    // Logic: Point is in the quadrant of the triangle but outside
    runBspTest("2.3 - Point in same area but outside",
               stdA, stdB, stdC, Point(5, 20), false);

    //===== CATEGORY 3: BOUNDARY POINTS =====
    std::cout << "===== CATEGORY 3: BOUNDARY POINTS =====" << std::endl;

    // Test 3.1: Point on vertex
    // Logic: Points on vertices should return false
    runBspTest("3.1 - Point on vertex A",
               stdA, stdB, stdC, Point(0, 0), false);

    // Test 3.2: Point on another vertex
    runBspTest("3.2 - Point on vertex B",
               stdA, stdB, stdC, Point(10, 30), false);

    // Test 3.3: Point on edge
    // Logic: Points on edges should return false
    runBspTest("3.3 - Point on horizontal edge",
               stdA, stdB, stdC, Point(10, 0), false);

    // Test 3.4: Point on sloped edge
    // Logic: Points on non-horizontal/vertical edges
    runBspTest("3.4 - Point on sloped edge",
               stdA, stdB, stdC, Point(5, 15), false);

    //===== CATEGORY 4: DEGENERATE TRIANGLES =====
    std::cout << "===== CATEGORY 4: DEGENERATE TRIANGLES =====" << std::endl;

    // Test 4.1: Zero-area triangle (collinear points)
    // Logic: Triangle with vertices in a straight line
    runBspTest("4.1 - Collinear triangle vertices",
               Point(0, 0), Point(10, 0), Point(20, 0),
               Point(5, 0), false);

    // Test 4.2: Zero-area triangle (identical points)
    // Logic: Triangle with all vertices at same point
    runBspTest("4.2 - All vertices at same point",
               Point(5, 5), Point(5, 5), Point(5, 5),
               Point(5, 5), false);

    // Test 4.3: Point with two vertices identical
    // Logic: Triangle with two identical vertices
    runBspTest("4.3 - Two vertices at same point",
               Point(0, 0), Point(0, 0), Point(10, 10),
               Point(5, 5), false);

    //===== CATEGORY 5: DIFFERENT TRIANGLE ORIENTATIONS =====
    std::cout << "===== CATEGORY 5: DIFFERENT TRIANGLE ORIENTATIONS =====" << std::endl;

    // Test 5.1: Triangle in different quadrant (all negative)
    // Logic: Tests with negative coordinates
    Point negA(-20, -10);
    Point negB(-10, -30);
    Point negC(-5, -5);
    runBspTest("5.1 - Negative coordinates triangle",
               negA, negB, negC,
               Point(-10, -15), true);

    // Test 5.2: Triangle crossing quadrants
    // Logic: Tests with coordinates in multiple quadrants
    Point mixA(-10, -10);
    Point mixB(10, 10);
    Point mixC(10, -10);
    runBspTest("5.2 - Triangle crossing quadrants",
               mixA, mixB, mixC,
               Point(0, -5), true);

    // Test 5.3: Very thin triangle
    // Logic: Tests accuracy with nearly collinear vertices
    Point thinA(0, 0);
    Point thinB(10, 0.1);
    Point thinC(20, 0);
    runBspTest("5.3 - Very thin triangle inside point",
               thinA, thinB, thinC,
               Point(10, 0.05), true);

    runBspTest("5.4 - Very thin triangle outside point",
               thinA, thinB, thinC,
               Point(10, 0.2), false);

    //===== CATEGORY 6: VERTEX ORDER =====
    std::cout << "===== CATEGORY 6: VERTEX ORDER =====" << std::endl;

    // Test 6.1: Reverse vertex order
    // Logic: Tests if algorithm handles different vertex orderings
    runBspTest("6.1 - Reverse vertex order",
               stdC, stdB, stdA, Point(10, 10), true);

    // Test 6.2: Different vertex order
    runBspTest("6.2 - Different vertex order",
               stdB, stdA, stdC, Point(10, 10), true);

    return (0);
}
