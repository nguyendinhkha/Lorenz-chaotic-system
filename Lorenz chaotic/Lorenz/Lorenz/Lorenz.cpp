#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;
#define N 1000

int main(int argc, char** argv)
{
    random_device random;
    mt19937 rng(random());
    uniform_int_distribution<int> uni(-20, 20);
    auto x0 = uni(rng);

    uniform_int_distribution<int> cast(-40, 40);
    auto y0 = cast(rng);

    uniform_int_distribution<int> inter(0, 50);
    auto z0 = inter(rng);

    float sigma = 10;
    float rho = 28;
    float beta = 8.0 / 3.0;

    double dx, dy, dz;
    double dt = 0.01;

    double x, y, z;
    x = x0;
    y = y0;
    z = z0;

    for (int i = 0; i < N; i++)
    {
        dx = x + (sigma * (y - x)) * dt;
        dy = y + (x * (rho - z) - y) * dt;
        dz = z + (x * y - beta * z) * dt;
        x = dx;
        y = dy;
        z = dz;

        cout << i << "   " << x << "   " << y << "   " << z << endl;
    }
    /*
    x = x + dx;
    y = y + dy;
    z = z + dz;
    */
    return 0;
}