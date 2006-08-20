/************************************************************************ 
 * This file is part of PDCurses. PDCurses is public domain software;	*
 * you may use it for any purpose. This software is provided AS IS with	*
 * NO WARRANTY whatsoever.						*
 *									*
 * If you use PDCurses in an application, an acknowledgement would be	*
 * appreciated, but is not mandatory. If you make corrections or	*
 * enhancements to PDCurses, please forward them to the current		*
 * maintainer for the benefit of other users.				*
 *									*
 * No distribution of modified PDCurses code may be made under the name	*
 * "PDCurses", except by the current maintainer. (Although PDCurses is	*
 * public domain, the name is a trademark.)				*
 *									*
 * See the file maintain.er for details of the current maintainer.	*
 ************************************************************************/

#define	CURSES_LIBRARY 1
#include <curses.h>

RCSID("$Id: move.c,v 1.17 2006/08/20 21:48:36 wmcbrine Exp $");

/*man-start**************************************************************

  Name:                                                          move

  Synopsis:
	int move(int y, int x);
	int wmove(WINDOW *win, int y, int x);

  X/Open Description:
	The cursor associated with the window is moved to the given
	location.  This does not move the physical cursor of the
	terminal until refresh() is called.  The position specified is
	relative to the upper left corner of the window, which is (0,0).

	NOTE: move() is a macro.

  X/Open Return Value:
	All functions return OK on success and ERR on error.

  Portability				     X/Open    BSD    SYS V
					     Dec '88
	move					Y	Y	Y
	wmove					Y	Y	Y

**man-end****************************************************************/

int move(int y, int x)
{
	PDC_LOG(("move() - called: y=%d x=%d\n", y, x));

	if (stdscr == (WINDOW *)NULL)
		return ERR;

	if ((x < 0) || (y < 0) || (x >= stdscr->_maxx) || (y >= stdscr->_maxy))
		return ERR;

	stdscr->_curx = x;
	stdscr->_cury = y;

	return OK;
}

int wmove(WINDOW *win, int y, int x)
{
	PDC_LOG(("wmove() - called: y=%d x=%d\n", y, x));

	if (win == (WINDOW *)NULL)
		return ERR;

	if ((x < 0) || (y < 0) || (x >= win->_maxx) || (y >= win->_maxy))
		return ERR;

	win->_curx = x;
	win->_cury = y;

	return OK;
}
