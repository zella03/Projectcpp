/*
 * template for the course Podstawy Programowania
 * only to be used for the project in this course
 * author: K.M. Ocetkiewicz
 */
#ifndef CONIO2_H
#define CONIO2_H

#define BLACK		0
#define BLUE		1
#define GREEN		2
#define CYAN		3
#define RED		4
#define MAGENTA		5
#define BROWN		6
#define LIGHTGRAY	7
#define DARKGRAY	8
#define LIGHTBLUE	9
#define LIGHTGREEN	10
#define LIGHTCYAN	11
#define LIGHTRED	12
#define LIGHTMAGENTA	13
#define YELLOW		14
#define WHITE		15

#define NONE_FILE 1
#define BLACK_FILE 2
#define WHITE_FILE 3
#define DOT_FILE 4


#define NONE_FROM 65536
#define BLACK_FROM 2*65536
#define WHITE_FROM 3*65536

#define _NOCURSOR	0
#define _SOLIDCURSOR	1
#define _NORMALCURSOR	2

#ifndef EOF
#define EOF		-1
#endif

#define LASTMODE	-1
#define C80		3
#define C4350		8


#define MENUX 1
#define MENUY 2

#define BOARDSIZE 9
#define BOARDX 45
#define	BOARDY 4

#define KEY_0 0
#define KEY_I  105
#define KEY_N 110
#define KEY_S 115
#define KEY_ESC 27
#define KEY_ENTER 0x0d
#define KEY_Q 113
#define KEY_UP 0x48
#define KEY_DOWN 0x50
#define KEY_LEFT 0x4b
#define KEY_RIGHT 0x4d
#define KEY_P 112
#define KEY_L 108
#define KEY_H 104
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_BACKSPACE 8

#define BORDER_ROW 205
#define BORDER_COL 186
#define BORDER_LEFT_COR_UP 201
#define BORDER_RIGHT_COR_UP 187
#define BORDER_LEFT_COR_DOWN 200
#define BORDER_RIGHT_COR_DOWN 188


#define PRE_GAME_STATE 0
#define PLAY_GAME_STATE 1
#define HANDICAP_STATE 2


extern int _wscroll;		// 1 = enable scroll
				// 0 = disable scroll

struct text_info {
	unsigned char curx;
	unsigned char cury;
	unsigned short attribute;
	unsigned short normattr;
	unsigned char screenwidth;
	unsigned char screenheight;
};

#ifdef __cplusplus
extern "C" {
#endif
	void gotoxy(int x, int y);		// move cursor to the position (x,y)
	int wherex(void);			// return x coordinate of the cursor
	int wherey(void);			// return y coordinate of the cursor 
	void _setcursortype(int cur_t);		// set cursor type: _NOCURSOR, _SOLIDCURSOR or _NORMALCURSOR

	void textattr(int newattr);		// set foreground and background color at once (newattr = background * 16 + foreground)
	void textbackground(int newcolor);	// set background color of new characters
	void textcolor(int newcolor);		// set foreground color of new characters

	void clreol(void);			// clear till the end of current line
	void clrscr(void);			// clear entire screen
	void delline(void);			// delete current line
	void insline(void);			// insert empty line at cursor position

	int getch(void);			// wait for keyboard input and return the read character
	int getche(void);			// as above, but also write the read character to screen
	int kbhit(void);			// test if a key was pressed; if kbhit returns nonzero,
						// the next getch will return immediately
	int ungetch(int ch);			// return character ch to input buffer; the
						// next getch will return this character

	int cputs(const char* str);		// write string str to screen at current cursor position
	int putch(int c);			// write single character to screen at current cursor position

	// save a portion of screen to buffer dest; dest must be large enough to hold
	// two bytes per every saved character
	int gettext(int left, int top, int right, int bottom, void* dest);
	// write a saved portion from buffer to screen
	int puttext(int left, int top, int right, int bottom, void* source);
	// move a portion of screen to position (delstleft, desttop)
	int movetext(int left, int top, int right, int bottom, int destleft, int desttop);

	// get information about the state of screen
	// see the text_info structure
	void gettextinfo(struct text_info* info);

	// set screen size: C80, C4350 or LASTMODE
	void textmode(int mode);

	// bonus functions
	void settitle(const char* title);

	int Conio2_Init(void);
#ifdef __cplusplus
}
#endif

#endif