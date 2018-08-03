// LAL (Live-A-Log), v.3.1
// by S. Morel 1998-2018

// Header file for Lal

// Warning: terms of the GNU General Public License apply.
// You should have received a copy of the GNU General Public
// License along with this source; if not, get it from www.gnu.org 


#ifndef _LAL_H
#define _LAL_H
   
#ifndef PI
#define PI 3.1415926
#endif

// depending on the OS, comment out one of the following includes:

#include "lalPort_switch.h"

#ifdef _USE_LALPORT_X11
#include "lalPort_X11.h"
#endif
#ifdef _USE_LALPORT_MACOS
#include "lalPort_MacOS.h"
#endif

typedef struct
{
  double re;
  double im;
}
complex;

typedef struct
{
  unsigned char r;
  unsigned char g;
  unsigned char b;
}
coul;

// Constants 

#define tSelectorOne  0 // ItemType = button array, only one button can be selected 
#define tSelectorMany 1 // ItemType = button array, several buttons can be selected 
#define tSelectorClick 2 // ItemType = button array, not latched when released
#define tInputKbrd  3 // ItemType = input by keyboard
#define tPlusMinus  4 // ItemType = like InputKbrd with up and down arrows to modify a number
#define tBarGraph       5 // ItemType = bar graph 
#define tCurve          6 // ItemType = 1-D plot
#define tMap            7 // ItemType = 2-D density map
#define tMultiCurve     8 // ItemType = double 1-D plot
#define tDisplayOnly    9 // ItemType = value display, no user input

#define ONE 0
#define MANY 0x40
#define CLICK 0x80

// Types of variable linked to lal
 
enum{Lchar,Luchar,Lshort,Lushort,Llong,Lulong,Lfloat,Ldouble,Lreal,Limaginary,Lmodulus,Lsquaremod,LphaseDeg,LphaseRad,Lstring};

// Colors and grey-levels

enum{Lred,Lgreen,Lblue,Lbrown,Lgrey,Lamber,Lpink,Lpurple};

#define Lblack 254
#define Lwhite 255

enum{GREY,COLOR}; // LUTs for maps

#define NOT_LOCKED 0
#define LOCKED 1

#define ARI 0
#define GEO 1

#define L_MAX  20   
#define H_TEXT  13   // height (in pix.) of a text line
#define W_TEXT  6     // width (in pix.) of a character
#define W_EDGE  3    // width (in pix.) of button edged
#define S_ARW   11    // arrow (PlusMinus) size  

// Structures 

typedef struct
{
  char *title;    // item title (displayed on a bar for button arrays)   
                  // NULL=> no title
                  // argument name for InputKbrd and PlusMinus            
  long color;     // item color
  long type;      // item type
 
  long   nbButt;         // nb of buttons (SelectorXXX)
  long   buttRow;        // nb. of buttons per row (0= default 2/3 auto-format)
  long   nbChar;         // nb of char. in input field (InputKbrd/DispOnly/PlusMinus)
  long   bSize;          // max. length of text in buttons (SelectorXXX)
  long   locked;         // user input disabled (InputKbrd/PlusMinus)
  double vMin;           // minimum value to display (PlusMinus/BarGraph)
  double vMax;           // maximum value to display (PlusMinus/BarGraph)
  double step;           // increment/decrement step (PlusMinus)
  long   progrs;         // arithmetical or geometrical progression (PlusMinus)
  long   xSize;          // (Map/Curve/MultiCurve)
  long   ySize;           
  long   xOrg;
  long   yOrg;
  long   zoomF;          // zoom factor (Map/Curve/MultiCurve)
  long   inEdit;         // =1: user is entering value (InputKbrd/PlusMinus)
  long   pushed;         // =1: button is temporary pushed (SelectorClick)
  char   tmps[80];       // temporary string for display
 
  char    **name;         // buttons names
  unsigned long argPtr;   // pointer on the variable linked to the item 
  long          argType;  // type of linked variable
  long          stCurve;  // index of first curve to draw (MultiCurve)
  long          enCurve;  // index of last curve to draw (MultiCurve)
  long          lut;      // used LUT (grey-levels or spectrum) (Map) 
 
  char        *disp;      // char string used for value of the variable display
  Point       *iPoint;    // point (argument if type=map) 
  double      *minPtr;    // smallest value (if type=curve) 
  double      *maxPtr;    // greatest value (if type=curve) 
 
  long  width;     // total item width (in pixel)  
  long  yMin;      // y-position of the top edge in pixmap (relative to yBlk)
  long  yMax;      // y-position of the bottom edge in pixmap
}
LItem;  
 
                       
class Lal
{
 private:
 
  char *_title; // name of the lal
  long _xPos;   // window position
  long _yPos; 
  long _wLal;   // window width
  long _hLal;   // window height
 
  long _wBlk[10];              // minimal block widths
  long _hBlk[10];              // block heights
  long _yBlk[10];              // block y-coordinates (top)
  long _wCol[10][5];           // minimal column widths
  long _hCol[10][5];           // minimal column heights
  long _xCol[10][5];           // column x-coordinates (left)
  long _blkCard[10];           // number of columns in each block
  long _colCard[10][5];        // number of items in each column
  long _itemsTable[10][5][20]; // table giving item indices 
  long _wBut[10][5];           // width (in number of chars) for InputKbrd/PlusMinus/BarGraph button for each column 
 
  long _nbBlocks;         // number of blocks in the lal   
  long _nbItems;          // total number of items in the lal
  LItem _itemsArray[200]; // items of the lal 
   
  long _count;         // item counter (reset for each new column)
  long _curBlock;      // current block where items are put in
  long _curCol;        // current column where items are put in
  char _kBuf[2];        // keyboard buffer 
  Boolean _hidden;     // true= the lal is not diplayed

  unsigned long _xlut[256]; // pseudo-LUT to convert LAL colors into TrueColor pixel values (X11 only)
  int  _mapLut;    // current LUT used for maps

  // private graphic port (MacOS or X11) dependent methods
    
  long InitLalBitmap(void);                                                  // init the bitmap of the lal
  void UpdateBitmap(void);                                                   // update the bitmap display 
  void Dot(long color,long x,long y);                                        // draw a point (for items)
  void SetPixel(long x0,long y0,long x,long y,long z,long value, long lut); // set a pixel value in a map item
  void DrawCaret(long xo,long yo,long x,long y,long r);                      // draw a caret in a text box while edited
  void FreePortMem(void);                                                    // free memory used by the port
    
  // lal general private methods
    
  void Rect(long color,long xpos,long ypos,long w);                   // draw a rectangle
  void Button(long color,long xpos,long ypos,long w);                 // draw a button
  void PushedButton(long color,long xpos,long ypos,long w);           // draw a pushed button 
  void LockedButton(long color,long xpos,long ypos,long w);           // draw a DisplayOnly (edges only)
  void Input(long color,long xpos,long ypos,long w);                  // draw a text zone
  void Bar(long n,long xpos,long ypos,long w);                        // draw a bar-graph
  void MapFrame(long color,long w,long xpos,long ypos,long u,long h); // draw a map frame
  void UpArrow(long color,long xpos,long ypos);                       // draw an "up" arrow (for PlusMinus)
  void DownArrow(long color,long xpos,long ypos);                     // draw an "down" arrow (for PlusMinus)
  void Print(long x,long y,long color,const char *s);                 // write a char string
  void Map(long n,long xpos,long ypos);                               // display a map
  void Curve(long n,long xpos,long ypos);                             // display a 1-D plot
  void MultiCurve(long n,long xpos,long ypos);                        // display a multiple 1-D plot
 
  void Draw(void);       // draw parts that never change

  long GetTheKey(void);  // get the ID of the pressed key
  char GetTheChar(void); // get the ASCII code of the pressed key
 
  long NewNonGraph(const char *theTitle,long theColor,long theType,const char *theNames,unsigned long theArg,long argType);
  long LNewMap(const char *theTitle,long theColor,long xo,long yo,long xl,long yl,long z,unsigned long theArg,long argType,Point *CursLoc);
  long LNewCurve(const char *theTitle,long theColor,long xo,long xl,long yl,long z,unsigned long theArg,long argType,double *min,double *max);
  long LNewMultiCurve(const char *theTitle,long theColor,long xo,long xl,long yl,long z,long n0,long n1,unsigned long theArg,long theArgType,double *min,double *max);

  
 public:

  // the following variables had to be made public to be accessible by 
  // LalEnv methods

  char  *fontTable;     // bitmap of the lal font 
  coul lut[24];   // used LUT
  GraphPort port;          // graphic port info (system-dependent)
  windowStructure wins; // window associated to the lal

  // methods
 
  Lal(const char *theTitle,long xLal,long yLal); // constructor: returns 1 if OK, 0 otherwise
  ~Lal(); // destructor
  
  // public graphic port (MacOS or X11) methods
    
  void Show(void);                // first lal display (with window creation)
    
  // create new item that is:
  
  // - a button array 

  long NewSelector(const char *theTitle,long theColor,long theType,const char *theNames,long *theArg);
  
  // - an InputKbrd
  
  long NewInputKbrd(const char *theTitle,long theColor,long theSize,long *theArg);
  long NewInputKbrd(const char *theTitle,long theColor,long theSize,unsigned long *theArg);
  long NewInputKbrd(const char *theTitle,long theColor,long theSize,short *theArg);
  long NewInputKbrd(const char *theTitle,long theColor,long theSize,unsigned short *theArg);
  long NewInputKbrd(const char *theTitle,long theColor,long theSize,float *theArg);
  long NewInputKbrd(const char *theTitle,long theColor,long theSize,double *theArg);
  long NewInputKbrd(const char *theTitle,long theColor,long theSize,char *theArg);
  long NewInputKbrd(const char *theTitle,long theColor,long theSize,unsigned char *theArg);
  long NewInputKbrd(const char *theTitle,long theColor,long theSize,complex *TheArg,long TheCmpEl);
  
  // - a DisplayOnly
  
  long NewDisplayOnly(const char *theTitle,long theColor,long theSize,long *theArg);
  long NewDisplayOnly(const char *theTitle,long theColor,long theSize,unsigned long *theArg);
  long NewDisplayOnly(const char *theTitle,long theColor,long theSize,short *theArg);
  long NewDisplayOnly(const char *theTitle,long theColor,long theSize,unsigned short *theArg);
  long NewDisplayOnly(const char *theTitle,long theColor,long theSize,float *theArg);
  long NewDisplayOnly(const char *theTitle,long theColor,long theSize,double *theArg);
  long NewDisplayOnly(const char *theTitle,long theColor,long theSize,char *theArg);
  long NewDisplayOnly(const char *theTitle,long theColor,long theSize,unsigned char *theArg);
  long NewDisplayOnly(const char *theTitle,long theColor,long theSize,complex *TheArg,long TheCmpEl);
  
  // - a PlusMinus
  
  long NewPlusMinus(const char *theTitle,long theColor,long theSize,double min,double max,double step,long progrs,long *theArg);
  long NewPlusMinus(const char *theTitle,long theColor,long theSize,double min,double max,double step,long progrs,unsigned long *theArg);
  long NewPlusMinus(const char *theTitle,long theColor,long theSize,double min,double max,double step,long progrs,short *theArg);
  long NewPlusMinus(const char *theTitle,long theColor,long theSize,double min,double max,double step,long progrs,unsigned short *theArg);
  long NewPlusMinus(const char *theTitle,long theColor,long theSize,double min,double max,double step,long progrs,float *theArg);
  long NewPlusMinus(const char *theTitle,long theColor,long theSize,double min,double max,double step,long progrs,double *theArg);
  long NewPlusMinus(const char *theTitle,long theColor,long theSize,double min,double max,double step,long progrs,char *theArg);
  long NewPlusMinus(const char *theTitle,long theColor,long theSize,double min,double max,double step,long progrs,unsigned char *theArg);
  long NewPlusMinus(const char *theTitle,long theColor,long theSize,double min,double max,double step,long progrs,complex *TheArg,long TheCmpEl);
  
  // - a BarGraph
  
  long NewBarGraph(const char *theTitle,long theColor,double min,double max,long *theArg);
  long NewBarGraph(const char *theTitle,long theColor,double min,double max,unsigned long *theArg);
  long NewBarGraph(const char *theTitle,long theColor,double min,double max,short *theArg);
  long NewBarGraph(const char *theTitle,long theColor,double min,double max,unsigned short *theArg);
  long NewBarGraph(const char *theTitle,long theColor,double min,double max,float *theArg);
  long NewBarGraph(const char *theTitle,long theColor,double min,double max,double *theArg);
  long NewBarGraph(const char *theTitle,long theColor,double min,double max,char *theArg);
  long NewBarGraph(const char *theTitle,long theColor,double min,double max,unsigned char *theArg);
  long NewBarGraph(const char *theTitle,long theColor,double min,double max,complex *TheArg,long TheCmpEl);

  // - a map

  long NewMap(const char *theTitle,long theColor,long xo,long yo,long xl,long yl,long z,long **theArg,Point *CursLoc);
  long NewMap(const char *theTitle,long theColor,long xo,long yo,long xl,long yl,long z,unsigned long **theArg,Point *CursLoc);
  long NewMap(const char *theTitle,long theColor,long xo,long yo,long xl,long yl,long z,short **theArg,Point *CursLoc);
  long NewMap(const char *theTitle,long theColor,long xo,long yo,long xl,long yl,long z,unsigned short **theArg,Point *CursLoc);
  long NewMap(const char *theTitle,long theColor,long xo,long yo,long xl,long yl,long z,float **theArg,Point *CursLoc);
  long NewMap(const char *theTitle,long theColor,long xo,long yo,long xl,long yl,long z,double **theArg,Point *CursLoc);
  long NewMap(const char *theTitle,long theColor,long xo,long yo,long xl,long yl,long z,char **theArg,Point *CursLoc);
  long NewMap(const char *theTitle,long theColor,long xo,long yo,long xl,long yl,long z,unsigned char **theArg,Point *CursLoc);
  long NewMap(const char *theTitle,long theColor,long xo,long yo,long xl,long yl,long z,complex **theArg,long theCmpEl,Point *CursLoc);
 
  // a 1-D plot
  
  long NewGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,long *theArg,double *min,double *max);
  long NewGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,unsigned long *theArg,double *min,double *max);
  long NewGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,short *theArg,double *min,double *max);
  long NewGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,unsigned short *theArg,double *min,double *max);
  long NewGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,float *theArg,double *min,double *max);
  long NewGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,double *theArg,double *min,double *max);
  long NewGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,char *theArg,double *min,double *max);
  long NewGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,unsigned char *theArg,double *min,double *max);
  long NewGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,complex *theArg,long theCmpEl,double *min,double *max);
  
  // a multiple 1-d plot
  
  long NewMultiGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,long n0,long n1,long **theArg,double *min,double *max);
  long NewMultiGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,long n0,long n1,unsigned long **theArg,double *min,double *max);
  long NewMultiGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,long n0,long n1,short **theArg,double *min,double *max);
  long NewMultiGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,long n0,long n1,unsigned short **theArg,double *min,double *max);
  long NewMultiGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,long n0,long n1,float **theArg,double *min,double *max);
  long NewMultiGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,long n0,long n1,double **theArg,double *min,double *max);
  long NewMultiGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,long n0,long n1,char **theArg,double *min,double *max);
  long NewMultiGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,long n0,long n1,unsigned char **theArg,double *min,double *max);
  long NewMultiGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,long n0,long n1,complex **theArg,long theCmpEl,double *min,double *max);

  
  void NextBlock(void);     // creat a new item block ; arg = number of columns
  void NextColumn(void);    // create a new item column
  long Prepare(void);       // prepare lal (compute window size, etc..)
  void Update(void);        // update lal content (display current values of linked variables)
  void Hide(void);          // hide the lal (without destroying it)
  void EditItem(long xw,long yw); // edit item clicked in lal (according to mouse position)
  
  long LockInput(long n);    // lock item against user inputs   
  long UnlockInput(long n);  // unlock item against user inputs   
  long ModifyMap(long n,long lut,long xo,long yo,long z);    // modify LUT, origin and zoom factor of a map
  long ModifyGraph(long n,long xo,long z);  // modify origin and zoom factor of a graph
  long ModifyMultiGraph(long n,long n0,long n1,long xo,long z); // modify LUT, curve index, origin and zoom factor of a multi-graph 
  void SetLut(long);                                            // set LUT 
};


class LalEnv
{
 private:
  coul          _lut[24];         // used LUT
  char          *_fontTable;      // lal font bitmap
  Lal           **_lalsArray;     // lals in the environnement 
  Lal           *_lalActive;      // activated lals
  Boolean       _active;          // true => lal activated by click
  long          _count;           // lal counter
  long          _mapLut;          // current LUT for maps        
  GraphPort     _port;            // graphic port info

  void CopyGraphPort(Lal *theLal); // copy graph port info to a lal

 public:
  LalEnv(int argc,char **argv);   // constructor
  void AttachLal(Lal *theLal);    // attach a lal to the environment
  void InitPort(int argc,char **argv);
  void WatchLal(void);
};


// Functions 


// graphic port (MacOS or X11) dependent functions 

void WaitABit(long t); // wait t ticks

// common functions

double Get2DValue(long i,long j,unsigned long a,long t); // get value from a 2-D array
double Get1DValue(long i,unsigned long a,long t); // get value from a 1-D array
double GetValue(unsigned long a,long t); // get value from pointer

void SetValue(unsigned long a,long t,char v);        // set value at a pointer
void SetValue(unsigned long a,long t,unsigned char v);
void SetValue(unsigned long a,long t,short v);
void SetValue(unsigned long a,long t,unsigned short v);
void SetValue(unsigned long a,long t,long v);
void SetValue(unsigned long a,long t,unsigned long v);
void SetValue(unsigned long a,long t,float v);
void SetValue(unsigned long a,long t,double v);
void SetCplxValue(unsigned long a,long t,double v);
void NumberToString(char *s,unsigned long a,long t); // convert number into a character string


#endif
