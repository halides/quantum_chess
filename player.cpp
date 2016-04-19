#include "player.h"
#include <iostream>
#include <algorithm>

Player::Player(color c) {
    col = c;

    Position pos;
    std::vector<echelon> qp;

    for (int i=0; i<8; i++) {
	qp.push_back(echelon::pawn);
    }
    qp.push_back(echelon::knight);
    qp.push_back(echelon::knight);
    qp.push_back(echelon::bishop);
    qp.push_back(echelon::bishop);
    qp.push_back(echelon::rook);
    qp.push_back(echelon::rook);
    qp.push_back(echelon::queen);

    srand(time(0));
    if (c == color::white) {
        std::random_shuffle(qp.begin(), qp.end());
    }
    std::random_shuffle(qp.begin(), qp.end());

    for (int i=1; i<9; i++) {
        pos.rank = (c == color::white)?2:7; //i just love the trinary operator
        pos.file = 96+i; //ASCII 'a' == 97
        pieces.push_back(Piece(pos, echelon::pawn, qp.back()));
        qp.pop_back();
    }
    pos.rank = (c == color::white)?1:8;

    pos.file='a';
    pieces.push_back(Piece(pos, echelon::rook, qp.back()));
    qp.pop_back();
    pos.file='h';
    pieces.push_back(Piece(pos, echelon::rook, qp.back()));
    qp.pop_back();


    pos.file='b';
    pieces.push_back(Piece(pos, echelon::knight, qp.back()));
    qp.pop_back();
    pos.file='g';
    pieces.push_back(Piece(pos, echelon::knight, qp.back()));
    qp.pop_back();

    pos.file='c';
    pieces.push_back(Piece(pos, echelon::bishop, qp.back()));
    qp.pop_back();
    pos.file='f';
    pieces.push_back(Piece(pos, echelon::bishop, qp.back()));
    qp.pop_back();

    pos.file='d';
    pieces.push_back(Piece(pos, echelon::queen, qp.back()));
    qp.pop_back();
    pos.file='e';
    pieces.push_back(Piece(pos, echelon::king, echelon::king));

}

void Player::move(Position from, Position to) {
//    std::cout << from.file << from.rank << to.file << to.rank;
    for (Piece& p: pieces) {
        if (p.get_pos() == from) {
            p.set_pos(to);
            return;
        }
    }
}

std::vector<Piece>& Player::get_pieces() {
    return pieces;
}
