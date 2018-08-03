// Graphic X11 port for Lal
// by S. Morel 2008-2018

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "lal.h"

// *********************************************************************
// X11-specific Lal methods

// --- Lal class ---


// Init Lal bitmap

long Lal::InitLalBitmap(void)
{
  // create pixmap of the lal
		
  wins.im=(char *)malloc(4*_wLal*_hLal*sizeof(char));
  if (wins.im==NULL)
  {
    fprintf(stderr,"Out of memory\n");
    exit(-1);
  }  	
  wins.xim=XCreateImage(port.display,port.visu,port.depth,ZPixmap,0,wins.im,_wLal,_hLal,32,0);
}


// draw a point (for items)

void Lal::Dot(long color,long x,long y)
{
  XPutPixel(wins.xim,x,y,_xlut[color]);
}


// draw a caret in a text box while edited

void Lal::DrawCaret(long xo,long yo,long x,long y,long r)
{
  long i;
  
  for (i=0;i<(H_TEXT-2);i++)
  {
    Dot(Lblack,xo+x+r*W_TEXT-1,yo+y-H_TEXT+4+i); // draw caret
  }
  UpdateBitmap();
}


// set a pixel value in a map item

void Lal::SetPixel(long x0,long y0,long x,long y,long z,long value, long lut)
{
  long i,j;
  long a;
  
  if (lut==GREY) a=64*value/255+24;
  else a=150*value/255+88;
  
  if (z<=1)
  {
    XPutPixel(wins.xim,x+x0,y+y0,_xlut[a]);
  }
  else
  {
    for (i=0;i<z;i++)
    {
      for (j=0;j<z;j++)
      {
        XPutPixel(wins.xim,x0+x*z+i,y0+y*z+j,_xlut[a]);
      }
    }
  }
}


// Update Lal bitmap

void Lal::UpdateBitmap(void)
{
  XPutImage(port.display,wins.win,port.gc,wins.xim,0,0,0,0,_wLal,_hLal);
}


// First lal display with window creation

void Lal::Show(void)
{
  char t[20];
  Colormap colmap;
  XColor colorx;
  XSizeHints sizeHints;
  long i;
   
  // create the window of the lal
    
  wins.win=XCreateSimpleWindow(port.display,RootWindow(port.display,port.screen),_xPos,_yPos,_wLal,_hLal,4,BlackPixel(port.display,port.screen),WhitePixel(port.display,port.screen));
  sizeHints.flags=PPosition|PSize;
  sizeHints.x=_xPos;
  sizeHints.y=_yPos;
  sizeHints.width=_wLal;
  sizeHints.height=_hLal;
  XSetStandardProperties(port.display,wins.win,_title,_title,0,port.argv,port.argc,&sizeHints);
  XSelectInput(port.display,wins.win,ExposureMask|KeyPressMask|ButtonPressMask|StructureNotifyMask);
  	
  // create the LUT of the lal
	
  colmap=XCreateColormap(port.display,wins.win,port.visu,AllocNone); 
  XSetWindowColormap(port.display,wins.win,colmap);
  XInstallColormap(port.display,colmap);
  XMapWindow(port.display,wins.win);

  /* Initalize the pseudo-LUT for all the lals
     = a table giving the colorcell in the unique
       TrueColor colormap from the LAL color code
     Note: original RGB coding for LAL s 3*8 bits
     for X11 is 3*16bits   */

   // colors for the items
  for (i=0;i<24;i++)
  {
    colorx.red=lut[i].r*256;
    colorx.green=lut[i].g*256;
    colorx.blue=lut[i].b*256;
    XAllocColor(port.display,colmap,&colorx);
    _xlut[i]=colorx.pixel;
  }
  // colors for the grey maps (64 levels)
  for (i=24;i<88;i++)
  {
    colorx.red=(i-24)*1024;
    colorx.green=(i-24)*1024;
    colorx.blue=(i-24)*1024;
    XAllocColor(port.display,colmap,&colorx);
    _xlut[i]=colorx.pixel;
  }
  // colors for the rainbow maps (150 tones)
  for (i=88;i<238;i++)
  {
    if (i<118)
    {
      colorx.red=(i-88)*2048;
      colorx.green=0;
      colorx.blue=0;
      XAllocColor(port.display,colmap,&colorx);
      _xlut[i]=colorx.pixel;
    }
    if ((i>=118) && (i<148))
    {
      colorx.red=240*256;
      colorx.green=(i-118)*2048;
      colorx.blue=0;
      XAllocColor(port.display,colmap,&colorx);
      _xlut[i]=colorx.pixel;
    }
    if ((i>=148) && (i<178))
    {
      colorx.red=240*256-(i-148)*2048;
      colorx.green=240*256;
      colorx.blue=0;
      XAllocColor(port.display,colmap,&colorx);
      _xlut[i]=colorx.pixel;
    }
    if ((i>=178) && (i<208))
    {
      colorx.red=0;
      colorx.green=240*256;
      colorx.blue=(i-178)*2048;
      XAllocColor(port.display,colmap,&colorx);
      _xlut[i]=colorx.pixel;
    }
    if (i>=208)
    {
      colorx.red=0;
      colorx.green=240*256-(i-208)*2048;
      colorx.blue=240*256;
      XAllocColor(port.display,colmap,&colorx);
      _xlut[i]=colorx.pixel;
    }
  }

  // black and white 
 
  colorx.red=0;
  colorx.green=0;
  colorx.blue=0;
  XAllocColor(port.display,colmap,&colorx);
  _xlut[254]=colorx.pixel;

  colorx.red=65535;
  colorx.green=65535;
  colorx.blue=65535;
  XAllocColor(port.display,colmap,&colorx);
  _xlut[255]=colorx.pixel;

  Draw();
  Update();
  XPutImage(port.display,wins.win,port.gc,wins.xim,0,0,0,0,_wLal,_hLal);
}


// Get the pressed key (-1 if no)

long Lal::GetTheKey(void)
{
  long kk;
  KeySym theKey;
  
  kk=-1;
  XNextEvent(port.display,&(port.report));
  
  if (port.report.type==KeyPress)
  {
    XLookupString(&(port.report.xkey),_kBuf,2,&theKey,NULL);
    kk=(long)theKey;
  }
  return(kk);
}


// Get the ASCII character corresponding to a pressed key

char Lal::GetTheChar(void)
{
  return(_kBuf[0]);
}

  
// hide lal

void Lal::Hide(void)
{
  XUnmapWindow(port.display,wins.win);
  _hidden=TRUE;
}


// free memory used by the port

void Lal::FreePortMem(void)
{
  free(wins.im);
}


// --- LalEnv class ---

void LalEnv::InitPort(int argc,char **argv)
{
  long i;
  XVisualInfo vTemplate;
  XVisualInfo *visualList;
  int visualsMatched;

  _port.display=XOpenDisplay(NULL);
  if (_port.display==NULL)
  {
    fprintf(stderr,"Cannot connect to X-server\n");
    exit(-1);
  }
  _port.screen=DefaultScreen(_port.display);
  _port.visu = XDefaultVisual(_port.display,_port.screen);
  _port.gc=XCreateGC(_port.display,RootWindow(_port.display,_port.screen),0,NULL); 
  _port.depth=DisplayPlanes(_port.display,_port.screen);

  _port.argc=argc;
  _port.argv=argv;
}


// Copy graphic port info from environment to a lal

void LalEnv::CopyGraphPort(Lal *theLal)
{
  theLal->port.display=_port.display;
  theLal->port.visu=_port.visu;
  theLal->port.screen=_port.screen;
  theLal->port.gc=_port.gc;
  theLal->port.depth=_port.depth;
  theLal->port.argc=_port.argc;
  theLal->port.argv=_port.argv;
}


// Lal environment management (X11 only)

void LalEnv::WatchLal(void)
{
  Lal *theLal;
  
  Point p;
  long i;
  Window theWindow;
	
  XNextEvent(_port.display,&(_port.report));
  _active=FALSE;
 
  if (_port.report.type==Expose)
  {
     //UpdateBitmap();
  }
  if (_port.report.type==ButtonPress) 
  {
    theWindow=_port.report.xbutton.window;
    _active=FALSE;
    for (i=0;i<_count;i++)
    {
      if (theWindow==(_lalsArray[i])->wins.win)
      {
         theLal=_lalsArray[i];
         _active=TRUE;
         _lalActive=theLal;
	 theLal->EditItem(_port.report.xbutton.x,_port.report.xbutton.y);
      }
    }
  }
}


// *********************************************************************
// X11 specific functions


// Wait a bit (t ticks, 1 tick=1/60 s)  

void WaitABit(long t)
{
  long d,i,j;

  d=clock();
  i=0;
  while (i==0)
  {
    j=clock();
    // the "tick" we use is 1/60 s (it comes from MacOS)
    // we have to convert it into ticks for this Unix/Linux system
    if (((float)(j-d)*60/CLOCKS_PER_SEC)>=t) i=1;
  }
}

    
