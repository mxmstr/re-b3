#include "rw.h"
#include "skeleton.h"
#include "B4ConvexHull.h"
#include <iostream>

int main() {

	// Initialize a B4ConvexHull object
	B4ConvexHull hull;
	// Example usage of B4ConvexHull methods
	hull.MakeBoxFromBoundingBox(GtMath::Vector3(-1.0f, -1.0f, -1.0f), GtMath::Vector3(1.0f, 1.0f, 1.0f));
	// Print some properties to verify
	std::cout << "Number of vertices: " << static_cast<int>(hull.m_numVertices) << std::endl;
	std::cout << "Number of planes: " << static_cast<int>(hull.m_numPlanes) << std::endl;
	std::cout << "Number of edges: " << static_cast<int>(hull.m_numEdges) << std::endl;


    return 0;
}
