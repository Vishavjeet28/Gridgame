#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Global constants
const int boardSize = 4;
const int minValue = -10;
const int maxValue = 10;

// Global variables
vector<vector<int>> board(boardSize, vector<int>(boardSize));
pair<int, int> goalTile;
pair<int, int> startPosition;
vector<pair<int, int>> visitedTiles;

// Function prototypes
int generateRandomNumber();
void fillTheBoard();
void revealTile();
void getStartPosition();
pair<int, int> moveUp();
pair<int, int> moveDown();
pair<int, int> moveLeft();
pair<int, int> moveRight();
bool checkGoal();
void playGame();
void printOutcome();

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    string playAgain;
    do {
        fillTheBoard();
        getStartPosition();
        visitedTiles.clear();
        visitedTiles.push_back(startPosition);

        playGame();
const int BOARD_SIZE = 4;
const int MIN_NUMBER = -10;
const int MAX_NUMBER = 10;

        cout << "Do you want to play again? (yes/no): ";
        cin >> playAgain;
    } while (playAgain == "yes");

    printOutcome();
    return 0;
}

// Function to generate a random number between minValue and maxValue (inclusive)
int generateRandomNumber() {
    return rand() % (maxValue - minValue + 1) + minValue;
// Function to generate a random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to fill the board with random numbers and set the goal tile
void fillTheBoard() {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            board[i][j] = generateRandomNumber();
void fillBoard(int board[BOARD_SIZE][BOARD_SIZE], int& goalRow, int& goalCol) {
    srand(time(0)); // Seed the random number generator with current time

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = generateRandomNumber(MIN_NUMBER, MAX_NUMBER);
        }
    }
    goalTile = make_pair(rand() % boardSize, rand() % boardSize);
    board[goalTile.first][goalTile.second] = generateRandomNumber() + 11;

    goalRow = generateRandomNumber(0, BOARD_SIZE - 1);
    goalCol = generateRandomNumber(0, BOARD_SIZE - 1);
    board[goalRow][goalCol] = generateRandomNumber(11, 20); // Set the goal tile
}

// Function to reveal the board with only revealed tiles
void revealTile() {
    cout << "Board:" << endl;
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (make_pair(i, j) == goalTile) {
                cout << " G ";
            } else if (make_pair(i, j) == startPosition) {
                cout << " S ";
            } else if (find(visitedTiles.begin(), visitedTiles.end(), make_pair(i, j)) != visitedTiles.end()) {
                cout << " " << board[i][j] << " ";
// Function to reveal the tiles on the board
void revealTiles(const int board[BOARD_SIZE][BOARD_SIZE], const bool revealed[BOARD_SIZE][BOARD_SIZE], int goalRow, int goalCol) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == goalRow && j == goalCol) {
                std::cout << "G ";
            } else if (revealed[i][j]) {
                std::cout << board[i][j] << " ";
            } else {
                cout << " ? ";
                std::cout << "* ";
            }
        }
        cout << endl;
        std::cout << std::endl;
    }
}

// Function to get the start position from the user
void getStartPosition() {
void getStartPosition(int& startRow, int& startCol, int goalRow, int goalCol) {
    do {
        cout << "Enter the row number (0 to " << (boardSize - 1) << "): ";
        cin >> startPosition.first;
        cout << "Enter the column number (0 to " << (boardSize - 1) << "): ";
        cin >> startPosition.second;
        if (startPosition == goalTile || startPosition.first < 0 || startPosition.first >= boardSize || startPosition.second < 0 || startPosition.second >= boardSize) {
            cout << "Invalid position. Please choose a valid hidden tile." << endl;
        std::cout << "Enter the row and column numbers to start the game: ";
        std::cin >> startRow >> startCol;



        if (startRow == goalRow && startCol == goalCol) {
            std::cout << "Invalid start position! Please choose a different tile." << std::endl;

        }
    } while (startPosition == goalTile || startPosition.first < 0 || startPosition.first >= boardSize || startPosition.second < 0 || startPosition.second >= boardSize);
    } while (startRow == goalRow && startCol == goalCol);
}

// Function to move the position up
pair<int, int> moveUp() {
    int newRow = startPosition.first - 1;
    if (newRow >= 0 && find(visitedTiles.begin(), visitedTiles.end(), make_pair(newRow, startPosition.second)) == visitedTiles.end()) {
        return make_pair(newRow, startPosition.second);
void moveUp(int& row,int& iflag) {
    if (row > 0) {
        row--;
         iflag=1;
    }
    else
    {
        iflag=0;
       std::cout << "Invalid Input" << std::endl;//Input is out of bounds 
    }
    return startPosition;

}

// Function to move the position down
pair<int, int> moveDown() {
    int newRow = startPosition.first + 1;
    if (newRow < boardSize && find(visitedTiles.begin(), visitedTiles.end(), make_pair(newRow, startPosition.second)) == visitedTiles.end()) {
        return make_pair(newRow, startPosition.second);
void moveDown(int& row,int& iflag) {
    if (row < BOARD_SIZE - 1) {
        row++;
        iflag=1;
    }
    else
    {
        iflag=0;
        std::cout << "Invalid Input" << std::endl;//Input is out of bounds
    }
    return startPosition;

}

// Function to move the position left
pair<int, int> moveLeft() {
    int newCol = startPosition.second - 1;
    if (newCol >= 0 && find(visitedTiles.begin(), visitedTiles.end(), make_pair(startPosition.first, newCol)) == visitedTiles.end()) {
        return make_pair(startPosition.first, newCol);
void moveLeft(int& col,int& iflag) {
    if (col > 0) {
        col--;
        iflag=1;
    }
    return startPosition;
    else
    {
        iflag=0;
        std::cout << "Invalid Input" << std::endl;//Input is out of bounds
    }

}

// Function to move the position right
pair<int, int> moveRight() {
    int newCol = startPosition.second + 1;
    if (newCol < boardSize && find(visitedTiles.begin(), visitedTiles.end(), make_pair(startPosition.first, newCol)) == visitedTiles.end()) {
        return make_pair(startPosition.first, newCol);
void moveRight(int& col,int& iflag) {
    if (col < BOARD_SIZE - 1) {
        col++;
        iflag=1;
    }
    else
    {
        iflag=0;
        std::cout << "Invalid Input" << std::endl;//Input is out of bounds
    }
    return startPosition;

}

// Function to check if the total sum of visited tiles falls within the range of -2 to 2
bool checkGoal() {
    int totalSum = 0;
    for (const auto& tile : visitedTiles) {
        totalSum += board[tile.first][tile.second];
// Function to check if the total of visited tiles falls within the range of -2 to 2
bool checkGoal(const int board[BOARD_SIZE][BOARD_SIZE], const bool revealed[BOARD_SIZE][BOARD_SIZE], int goalRow, int goalCol) {
    int sum = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j]) {
                sum += board[i][j];
            }
        }
    }
    return totalSum >= -2 && totalSum <= 2;

    return sum >= -2 && sum <= 2;
}

// Function to play the game
void playGame() {
    while (true) {
        revealTile();
        if (startPosition == goalTile) {
            cout << "Congratulations! You reached the goal tile." << endl;
            if (checkGoal()) {
                cout << "Total sum of visited tiles is within the range of -2 to 2. You win!" << endl;
int main() {
    int flag=1;
    int iflag=1;
    int board[BOARD_SIZE][BOARD_SIZE];
    bool revealed[BOARD_SIZE][BOARD_SIZE] = { false };
    int goalRow, goalCol;
    std::vector<std::string> attempts;

    fillBoard(board, goalRow, goalCol);

    std::cout << "Welcome to the board game!" << std::endl;

    do {
        int startRow, startCol;
        int currentRow, currentCol;
        int moveCount = 0;
        int sum = 0;

        revealTiles(board, revealed, goalRow, goalCol);
        getStartPosition(startRow, startCol, goalRow, goalCol);

        if(startRow>3 || startCol>3  || startRow<0 || startCol<0)
        {
            std::cout << "Invalid Input" << std::endl;//Input is out of bounds
            flag=0;
            break;
        }


        currentRow = startRow;
        currentCol = startCol;
        revealed[currentRow][currentCol] = true;
        sum += board[currentRow][currentCol];
        revealTiles(board, revealed, goalRow, goalCol);
        while (currentRow != goalRow || currentCol != goalCol) {
            std::string move;

            std::cout << "Current sum: " << sum << std::endl;
            std::cout << "Enter your move (up, down, left, right):";
            std::cin >> move;

            if (move == "up") {
                moveUp(currentRow,iflag);
            } else if (move == "down") {
                moveDown(currentRow,iflag);
            } else if (move == "left") {
                moveLeft(currentCol,iflag);
            } else if (move == "right") {
                moveRight(currentCol,iflag);
            } 
            else {
                std::cout << "Invalid move! Please try again." << std::endl;
                continue;
            }





            if (currentRow == goalRow && currentCol == goalCol) {
                if(sum>=-2 && sum<=2)
                {
                   std::cout << "Congratulations! You reached the goal tile." << std::endl;
                break; 
                }
                else
                {
                 std::cout << "Failure!Sum is not between [-2,2]" << std::endl;   
                }

                break;
            }

if(iflag==1)
{
            if (revealed[currentRow][currentCol]) {
                std::cout << "You have already visited this tile. Please choose a different move." << std::endl;
            } else {
                cout << "Total sum of visited tiles is not within the range of -2 to 2. Game over!" << endl;
                revealed[currentRow][currentCol] = true;
                sum += board[currentRow][currentCol];
                moveCount++;
            }
            break;
}

            revealTiles(board, revealed, goalRow, goalCol);
        }

        cout << "Enter a move direction (up, down, left, right): ";
        string moveDirection;
        cin >> moveDirection;
        pair<int, int> newPosition = startPosition;

        if (moveDirection == "up") {
            newPosition = moveUp();
        } else if (moveDirection == "down") {
            newPosition = moveDown();
        } else if (moveDirection == "left") {
            newPosition = moveLeft();
        } else if (moveDirection == "right") {
            newPosition = moveRight();
        if (checkGoal(board, revealed, goalRow, goalCol)) {
            attempts.push_back("Success");
        } else {
            cout << "Invalid move. Please choose a valid direction." << endl;
            continue;
            attempts.push_back("Failure");
        }

        if (newPosition == startPosition) {
            cout << "Invalid move. Please choose a different direction." << endl;
        } else {
            visitedTiles.push_back(newPosition);
            startPosition = newPosition;
        std::cout << "Total moves: " << moveCount << std::endl;

        std::cout << "Do you want to play again? (yes/no): ";
        std::string playAgain;
        std::cin >> playAgain;

        if (playAgain != "yes") {
            break;
        }

        // Reset the board and revealed tiles for the next game
        fillBoard(board, goalRow, goalCol);
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                revealed[i][j] = false;
            }
        }
    } while (true);

   if(flag==1)
   {
    std::cout << "Game Over! Here are your attempts:" << std::endl;
    for (int i = 0; i < attempts.size(); i++) {
        std::cout << "Attempt " << i + 1 << ": " << attempts[i] << std::endl;
    }
}
   }

// Function to print the outcome of the game
void printOutcome() {
    cout << "Game Over. Here are the outcomes of your attempts:" << endl;
    int attempt = 1;
    for (const auto& tile : visitedTiles) {
        cout << "Attempt " << attempt << ": Start position: (" << tile;
    }}
    return 0;
}