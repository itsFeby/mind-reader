#include <ctime>
#include <iostream>
#include <chrono>
#include <string>
#include <thread>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"

void loadingEffect(std::string message, int duration) {
    std::cout << message;
    for (int i = 0; i < duration; ++i) {
        std::cout << ".";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << std::endl;
}

void spinnerEffect(int duration) {
    char spinner[] = {'|', '/', '-', '\\'};
    std::cout << " ";
    for (int i = 0; i < duration * 4; ++i) {
        std::cout << "\b" << spinner[i % 4] << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
    std::cout << "\b " << std::endl;
}


void typeEffect(std::string text, int delay = 40) {
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    std::cout << std::endl;
}


int generateDifferentNumber(int exclude1, int exclude2 = -1) {
    int prediction;
    do {
        prediction = rand() % 10 + 1;
    } while (prediction == exclude1 || prediction == exclude2);
    return prediction;
}

int main(){
    srand(time(0));
    while (true){
        int number;
        std::cout << "I can read your mind!" << std::endl;
        std::cout << RED << "====================================================" << RESET << std::endl;
        std::cout << "Think of a number from 1-10, type in it (Don't worry, i won't peek" << RED << " ( ͡° ͜ʖ ͡°)" << RESET << "...)" <<std::endl;
        std::cout << "Enter the number: ";
        std::cin >> number;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "That's not even a number, dumbass (  •̀⤙•́  )\n";
            continue;
        }


        if (number > 10 or number <1){
            std::cout << "\nI said a number from 1-10, idiot!" << std::endl;
        } else {
            int fakeAnswer1 = generateDifferentNumber(number);
            int fakeAnswer2 = generateDifferentNumber(number, fakeAnswer1);
            std::cout << "I'm reading your mind...";
            spinnerEffect(7);
            typeEffect("\nThe number you are thinking of is...");
            typeEffect("✨" + std::to_string(fakeAnswer1) + "✨");
            loadingEffect("", 5);
            typeEffect(std::string("Huh? Was that ") + RED + "wrong?" + RESET + BLUE + " ಥ﹏ಥ" + RESET + " Eh... the system error... it's not my fault " + BLUE + "(つ╥﹏╥)つ" + RESET);
            loadingEffect("", 4);
            typeEffect(std::string("Wait a sec!") + BLUE + " (,,>﹏<,,)" + RESET + " Don't go! I will fix my answer");
            spinnerEffect(4);
            typeEffect("\nThe number you are thinking of is... ");
            typeEffect("✨" + std::to_string(fakeAnswer2) + "✨");
            loadingEffect("", 7);
            typeEffect(std::string("Huh? Still ") + RED + "no?" +RESET + BLUE + " (ó﹏ò｡)" + RESET + " wait a sec!");
            spinnerEffect(4);
            typeEffect("\nThe number you are thinking of is ");
            typeEffect("✨" + std::to_string(number) + "✨");
            loadingEffect("", 5);
            typeEffect(std::string("Was that ") + GREEN + "right?" + RESET + BLUE + " (,,>﹏<,,)" + RESET + " Told you, I'm a mind reader!" + BLUE + " ( ๑‾̀◡‾́)✨" + RESET);
            typeEffect(BLUE + std::string("⎛⎝( ` ᢍ ´ )⎠⎞ᵐᵘʰᵃʰᵃ") + RESET);
        }

        typeEffect(RED + std::string("====================================================") + RESET);

        char playAgain;
        while (true) {
            std::cout << "\nDo you want to play again? (y/n): ";
            std::cin >> playAgain;
            if (playAgain == 'y' || playAgain == 'Y') {
                continue;
            } else if (playAgain == 'n' || playAgain == 'N') {
                std::cout << "\nThank you for playing, have a nice day!" << BLUE << " (˵ •̀ ᴗ - ˵ ) ✧" << RESET << std::endl;
                return 0;
            } else {
                std::cout << "I said y or n, bro" << RED << "(｡•̀ ⤙ •́ ｡ꐦ)" << RESET << " !!! try again!" << std::endl;
            }
        }
    }

  return 0;
}
