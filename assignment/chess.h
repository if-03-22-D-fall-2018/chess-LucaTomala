 #include <stdbool.h>
 #ifndef ___CHESS_H
 #define ___CHESS_H
 enum Color
 {
   White, Black
 };

 enum PawnMoves
 {
   CaptureMove, NormalMove
 };
 enum PieceType
 {
   Pawn, Rook, Knight, Bishop, Queen, King, NoPiece
 };

 struct ChessPiece
 {
     enum Color color;
     enum PieceType type;
 };

 struct ChessSquare
 {
     bool is_occupied;
     struct ChessPiece piece;
 };
