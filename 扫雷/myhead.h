#define X 15
#define Y 15
#define MINE 25
void reset_map(char fb[Y][X], char map[Y][X], int yy[Y], char xx[X + 1], int fuben[Y][X]);
void print_map(char map[Y][X], int yy[Y], char xx[X + 1]);
void set_mine(int fuben[Y][X]);
int check_mine(const int fuben[Y][X], int x, int y);
void check_num(const int fuben[Y][X], int x, int y, char map[Y][X]);
int check_zero(const int fuben[Y][X], char map[Y][X]);
int check_win(char map[Y][X]);
