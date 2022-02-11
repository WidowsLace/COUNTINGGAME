/*   
            //Greet the USER 
                //show modes and ask USER to select one
                    //allow USER to select mode
                    // ARRAY (1,2,3,4,5)
            //list of modes: Very easy (1), Easy(2), Medium (3), Difficult(4), Very difficult(5)
                //Set initial values depending on what mode is chosen        
                    //   bottom and top of range of values the USER will guess
                    //   number of guesses it has taken so far
                    //   LOOP 
                    //   guess the middle of the current range
            //show feedback from first guess
                    //   SHOW 'CORRECT' for 'yes, that is correct'
                    //   SHOW 'GUESS IS TOO HIGH.. TRY AGAIN' for 'guess is too high'
                    //   SHOW 'GUESS IS TOO LOW.. TRY AGAIN ' for 'guess is too low'
            //feedback result
                    //   IF the USER is correct, break out of the loop
                    //   IF too high, re-set range to lower half of current
                    //   IF too low,  re-set range to upper half of current
            //End of LOOP over guesses
                    //   print out the number of guesses it took
​
            //   When game is over, ask IF USER would like to play again
​
*/

#include <iostream> //here is my header!
#include <cstdlib> // this header gets rand and srand functions
#include <ctime> //this gets the time function
#include <string> //In order to use getline

int main()
{
    bool restart = false;

    do {    
        std::cout << R"(
                                   __  .__                                               
          ____  ____  __ __  _____/  |_|__| ____    ____      _________    _____   ____  
        _/ ___\/  _ \|  |  \/    \   __\  |/    \  / ___\    / ___\__  \  /     \_/ __ \ 
        \  \__(  <_> )  |  /   |  \  | |  |   |  \/ /_/  >  / /_/  > __ \|  Y Y  \  ___/ 
         \___  >____/|____/|___|  /__| |__|___|  /\___  /   \___  (____  /__|_|  /\___  >
             \/                 \/             \//_____/   /_____/     \/      \/     \/ 
                                                                                                        )" << '\n';
    
        srand(time(NULL)); //sets our random seed based on computer time
                    
        int GuessedNum; //declared but not initialised a int variable called GuessedNum
        int FavoriteNum { 0 }; //declared and initialised an int variable called favorite number, we will make this random later on
        // const int MAX_GUESSES = 10;
        int num, guess, tries = 0;
        char playagain;
        int counter = 1; //sets the initial counter for the number of guesses
        int DifferenceBetweenValues{ 0 };
        DifferenceBetweenValues = std::abs(FavoriteNum - GuessedNum); //sets differences between the values to the absolute of favoriteNum, this is for hints for the user. holy shit my therapist will hear about this 
        // tries++; //<<<<<<<<<<<<<<<<<<<<<<<

        std::cout << std::endl; 
        std::cout << "CHOOSE A GAME MODE:\n";
        std::cout << "[1] Very Easy (1-20), infinate tries\n"
                << "[2] Easy (1-10), 5 tries\n"
                << "[3] Medium (1-100), 5 tries\n"
                << "[4] Difficult (1-500), 5 tries\n"
                << "[5] Very Difficult (1-1000), 9 tries\n";

        std::string input;
        std::getline(std::cin, input);

        while(input != "1" && input != "2" && input != "3" && input != "4" && input != "5") {
            //std::cout << "Invalid!\n";

            std::getline(std::cin, input);
        }

        if (input == "1") {
            FavoriteNum = rand() % 10 + 1;
            
            std::cout << "Let's play a game! Guess my favorite number" << std::endl;
            std::cin >> GuessedNum; //initialize the variable (as it will give the guessed number) a value.
            

            while(GuessedNum != FavoriteNum)
            {
                if (GuessedNum > 10){
                    std::cout << "I said between 1 and 10, " << GuessedNum << "  is greater than 10" << std::endl;
                    std::cout << "Guess again: " << std::endl;
                    std::cin >> GuessedNum;  
                }   
                else if (GuessedNum <= 0){
                    std::cout << "I said between 1 and 10 " << GuessedNum << " is less than 1" << std::endl;
                    std::cout << "Guess again: " << std::endl;
                    std::cin >> GuessedNum;
                }
                else if (DifferenceBetweenValues <= 2){
                    std::cout << "You're close, but not quite there, keep trying :D" << std::endl;
                    std::cin  >> GuessedNum;        
                }  
                else if  (DifferenceBetweenValues > 2){
                    std::cout << "You're not even close, but thats okay. Keep trying :D" << std::endl;
                    std::cin >> GuessedNum;
                }

                else {
                    std::cout << "You guessed: " << GuessedNum << ", and that is NOT my favorite number ):" << std::endl; 
                    std::cout << "Guess again: " << std::endl;
                    std::cin >> GuessedNum;     
                }
                if (GuessedNum == FavoriteNum) {   
                    std::cout << "You're right!! " << GuessedNum << ",That IS my favorite number!!" <<  std::endl;
                    std::cout << "\n You got it in " << tries << " guesses!\n"; 
                    return 0;   
                }
            }
        } 
        else if (input == "2") { 
            FavoriteNum = rand() % 10 + 1; // A random number is chosen
                    
            std::cout << "Let's play a game! Guess my favorite number" << std::endl;
            tries++;
            std::cin >> GuessedNum; //initialize the variable (as it will give the guessed number) a value. // Getting the guess from the user
                                    
            while(GuessedNum != FavoriteNum){
                int numGuesses = 0;
                int number;
                int DifferenceBetweenValues{ 0 };
                DifferenceBetweenValues = std::abs(FavoriteNum - GuessedNum); //sets differences between the values to the absolute of favoriteNum, this is for hints for the user                                

                if (GuessedNum > 10){ // If the guessed number is greater than the max
                    std::cout << "I said between 1 and 10, " << GuessedNum << "  is greater than 10" << std::endl;
                    std::cout << "Guess again: " << std::endl;
                    tries++;
                    std::cin >> GuessedNum; // Get a new guess from the user
                }   
                else if (GuessedNum <= 0){ // If the guessed number is less than the min
                    std::cout << "I said between 1 and 10 " << GuessedNum << " is less than 1" << std::endl;
                    std::cout << "Guess again: " << std::endl;
                    tries++;
                    std::cin >> GuessedNum; // Get a new guess from the user
                }
                else if  (DifferenceBetweenValues = 5){ // If the guessed number is within 5 of the favorite number
                    std::cout << "You're close, but not quite there, keep trying :D" << std::endl;
                    tries++;
                    std::cin  >> GuessedNum; // Get a new guess from the user
                }  
                else if  (DifferenceBetweenValues > 5){ // If the guessed number is more than 5 away from the favorite number
                    std::cout << "You're not even close, but thats okay. Keep trying :D" << std::endl;
                    tries++;
                    std::cin >> GuessedNum; // Get a new guess from the user
                }
                else {
                    std::cout << "You guessed: " << GuessedNum << ", and that is NOT my favorite number ):" << std::endl; 
                    std::cout << "Guess again: " << std::endl;
                    tries++;
                    std::cin >> GuessedNum;
                }
                
                if (GuessedNum == FavoriteNum) {
                std::cout << "You're right!! " << GuessedNum << ",That IS my favorite number!!" << std::endl;
                }
                
                if(GuessedNum == FavoriteNum) {
                    std::cout << "try again? y or n \n";
                    std::cin >> input;
                        if (input == "y") {

                            // {tries = 0;}
                            restart = true;
                            break;
                        } 
                        else if (input == "n"){ 
                            std::cout << "thank you for playing!\n";
                            // restart = false;
                            return 0;
                        }
                    
                    // }
                }
                
                if(tries == 5) {
                    std::cout << "You ran out of tries!\n";
                    std::cout <<"You used " << tries << " tries and still got it wrong LMAOOO!!! how does it feel to be gaslit by a computer? probably just as bad as your guessing skills.\n";                          
                    
                    std::cout << "try again? y or n \n";
                    std::cin >> input;
                        if (input == "y") {

                            // {tries = 0;}
                            restart = true;
                            break;
                        } 
                        else if (input == "n"){ 
                            std::cout << "thank you for playing!\n";
                            // restart = false;
                            return 0;
                        }
                }
            }
            
        }
                else if (input == "3") { 
            FavoriteNum = rand() % 100 + 1; // A random number is chosen
                    
            std::cout << "Let's play a game! Guess my favorite number" << std::endl;
            tries++;
            std::cin >> GuessedNum; //initialize the variable (as it will give the guessed number) a value. // Getting the guess from the user
                                    
            while(GuessedNum != FavoriteNum){
                int numGuesses = 0;
                int number;
                int DifferenceBetweenValues{ 0 };
                DifferenceBetweenValues = std::abs(FavoriteNum - GuessedNum); //sets differences between the values to the absolute of favoriteNum, this is for hints for the user                                

                if (GuessedNum > 100){ // If the guessed number is greater than the max
                    std::cout << "I said between 1 and 100, " << GuessedNum << "  is greater than 10" << std::endl;
                    std::cout << "Guess again: " << std::endl;
                    tries++;
                    std::cin >> GuessedNum; // Get a new guess from the user
                }   
                else if (GuessedNum <= 0){ // If the guessed number is less than the min
                    std::cout << "I said between 1 and 100 " << GuessedNum << " is less than 1" << std::endl;
                    std::cout << "Guess again: " << std::endl;
                    tries++;
                    std::cin >> GuessedNum; // Get a new guess from the user
                }
                else if  (DifferenceBetweenValues = 25){ // If the guessed number is within 5 of the favorite number
                    std::cout << "You're close, but not quite there, keep trying :D" << std::endl;
                    tries++;
                    std::cin  >> GuessedNum; // Get a new guess from the user
                }  
                else if  (DifferenceBetweenValues > 25){ // If the guessed number is more than 5 away from the favorite number
                    std::cout << "You're not even close, but thats okay. Keep trying :D" << std::endl;
                    tries++;
                    std::cin >> GuessedNum; // Get a new guess from the user
                }
                else {
                    std::cout << "You guessed: " << GuessedNum << ", and that is NOT my favorite number ):" << std::endl; 
                    std::cout << "Guess again: " << std::endl;
                    tries++;
                    std::cin >> GuessedNum;
                }
                
                if (GuessedNum == FavoriteNum) {
                std::cout << "You're right!! " << GuessedNum << ",That IS my favorite number!!" << std::endl;
                }
                
                if(GuessedNum == FavoriteNum) {
                    std::cout << "try again? y or n \n";
                    std::cin >> input;
                        if (input == "y") {

                            // {tries = 0;}
                            restart = true;
                            break;
                        } 
                        else if (input == "n"){ 
                            std::cout << "thank you for playing!\n";
                            // restart = false;
                            return 0;
                        }
                    
                    // }
                }
            }
            
                
                if(tries == 5) {
                    std::cout << "You ran out of tries!\n";
                    std::cout <<"You used " << tries << " tries and still got it wrong LMAOOO!!! how does it feel to be gaslit by a computer? probably just as bad as your guessing skills.\n";                          
                    
                    std::cout << "try again? y or n \n";
                    std::cin >> input;
                        if (input == "y") {

                            // {tries = 0;}
                            restart = true;
                            break;
                        } 
                        else if (input == "n"){ 
                            std::cout << "thank you for playing!\n";
                            // restart = false;
                            return 0;
                        }
                }
            }

                else if (input == "4") { //fix hints
                            FavoriteNum = rand() % 500 + 1; // A random number is chosen
                                    
                            std::cout << "Let's play a game! Guess my favorite number" << std::endl;
                            tries++;
                            std::cin >> GuessedNum; //initialize the variable (as it will give the guessed number) a value. // Getting the guess from the user
                                                    
                            while(GuessedNum != FavoriteNum){
                                int numGuesses = 0;
                                int number;
                                int DifferenceBetweenValues{ 0 };
                                DifferenceBetweenValues = std::abs(FavoriteNum - GuessedNum); //sets differences between the values to the absolute of favoriteNum, this is for hints for the user                                

                                if (GuessedNum > 500){ // If the guessed number is greater than the max
                                    std::cout << "I said between 1 and 500, " << GuessedNum << "  is greater than 10" << std::endl;
                                    std::cout << "Guess again: " << std::endl;
                                    tries++;
                                    std::cin >> GuessedNum; // Get a new guess from the user
                                }   
                                else if (GuessedNum <= 0){ // If the guessed number is less than the min
                                    std::cout << "I said between 1 and 500 " << GuessedNum << " is less than 1" << std::endl;
                                    std::cout << "Guess again: " << std::endl;
                                    tries++;
                                    std::cin >> GuessedNum; // Get a new guess from the user
                                }
                                else if  (DifferenceBetweenValues = 55){ // If the guessed number is within 5 of the favorite number
                                    std::cout << "You're close, but not quite there, keep trying :D" << std::endl;
                                    tries++;
                                    std::cin  >> GuessedNum; // Get a new guess from the user
                                }  
                                else if  (DifferenceBetweenValues > 55){ // If the guessed number is more than 5 away from the favorite number
                                    std::cout << "You're not even close, but thats okay. Keep trying :D" << std::endl;
                                    tries++;
                                    std::cin >> GuessedNum; // Get a new guess from the user
                                }
                                else {
                                    std::cout << "You guessed: " << GuessedNum << ", and that is NOT my favorite number ):" << std::endl; 
                                    std::cout << "Guess again: " << std::endl;
                                    tries++;
                                    std::cin >> GuessedNum;
                                }
                                
                                if (GuessedNum == FavoriteNum) {
                                std::cout << "You're right!! " << GuessedNum << ",That IS my favorite number!!" << std::endl;
                                }
                                
                                if(GuessedNum == FavoriteNum) {
                                    std::cout << "try again? y or n \n";
                                    std::cin >> input;
                                        if (input == "y") {

                                            // {tries = 0;}
                                            restart = true;
                                            break;
                                        } 
                                        else if (input == "n"){ 
                                            std::cout << "thank you for playing!\n";
                                            // restart = false;
                                            return 0;
                                        }
                                    
                                    // }
                                }
                                
                                if(tries == 8) {
                                    std::cout << "You ran out of tries!\n";
                                    std::cout <<"You used " << tries << " tries and still got it wrong LMAOOO!!! how does it feel to be gaslit by a computer? probably just as bad as your guessing skills.\n";                          
                                    
                                    std::cout << "try again? y or n \n";
                                    std::cin >> input;
                                        if (input == "y") {

                                            // {tries = 0;}
                                            restart = true;
                                            break;
                                        } 
                                        else if (input == "n"){ 
                                            std::cout << "thank you for playing!\n";
                                            // restart = false;
                                            return 0;
                                        }
                                }
                            }
                        
                            
                }
                        
                else if (input == "5") { 
                            FavoriteNum = rand() % 1000 + 1; // A random number is chosen
                                    
                            std::cout << "Let's play a game! Guess my favorite number" << std::endl;
                            tries++;
                            std::cin >> GuessedNum; //initialize the variable (as it will give the guessed number) a value. // Getting the guess from the user
                                                    
                            while(GuessedNum != FavoriteNum){
                                int numGuesses = 0;
                                int number;
                                int DifferenceBetweenValues{ 0 };
                                DifferenceBetweenValues = std::abs(FavoriteNum - GuessedNum); //sets differences between the values to the absolute of favoriteNum, this is for hints for the user                                

                                if (GuessedNum > 1000){ // If the guessed number is greater than the max
                                    std::cout << "I said between 1 and 1000, " << GuessedNum << "  is greater than 10" << std::endl;
                                    std::cout << "Guess again: " << std::endl;
                                    tries++;
                                    std::cin >> GuessedNum; // Get a new guess from the user
                                }   
                                else if (GuessedNum <= 0){ // If the guessed number is less than the min
                                    std::cout << "I said between 1 and 1000, " << GuessedNum << " is less than 1" << std::endl;
                                    std::cout << "Guess again: " << std::endl;
                                    tries++;
                                    std::cin >> GuessedNum; // Get a new guess from the user
                                }
                                else if  (DifferenceBetweenValues = 100){ // If the guessed number is within 5 of the favorite number
                                    std::cout << "You're close, but not quite there, keep trying :D" << std::endl;
                                    tries++;
                                    std::cin  >> GuessedNum; // Get a new guess from the user
                                }  
                                else if  (DifferenceBetweenValues > 100){ // If the guessed number is more than 5 away from the favorite number
                                    std::cout << "You're not even close, but thats okay. Keep trying :D" << std::endl;
                                    tries++;
                                    std::cin >> GuessedNum; // Get a new guess from the user
                                }
                                else {
                                    std::cout << "You guessed: " << GuessedNum << ", and that is NOT my favorite number ):" << std::endl; 
                                    std::cout << "Guess again: " << std::endl;
                                    tries++;
                                    std::cin >> GuessedNum;
                                }
                                
                                if (GuessedNum == FavoriteNum) {
                                std::cout << "You're right!! " << GuessedNum << ",That IS my favorite number!!" << std::endl;
                                }
                                
                                if(GuessedNum == FavoriteNum) {
                                    std::cout << "try again? y or n \n";
                                    std::cin >> input;
                                        if (input == "y") {

                                            // {tries = 0;}
                                            restart = true;
                                            break;
                                        } 
                                        else if (input == "n"){ 
                                            std::cout << "thank you for playing!\n";
                                            // restart = false;
                                            return 0;
                                        }
                                    
                                    // }
                                }
                                
                                if(tries == 9) {
                                    std::cout << "You ran out of tries!\n";
                                    std::cout <<"You used " << tries << " tries and still got it wrong LMAOOO!!! how does it feel to be gaslit by a computer? probably just as bad as your guessing skills.\n";                          
                                    
                                    std::cout << "try again? y or n \n";
                                    std::cin >> input;
                                        if (input == "y") {

                                            // {tries = 0;}
                                            restart = true;
                                            break;
                                        } 
                                        else if (input == "n"){ 
                                            std::cout << "thank you for playing!\n";
                                            // restart = false;
                                            return 0;
                                        }
                                }
                            }

        }
    }while(restart);
}