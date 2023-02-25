#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <mpi.h>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;
const int MAX_ITERATIONS = 1000;
const double xmin = -2.0;
const double xmax = 1.0;
const double ymin = -1.5;
const double ymax = 1.5;

void calculatePixel(int row, int col, int* result);
void saveImage(int* data, const char* filename);

int main(int argc, char** argv) {
    int rank, size;
    double t_start, t_end, t_delta;
    MPI_Init(&argc, &argv);
    t_start = MPI_Wtime();
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int numPixels = WIDTH * (HEIGHT / size);
    int* localResult = new int[numPixels];

    int startRow = rank * (HEIGHT / size);
    int endRow = (rank + 1) * (HEIGHT / size) - 1;

    for (int row = startRow; row <= endRow; row++) {
        for (int col = 0; col < WIDTH; col++) {
            int index = (row - startRow) * WIDTH + col;
            calculatePixel(row, col, &localResult[index]);
        }
    }

    int* globalResult = NULL;
    if (rank == 0) {
        globalResult = new int[WIDTH * HEIGHT];
    }

    MPI_Gather(localResult, numPixels, MPI_INT, globalResult, numPixels, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        saveImage(globalResult, "mandelbrot.ppm");
        delete[] globalResult;
    }

    delete[] localResult;

    t_end = MPI_Wtime();
    t_delta = t_end - t_start;
    cout << "Elapsed time: " << t_deta << '\n';

    MPI_Finalize();

    return 0;
}

void calculatePixel(int row, int col, int* result) {
    double x0 = xmin + (xmax - xmin) * col / WIDTH;
    double y0 = ymin + (ymax - ymin) * row / HEIGHT;

    double x = 0.0;
    double y = 0.0;
    int iteration = 0;
    while (x*x + y*y <= 2*2 && iteration < MAX_ITERATIONS) {
        double xtemp = x*x - y*y + x0;
        y = 2*x*y + y0;
        x = xtemp;
        iteration++;
    }

    *result = iteration;
}

void saveImage(int* data, const char* filename) {
    ofstream file(filename);
    file << "P3" << endl;
    file << WIDTH << " " << HEIGHT << endl;
    file << "255" << endl;
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int value = data[i];
        int r = value % 256;
        int g = (value / 256) % 256;
        int b = (value / 256 / 256) % 256;
        file << r << " " << g << " " << b << " ";
    }
    file.close();
}
