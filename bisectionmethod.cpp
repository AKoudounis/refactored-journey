#include <iostream>
#include <cmath>

double polynomial(double x)
{
    return (x*x*x -x*x -2);
}

bool checksign(double fa, double fc){
    
    if ((fa>0 && fc>0) || (fa<0 && fc<0))
    {
        return false;
    }
    else return true;
}


int main()
{
    const double epsilon{0.000001};
    short counter{0};
    const int NMAX{50};
    double c,root{0};
    double a{-10};
    double b{20};
    
    
    while (counter < NMAX){
        c = (a+b)/2;
        double fa = polynomial(a);
        double fc = polynomial(c);

        if (abs(fc) < epsilon){
            root = c; 
            break;
        }
        
        if(checksign(fa, fc))                 //if(fa * fc < 0)
        {
            b = c;
             
        }

        else {
            a = c; counter++;
        }
       
    }

    root = c; 
    

    std::cout << "The value of the root is : " << root;

}

