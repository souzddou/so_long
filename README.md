<div align="center">

# 🕹️ so_long

### A 2D tile-based game built from scratch in C with MiniLibX — 1337 School

[![1337](https://img.shields.io/badge/1337-so__long-000000?style=for-the-badge)](https://github.com/souzddou/so_long)
[![Language](https://img.shields.io/badge/language-C-blue?style=for-the-badge)](https://github.com/souzddou/so_long)
[![Library](https://img.shields.io/badge/graphics-MiniLibX-orange?style=for-the-badge)](https://github.com/souzddou/so_long)

</div>

---

## 📖 About

**so_long** is a 1337/42 School project: a small top-down 2D game where the player moves around a tile map, collects every coin, and reaches the exit — all rendered from scratch in C using **MiniLibX** (real MLX, linked with `-lmlx -lXext -lX11`).

The map, texture set, and every rule (border walls, collectible count, reachability) are validated before the game window ever opens, and the game keeps a live move counter in the terminal as you play.

---

## ✨ Features

- 🗺️ **Custom `.ber` map parser** — strict validation of shape, borders, and required tiles
- 🌊 **Flood-fill solvability check** — guarantees every coin and the exit are actually reachable from the player's start before the game launches
- 🧱 **Context-aware wall tiling** — walls automatically pick the right texture variant (corner, straight, dead-end, etc.) based on their neighbors, instead of a single repeated wall sprite
- 🚶 **Smooth tile-based movement** with `WASD`
- 🪙 **Coin collection** with a live counter
- 🚪 **Exit tile** that only opens the win condition once every coin is collected
- 🔢 **Move counter** printed to the terminal on every move
- 🏆 **Win message** on reaching the exit with all coins collected
- 🧹 Clean shutdown & memory cleanup on `ESC` or window close

---

## 🗂️ Project Structure

```
so_long/
├── Makefile
├── so_long.c              # entry point, arg/extension checks, game loop kickoff
├── read_from_file.c       # reads the .ber map file line by line
├── parsing.c               # duplication / missing-tile / reachability orchestration
├── parsing2.c              # rectangularity & border-wall validation
├── check_road.c            # flood-fill reachability check (coins + exit)
├── init_images.c           # loads all .xpm textures into MiniLibX images
├── design_wall.c           # neighbor-aware wall texture selection
├── draw_map.c              # renders the map to the window
├── display_map.c           # window/game loop setup (hooks, mlx_loop)
├── key_hook.c               # WASD movement, coin pickup, win/quit logic
├── destroy_images.c        # image/window/display cleanup
├── utils_function.c         # helper utilities
├── libft.c / libft2.c       # custom libft functions
├── includes/
│   ├── so_long.h
│   ├── structs.h            # t_vars, t_char, t_walls
│   ├── get_next_line/       # line-by-line file reading
│   └── printf/               # custom ft_printf
├── textures/
│   ├── player.xpm, enemy.xpm, wall.xpm, door.xpm, gain.xpm, space.xpm
│   └── W/                    # directional wall-tiling variants (corners, straights, dead-ends)
└── maps/
    ├── map1.ber
    ├── map2.ber
    └── .ber.ber
```

---

## 🛠️ Built With

| Tool / Library | Purpose |
|---|---|
| **C** | Core language |
| **MiniLibX** | Window creation, image loading, rendering, key hooks |
| **X11 / Xext** | MiniLibX's underlying display backend on Linux |
| **libft** (custom) | Standard library replacements |
| **get_next_line** (custom) | Line-by-line file reading |
| **ft_printf** (custom) | Formatted terminal output (move counter, messages) |
| **Makefile** | Build automation |

---

## ⚙️ Installation & Build

### Prerequisites

- Linux with X11 (MiniLibX in this repo targets Linux, via `-lmlx -lXext -lX11`)
- `gcc`/`cc`, `make`
- MiniLibX and its X11 dependencies installed

```bash
sudo apt-get update
sudo apt-get install libxext-dev libbsd-dev libx11-dev
```

> MiniLibX itself (`mlx.h` / `libmlx.a`) needs to be available on your system's include/library path — this repo does not vendor it directly, so make sure it's installed separately (e.g. via the classic 42 `minilibx-linux` repo) or added as a submodule.

### Build

```bash
git clone https://github.com/souzddou/so_long.git
cd so_long
make
```

### Run

```bash
./so_long maps/.ber.ber
```

> ⚠️ `map1.ber` and `map2.ber` in this repo currently either contain an unsupported tile character or are empty, and will be rejected by the parser. Use `.ber.ber`, or create your own valid map, to actually launch the game.

---

## 🕹️ Controls

| Key | Action |
|---|---|
| `W` | Move up |
| `A` | Move left |
| `S` | Move down |
| `D` | Move right |
| `ESC` | Quit the game |
| Window close (X) | Quit the game |

Every move prints `Moves : <n>` to the terminal. Reaching the exit (`E`) after collecting all coins (`C`) prints the final move count and a win message, then closes the game.

---

## 🗺️ Map Format (`.ber`)

The map is a plain-text grid where every character represents a tile:

| Tile | Meaning |
|---|---|
| `1` | Wall |
| `0` | Empty floor |
| `P` | Player start position (exactly one required) |
| `C` | Collectible coin (at least one required) |
| `E` | Exit (exactly one required, opens the win once all coins are collected) |

### Validation Rules

The parser rejects the map (`Eroor`) if any of these fail:

- ✅ The map is **rectangular** — every row has the same width
- ✅ The map is fully **enclosed in walls** (`1`) on all four borders
- ✅ Exactly **one** `P` and exactly **one** `E`
- ✅ At least one `C`, at least one `1`, one `P`, and one `E` are present
- ✅ Only valid tile characters (`0`, `1`, `P`, `C`, `E`) appear anywhere in the map
- ✅ A **flood fill** from the player's position confirms every coin and the exit are reachable without crossing a wall

### Example (`.ber.ber`)

```
1111111111111111111111
1010001111PE1110101111
1010101111011111111011
1000000000000000001111
1011101011111010111011
1111111011101010001011
1000111011111010111001
1010101011111110101001
1110111010001010111011
10000C00C1010100000001
1111111111111111111111
```

---

## 🧠 How It Works

1. **`read_from_file`** reads the `.ber` file into memory via a custom `get_next_line`.
2. **`parsing2`** checks the map is rectangular and fully walled on its border.
3. **`parsing`** then checks for duplicate/missing `P`, `E`, and `C` tiles, rejects any invalid character, and runs **`check_road`**.
4. **`check_road`** performs a **flood fill** starting from the player's position on a working copy of the map; if it can't reach every coin and the exit, the map is rejected — this guarantees every generated game is winnable.
5. **`init_images`** loads every `.xpm` texture (player, coins, exit/door, walls, and all directional wall variants) into MiniLibX images.
6. **`design_wall`** inspects each wall tile's neighbors (`t_walls`: up/down/left/right) and picks the matching texture — straight edges, corners, dead-ends, and fully-surrounded tiles all render differently instead of one flat wall sprite.
7. **`draw_map`** / **`display_map`** render the grid and register the **`key_hook`** for input, running the game inside `mlx_loop`.
8. **`key_hook`** moves the player, updates/decrements the coin count on pickup, prints the move counter, checks the win condition, and handles `ESC`/window-close cleanup via `destroy_images` and `cleanup_and_exit`.

---

## ✅ Error Handling

The program handles and reports (`Eroor`/`Error`) for:

- Wrong number of arguments
- Map filename not ending in `.ber`
- File that can't be opened
- Non-rectangular map
- Map not fully enclosed by walls
- Missing or duplicated `P` / `E`
- Missing `C` or `1` tiles
- Invalid characters in the map
- A map with an unreachable coin or exit
- Failed texture/image loads (`check_image_fail`)

---

## 🧪 Testing

```bash
# Run with the working sample map
./so_long maps/.ber.ber

# Try your own maps to test parsing edge cases
./so_long maps/my_broken_map.ber

# Check for memory leaks
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/.ber.ber
```

---

## 👤 Author

- **souzddou** — [GitHub](https://github.com/souzddou) · `souzddou@student.42.fr`

---

## 📄 License

This project is part of the 1337/42 School curriculum and is intended for educational purposes.
