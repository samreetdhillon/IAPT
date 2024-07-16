class drag
{
private:
    double _m, _r, _p, _mu, _c, _g, _val, _x, _v;
    double A, B;

public:
    void input(double m, double r, double p, double mu, double c, double g, double val)
    {
        _m = m;
        _r = r;
        _p = p;
        _mu = mu;
        _c = c;
        _g = g;
        _val = val;
    }

    float ono(double A, double v1, double B)
    {
        return _g - (((_p * 4 * atan(1) * _c * _r * _r) / (2 * _m)) * v1 * v1) - ((6 * 4 * atan(1) * _mu * _r * v1) / _m) - ((4 * _p * _r * _r * _r * 4 * atan(1) * _g) / (3 * _m));
    }

    float yoko(double A, double x1, double B1)
    {
        return B1;
    }

    void b(double x, double v)
    {
        double in, a;
        float h = 0.15;

        _x = x;
        _v = v;

        A = 0;
        B = 0;

        std::ofstream out("drag1.dat");
        for (float t = 0.0; t > -1; t += h)
        {
            a = ono(A, _v, B);
            out << t << "  " << _x << "  " << _v << "  " << a << "\n";
            if (_val == 1.0)
            {
                rk4A(std::bind(&drag::yoko, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), x, v, A, -h);
                rk4A(std::bind(&drag::ono, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), v, a, A, h);
            }

            else if (_val == 2.0)
            {
                eulersA(std::bind(&drag::yoko, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), x, v, A, -h);
                eulersA(std::bind(&drag::ono, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), v, a, A, h);
            }

            else if (_val == 3.0)
            {
                ralsA(std::bind(&drag::yoko, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), x, v, A, -h);
                ralsA(std::bind(&drag::ono, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), v, a, A, h);
            }

            else
            {
                std::cout << "ERROR !!Not any Method!! \n";
                break;
            }

            if (x < 0)
            {
                break;
            }
        }
        out.close();

        // Important if building for both Unix and Windows OS
        // Plot the data using gnuplot
#ifdef _WIN32
        FILE *gnuplotPipe = _popen("gnuplot -persistent", "w");
#else
        FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
#endif

        if (!gnuplotPipe)
        {
            std::cerr << "Error opening pipe to gnuplot" << std::endl;
            return;
        }
        fprintf(gnuplotPipe, "set title 'Motion Of Spherical Body'\n");
        fprintf(gnuplotPipe, "set xlabel 'Time'\n");
        fprintf(gnuplotPipe, "set ylabel 'Height/Velocity/Acceleration'\n");
        fprintf(gnuplotPipe, "plot 'drag1.dat' using 1:2 with lines title 'Height'\n");
        fprintf(gnuplotPipe, "replot 'drag1.dat' using 1:3 with lines title 'Velocity'\n");
        fprintf(gnuplotPipe, "replot 'drag1.dat' using 1:4 with lines title 'Acceleration'\n");

#ifdef _WIN32
        _pclose(gnuplotPipe);
#else
        pclose(gnuplotPipe);
#endif
        return;
    }
};