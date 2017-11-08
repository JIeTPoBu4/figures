#include "figure.h"
#include "figure_manage.h"

#define ARRAY_SIZE 10

using namespace std;

void rand_figure_create(figure **array, int size);
void delete_figures(figure **array, int size);
void show(figure **array, int size);

int main() {
	figure *array[ARRAY_SIZE];

	try{
		rand_figure_create(array, ARRAY_SIZE);
	}
	catch (bad_alloc ba) {
		return 1;
	}
	catch(int i) {
		return i;
	}

	show(array, ARRAY_SIZE);
	delete_figures(array, ARRAY_SIZE);

	return 0;
}

