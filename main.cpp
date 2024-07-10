#include <pybind11/pybind11.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include "MASTER.hpp"
using namespace std;

string mainserver(double prog_choice, double val, double m, double r, double V0, double th, double c,
                  double L, double C, double R, double initialTime, double finalTime, double I, double Q, double n,
                  double m1, double m2, double l1, double l2, double o11, double o22, double g)
{
    Master Free;
    string response = Free.Slave(prog_choice, val, m, r, V0, th, c,
                                 L, C, R, initialTime, finalTime, I, Q, n,
                                 m1, m2, l1, l2, o11, o22, g);
    return response;
}

PYBIND11_MODULE(cpp_function, m)
{
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("run", &mainserver, "The main entry point for access to C++ code from Python");
}
