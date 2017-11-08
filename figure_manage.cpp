#ifndef _FIGURE_MANAGE
#define _FIGURE_MANAGE

#include <cstdlib>
#include <ctime>
#include "figure.h"
#include "figure_manage.h"

using namespace std;

void rand_figure_create(figure **array, int size) {
	for (int i = 0; i < size; i++) {
		try{
			switch ((rand()+(int)clock()) % 2) {
			case 0:
				array[i] = new cylinder(((double)clock()) + rand() / 100, (((double)clock()) * rand() /45));
				break;
			case 1:
				array[i] = new paralellepiped((double)clock() / (i+1), (double)clock() / (i + 3), (double)clock() / (i + 2));
				break;
			default:
				cerr << "Error:wrong function computing!\n";

				for(int j = 0; j < i; j++) {
					delete[] array[j];
				}

				throw 1;
			}
		}
		catch (bad_alloc ba) {
			cerr << "Error:can`t allocate memory!\n";
			delete_figures(array, i);
			throw;
		}
	}
}

void delete_figures(figure **array, int size) {
	for (int i = 0; i < size; i++) {
		delete array[i];
	}
}

void show(figure **array, int size) {
	for (int i = 0; i < size; i++) {
		array[i]->show_parameters();
		cout <<  "figure area:" << array[i]->get_figure_area() << endl;
		cout <<  "figure amount:" << array[i]->get_figure_amount() << endl << endl;
	}
}

#endif