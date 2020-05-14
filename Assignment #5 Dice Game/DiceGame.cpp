#include <iostream>
#include <iomanip>
#include <stdlib.h>
int main()
{   
    int die, score, simulations, turnTotal;
    double a = 0;
    double b = 0;
    double c = 0;
    double d = 0;
    double e = 0;
    double f = 0;
    double z = 0;
    std::cout << "Hold-at-20 turn simulations? ";
    std::cin >> simulations;
    std::cout << std::endl;
            
    srand (1000);
    score = 0;
    turnTotal = 0;
    for (int i=0; i<simulations; i++)
    {   
        while (turnTotal <= 20)
        {
            die = rand() % 6 + 1;
            if (die == 1)
            {
                turnTotal = 0;
                exit;   
            }
            turnTotal += die;   
        }
        score += turnTotal;
        if (turnTotal == 0)
        {
            z++;
        }
        else if (turnTotal == 20)
        {
            a++;
        }
        else if (turnTotal == 21)
        {
            b++;
        }
        else if (turnTotal == 22)
        {
            c++;
        }
        else if (turnTotal == 23)
        {
            d++;
        }
        else if (turnTotal == 24)
        {
            e++;
        }
        else if (turnTotal == 25)
        {
            f++;
        }
        turnTotal = 0;
    }
    std::cout << "Score" << '\t' << "Estimated Probability" << std::endl;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << " 0:" << '\t' << z / simulations << std::endl;
    std::cout << "20:" << '\t' << a / simulations << std::endl;
    std::cout << "21:" << '\t' << b / simulations << std::endl;
    std::cout << "22:" << '\t' << c / simulations << std::endl;
    std::cout << "23:" << '\t' << d / simulations << std::endl;
    std::cout << "24:" << '\t' << e / simulations << std::endl;
    std::cout << "25:" << '\t' << f / simulations << std::endl;
    
    return 0;
}
