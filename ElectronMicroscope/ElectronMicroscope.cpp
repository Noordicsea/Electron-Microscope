#include <iostream>
#include <cmath>

// Define value for PI
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    char choice;

    do {
        // Variables
        double vi, ax, ay, determinedDistance;
        double yf, vfx, vfy, vf, theta;

        // User input
        std::cout << "Use 1.56e34 notation for 1.56*10^34 or the alike.\n\n";

        std::cout << "Enter the initial velocity vi (in m/s): ";
        std::cin >> vi;

        std::cout << "Enter the acceleration in x-direction ax (in m/s^2): ";
        std::cin >> ax;

        std::cout << "Enter the acceleration in y-direction ay (in m/s^2): ";
        std::cin >> ay;

        std::cout << "Enter the determined distance (in meters): ";
        std::cin >> determinedDistance;

        // Time calculation from quadratic equation
        double discriminant = vi * vi + 2 * ax * determinedDistance;
        if (discriminant < 0) {
            std::cout << "The electron cannot cover the given distance with the provided parameters." << std::endl;
            return 0;
        }

        double t = (-vi + sqrt(discriminant)) / ax;

        // (a) Position of the electron yf
        yf = 0.5 * ay * t * t;

        // (b) Velocity of the electron vf
        vfx = vi + ax * t;
        vfy = ay * t;

        // (c) Speed of the electron |Vf|
        vf = std::sqrt(vfx * vfx + vfy * vfy);

        // (d) Direction of travel of the electron theta
        theta = std::atan(vfy / vfx) * (180.0 / M_PI);

        // Output the results
        std::cout << "(a) The position of the electron yf = " << yf << " meters" << std::endl;
        std::cout << "(b) The velocity of the electron vf = " << vfx << " i-hat + " << vfy << " j-hat m/s" << std::endl;
        std::cout << "(c) The speed of the electron |Vf| = " << vf << " m/s" << std::endl;
        std::cout << "(d) The direction of travel of the electron theta = " << theta << " degrees" << std::endl;

        // Ask user if they want to continue or exit
        std::cout << "\nWould you like to continue? Press 'y' to continue or 'n' to exit: ";
        std::cin >> choice;
        std::cin.ignore();

    } while (choice == 'y' || choice == 'Y');

    return 0;
}