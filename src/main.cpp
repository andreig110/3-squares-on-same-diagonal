/*
 * Andrei Guga
 * 02 Feb 2019
 * 
 * This program determines whether three squares are on the same diagonal.
 */

#include <iostream>

#include "types.h"

using namespace std;

namespace {

    // Alternative name for function: diagonally_aligned
    bool on_same_diagonal(const Square& sq1, const Square& sq2, const Square& sq3)
    {
        const int df21 = sq2.file - sq1.file;
        const int dr21 = sq2.rank - sq1.rank;
        const int df31 = sq3.file - sq1.file;
        const int dr31 = sq3.rank - sq1.rank;

        bool res =  (df21 ==  dr21) && (df31 ==  dr31);
        if (!res)
            res  =  (df21 == -dr21) && (df31 == -dr31);

        return res;
    }
}

int main()
{
    Square sq1, sq2, sq3;
    
    cout << "Enter the address of the first square: ";
    cin >> sq1;
    cout << "Enter the address of the second square: ";
    cin >> sq2;
    cout << "Enter the address of the third square: ";
    cin >> sq3;
    
    for (int rank = RANK_8; rank >= RANK_1; --rank) {
        cout << "  " << char('1' + rank) << "  ";
        for (int file = FILE_A; file <= FILE_H; ++file) {
            if (    (sq1.file == file && sq1.rank == rank)
                 || (sq2.file == file && sq2.rank == rank)
                 || (sq3.file == file && sq3.rank == rank)  )
                cout << "X ";
            else
                cout << "\u22C5 ";
        }
        cout << "\n";
    }
    
    cout << "     ";
    for (int file = FILE_A; file <= FILE_H; ++file)
        cout << char('A' + file) << " ";
    cout << "\n";
    
    cout << "Squares " << sq1 << ", " << sq2 << " and " << sq3;
    if (on_same_diagonal(sq1, sq2, sq3))
        cout << " are on the same diagonal." << endl;
    else
        cout << " are not on the same diagonal." << endl;
}
