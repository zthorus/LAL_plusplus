// LAL (Live-A-Log), v.3.1
// by S. Morel 1998-2018

// Header file for X11 port
// by S. Morel 2005-2018

// Warning: terms of the GNU General Public License apply.
// You should have received a copy of the GNU Library General Public
// License along with this source; if not, get it from www.gnu.org

#ifndef _LALPORT_X11
#define _LALPORT_X11

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysymdef.h>

// definition of values for special keys in X11
/* note: problem with gcc when compiling lal.C:
   though the follwing works, keysyms are not
   replaced by their values. Temporary fix
   (used values in /usr/X11R6/include/X11/keysymdef.h)
*/ 

#define LEFT_ARROW_K  0xFF51 // XK_Left
#define RIGHT_ARROW_K 0xFF53 // XK_Right
#define DELETE_K      0xFF08 // XK_BackSpace
#define RETURN_K      0xFF0D // XK_Return
#define ENTER_K       0xFF0D // XK_Return

// definition of window for X11 port

typedef struct
{
  Window win;	// data on window
  XImage *xim;   // pixmap of window
  char *im;     // pointer on pixmap data
}
windowStructure;

// definition of a point (MacOS idiosyncracy, not existing for X11)

typedef struct
{
  long h;
  long v;
}
Point;

typedef struct
{
  char kBuf[2];
  Display *display;
  Visual  *visu;
  XEvent report;
  int screen;
  GC gc;
  unsigned int depth;
  int argc;
  char **argv;
}
GraphPort;

// boolean definition
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

typedef int Boolean;
  

#endif
