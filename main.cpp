#include <iostream>
#include <cmath>
#include <functional>
#include <vector>


double x_func (double& x){
    return x;
}

double x_square_func (double& x){
    return x*x;
}

double trapeze (std::function<double(double&)> f, double& start, double& end){
    std::cout << "Starting integration using trapeze method..." << std::endl;
    double step = 0.1;
    double x = start + step;
    double prev_value = f(start);
    double value = 0;

    double result = 0;
    while (x<= end){
        value = f(x);
        result += ((value + prev_value) /2) * step;
        prev_value = value;
        x += step;
    }
    return result;
}

double column (std::function<double(double&)> f, double& start, double& end){
    std::cout << "Starting integration using column method..." << std::endl;
    double step = 0.1;
    double x = start;

    double result = 0;
    while (x<= end){
        result += f(x) * step;
        x += step;
    }
    return result;
}

/*
 * func_vect - vector which contains pairs:
 *          pair.first - the name of the function as it will be presented to the user
 *          pair.second - the function itself stored in std::function
 *
 * Inter_vect - vector which contains pairs:
 *          pair.first - the name of the integration method as it will be presented to the user
 *          pair.second - the function itself stored in std::function
 * */
std::vector <std::pair<std::string, std::function<double(double&)>>> func_vect =
        {
             std::make_pair("x", x_func), std::make_pair("x^2", x_square_func),
             std::make_pair("cos(x)", cos), std::make_pair("sin(x)", sin)
         };

std::vector <std::pair<std::string, std::function<double(std::function<double(double&)>, double&, double&)>>>
        inter_vect =
                    {
                        std::make_pair("Trapeze", trapeze), std::make_pair("Column", column)
                    };

int main() {
    // Choose function for integration
    std::function<double(double&)> function_;

    bool function_choose = true;
    while(function_choose){
        std::cout << "Write number to choose function \n";
        for (int i = 0; i < func_vect.size(); i++){
            std::cout << i+1 << ". " << func_vect[i].first << std::endl;
        }

        int number;
        std::cin >> number;

        if (number > func_vect.size()){
            std::cout << "Incorrect input. Try again \n";
        }
        else {
            function_ = func_vect[number - 1].second;
            function_choose = false;
        }
    }

    // Choose integration boundaries
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

    // Choose integration method
    std::function<double(std::function<double(double&)>, double&, double&)> integration_method;

    bool inter_choose = true;
    while (inter_choose){
        std::cout << "Write number to choose integration method \n";
        for (int i = 0; i < inter_vect.size(); i++){
            std::cout << i+1 << ". " << inter_vect[i].first << std::endl;
        }

        int number;
        std::cin >> number;

        if (number > inter_vect.size()){
            std::cout << "Incorrect input. Try again \n";
        }
        else {
            integration_method = inter_vect[number - 1].second;
            inter_choose = false;
        }
    }

    // Calculate the result
    double final_result =  integration_method(function_, start, end);
    std::cout << " \nResult: \n" << final_result << std::endl;

    return 0;
}
