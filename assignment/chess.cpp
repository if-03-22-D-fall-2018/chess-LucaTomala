/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.c
 * Author:			P. Bauer
 * Due Date:		November 03, 2010
 * ----------------------------------------------------------
 * Description:
 * Implementation of basic chess functions.
 * ----------------------------------------------------------
 */
 #include "chess.h"

 void setup_chess_board(ChessBoard chess_board)
 {
   init_chess_board(chess_board);
  for (char c = 'a'; c <= 'h'; c++) {
    add_piece(chess_board, c, 2, {White, Pawn});
    add_piece(chess_board, c, 7, {Black, Pawn});
  }

  add_piece(chess_board, 'a', 1, {White, Rook});
  add_piece(chess_board, 'h', 1, {White, Rook});
  add_piece(chess_board, 'b', 1, {White, Knight});
  add_piece(chess_board, 'g', 1, {White, Knight});
  add_piece(chess_board, 'c', 1, {White, Bishop});
 	add_piece(chess_board, 'f', 1, {White, Bishop});
 	add_piece(chess_board, 'd', 1, {White, Queen});
 	add_piece(chess_board, 'e', 1, {White, King});

 	add_piece(chess_board, 'a', 8, {Black, Rook});
 	add_piece(chess_board, 'h', 8, {Black, Rook});
 	add_piece(chess_board, 'b', 8, {Black, Knight});
  add_piece(chess_board, 'g', 8, {Black, Knight});
  add_piece(chess_board, 'c', 8, {Black, Bishop});
 	add_piece(chess_board, 'f', 8, {Black, Bishop});
 	add_piece(chess_board, 'd', 8, {Black, Queen});
  add_piece(chess_board, 'e', 8, {Black, King});
 }
 void init_chess_board(ChessBoard chess_board)
 {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        chess_board[i][j].is_occupied = false;
        chess_board[i][j].piece.type = NoPiece;
      }
    }
 }

 struct ChessSquare* get_square(ChessBoard chess_board,File file,Rank rank)
 {
   if(file > 'h' || (file < 'a' && rank > 8) || rank < 1) {
    return 0;
  }
return &chess_board[rank - 1][file - 'a'];
 }
 bool is_square_free (File file, Rank rank) {
  return file - 'a' < 8 && file - 'a' >= 0 && rank < 8 && rank >= 0;
}

 struct ChessPiece get_piece(ChessBoard chess_board, File a, Rank rank)
 {
   if (is_square_occupied(chess_board,rank,a && is_square_free(a, rank - 1))) {
     return chess_board[rank - 1][a - 'a'].piece;
   }
   struct ChessPiece p;
   p.type = NoPiece;
   return p;

 }

 bool is_square_occupied(ChessBoard chess_board,File file,Rank rank){
    return chess_board[rank - 1][file - 'a'].is_occupied;
 }
 bool add_piece(ChessBoard chess_board,File file,Rank rank,struct ChessPiece piece){
   if (!is_square_occupied(chess_board, file, rank) && is_square_free(file, rank - 1)) {
        chess_board[rank - 1][file - 'a'].is_occupied = true;
        chess_board[rank - 1][file - 'a'].piece = piece;
        return true;
     }
   return false;
  }
 bool remove_piece(ChessBoard chess_board, File file, Rank rank){
   if (is_square_occupied(chess_board, file, rank) && is_square_free(file, rank - 1)){
     add_piece(chess_board, file, rank, {});
     chess_board[rank-1][file-'a'].is_occupied = false;
     return true;
   }
   return false;
 }
 bool is_piece(struct ChessPiece piece, enum Color color, enum PieceType type){
   return (piece.color == color && piece.type == type);
 }

 bool 	squares_share_file (File s1_f, Rank s1_r, File s2_f, Rank s2_r){
   return s1_f == s2_f && is_square_free(s1_f, s1_r - 1) && is_square_free(s2_f, s2_r - 1);
 }
 bool 	squares_share_rank (File s1_f, Rank s1_r, File s2_f, Rank s2_r){
   return s1_r == s2_r && is_square_free(s1_f, s1_r - 1) && is_square_free(s2_f, s2_r - 1);
 }
 bool 	squares_share_diagonal (File s1_f, Rank s1_r, File s2_f, Rank s2_r){
   return false;
 }
 bool 	squares_share_knights_move (File s1_f, Rank s1_r, File s2_f, Rank s2_r){
   return false;
 }
 bool 	squares_share_pawns_move (enum Color color, enum MoveType move, File s1_f, Rank s1_r, File s2_f, Rank s2_r){
   return false;
 }
 bool 	squares_share_queens_move (File s1_f, Rank s1_r, File s2_f, Rank s2_r){
   return false;
 }
 bool 	squares_share_kings_move (File s1_f, Rank s1_r, File s2_f, Rank s2_r){
   return false;
}
