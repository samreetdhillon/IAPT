#include<iostream>
#include<fstream>
#include<cmath>
#include "rk4C3.hpp"
#include "ralstonC3.hpp"
class field {
private:
    double q, m, vx, vy, vz, Ex, Ey, Ez, Bx, By, Bz, h, val, ax, ay, az, A, B;
public:
    field() {
        std::cout << "Enter the charge and mass of the particle:\n";
        std::cin >> q >> m;
        std::cout << "Enter X, Y and Z components of initial velocity:\n";
        std::cin >> vx >> vy >> vz;
        std::cout << "Enter the X, Y and Z components of E field:\n";
        std::cin >> Ex >> Ey >> Ez;
        std::cout << "Enter the X, Y and Z components of B field:\n";
        std::cin >> Bx >> By >> Bz;
    
        std::cout<<"::For numerical Method ::\n";
        std::cout<<"::    1 for Euler      ::\n";
        std::cout<<"::     2 for Fn        ::\n";
        std::cout<<"::   3 for Ralston     ::\n";
        std::cout<<":: 4 for Runge-Kutta   ::\n";
        std::cout<<"::Enter the value selected from above::\n";
        std::cin>>val;     
         
    }

    double AX(double x1, double y1, double z1, double vx1, double vy1, double vz1) {
        return q * (Ex + (vy1 * Bz - vz1 * By)) / m;
    }

    double AY(double x1, double y1, double z1, double vx1, double vy1, double vz1) {
        return q * (Ey + (vz1 * Bx - vx1 * Bz)) / m;
    }

    double AZ(double x1, double y1, double z1, double vx1, double vy1, double vz1) {
        return q * (Ez + (vx1 * By - vy1 * Bx)) / m;
    }

    void solve() {
        std::ofstream out("charge.dat");
        double n = 3000;
        h = 0.0015;
        double x = 0;
        double y = 0;
        double z = 0;

for (double i = 0; i < n; i++) {
 
 if(val == 1.0){
 euler3(std::bind(&field::AX, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      std::bind(&field::AY, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      std::bind(&field::AZ, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      x, y, z, vx, vy, vz, h);}

else if(val == 2.0){
 fn3(std::bind(&field::AX, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      std::bind(&field::AY, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      std::bind(&field::AZ, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      x, y, z, vx, vy, vz, h);}

else if(val == 3.0){
 ralston3(std::bind(&field::AX, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      std::bind(&field::AY, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      std::bind(&field::AZ, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      x, y, z, vx, vy, vz, h);}

else if(val == 4.0){
 rk43(std::bind(&field::AX, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      std::bind(&field::AY, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      std::bind(&field::AZ, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      x, y, z, vx, vy, vz, h);}

else {
std::cout<<"ERROR !!Not Any Method!!\n";
break;
}
            out << x << "  " << y << "  " << z << "\n";
        }
    }
};
int main(){
field c1;
c1.solve();
return 0;    
}
