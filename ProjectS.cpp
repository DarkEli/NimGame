#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;

int stone;
int go;
bool bool1;
int x;
int pca;

void pcFirst();
void playerFirst();

void init() {
    cout << "The Nim game is working" << endl;
    cout << "Please input the amount of stones" << endl;
    cin >> stone ;
    cout << "Amount of Stones: " << stone << endl;
}

bool isIntWithinBound(int a) {
    return a >= 1 && a <= 2;
}

bool isIntWithinBound1(int b) {
    return b >= 1 && b <= 3;
}

bool checkPos(int c) {
    return c > 0;
}

void stagePlayerLost() {
    cout << "You lost the game!!!" << endl;
}

void stagePCLost() {
    cout << "You won!!!" << endl;
}

void stageOne() {
    cout << "Who will go first" << endl;
    cout << "Press 1 if player would like to go first" << endl;
    cout << "Press 2 if player wants the computer to go first" << endl;
    cout << "Please input the number" << endl;
    cin >> go;
    bool1 = isIntWithinBound(go);

    if (bool1) {
        cout << "The input number is:" << go << endl;
    } else {
        cout << "Please input an appropriate integer (1 or 2)" << endl;
    }

    if (go == 1) {
        cout << "You will go first!" << endl;
        playerFirst();
    } else if (go == 2) {
        cout << "Computer will go first" << endl;
        pcFirst();
    }
}

void playerFirst() {
    cin >> x;
    if (isIntWithinBound1(x)) {
        cout << "You have input: " << x << endl;
    } else {
        cout << "Please input an appropriate integer (1 or 2 or 3)" << endl;
        cin >> x;
        cout << "You have input: " << x << endl;
    }

    stone = (stone - x);

    if (checkPos(stone)) {
        cout << "The remaining amount of stones is " << stone << endl;
        pcFirst();
    } else {
        stagePlayerLost();
    }

}

int getRandomNumber(int min, int max) {
    // Seed the random number generator with current time
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random number between min and max
    return (rand() % (max - min + 1)) + min;
}

void pcFirst() {
    pca = getRandomNumber(1, 3);
    stone = stone - pca;
    if (checkPos(stone)) {
        cout << "The remaining amount of stones is " << stone << endl;
        playerFirst();
    } else {
        stagePCLost();
    }

}

int main() {
    init();
    stageOne();

    return 0;
}