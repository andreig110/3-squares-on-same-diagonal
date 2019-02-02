#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

#include <iostream>
#include <string>

namespace {

    const std::string FileToChar("abcdefgh");
    const std::string RankToChar("12345678");

} // namespace

enum File : int {
    FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NB
};

enum Rank : int {
    RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NB
};

struct Square {
    Square() = default;
    Square(File f, Rank r) { file = f; rank = r; }
    Square(int f, int r) { file = static_cast<File>(f); rank = static_cast<Rank>(r); }
    File file;
    Rank rank;
};


// Stream extraction and insertion operators

inline std::ostream& operator<<(std::ostream& os, const Square& sq)
{
    //os << FileToChar[sq.file] << RankToChar[sq.rank];
    os << char('a' + sq.file) << char('1' + sq.rank);  // It is about 5 % faster than previous line (on my PC)
    return os;
}

inline std::istream& operator>>(std::istream& is, Square& sq)
{
    char file;
    is >> file;
    if (file >= 'a' && file <= 'h')
        file -= 'a';
    else if (file >= 'A' && file <= 'H')
        file -= 'A';
    else if (file >= '1' && file <= '8')
        file -= '1';
    //else ;  // Undefined behaviour
    
    char rank;
    is >> rank;
    rank -= '1';  // Undefined behaviour if rank is not in range '1'..'8'
    
    /*if( !((file >= FILE_A && file <= FILE_H) && (rank >= RANK_1 && rank <= RANK_8)) )
        is.setstate(std::ios::failbit);*/
    
    sq.file = static_cast<File>(file);
    sq.rank = static_cast<Rank>(rank);
    return is;
}

#endif // #ifndef TYPES_H_INCLUDED
