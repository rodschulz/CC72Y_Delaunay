/**
 * Author: rodrigo
 * 2015
 */
#pragma once

#include <vector>
#include <string>
#include "Triangle.h"

#include "opencv/cxcore.h"
#include "opencv/cv.h"
#include "opencv/highgui.h"

using namespace std;
using namespace cv;

class Printer
{
public:
	// Generates a base image
	static Mat generateBaseImage();
	// Prints the given vertices in the given image
	static void printVertices(Mat &_image, const vector<VertexPtr> &_vertices);
	// Prints the given triangles in the given image
	static void printTriangulation(Mat &_image, const vector<TrianglePtr> &_triangulation);
	// Prints the given triangles in the given image
	static void printSelectedTriangles(Mat &_image, const vector<TrianglePtr> &_selected);
	// Prints the neighbors relations of the given triangle
	static void printNeighbors(Mat &_image, const TrianglePtr &_triangle);
	// Saves the given image to disk
	static void saveImage(const string &_outputName, const Mat &_image);

private:
	Printer();
	~Printer();

	// Converts a point from xy coordinates to pixels
	static Point convert(const double _x, const double _y);
	// Converts a vertex from xy coordinates to pixels
	static Point convert(const Vertex &_vertex);
	// Draws the given triangle in the given image
	static void drawTriangle(Mat &_image, const TrianglePtr &_triangle, const Scalar &_color);
	// Draws the given point in the given image
	static void drawPoint(Mat &_image, const VertexPtr &_vertex);
};
