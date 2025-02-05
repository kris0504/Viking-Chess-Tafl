# Viking-Chess-Tafl

## Overview
Viking Chess: Tablut is an implementation of the ancient Nordic board game Tablut, a variant of the Tafl family of games. The game is played on a 9x9, 11x11, or 13x13 board, where the defending player protects the king while the attacking player attempts to capture him.

## How to Play
- The game supports board sizes of **9x9, 11x11, or 13x13**.
- One player controls the **defenders** (D), protecting the **king** (K), while the other controls the **attackers** (A).
- Attackers win by **capturing the king**.
- Defenders win by **moving the king to one of the four corners** (X).
- Pieces move **horizontally or vertically** any number of spaces, but cannot pass through other pieces.
- Only the **king can enter the throne** (center tile marked as T).
- A piece is captured if surrounded on **two opposite sides** by enemies.

## Commands
During the game, you can use the following commands:
- `move <start> <end>` - Move a piece from `<start>` position to `<end>` position (e.g., `move d4 d8`).
- `back` - Undo the last move.
- `help` - Display all available commands.
- `info` - Show current game statistics.
- `quit` - Exit the game.

## Features
- **Multiple board sizes**: Play on **9x9, 11x11, or 13x13** boards.
- **Turn-based gameplay**: Attackers and defenders take turns.
- **Piece capturing**: Pieces are removed when surrounded by opponents.
- **Game state management**: The game tracks the number of moves, remaining pieces, and captured units.
- **Undo functionality**: Revert the last move with `back`.
- **Victory conditions**: Attackers win by capturing the king, while defenders win if the king reaches a corner.

