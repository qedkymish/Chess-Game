# Console Chess

A text-based chess board and legal-move generator written in C++.

Built as the final project for CSIS-297 (Intermediate C++) at Grossmont College, then extended
afterward. The design goal was to keep every piece's movement rules inside that piece's own class,
so the board never needs to know how a knight moves.

## Design

### One class per piece

`ChessPiece` is an abstract base class with a single pure virtual method:

```cpp
virtual vector<Position> getLegalMoves(const ChessBoard& board) const = 0;
```

Each of the six piece types (`Pawn`, `Knight`, `Bishop`, `Rook`, `Queen`, `King`) derives from it
and implements that method independently. Adding a new piece means adding one class and touching
nothing else.

Every generator is written color-agnostic: direction, starting rank, and friendly-occupancy checks
all branch on `getColor()`, so both sides run the same code paths. Sliding pieces (bishop, rook,
queen) share a single `ChessBoard::isPathClear()` helper rather than each reimplementing ray
traversal.

### Ownership, and why captures need no code

The board owns its pieces through `unique_ptr<ChessPiece>[8][8]`, so there is no manual `delete`
anywhere in the project, and `ChessPiece` declares a virtual destructor for correct cleanup through
base-class pointers.

Captures fall out of that ownership model instead of needing their own branch. A move is:

```cpp
board[to.getRow()][to.getCol()] = move(board[from.getRow()][from.getCol()]);
```

Move-assigning onto an occupied square destroys whatever that `unique_ptr` was holding, so the
captured piece is freed automatically. There is no capture code path, and there is nothing to leak.

## What it does

- Legal move generation for all six piece types, both colors
- Captures, including pawn diagonal captures
- Path blocking for sliding pieces; friendly-occupancy and boundary rejection
- Pawn direction and the two-square opening from the starting rank
- Board rendering with legal-move highlighting (`x` marks reachable squares)
- Algebraic notation parsing and formatting (`e7`, `e7e5`)
- Menu-driven interface with a free play mode

## What it does not do

Stated plainly, because the scope was deliberate:

- **No check or checkmate detection.** A king can be moved into check, and pinned pieces are not
  pinned. Legality here means "this piece moves that way," not "this move is legal in this position."
- **No castling, en passant, or pawn promotion.**
- **No turn enforcement.** Free play mode lets either color move at any time.
- **No AI opponent and no move search.** This is a move generator and a board, not a chess engine.

## Building

Requires a C++17 compiler. No external dependencies.

```bash
git clone https://github.com/qedkymish/console-chess-cpp.git
cd console-chess-cpp
g++ -std=c++17 -Iinclude src/*.cpp -o chess
./chess
```

Builds clean with GCC 11 and 13, and with MSVC.

## Sample session

```
     A  B  C  D  E  F  G  H
 1   r  n  b  q  k  b  n  r
 2   p  p  p  p  p  p  p  p
 3   .  .  .  .  .  .  .  .
 4   .  .  .  .  .  .  .  .
 5   .  .  .  .  .  .  .  .
 6   .  .  .  .  .  .  .  .
 7   P  P  P  P  P  P  P  P
 8   R  N  B  Q  K  B  N  R

Enter your move ('e7' for legal moves, 'e7e5' to move, or 'q' to quit): e7

     A  B  C  D  E  F  G  H
 1   r  n  b  q  k  b  n  r
 2   p  p  p  p  p  p  p  p
 3   .  .  .  .  .  .  .  .
 4   .  .  .  .  .  .  .  .
 5   .  .  .  .  x  .  .  .
 6   .  .  .  .  x  .  .  .
 7   P  P  P  P  P  P  P  P
 8   R  N  B  Q  K  B  N  R

Legal moves for e7: e6 e5
```

Uppercase is White, lowercase is Black, `x` marks a legal destination.

**Known deviation:** rank 1 renders at the top of the board with Black on it, which is inverted from
standard chess orientation. The mapping is internally consistent but nonstandard.

## Project structure

```
include/    Class declarations (ChessPiece, the six pieces, Position, ChessBoard, Chess)
src/        Implementations and main.cpp
```

## Possible next steps

- Correct the board orientation so rank 1 is White's back rank
- Check detection, which is the prerequisite for everything else in real chess rules
- Turn enforcement, then castling, en passant, and promotion
- A test suite over known positions, since move generation is unusually easy to unit test
