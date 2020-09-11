#include <iostream>
#include <cmath>
#include <functional>
#include <vector>


double x_func (double x){
    std::cout << "x_func \n";
    return x;
}

double x_square_func (double x){
    std::cout << "x_square_func \n";
    return x*x;
}


const int number_of_functions = 4;
const char *functions[number_of_functions] = {"x", "x^2", "cos(x)", "sin(x)"};
std::vector <std::function<double(double)>> func_vect = {x_func, x_square_func, cos, sin};

int main() {
    std::function<double(double)> function_;

    bool function_choose = true;
    while(function_choose){
        std::cout << "Write number to choose function \n";
        for (int i = 0; i < func_vect.size(); i++){
            std::cout << i+1 << ". " << functions[i] << std::endl;
        }

        int number;
        std::cin >> number;

        if (number > func_vect.size()){
            std::cout << "Incorrect input. Try again \n";
        }
        else {
            function_ = func_vect[number - 1];
            function_choose = false;
        }
    }
    double start, end;

    bool segment_choose = true;
    while(segment_choose){
        std::cout << "Choose integration segment boundaries \n";
        std::cout << "Starting point: \n";
        std::cin >> start;
        std::cout << "Ending point: \n";
        std::cin >> end;
        if (start > end){
            std::cout << "Incorrect input. Try again \n";
        }
        else{
            segment_choose = false;
        }
    }

    

}
