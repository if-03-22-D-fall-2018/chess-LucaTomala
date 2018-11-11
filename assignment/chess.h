#ifndef __CHESS_H
 #define __CHESS_H

  enum Color { White, Black };
  enum MoveType { NormalMove, CaptureMove };
  enum PieceType{ Pawn, Knight, Rook, Bishop, Queen, King, NoPiece };

 struct ChessPiece{
   enum Color color;
   enum PieceType type;
 };
 struct ChessSquare{
   enum PieceType NoPiece;
   bool is_occupied;
   struct ChessPiece piece;
 };

 typedef struct ChessSquare ChessBoard[8][8];
 typedef int Rank;
 typedef unsigned char File;

 void setup_chess_board(ChessBoard chess_board);
 void init_chess_board(ChessBoard chess_board);

 struct ChessSquare* get_square(ChessBoard chess_board,File file,Rank rank);
 struct ChessPiece get_piece(ChessBoard chess_board, File a, Rank rank);

 bool is_square_occupied(ChessBoard chess_board,File file,Rank rank);
 bool add_piece(ChessBoard chess_board,File a,Rank rank,struct ChessPiece piece);
 bool remove_piece(ChessBoard chess_board, File file, Rank rank);
 bool is_piece(struct ChessPiece piece, enum Color color, enum PieceType type);

 bool 	squares_share_file (File s1_f, Rank s1_r, File s2_f, Rank s2_r);
 bool 	squares_share_rank (File s1_f, Rank s1_r, File s2_f, Rank s2_r);
 bool 	squares_share_diagonal (File s1_f, Rank s1_r, File s2_f, Rank s2_r);
 bool 	squares_share_knights_move (File s1_f, Rank s1_r, File s2_f, Rank s2_r);
 bool 	squares_share_pawns_move (enum Color color, enum MoveType move, File s1_f, Rank s1_r, File s2_f, Rank s2_r);
 bool 	squares_share_queens_move (File s1_f, Rank s1_r, File s2_f, Rank s2_r);
 bool 	squares_share_kings_move (File s1_f, Rank s1_r, File s2_f, Rank s2_r);

#endif
