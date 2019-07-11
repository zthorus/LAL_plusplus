#include "lal.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char **argv)
{
  LalEnv *testLalEnv;
  Lal *testLal;
  Lal *testLal2;
  long x=0;
  long y=0;
  float v=123.45;
  double **a;
  float *b;
  long i,j;
  long running;
  char s[40];
  char dum[80];
  char tvChans[40];
  Point pt;

  pt.h=0;
  pt.v=0;
  strcpy(tvChans,"BBC|CBS|NBC|NHK");

  a=(double **)malloc(100*sizeof(double *));
  b=(float *)malloc(100*sizeof(float));
  for (i=0;i<100;i++)
  {
    b[i]=cos(2*(float)i*PI/10);
    a[i]=(double *)malloc(100*sizeof(double));
    for (j=0;j<100;j++)
    {
      a[i][j]=b[i]*sin(2*(float)j*PI/50);
    }
  }
  strcpy(s,"bubu");

  testLalEnv=new LalEnv(argc,argv);

  testLal=new Lal("Test",50,50);
  testLalEnv->AttachLal(testLal);

  testLal->SetLut(COLOR);
  testLal->NewSelector("TV Channel",Lgreen,CLICK,tvChans,&x);
  testLal->NextColumn();
  testLal->NewInputKbrd("Enter X",Lred,8,s);
  testLal->NextBlock();
  testLal->NewPlusMinus("Threshold",Lblue,8,0,1000,2,ARI,&v);
  testLal->NewBarGraph("Fuel",Lpink,10.,250.,&v);
  testLal->NewSelector("Fruits",Lpurple,MANY,"Apple|Banana|Grape|Orange|Peach|Pear",&y);
  testLal->NewInputKbrd("Fruits",Lpurple,4,&y);
  testLal->NextColumn();
  testLal->NewGraph("Curve",Lamber,0,100,60,2,b,NULL,NULL);
  testLal->NewMap("Map",Lbrown,0,0,100,100,2,a,&pt);
  testLal->NewMultiGraph("Multi-curve",Lpurple,0,100,50,2,1,3,a,NULL,NULL);
  
  testLal->Prepare();
  testLal->Show();

  testLal2=new Lal("Test2",300,50);
  testLalEnv->AttachLal(testLal2);

  testLal2->SetLut(COLOR);
  testLal2->NewSelector("TV Channel",Lpink,ONE,tvChans,&x);
  testLal2->NewMap("Map",Lbrown,0,0,100,100,2,a,&pt);
  testLal2->Prepare();
  testLal2->Show();

  running=1;
  while(running)
  {
    testLalEnv->WatchLal();
    printf("Clicked point on map: x = %d ; y = %d\n",pt.h,pt.v);
    if (x==3)
    {
      running=0;
    }
    testLal2->Update();
  }
  
  delete testLal;
  delete testLal2;
  delete testLalEnv;
  exit(0);
}

 
