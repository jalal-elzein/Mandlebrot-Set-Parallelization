#include <iostream>
#include <fstream>
#include <complex>
#include <time.h>

using std::complex, std::ofstream;
using std::cout;

constexpr int WIDTH{ 800 };
constexpr int HEIGHT{ 600 };
constexpr int MAX_ITERATIONS{ 1000 };
constexpr double RE_START{ -2 };
constexpr double RE_END{ 2 };
constexpr double IM_START{ -1.2 };
constexpr double IM_END{ 1.2 };
constexpr char nl{ '\n' };

// C++20 impelementation

int mandelbrot(complex<double> c) {

    complex<double> z = 0;
    int i;
    for (i = 0; i < MAX_ITERATIONS && abs(z) < 2; ++i) {

        z = (z * z) + c;

    }
    return i;

}

int main() {

    clock_t t_start, t_end;
    double t_delta;

    t_start = clock();

    ofstream file("mandelbrot.ppm");

    file << "P3" << nl;
    file << WIDTH << " " << HEIGHT << nl;
    file << "255" << nl;

    for (int y = 0; y < HEIGHT; ++y) {

        for (int x = 0; x < WIDTH; ++x) {

            double re = RE_START + (double)x / (WIDTH - 1) * (RE_END - RE_START);
            double im = IM_START + (double)y / (HEIGHT - 1) * (IM_END - IM_START);

            complex<double> c(re, im);

            int n = mandelbrot(c);
            int r = (n % 13) * 234;
            int g = (n % 69) * 69;
            int b = (n % 234) * 13;

            file << r << " " << g << " " << b << " ";

        }
        file << nl;

    }
    file.close();

    t_end = clock();
    t_delta = double(t_end - t_start) / double(CLOCKS_PER_SEC);
    cout << "Elapsed time: " << t_delta << nl;

    return 0;

}
