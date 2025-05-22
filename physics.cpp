// Copyright (c) 2025 Dylan Mutabazi All rights reserved
//
// Created by Dylan Mutabazi
// Created March 2025
// This program makes the user guess a randomnumber between 0 and 9

#include <iostream>
#include <string>

// Function used to calculate acceleration 
float physics_calc(float initial_velocity, float final_velocity, float time) {
    return (final_velocity - initial_velocity) / time;
}

int main() {

    // Initial greeting
    std::cout << "Top of the morning lad, this drunken calculator calculates how fast that object is going, the acceleration to be exact.\n"
                 "Just give me the initial and final velocity, as well as how long it took (the time ya moron).\n";

    // Sets lives to 3
    // lives will be used so that the user can have 3 wrong inputs
    int lives = 3;


    // loops are used so that we can asks the question again after a wrong input
    while (true) {

        // Sets and assigns a value to initial velocity 
        std::cout << "\nWhat is ya initial velocity lad? ";
        std::string initial_velocity_str;
        std::cin >> initial_velocity_str;

        try {

            // Converts string to float 
            float initial_velocity = std::stof(initial_velocity_str);

            while (true) {

                // Sets and assigns a value for final_velocity
                std::cout << "\nNow for your final_velocity: ";
                std::string final_velocity_str;
                std::cin >> final_velocity_str;

                try {

                    // converts string to float 
                    float final_velocity = std::stod(final_velocity_str);

                    while (true) {

                        // Sets and assigns value to time
                        std::cout << "\nAlright mate how give me the time it took from point a to point b in seconds: ";
                        std::string time_str;
                        std::cin >> time_str;

                        // Checks if its less or = to 0 
                        if (time_str <= "0") {
                            std::cout << "You can't divide by zero lad, are you drunk or something\n";
                            lives--;

                            std::cout << "Ok listen here ill let you try again but you only have " << lives << " chance(s)\n";

                            if (lives <= 0) {
                                std::cout << "\nI might be drunk, BUT YOU'RE DRUNKER GET OUTTTTTT!!!!!\n";
                                break;
                            }
                        } else {
                            try {

                                // Converts string to int
                                float time = std::stod(time_str);

                                // Sets variable called acceleration and assigns returned value
                                // Calls function with given arguments
                                float acceleration = physics_calc(initial_velocity, final_velocity, time);

                                std::cout << " Using the formula (" << final_velocity << " - " << initial_velocity << ") / " << time << " the answer = " << acceleration << " m/s²\n";
                                break;

                            // Catches any error and gives user 3 chances 
                            } catch (...) {
                                std::cout << "\n"
                                          << final_velocity_str << " is an invalid number lad\n";
                                lives--;

                                std::cout << "Ok listen here ill let you try again but you only have " << lives << " chance(s)\n";

                                if (lives <= 0) {
                                    std::cout << "\nI might be drunk, BUT YOU'RE DRUNKER GET OUTTTTTT!!!!!\n";
                                    break;
                                }
                            }
                        }
                    }
                    break;

                } catch (...) {
                    std::cout << "\n"
                              << final_velocity_str << " is an invalid number lad\n";
                    lives--;

                    std::cout << "Ok listen here ill let you try again but you only have " << lives << " chance(s)\n";

                    if (lives <= 0) {
                        std::cout << "\nI might be drunk, BUT YOU'RE DRUNKER GET OUTTTTTT!!!!!\n";
                        break;
                    }
                }
            }
            break;

        } catch (...) {
            std::cout << initial_velocity_str << " is an invalid number lad\n";
            lives--;

            std::cout << "Ok listen here ill let you try again but you only have " << lives << " chance(s)\n";

            if (lives <= 0) {
                std::cout << "\nI might be drunk, BUT YOU'RE DRUNKER GET OUTTTTTT!!!!!\n";
                break;
            }
        }
    }
}
