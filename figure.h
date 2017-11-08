#ifndef _FIGURE_H
#define _FIGURE_H

#include <cmath>
#include <iostream>
#define pi 3.14

using namespace std;

class figure {
public:
	virtual ~figure() {}
	virtual double get_figure_area() = 0;
	virtual double get_figure_amount() = 0;
	virtual void show_parameters() = 0;
};

class cylinder : public figure {
public:
	cylinder(double pradius, double pheight) : radius(pradius), height(pheight) {}

	double get_figure_area() {
		return ((pi * pow(radius,2) * 2) + (2 * pi * radius * height));
	}

	double get_figure_amount() {
		return (pi * pow(radius, 2) * height);
	}

	void show_parameters() {
		cout << "Radius:" << radius << ", height:" << height << endl;
	}

	void set_radius(double pradius) {
		radius = pradius;
	}

	void set_height(double pheight) {
		height = pheight;
	}

	double get_radius() {
		return radius;
	}

	double get_height() {
		return height;
	}
private:
	double radius;
	double height;
};

class paralellepiped : public figure {
public:
	paralellepiped(double plength, double pwidth, double pheight) :
		length(plength), width(pwidth), height(pheight) {}

	double get_figure_area() {
		return ((length * width * 2) + (2 * (length + width) * height));
	}

	double get_figure_amount() {
		return (length * width * height);
	}

	void show_parameters() {
		cout << "Length:" << length << ", width:" << width << ", height:" << height << endl;
	}

	void set_length(double plength) {
		length = plength;
	}

	void set_width(double pwidth) {
		width = pwidth;
	}

	void set_height(double pheight) {
		height = pheight;
	}

	double get_length() {
		return length;
	}

	double get_width() {
		return width;
	}

	double get_height() {
		return height;
	}
private:
	double length;
	double width;
	double height;
};

#endif