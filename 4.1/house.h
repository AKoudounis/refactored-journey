#include <string>

using namespace std;

class House{

private:
    int age;
    string type;
    int numberofrooms;
    double cost;

public:

    House();


    void setAge(int);
    int getAge()const;

    void setType(string);
    string getType()const;

    void setNumberofrooms(int);
    int getNumberofrooms()const;

    void setCost(double);
    double getCost()const;


    double estimatePrice();

   
    ~House();

};