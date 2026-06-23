#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main() {

    int playerChoice;
    int computerChoice;
    int playerScore = 0;
    int computerScore = 0;
    int roundsPlayed = 0;
    char playAgain;
    string playerName;
    string choices[3] = {"Rock", "Paper", "Scissors"};

    srand(time(0));

    cout << "Welcome to Rock-Paper-Scissors!" << endl;
    cout << "Enter your name: ";
    getline(cin, playerName);


    do {

        cout << "\n========== SCOREBOARD ==========" << endl;
        cout << playerName << ": " << playerScore << " | Computer: " << computerScore << endl;
        cout << "Rounds played: " << roundsPlayed << endl;
        cout << "=================================" << endl;

        cout << "\nChoose your move:" << endl;
        cout << "1. Rock" << endl;
        cout << "2. Paper" << endl;
        cout << "3. Scissors" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> playerChoice;

        if (playerChoice < 1 || playerChoice > 3) {
            cout << "Invalid choice! Please enter 1, 2, or 3." << endl;
            continue;
        }

        computerChoice = rand() % 3 + 1;

        cout << "\n" << playerName << " chose: " << choices[playerChoice - 1] << endl;
        cout << "Computer chose: " << choices[computerChoice - 1] << endl;

        if (playerChoice == computerChoice) {
            cout << "It's a tie!" << endl;
        }
        else if
            ((playerChoice == 1 && computerChoice == 3) ||
            (playerChoice == 2 && computerChoice == 1) ||
            (playerChoice == 3 && computerChoice == 2))
            {
            cout << "Congratulations " << playerName << "! You win this round!" << endl;
            playerScore++;
        }
        else {
            cout << "Computer wins this round!" << endl;
            computerScore++;
        }

        roundsPlayed++;

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N') {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            cout << "Do you want to play again? (y/n): ";
            cin >> playAgain;
        }

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\n========== GAME OVER ==========" << endl;
    cout << "Final Score:" << endl;
    cout << playerName << ": " << playerScore << " wins" << endl;
    cout << "Computer: " << computerScore << " wins" << endl;
    cout << "Total rounds played: " << roundsPlayed << endl;

    if (playerScore > computerScore) {
        cout << "\n" << playerName << " is the overall winner! Great job!" << endl;
    }
    else if (computerScore > playerScore) {
        cout << "\nComputer is the overall winner! Better luck next time!" << endl;
    }
    else {
        cout << "\nIt's a tie overall! You and the computer are evenly matched!" << endl;
    }

    cout << "Thanks for playing, " << playerName << "!" << endl;

    return 0;
}
