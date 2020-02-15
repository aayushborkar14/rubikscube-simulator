#include <iostream>

using namespace std;

char cube[6][3][3] = {
        {{'W', 'W', 'W'}, {'W', 'W', 'W'}, {'W', 'W', 'W'}},
        {{'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'}},
        {{'G', 'G', 'G'}, {'G', 'G', 'G'}, {'G', 'G', 'G'}},
        {{'R', 'R', 'R'}, {'R', 'R', 'R'}, {'R', 'R', 'R'}},
        {{'B', 'B', 'B'}, {'B', 'B', 'B'}, {'B', 'B', 'B'}},
        {{'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}}
};
int upSide{0};
int leftSide{1};
int frontSide{2};
int rightSide{3};
int backSide{4};
int downSide{5};

void clockwise(char arr[6][3][3], int side) {
    cube[side][0][0] = arr[side][2][0];
    cube[side][0][1] = arr[side][1][0];
    cube[side][0][2] = arr[side][0][0];
    cube[side][1][2] = arr[side][0][1];
    cube[side][2][2] = arr[side][0][2];
    cube[side][2][1] = arr[side][1][2];
    cube[side][2][0] = arr[side][2][2];
    cube[side][1][0] = arr[side][2][1];
}

void printCube() {
    for (int j=0; j<3; j++) {
        for (int k=0; k<3; k++) {
            if (k == 0) {
                cout << "      ";
            }
            cout << cube[upSide][j][k] << " ";
        }
        cout << "\n";
    }
    cout << cube[leftSide][0][0] << " " << cube[leftSide][0][1] << " " << cube[leftSide][0][2] << " ";
    cout << cube[frontSide][0][0] << " " << cube[frontSide][0][1] << " " << cube[frontSide][0][2] << " ";
    cout << cube[rightSide][0][0] << " " << cube[rightSide][0][1] << " " << cube[rightSide][0][2] << " ";
    cout << cube[backSide][0][0] << " " << cube[backSide][0][1] << " " << cube[backSide][0][2] << " ";
    cout << "\n";
    cout << cube[leftSide][1][0] << " " << cube[leftSide][1][1] << " " << cube[leftSide][1][2] << " ";
    cout << cube[frontSide][1][0] << " " << cube[frontSide][1][1] << " " << cube[frontSide][1][2] << " ";
    cout << cube[rightSide][1][0] << " " << cube[rightSide][1][1] << " " << cube[rightSide][1][2] << " ";
    cout << cube[leftSide][1][0] << " " << cube[leftSide][1][1] << " " << cube[leftSide][1][2] << " ";
    cout << "\n";
    cout << cube[leftSide][2][0] << " " << cube[leftSide][2][leftSide] << " " << cube[1][2][2] << " ";
    cout << cube[frontSide][2][0] << " " << cube[frontSide][2][1] << " " << cube[frontSide][2][2] << " ";
    cout << cube[rightSide][2][0] << " " << cube[rightSide][2][1] << " " << cube[rightSide][2][2] << " ";
    cout << cube[leftSide][2][0] << " " << cube[leftSide][2][1] << " " << cube[leftSide][2][2] << " ";
    cout << "\n";
    for (int j=0; j<3; j++) {
        for (int k=0; k<3; k++) {
            if (k == 0) {
                cout << "      ";
            }
            cout << cube[5][j][k] << " ";
        }
        cout << "\n";
    }
}

void r() {
    char temp[6][3][3];
    for (int i=0; i<6; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                temp[i][j][k] = cube[i][j][k];
            }
        }
    }
    for (int j=0; j<3; j++) {
        cube[upSide][j][2] = temp[frontSide][j][2];
        cube[frontSide][j][2] = temp[downSide][j][2];
        cube[downSide][j][2] = temp[backSide][j][2];
        cube[backSide][j][2] = temp[upSide][j][2];
    }
    clockwise(temp, rightSide);
}

void l() {
    char temp[6][3][3];
    for (int i=0; i<6; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                temp[i][j][k] = cube[i][j][k];
            }
        }
    }
    for (int j=0; j<3; j++) {
        cube[upSide][j][0] = temp[backSide][j][0];
        cube[backSide][j][0] = temp[downSide][j][0];
        cube[frontSide][j][0] = temp[upSide][j][0];
        cube[downSide][j][0] = temp[frontSide][j][0];
    }
    clockwise(temp, leftSide);
}

void u() {
    char temp[6][3][3];
    for (int i=0; i<6; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                temp[i][j][k] = cube[i][j][k];
            }
        }
    }
    for (int k=0; k<3; k++) {
        cube[leftSide][0][k] = temp[frontSide][0][k];
        cube[frontSide][0][k] = temp[rightSide][0][k];
        cube[rightSide][0][k] = temp[backSide][0][k];
        cube[backSide][0][k] = temp[leftSide][0][k];
    }
    clockwise(temp, upSide);
}

void d() {
    char temp[6][3][3];
    for (int i=0; i<6; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                temp[i][j][k] = cube[i][j][k];
            }
        }
    }
    for (int k=0; k<3; k++) {
        cube[leftSide][2][k] = temp[backSide][2][k];
        cube[frontSide][2][k] = temp[leftSide][2][k];
        cube[rightSide][2][k] = temp[frontSide][2][k];
        cube[backSide][2][k] = temp[rightSide][2][k];
    }
    clockwise(temp, downSide);
}

void f() {
    char temp[6][3][3];
    for (int i=0; i<6; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                temp[i][j][k] = cube[i][j][k];
            }
        }
    }
    for (int k=0; k<3; k++) {
        cube[upSide][2][k] = temp[leftSide][2][k];
        cube[leftSide][2][k] = temp[downSide][2][k];
        cube[downSide][2][k] = temp[rightSide][2][k];
        cube[rightSide][2][k] = temp[upSide][2][k];
    }
    clockwise(temp, frontSide);
}

void b() {
    char temp[6][3][3];
    for (int i=0; i<6; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                temp[i][j][k] = cube[i][j][k];
            }
        }
    }
    for (int k=0; k<3; k++) {
        cube[upSide][0][k] = temp[rightSide][0][k];
        cube[rightSide][0][k] = temp[downSide][0][k];
        cube[downSide][0][k] = temp[leftSide][0][k];
        cube[leftSide][0][k] = temp[upSide][0][k];
    }
    clockwise(temp, backSide);
}

int main() {
    char choice{};
    cout << "Rubiks' cube Simulator" << "\n";
    printCube();
    do {
        cout << "\n";
        cout << "Choice List: " << "\n";
        cout << "R" << "\n";
        cout << "L" << "\n";
        cout << "U" << "\n";
        cout << "D" << "\n";
        cout << "F" << "\n";
        cout << "B" << "\n";
        cout << "E. Exit" << "\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 'r':
            case 'R': {
                r();
                break;
            }
            case 'l':
            case 'L': {
                l();
                break;
            }
            case 'u':
            case 'U': {
                u();
                break;
            }
            case 'd':
            case 'D': {
                d();
                break;
            }
            case 'f':
            case 'F': {
                f();
                break;
            }
            case 'b':
            case 'B': {
                b();
                break;
            }
            case 'e':
            case 'E': {
                cout << "Goodbye!";
                break;
            }
            default:
                cout << "Wrong Choice Entered" << "\n";
        }
        if (choice!='e' && choice!='E') {
            printCube();
        }
    } while (choice!='e' && choice!='E');
    return 0;
}