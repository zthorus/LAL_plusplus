// LAL++ (Live-A-Log++), v.1.2
// by S. Morel 1998, 2001, 2002, 2004, 2008, 2018

// Warning: terms of the GNU General Public License apply to this source.
// You should have received a copy of the GNU General Public License.
// If not, get it from www.gnu.org


   
#include <string.h>
#include <stdlib.h>
#include <stdio.h> /**/
#include <math.h>

#include "lal.h"


// ---------------------------- LalEnv class ------------------------------

//constructor 

LalEnv::LalEnv(int argc,char **argv)
{
  char a[32][72];
  char c,e;
  long i,j,k,n;
  long r;       // result code
 
  // font table
 
  strcpy(a[0],"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@D@@@@@@@@@@@@@@@@@@@@@@@@@@@@DJJNO");
  strcpy(a[1],"LDBDD@@@@ANBNNB_N_NN@@@@@N@DJ_UURDDBUD@@@AQFQQFPPAQQ@@B@HQ@D@JTVT@HAND");
  strcpy(a[2],"@@@BQBAAJ^^AQQDDD_DA@D@_NJH@HAU_@_@BQBBFRAQBNQ@@H@BB@D@JEMU@HADD@@@DQB");
  strcpy(a[3],"DA_AQDQO@@D_DD@@@@UUR@DB@D@@@DQBHQBQQDQA@@B@H@@D@@NRM@BD@@D@DHNB_NBNND");
  strcpy(a[4],"NNDD@@@D@@@@D@@@@@@@D@@H@@@@@@@@@@@D@@@@@@@@@@@@@@@@H@@@@@@@@@@@@@@H@@");
  strcpy(a[5],"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@NN^N");
  strcpy(a[6],"^__NQDAQPQQN^N^N_QQQQQ_FHFD@QQQQQPPQQDARP[YQQQQQDQQQJQADHBJ@]QQPQPPPQD");
  strcpy(a[7],"ATPUUQQQQPDQQQDQBDDB@@U_^PQ^^S_DAXPQSQ^Q^NDQQQDJDDDB@@^QQPQPPQQDQTPQQQ");
  strcpy(a[8],"PQQADQQUDDHDBB@@PQQQQPPQQDQRPQQQPQQQDQJ[JDPDBB@@NQ^N^_PNQDNQ_QQNPNQNDN");
  strcpy(a[9],"DQQD_FAF@_@@@@@@@@@@@@@@@@@A@@@@@@@@@@A@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
  strcpy(a[10],"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ADH@@D@");
  strcpy(a[11],"P@A@C@PDDPD@@@@@@@D@@@@@@BDDM@B@P@A@D@P@@PD@@@@@@@D@@@@@@BDDV@@O^NONNO");
  strcpy(a[12],"^DDRD^VN^OVONQQUQQ_BDD@@@QQQQQDQQDDTDUYQQQYPDQQUJQBDDB@@@QQPQ_DQQDD!DU");
  strcpy(a[13],"QQQQPNDQQUDQDBDD@@@SQPQPDQQDDRDUQQQQPADSJUJQHBDD@@@M^OOODOQDDQDUQN^OP^");
  strcpy(a[14],"CMDJQO_BDD@@@@@@@@@A@@D@@@@@PA@@@@@@@A@ADH@@@@@@@@@N@@X@@@@@PA@@@@@@@N");
  strcpy(a[15],"@@@@@@JD@BMJJ@@@@@@@@@@@@@@@@@@@@@@@@@@J@DV@@BDD@MF@BHD@BHD@MBHD@MBHD@");
  strcpy(a[16],"NNN_QNQDBJJVI@DDJJDDJJVDDJJVDDJJQQQPYQQ@@@@@F@@@@@@@@@@@@@@@@@@@QQPPUQ");
  strcpy(a[17],"QOOOOOONNNNNDDDDVNNNNNQQQQ__P^SQQQQQQQQQQQQQDDDDYQQQQQQQQQQQPPQQQQQQQQ");
  strcpy(a[18],"QP____DDDDQQQQQQQQQQQQQPQQQSSSSSSPPPPPDDDDQQQQQQSSSSQQN_QNNMMMMMMOOOOO");
  strcpy(a[19],"DDDDQNNNNNMMMM@@@@@@@@@@@@@D@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@H@@@@@@@@@@");
  strcpy(a[20],"@@@@@@@@@@@@N@@@@@@@@@@@@@@@@@@@@@C@@@@@@F@LQ@OF@@@@@@@@@@@@@@@@@@D@@@");
  strcpy(a[21],"@@DI@RI@UI!!^bJ@ON@@BDQ@D__@DGFN@@NIDPTNUQBBKd@BTQ@DDBJ@BIJ@DIIQ@@DFN!");
  strcpy(a[22],"R_URYMK`@_TS[DHA_RCDJ_DIIQNND@UPI_ORUQ@@@D^UU_DBDREBJJDGFQUSD@TPE_EQYM");
  strcpy(a[23],"@@@_TY[DBD_RIDJJD@@QWU@@UQRNEQVB@@@HTQ@D@@DRIIJJDOOJTY@@N^Q@EV@!@@@@WN");
  strcpy(a[24],"@_NGD]F_JJD@@[ON@@D@N@@P@@@@@@@@@@@@@P@@@@D@@@@@@@@@@@@@@@@@@@@@@@@@@P");
  strcpy(a[25],"@@@@X@@@@@@@@@C@@@@@@HMM@@@@@@@@@@@@@@@@@@@@@@D@@@@@@DVV@@@@@@@@@@@@@@");
  strcpy(a[26],"@@@@DB@@D@@@@@@NNNO@@@EEBF@@J@OOOOOO@@@CDAD@@@@QQQT@@@JEDBDD@_iIIIIIDB");
  strcpy(a[27],"@BNND@@@@QQQTJ@@JJFD@JQ@IIIIIIHB_DDQJIR@@__QVUN_`@@@_QQ_iIIIIIPBATDNJR");
  strcpy(a[28],"I@@QQQTW@@@@@@@JQ@IIIIIIQBAHDPQRI@@QQQTT@@@@@@DDQ_iIIIIINB@HD@_IRU@QQN");
  strcpy(a[29],"OK@@@@@@@@O@OOOOOO@@@@D@@@@@@@@@@@@@@@@@@@A@@@@@@@@@@@X@@@@@@@@@@@@@@@");
  strcpy(a[30],"@@@@N@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
  strcpy(a[31],"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
  
  r=1;
  _fontTable=(char *)malloc(14000*sizeof(char));
  if (_fontTable==NULL) r=0;
  _lalsArray=(Lal **)malloc(32*sizeof(Lal *));
  
  k=0;
  for (i=0;i<32;i++)
  {
    for (j=0;j<70;j++)
    {
      e=32;
      if (a[i][j]=='!') c=28;
      else c=a[i][j]-'@';
      for (n=0;n<6;n++)
      {
        if ((e&c)!=0) _fontTable[k]=255;
        else _fontTable[k]=0; 
        k++;
        e>>=1;
      }
    }
  }
  _count=0;
  _lut[0].r=234;  _lut[0].g=0;    _lut[0].b=0;    // red
  _lut[1].r=156;  _lut[1].g=0;    _lut[1].b=0;
  _lut[2].r=255;  _lut[2].g=98;   _lut[2].b=98;
  _lut[3].r=0;    _lut[3].g=180;  _lut[3].b=0;    // green
  _lut[4].r=0;    _lut[4].g=140;  _lut[4].b=0;
  _lut[5].r=0;    _lut[5].g=220;  _lut[5].b=0;
  _lut[6].r=0;    _lut[6].g=100;  _lut[6].b=250;  // blue
  _lut[7].r=0;    _lut[7].g=0;    _lut[7].b=100;
  _lut[8].r=0;    _lut[8].g=200;  _lut[8].b=255;
  _lut[9].r=150;  _lut[9].g=50;   _lut[9].b=10;   // brown
  _lut[10].r=75;  _lut[10].g=25;  _lut[10].b=5;
  _lut[11].r=225; _lut[11].g=75;  _lut[11].b=15;
  _lut[12].r=156; _lut[12].g=156; _lut[12].b=156; // grey
  _lut[13].r=117; _lut[13].g=117; _lut[13].b=117;
  _lut[14].r=195; _lut[14].g=195; _lut[14].b=195;
  _lut[15].r=255; _lut[15].g=98;  _lut[15].b=0;   // amber
  _lut[16].r=195; _lut[16].g=78;  _lut[16].b=0;
  _lut[17].r=255; _lut[17].g=137; _lut[17].b=0;
  _lut[18].r=234; _lut[18].g=0;   _lut[18].b=156; // pink
  _lut[19].r=156; _lut[19].g=0;   _lut[19].b=104;
  _lut[20].r=255; _lut[20].g=78;  _lut[20].b=176;
  _lut[21].r=110; _lut[21].g=0;   _lut[21].b=165; // purple
  _lut[22].r=66;  _lut[22].g=0;   _lut[22].b=100;
  _lut[23].r=150; _lut[23].g=0;   _lut[23].b=225;
  
  InitPort(argc,argv); // init the graphic port
}    


// "attach" a lal to an environment

void LalEnv::AttachLal(Lal *theLal)
{
  int i;
   
  theLal->fontTable=_fontTable;
  for (i=0;i<24;i++)
  { 
    theLal->lut[i].r=_lut[i].r;
    theLal->lut[i].g=_lut[i].g;
    theLal->lut[i].b=_lut[i].b;
  }
   
  _lalsArray[_count]=theLal;
  _count++;

  CopyGraphPort(theLal);
}


// ----------------------------- Lal class --------------------------------

// constructor

Lal::Lal(const char *theTitle,long xLal,long yLal)
{
  long l;
 
  l=strlen(theTitle);
  _title=(char *)malloc((l+1)*sizeof(char));
  strcpy(_title,theTitle);
  _xPos=xLal;
  _yPos=yLal;
  _nbItems=0;
  _curBlock=0;
  _curCol=0;
  _blkCard[0]=1;     // there is necessary a column in the block
  _colCard[0][0]=0;  // but the column may be empty
  _count=0;
  _mapLut=GREY;
}


// destructor

Lal::~Lal(void)
{
  long i,j;
  
  FreePortMem();
  
  for (i=0;i<_nbItems;i++)
  {
    free(_itemsArray[i].title);
    if (_itemsArray[i].nbButt>0)
    {
      for (j=0;j<_itemsArray[i].nbButt;j++) free(_itemsArray[i].name[j]);
      free(_itemsArray[i].name);
    }
  }
}

// create button array

long Lal::NewSelector(const char *theTitle,long theColor,long theType,const char *theNames,long *theArg)
{
  long l,lm;
  long r=1;
  long i,k,m;
  long c;
  long theSize;
 
  c=_nbItems;
 
  if (theTitle!=NULL)
  {
    l=strlen(theTitle);
    _itemsArray[c].title=(char *)malloc((l+1)*sizeof(char));
    if (_itemsArray[c].title==NULL) r=-1;
    else strcpy(_itemsArray[c].title,theTitle);
  }
  else _itemsArray[c].title=NULL;

  _itemsArray[c].color=theColor;
  switch (theType & 0xC0)
  {
    case 0x00: _itemsArray[c].type=tSelectorOne; break;
    case 0x40: _itemsArray[c].type=tSelectorMany; break;
    case 0x80: _itemsArray[c].type=tSelectorClick; break;
  }
  _itemsArray[c].argPtr=(unsigned long)theArg;
  _itemsArray[c].argType=Llong;
 
  theSize=1;
  l=0;
  lm=0;
  for (k=0;k<strlen(theNames);k++) // find number of buttons and size
  {
    if (theNames[k]=='|')
    {
      theSize++; 
      if (l>lm) lm=l;
      l=0;
    }
    else l++;
  }   
  _itemsArray[c].nbButt=theSize;
  _itemsArray[c].bSize=lm;
  
  if (_itemsArray[c].type==tSelectorClick) _itemsArray[c].pushed=0;           
  
  _itemsArray[c].name=(char **)malloc(theSize*sizeof(char *)); 
  if ((_itemsArray[c].name!=NULL) && (theSize>0))
  {
    for (k=0;k<theSize;k++)
    {
      _itemsArray[c].name[k]=(char *)malloc((lm+1)*sizeof(char));
      if (_itemsArray[c].name[k]==NULL) r=-1;
    }  
   
    if (r!=-1)
    {
      k=m=0;
      l=strlen(theNames);
      for (i=0;i<l;i++)    // extract buttons names
      {
        if (theNames[i]!='|') 
        {
          _itemsArray[c].name[k][m]=theNames[i];
          m++;
        }
        else
        {
          _itemsArray[c].name[k][m]='\0';
          k++;
          m=0;
        }
      }
      _itemsArray[c].name[k][m]='\0';
      if ((_itemsArray[c].type==tSelectorMany) && (theSize<2)) r=-1; 
     
      if ((theType & 0x3F)>theSize) _itemsArray[c].buttRow=theSize;
      else _itemsArray[c].buttRow=theType&0x3F;
    }
  }

  if (r!=-1)
  { 
    _itemsTable[_curBlock][_curCol][_count]=_nbItems;
    _colCard[_curBlock][_curCol]++;
    _nbItems++;
    _count++;
  }
  else c=r;
  
  return(c);
}


// create new item that is non-graphical (except button arrays)

long Lal::NewNonGraph(const char *theTitle,long theColor,long theType,const char *theNames,unsigned long theArg,long theArgType)
{
  long l;
  long r=1;
  long i,k,m;
  long c;
  char ch[8][10];
 
  c=_nbItems;
 
  if (theTitle!=NULL)
  {
    l=strlen(theTitle);
    _itemsArray[c].title=(char *)malloc((l+1)*sizeof(char));
    if (_itemsArray[c].title==NULL) r=-1;
    else strcpy(_itemsArray[c].title,theTitle);
  }
  else _itemsArray[c].title=NULL;

  _itemsArray[c].color=theColor;
  _itemsArray[c].type=theType;
  _itemsArray[c].argPtr=theArg;
  _itemsArray[c].argType=theArgType;
 
  _itemsArray[c].nbButt=0;
  if (_itemsArray[c].title!=NULL) _itemsArray[c].bSize=strlen(_itemsArray[c].title);
  else _itemsArray[c].bSize=1;
   
  k=m=0;
  l=strlen(theNames);
  for (i=0;i<l;i++)
  {
    if (theNames[i]!='|') 
    {
      ch[k][m]=theNames[i];
      m++;
    }
    else
    {
      ch[k][m]='\0';
      k++;
      m=0;
    }
  }
  ch[k][m]='\0';
 
  if ((theType==tInputKbrd) || (theType==tDisplayOnly))
  {
    _itemsArray[c].type=tInputKbrd;
    _itemsArray[c].nbChar=atoi(ch[0]);
    if (theType==tInputKbrd) _itemsArray[c].locked=NOT_LOCKED;
    else _itemsArray[c].locked=LOCKED;
    _itemsArray[c].inEdit=0;
  }
  if (theType==tPlusMinus)
  {
    _itemsArray[c].nbChar=atoi(ch[0]);
    _itemsArray[c].vMin=atof(ch[1]);
    _itemsArray[c].vMax=atof(ch[2]);
    _itemsArray[c].step=atof(ch[3]);
    if (ch[4][0]=='A') _itemsArray[c].progrs=ARI;
    else _itemsArray[c].progrs=GEO;
    _itemsArray[c].inEdit=0;
  }
  if (theType==tBarGraph)
  {
    _itemsArray[c].vMin=atof(ch[0]);
    _itemsArray[c].vMax=atof(ch[1]);
  }      
 
  _itemsTable[_curBlock][_curCol][_count]=_nbItems;
  _colCard[_curBlock][_curCol]++;
  _nbItems++;
  _count++;

  return(c);
}


// create new InputKbrd

long Lal::NewInputKbrd(const char *theTitle,long theColor,long theSize,long *theArg)
{
  char s[80];
  sprintf(s,"%d",theSize);
  return(NewNonGraph(theTitle,theColor,tInputKbrd,s,(unsigned long)theArg,Llong));
}

long Lal::NewInputKbrd(const char *theTitle,long theColor,long theSize,unsigned long *theArg)
{
  char s[80];
  sprintf(s,"%d",theSize);
  return(NewNonGraph(theTitle,theColor,tInputKbrd,s,(unsigned long)theArg,Lulong));
}

long Lal::NewInputKbrd(const char *theTitle,long theColor,long theSize,short *theArg)
{
  char s[80];
  sprintf(s,"%d",theSize);
  return(NewNonGraph(theTitle,theColor,tInputKbrd,s,(unsigned long)theArg,Lshort));
}

long Lal::NewInputKbrd(const char *theTitle,long theColor,long theSize,unsigned short *theArg)
{
  char s[80];
  sprintf(s,"%d",theSize);
  return(NewNonGraph(theTitle,theColor,tInputKbrd,s,(unsigned long)theArg,Lushort));
}

long Lal::NewInputKbrd(const char *theTitle,long theColor,long theSize,char *theArg)
{
  char s[80];
  sprintf(s,"%d",theSize);
  return(NewNonGraph(theTitle,theColor,tInputKbrd,s,(unsigned long)theArg,Lstring));
}

long Lal::NewInputKbrd(const char *theTitle,long theColor,long theSize,unsigned char *theArg)
{
  char s[80];
  sprintf(s,"%d",theSize);
  return(NewNonGraph(theTitle,theColor,tInputKbrd,s,(unsigned long)theArg,Luchar));
}

long Lal::NewInputKbrd(const char *theTitle,long theColor,long theSize,float *theArg)
{
  char s[80];
  sprintf(s,"%d",theSize);
  return(NewNonGraph(theTitle,theColor,tInputKbrd,s,(unsigned long)theArg,Lfloat));
}

long Lal::NewInputKbrd(const char *theTitle,long theColor,long theSize,double *theArg)
{
  char s[80];
  sprintf(s,"%d",theSize);
  return(NewNonGraph(theTitle,theColor,tInputKbrd,s,(unsigned long)theArg,Ldouble));
}

long Lal::NewInputKbrd(const char *theTitle,long theColor,long theSize,complex *theArg,long theCmpEl)
{
  char s[80];
  sprintf(s,"%d",theSize);
  return(NewNonGraph(theTitle,theColor,tInputKbrd,s,(unsigned long)theArg,theCmpEl));
}


// create new DisplayOnly

long Lal::NewDisplayOnly(const char *theTitle,long theColor,long theSize,long *theArg)
{
  char s[80];
  sprintf(s,"%d",theSize);
  return(NewNonGraph(theTitle,theColor,tDisplayOnly,s,(unsigned long)theArg,Llong));
}

long Lal::NewDisplayOnly(const char *theTitle,long theColor,long theSize,unsigned long *theArg)
{
  char s[80];
  sprintf(s,"%d",theSize);
  return(NewNonGraph(theTitle,theColor,tDisplayOnly,s,(unsigned long)theArg,Lulong));
}

long Lal::NewDisplayOnly(const char *theTitle,long theColor,long theSize,short *theArg)
{
  char s[80];
  sprintf(s,"%d",theSize);
  return(NewNonGraph(theTitle,theColor,tDisplayOnly,s,(unsigned long)theArg,Lshort));
}

long Lal::NewDisplayOnly(const char *theTitle,long theColor,long theSize,unsigned short *theArg)
{
  char s[80];
  sprintf(s,"%d",theSize);
  return(NewNonGraph(theTitle,theColor,tDisplayOnly,s,(unsigned long)theArg,Lushort));
}

long Lal::NewDisplayOnly(const char *theTitle,long theColor,long theSize,char *theArg)
{
  char s[80];
  sprintf(s,"%d",theSize);
  return(NewNonGraph(theTitle,theColor,tDisplayOnly,s,(unsigned long)theArg,Lstring));
}

long Lal::NewDisplayOnly(const char *theTitle,long theColor,long theSize,unsigned char *theArg)
{
  char s[80];
  sprintf(s,"%d",theSize);
  return(NewNonGraph(theTitle,theColor,tDisplayOnly,s,(unsigned long)theArg,Luchar));
}

long Lal::NewDisplayOnly(const char *theTitle,long theColor,long theSize,float *theArg)
{
  char s[80];
  sprintf(s,"%d",theSize);
  return(NewNonGraph(theTitle,theColor,tDisplayOnly,s,(unsigned long)theArg,Lfloat));
}

long Lal::NewDisplayOnly(const char *theTitle,long theColor,long theSize,double *theArg)
{
  char s[80];
  sprintf(s,"%d",theSize);
  return(NewNonGraph(theTitle,theColor,tDisplayOnly,s,(unsigned long)theArg,Ldouble));
}

long Lal::NewDisplayOnly(const char *theTitle,long theColor,long theSize,complex *theArg,long theCmpEl)
{
  char s[80];
  sprintf(s,"%d",theSize);
  return(NewNonGraph(theTitle,theColor,tDisplayOnly,s,(unsigned long)theArg,theCmpEl));
}


// create a PlusMinus
  
long Lal::NewPlusMinus(const char *theTitle,long theColor,long theSize,double min,double max,double step,long progrs,long *theArg)
{
  char s[80];
  sprintf(s,"%d|%f|%f|%f|",theSize,min,max,step);
  if (progrs==ARI) strcat(s,"A"); else strcat(s,"G");
  return(NewNonGraph(theTitle,theColor,tPlusMinus,s,(unsigned long)theArg,Llong));
}

long Lal::NewPlusMinus(const char *theTitle,long theColor,long theSize,double min,double max,double step,long progrs,unsigned long *theArg)
{
  char s[80];
  sprintf(s,"%d|%f|%f|%f|",theSize,min,max,step);
  if (progrs==ARI) strcat(s,"A"); else strcat(s,"G");
  return(NewNonGraph(theTitle,theColor,tPlusMinus,s,(unsigned long)theArg,Lulong));
}

long Lal::NewPlusMinus(const char *theTitle,long theColor,long theSize,double min,double max,double step,long progrs,short *theArg)
{
  char s[80];
  sprintf(s,"%d|%f|%f|%f|",theSize,min,max,step);
  if (progrs==ARI) strcat(s,"A"); else strcat(s,"G");
  return(NewNonGraph(theTitle,theColor,tPlusMinus,s,(unsigned long)theArg,Lshort));
}

long Lal::NewPlusMinus(const char *theTitle,long theColor,long theSize,double min,double max,double step,long progrs,unsigned short *theArg)
{
  char s[80];
  sprintf(s,"%d|%f|%f|%f|",theSize,min,max,step);
  if (progrs==ARI) strcat(s,"A"); else strcat(s,"G");
  return(NewNonGraph(theTitle,theColor,tPlusMinus,s,(unsigned long)theArg,Lushort));
}

long Lal::NewPlusMinus(const char *theTitle,long theColor,long theSize,double min,double max,double step,long progrs,float *theArg)
{
  char s[80];
  sprintf(s,"%d|%f|%f|%f|",theSize,min,max,step);
  if (progrs==ARI) strcat(s,"A"); else strcat(s,"G");
  return(NewNonGraph(theTitle,theColor,tPlusMinus,s,(unsigned long)theArg,Lfloat));
}

long Lal::NewPlusMinus(const char *theTitle,long theColor,long theSize,double min,double max,double step,long progrs,double *theArg)
{
  char s[80];
  sprintf(s,"%d|%f|%f|%f|",theSize,min,max,step);
  if (progrs==ARI) strcat(s,"A"); else strcat(s,"G");
  return(NewNonGraph(theTitle,theColor,tPlusMinus,s,(unsigned long)theArg,Ldouble));
}

long Lal::NewPlusMinus(const char *theTitle,long theColor,long theSize,double min,double max,double step,long progrs,char *theArg)
{
  char s[80];
  sprintf(s,"%d|%f|%f|%f|",theSize,min,max,step);
  if (progrs==ARI) strcat(s,"A"); else strcat(s,"G");
  return(NewNonGraph(theTitle,theColor,tPlusMinus,s,(unsigned long)theArg,Lchar));
}

long Lal::NewPlusMinus(const char *theTitle,long theColor,long theSize,double min,double max,double step,long progrs,unsigned char *theArg)
{
  char s[80];
  sprintf(s,"%d|%f|%f|%f|",theSize,min,max,step);
  if (progrs==ARI) strcat(s,"A"); else strcat(s,"G");
  return(NewNonGraph(theTitle,theColor,tPlusMinus,s,(unsigned long)theArg,Luchar));
}

long Lal::NewPlusMinus(const char *theTitle,long theColor,long theSize,double min,double max,double step,long progrs,complex *theArg,long theCmpEl)
{
  char s[80];
  sprintf(s,"%d|%f|%f|%f|",theSize,min,max,step);
  if (progrs==ARI) strcat(s,"A"); else strcat(s,"G");
  return(NewNonGraph(theTitle,theColor,tPlusMinus,s,(unsigned long)theArg,theCmpEl));
}


// create a BarGraph

long Lal::NewBarGraph(const char *theTitle,long theColor,double min,double max,long *theArg)
{
  char s[80];
  sprintf(s,"%f|%f",min,max);
  return(NewNonGraph(theTitle,theColor,tBarGraph,s,(unsigned long)theArg,Llong));
}

long Lal::NewBarGraph(const char *theTitle,long theColor,double min,double max,unsigned long *theArg)
{
  char s[80];
  sprintf(s,"%f|%f",min,max);
  return(NewNonGraph(theTitle,theColor,tBarGraph,s,(unsigned long)theArg,Lulong));
}

long Lal::NewBarGraph(const char *theTitle,long theColor,double min,double max,short *theArg)
{
  char s[80];
  sprintf(s,"%f|%f",min,max);
  return(NewNonGraph(theTitle,theColor,tBarGraph,s,(unsigned long)theArg,Lshort));
}

long Lal::NewBarGraph(const char *theTitle,long theColor,double min,double max,unsigned short *theArg)
{
  char s[80];
  sprintf(s,"%f|%f",min,max);
  return(NewNonGraph(theTitle,theColor,tBarGraph,s,(unsigned long)theArg,Lushort));
}

long Lal::NewBarGraph(const char *theTitle,long theColor,double min,double max,float *theArg)
{
  char s[80];
  sprintf(s,"%f|%f",min,max);
  return(NewNonGraph(theTitle,theColor,tBarGraph,s,(unsigned long)theArg,Lfloat));
}

long Lal::NewBarGraph(const char *theTitle,long theColor,double min,double max,double *theArg)
{
  char s[80];
  sprintf(s,"%f|%f",min,max);
  return(NewNonGraph(theTitle,theColor,tBarGraph,s,(unsigned long)theArg,Ldouble));
}

long Lal::NewBarGraph(const char *theTitle,long theColor,double min,double max,char *theArg)
{
  char s[80];
  sprintf(s,"%f|%f",min,max);
  return(NewNonGraph(theTitle,theColor,tBarGraph,s,(unsigned long)theArg,Lchar));
}

long Lal::NewBarGraph(const char *theTitle,long theColor,double min,double max,unsigned char *theArg)
{
  char s[80];
  sprintf(s,"%f|%f",min,max);
  return(NewNonGraph(theTitle,theColor,tBarGraph,s,(unsigned long)theArg,Luchar));
}

long Lal::NewBarGraph(const char *theTitle,long theColor,double min,double max,complex *theArg,long theCmpEl)
{
  char s[80];
  sprintf(s,"%f|%f",min,max);
  return(NewNonGraph(theTitle,theColor,tBarGraph,s,(unsigned long)theArg,theCmpEl));
}


// Create a new item that is a map

long Lal::LNewMap(const char *theTitle,long theColor,long xo,long yo,long xl,long yl,long z,unsigned long theArg,long theArgType,Point *cursLoc)
{
  long c,l,r;
  
  c=_nbItems;
  r=1;
  
  if ((z==0) || (xl<=0) || (yl<=0)) r=-1; 
  _itemsArray[c].type=tMap;
  if (theTitle!=NULL)
  {
    l=strlen(theTitle);
    _itemsArray[c].title=(char *)malloc((l+1)*sizeof(char));
    if (_itemsArray[c].title==NULL) r=-1;
    else strcpy(_itemsArray[c].title,theTitle);
  }
  else _itemsArray[c].title=NULL;
  _itemsArray[c].color=theColor;
  _itemsArray[c].xSize=xl;
  _itemsArray[c].ySize=yl;
  _itemsArray[c].xOrg=xo;
  _itemsArray[c].yOrg=yo;
  _itemsArray[c].zoomF=z;
  _itemsArray[c].argPtr=theArg;
  _itemsArray[c].argType=theArgType;
  _itemsArray[c].iPoint=cursLoc;
  _itemsArray[c].nbButt=0;
  _itemsArray[c].lut=_mapLut;
 
  _itemsTable[_curBlock][_curCol][_count]=_nbItems;
  _colCard[_curBlock][_curCol]++;
  _nbItems++;
  _count++;
 
  return(c);
}

long Lal::NewMap(const char *theTitle,long theColor,long xo,long yo,long xl,long yl,long z,long **theArg,Point *CursLoc)
{
  return(LNewMap(theTitle,theColor,xo,yo,xl,yl,z,(unsigned long)theArg,Llong,CursLoc));
}

long Lal::NewMap(const char *theTitle,long theColor,long xo,long yo,long xl,long yl,long z,unsigned long **theArg,Point *CursLoc)
{
  return(LNewMap(theTitle,theColor,xo,yo,xl,yl,z,(unsigned long)theArg,Lulong,CursLoc));
}

long Lal::NewMap(const char *theTitle,long theColor,long xo,long yo,long xl,long yl,long z,short **theArg,Point *CursLoc)
{
  return(LNewMap(theTitle,theColor,xo,yo,xl,yl,z,(unsigned long)theArg,Lshort,CursLoc));
}

long Lal::NewMap(const char *theTitle,long theColor,long xo,long yo,long xl,long yl,long z,unsigned short **theArg,Point *CursLoc)
{
  return(LNewMap(theTitle,theColor,xo,yo,xl,yl,z,(unsigned long)theArg,Lushort,CursLoc));
}

long Lal::NewMap(const char *theTitle,long theColor,long xo,long yo,long xl,long yl,long z,float **theArg,Point *CursLoc)
{
  return(LNewMap(theTitle,theColor,xo,yo,xl,yl,z,(unsigned long)theArg,Lfloat,CursLoc));
}

long Lal::NewMap(const char *theTitle,long theColor,long xo,long yo,long xl,long yl,long z,double **theArg,Point *CursLoc)
{
  return(LNewMap(theTitle,theColor,xo,yo,xl,yl,z,(unsigned long)theArg,Ldouble,CursLoc));
}

long Lal::NewMap(const char *theTitle,long theColor,long xo,long yo,long xl,long yl,long z,char **theArg,Point *CursLoc)
{
  return(LNewMap(theTitle,theColor,xo,yo,xl,yl,z,(unsigned long)theArg,Lchar,CursLoc));
}

long Lal::NewMap(const char *theTitle,long theColor,long xo,long yo,long xl,long yl,long z,unsigned char **theArg,Point *CursLoc)
{
  return(LNewMap(theTitle,theColor,xo,yo,xl,yl,z,(unsigned long)theArg,Luchar,CursLoc));
}

long Lal::NewMap(const char *theTitle,long theColor,long xo,long yo,long xl,long yl,long z,complex **theArg,long theCmpEl,Point *CursLoc)
{
  return(LNewMap(theTitle,theColor,xo,yo,xl,yl,z,(unsigned long)theArg,theCmpEl,CursLoc));
}


// Create a new item that is a curve

long Lal::LNewCurve(const char *theTitle,long theColor,long xo,long xl,long yl,long z,unsigned long theArg,long theArgType,double *min,double *max)
{
  long c,l,r;
  
  c=_nbItems;
  r=1;
  
  if ((z==0) || (xl<=0) || (yl<=0)) r=-1; 
  _itemsArray[c].type=tCurve;
  if (theTitle!=NULL)
  {
    l=strlen(theTitle);
    _itemsArray[c].title=(char *)malloc((l+1)*sizeof(char));
    if (_itemsArray[c].title==NULL) r=-1;
    else strcpy(_itemsArray[c].title,theTitle);
  }
  else _itemsArray[c].title=NULL;
  _itemsArray[c].color=theColor;
  _itemsArray[c].xSize=xl;
  _itemsArray[c].ySize=yl;
  _itemsArray[c].xOrg=xo;
  _itemsArray[c].zoomF=z;
  _itemsArray[c].argType=theArgType;
  _itemsArray[c].argPtr=theArg;
  _itemsArray[c].minPtr=min;
  _itemsArray[c].maxPtr=max;
  _itemsArray[c].nbButt=0;
  
  _itemsTable[_curBlock][_curCol][_count]=_nbItems;
  _colCard[_curBlock][_curCol]++;
  _nbItems++;
  _count++;
 
  return(c);
}

long Lal::NewGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,long *theArg,double *min,double *max)
{
  return(LNewCurve(theTitle,theColor,xo,xl,yl,z,(unsigned long)theArg,Llong,min,max));
}

long Lal::NewGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,unsigned long *theArg,double *min,double *max)
{
  return(LNewCurve(theTitle,theColor,xo,xl,yl,z,(unsigned long)theArg,Llong,min,max));
}

long Lal::NewGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,short *theArg,double *min,double *max)
{
  return(LNewCurve(theTitle,theColor,xo,xl,yl,z,(unsigned long)theArg,Lshort,min,max));
}

long Lal::NewGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,unsigned short *theArg,double *min,double *max)
{
  return(LNewCurve(theTitle,theColor,xo,xl,yl,z,(unsigned long)theArg,Lshort,min,max));
}

long Lal::NewGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,float *theArg,double *min,double *max)
{
  return(LNewCurve(theTitle,theColor,xo,xl,yl,z,(unsigned long)theArg,Lfloat,min,max));
}

long Lal::NewGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,double *theArg,double *min,double *max)
{
  return(LNewCurve(theTitle,theColor,xo,xl,yl,z,(unsigned long)theArg,Ldouble,min,max));
}

long Lal::NewGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,char *theArg,double *min,double *max)
{
  return(LNewCurve(theTitle,theColor,xo,xl,yl,z,(unsigned long)theArg,Lchar,min,max));
}

long Lal::NewGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,unsigned char *theArg,double *min,double *max)
{
  return(LNewCurve(theTitle,theColor,xo,xl,yl,z,(unsigned long)theArg,Lchar,min,max));
}

long Lal::NewGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,complex *theArg,long theCmpEl,double *min,double *max)
{
  return(LNewCurve(theTitle,theColor,xo,xl,yl,z,(unsigned long)theArg,theCmpEl,min,max));
}


// Create a new item that is a double curve

long Lal::LNewMultiCurve(const char *theTitle,long theColor,long xo,long xl,long yl,long z,long n0,long n1,unsigned long theArg,long theArgType,double *min,double *max)
{
  long c,l,r;
  
  c=_nbItems;
  
  if ((z==0) || (xl<=0) || (yl<=0)) r=-1; 
  _itemsArray[c].type=tMultiCurve;
  if (theTitle!=NULL)
  {
    l=strlen(theTitle);
    _itemsArray[c].title=(char *)malloc((l+1)*sizeof(char));
    if (_itemsArray[c].title==NULL) r=-1;
    else strcpy(_itemsArray[c].title,theTitle);
  }
  else _itemsArray[c].title=NULL;
  _itemsArray[c].color=theColor;
  _itemsArray[c].xSize=xl;
  _itemsArray[c].ySize=yl;
  _itemsArray[c].xOrg=xo;
  _itemsArray[c].zoomF=z;
  _itemsArray[c].argType=theArgType;
  _itemsArray[c].argPtr=theArg;
  _itemsArray[c].minPtr=min;
  _itemsArray[c].maxPtr=max;
  _itemsArray[c].nbButt=0;
  _itemsArray[c].stCurve=n0;
  _itemsArray[c].enCurve=n1;
  
  _itemsTable[_curBlock][_curCol][_count]=_nbItems;
  _colCard[_curBlock][_curCol]++;
  _nbItems++;
  _count++;
 
  return(c);
}

long Lal::NewMultiGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,long n0,long n1,long **theArg,double *min,double *max)
{
  return(LNewMultiCurve(theTitle,theColor,xo,xl,yl,z,n0,n1,(unsigned long)theArg,Llong,min,max));
}

long Lal::NewMultiGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,long n0,long n1,short **theArg,double *min,double *max)
{
  return(LNewMultiCurve(theTitle,theColor,xo,xl,yl,z,n0,n1,(unsigned long)theArg,Lshort,min,max));
}

long Lal::NewMultiGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,long n0,long n1,float **theArg,double *min,double *max)
{
  return(LNewMultiCurve(theTitle,theColor,xo,xl,yl,z,n0,n1,(unsigned long)theArg,Lfloat,min,max));
}

long Lal::NewMultiGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,long n0,long n1,double **theArg,double *min,double *max)
{
  return(LNewMultiCurve(theTitle,theColor,xo,xl,yl,z,n0,n1,(unsigned long)theArg,Ldouble,min,max));
}

long Lal::NewMultiGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,long n0,long n1,char **theArg,double *min,double *max)
{
  return(LNewMultiCurve(theTitle,theColor,xo,xl,yl,z,n0,n1,(unsigned long)theArg,Lchar,min,max));
}

long Lal::NewMultiGraph(const char *theTitle,long theColor,long xo,long xl,long yl,long z,long n0,long n1,complex **theArg,long theCmpEl,double *min,double *max)
{
  return(LNewMultiCurve(theTitle,theColor,xo,xl,yl,z,n0,n1,(unsigned long)theArg,theCmpEl,min,max));
}


        
// disable InputKbrd/PlusMinus input 

long Lal::LockInput(long n)
{
  long r=0;
  
  if ((_itemsArray[n].type==tInputKbrd) || (_itemsArray[n].type==tPlusMinus))
  {
    _itemsArray[n].locked=LOCKED;
    r=1;
  }
  return(r);
}

      
// enable InputKbrd/PlusMinus input 

long Lal::UnlockInput(long n)
{
  long r=0;
  
  if ((_itemsArray[n].type==tInputKbrd) || (_itemsArray[n].type==tPlusMinus))
  {
    _itemsArray[n].locked=NOT_LOCKED;
    r=1;
  }
  return(r);
}


// modify origin and zoom factor of a map

long Lal::ModifyMap(long n,long lut,long xo,long yo,long z)
{
  long r=0;
  
  if (_itemsArray[n].type==tMap)
  {
    _itemsArray[n].xOrg=xo;
    _itemsArray[n].yOrg=yo;
    _itemsArray[n].zoomF=z;
    _itemsArray[n].lut=lut;
    r=1;
  }
  return(r);
}


// modify origin and zoom factor of a graph

long Lal::ModifyGraph(long n,long xo,long z)
{
  long r=0;
  
  if ((_itemsArray[n].type==tCurve) || (_itemsArray[n].type==tMultiCurve))
  {
    _itemsArray[n].xOrg=xo;
    _itemsArray[n].zoomF=z;
    r=1;
  }
  return(r);
}
    

// modify lut, curve index, origin and zoom factor of a multi-graph  

long Lal::ModifyMultiGraph(long n,long n0,long n1,long xo,long z)
{
  long r=0;
  
  if ((_itemsArray[n].type==tCurve) || (_itemsArray[n].type==tMultiCurve))
  {
    _itemsArray[n].xOrg=xo;
    _itemsArray[n].zoomF=z;
    _itemsArray[n].stCurve=n0;
    _itemsArray[n].enCurve=n1;
    r=1;
  }
  return(r);
}

// create a new item block

void Lal::NextBlock(void)
{
  _curBlock++;
  _blkCard[_curBlock]=1;
  _colCard[_curBlock][0]=0;
  _curCol=0;
  _count=0;
}


// create a new item column

void Lal::NextColumn(void)
{
  _blkCard[_curBlock]++;
  _curCol++;
  _colCard[_curBlock][_curCol]=0;
  _count=0;
}
  

// prepare Lal display

long Lal::Prepare(void)
{
  long i,j,k,n,z;
  long x,h;
  long xm,hm,wm;
  long r=1;
  long lw;
  long s,t;
  long curWBlk;
 
  _hLal=0;
  wm=0;
  _nbBlocks=_curBlock+1;
  _yBlk[0]=0;
 
  for (i=0;i<_nbBlocks;i++)
  {
    curWBlk=0;
    hm=0;
   
    for (j=0;j<_blkCard[i];j++)
    {
      h=0;
      xm=0;
      z=0;

      // compute minimum width and y-coordinate for each item
     
      for (k=0;k<_colCard[i][j];k++) 
      {
        n=_itemsTable[i][j][k]; // get item index  
      
        t=_itemsArray[n].type;
      
        _itemsArray[n].yMin=h;
  
        if (t<3) // button array case
        {
          s=_itemsArray[n].nbButt;
          if (_itemsArray[n].title!=NULL) h+=H_TEXT;
          lw=_itemsArray[n].bSize;
        
          if (_itemsArray[n].buttRow==0) // default
          {
            if (s==1) x=W_TEXT*lw+2*W_EDGE;
            if ((s==3) || (s>4)) x=3*(W_TEXT*lw+2*W_EDGE);
            if ((s==2) || (s==4)) x=2*(W_TEXT*lw+2*W_EDGE);
            h+=((s-1)/3+1)*(H_TEXT+2*W_EDGE);
          }
          else
          {
            x=_itemsArray[n].buttRow*(W_TEXT*lw+2*W_EDGE);
            h+=((s-1)/_itemsArray[n].buttRow+1)*(H_TEXT+2*W_EDGE);
          }
        }
        if ((t==tInputKbrd) || (t==tPlusMinus))
        {
          s=_itemsArray[n].nbChar;
          h+=H_TEXT+2*W_EDGE;
          lw=strlen(_itemsArray[n].title);
          x=W_TEXT*(lw+s+1)+4*W_EDGE;
          if (t==tPlusMinus) x+=2*H_TEXT+4*W_EDGE;
          if (lw>z) z=lw;
        }
        if (t==tBarGraph)
        {
          h+=H_TEXT+2*W_EDGE;
          lw=strlen(_itemsArray[n].title);
          x=W_TEXT*(lw+10+1)+4*W_EDGE;
          if (lw>z) z=lw;
        }
        if (t==tMap) 
        {        
          if (_itemsArray[n].title!=NULL) h+=H_TEXT;
          if (_itemsArray[n].zoomF>0)
          {
            h+=_itemsArray[n].ySize*_itemsArray[n].zoomF+2*W_EDGE;
            x=_itemsArray[n].xSize*_itemsArray[n].zoomF+2*W_EDGE;
          }
          else
          {
            h+=_itemsArray[n].ySize+2*W_EDGE;
            x=_itemsArray[n].xSize+2*W_EDGE;
          }
        }
        if ((t==tCurve) || (t==tMultiCurve))
        {
          if (_itemsArray[n].title!=NULL) h+=H_TEXT;
          h+=_itemsArray[n].ySize+2*W_EDGE;
          if ((_itemsArray[n].zoomF)>0) x=_itemsArray[n].xSize*_itemsArray[n].zoomF+2*W_EDGE;
          else x=_itemsArray[n].xSize+2*W_EDGE;
        }
      
        _itemsArray[n].yMax=h-1;
        if (x>xm) xm=x;
      } // end of loop for each item in column
    
      _wCol[i][j]=xm; // column width is given by the widest item
      _hCol[i][j]=h;
      if (h>hm) hm=h;
      curWBlk+=xm;
      _wBut[i][j]=z;
    } // end of loop for each column
  
    _wBlk[i]=curWBlk;
    if (curWBlk>wm) wm=curWBlk;
    _hBlk[i]=hm;                    // block height is given by the tallest column;
    _yBlk[i+1]=_yBlk[i]+hm;
    _hLal+=hm;
  } // end of loop for each block
 
  _wLal=wm; // lal width is given by the widest block
  
  r=InitLalBitmap();

  return(r);
}


// draw items (static part) in the pixmap

void Lal::Draw(void)
{
  long a,b,c,i,j,k,l,n,s,t,w;
  long x,y,u,v;
  long xo,yo;
  long r=1;
  long w1,w2;
  long lw;
  char cs[80];
 
  for (i=0;i<_nbBlocks;i++)
  { 
    xo=0;
   
    for (j=0;j<_blkCard[i];j++)
    {
      yo=_yBlk[i];
      if (j==(_blkCard[i]-1)) w=_wLal-xo;
      else w=_wCol[i][j]*((float)_wLal/_wBlk[i]); // compute actual column width
      _wCol[i][j]=w;
      _xCol[i][j]=xo;
      _xCol[i][j+1]=2048; // temporal upper limit
     
      lw=_wBut[i][j];
     
      for (k=0;k<_colCard[i][j];k++) 
      {
        n=_itemsTable[i][j][k]; // get item index  
        _itemsArray[n].width=w;
      
        t=_itemsArray[n].type;
        c=_itemsArray[n].color;
        
        if (t<3) // button array case             
        {
          s=_itemsArray[n].nbButt;
          if (_itemsArray[n].title!=NULL)
          {
            Rect(c,xo,yo,w);
            l=strlen(_itemsArray[n].title);
            x=(w-l*W_TEXT)/2;
            if (x<0) x=0;
            strcpy((char *)cs,_itemsArray[n].title);
            Print(xo+x,yo+H_TEXT-2,Lwhite,cs);
            yo+=H_TEXT;
          }
          u=0;
       
          r=_itemsArray[n].buttRow;
          if (r==0) // default
          {
            if (s==1)
            {
              Rect(c,xo,yo+3,w);
              l=strlen(_itemsArray[n].name[u]);
              strcpy((char *)cs,_itemsArray[n].name[u]);
              x=(w-W_TEXT*l)/2;
              if (x<0) x=0;
              Print(xo+x,yo+H_TEXT,Lwhite,cs);
              yo+=H_TEXT+2*W_EDGE;
            }
            else
            {
              if ((s%3)==0)
              {
                w1=s/3;
                w2=0;
              }
              if ((s%3)==2)
              {
                w1=s/3;
                w2=1;
              }
              if ((s%3)==1)
              {
                w1=((s-4)/3);
                w2=2;    
              }
              if (w1>0)
              {
                for (a=0;a<w1;a++)
                {
                  for (b=0;b<3;b++)
                  {
                    Rect(c,xo+b*w/3,yo+3,w/3);
                    l=strlen(_itemsArray[n].name[u]);
                    strcpy((char *)cs,_itemsArray[n].name[u]);
                    x=b*w/3-W_TEXT*l/2+w/6;
                    Print(xo+x,yo+H_TEXT,Lwhite,cs);
                    u++;
                  }
                  yo+=H_TEXT+2*W_EDGE;
                }
              }
              if (w2>0)
              {
                for (a=0;a<w2;a++)
                {
                  for (b=0;b<2;b++)
                  {
                    Rect(c,xo+b*w/2,yo+3,w/2);
                    l=strlen(_itemsArray[n].name[u]);
                    strcpy((char *)cs,_itemsArray[n].name[u]);
                    x=b*w/2-W_TEXT*l/2+w/4;
                    Print(x+xo,yo+H_TEXT,Lwhite,cs);
                    u++;
                  }
                  yo+=H_TEXT+2*W_EDGE;
                }
              }
            }
          }
          else
          {
            v=s;
            while (v!=0)
            {
              if (v>=r)
              {
                for (a=0;a<r;a++)
                {
                  Rect(c,xo+a*w/r,yo+3,w/r);
                  l=strlen(_itemsArray[n].name[u]);
                  strcpy((char *)cs,_itemsArray[n].name[u]);
                  x=a*w/r-W_TEXT*l/2+w/(2*r);
                  Print(x+xo,yo+H_TEXT,Lwhite,cs);
                  u++;
                }
                yo+=H_TEXT+2*W_EDGE;
                v-=r;
              }
              else
              {
                for (a=0;a<v;a++)
                {
                  Rect(c,xo+a*w/v,yo+3,w/v);
                  l=strlen(_itemsArray[n].name[u]);
                  strcpy((char *)cs,_itemsArray[n].name[u]);
                  x=a*w/v-W_TEXT*l/2+w/(2*v);
                  Print(x+xo,yo+H_TEXT,Lwhite,cs);
                  u++;
                }
                yo+=H_TEXT+2*W_EDGE;
                v=0;
              }
            }
          }
        } // end of button array case
       
        if ((t==tInputKbrd) || (t==tPlusMinus) || (t==tBarGraph))
        {
          Rect(c,xo,yo+3,lw*W_TEXT+2*W_EDGE);
      
          if (_itemsArray[n].title!=NULL) strcpy(cs,_itemsArray[n].title);
          else strcpy(cs," ");
          l=strlen(cs);
          x=W_EDGE+(lw-l)*W_TEXT/2;
          if (x<0) x=0;
          Print(xo+x,yo+H_TEXT,Lwhite,cs);
          if (t==tPlusMinus)
          {
            Rect(c,xo+lw*W_TEXT+2*W_EDGE,yo+3,H_TEXT+2*W_EDGE);
            Button(c,xo+lw*W_TEXT+2*W_EDGE,yo,H_TEXT+2*W_EDGE);
            UpArrow(c,xo+lw*W_TEXT+3*W_EDGE+1,yo+W_EDGE+1);
            Rect(c,xo+lw*W_TEXT+H_TEXT+4*W_EDGE,yo+3,H_TEXT+2*W_EDGE);
            Button(c,xo+lw*W_TEXT+H_TEXT+4*W_EDGE,yo,H_TEXT+2*W_EDGE);
            DownArrow(c,xo+lw*W_TEXT+H_TEXT+5*W_EDGE+1,yo+W_EDGE+1);
            Input(c,xo+lw*W_TEXT+2*H_TEXT+6*W_EDGE,yo,w-lw*W_TEXT-2*H_TEXT-6*W_EDGE);
          }
          else Input(c,xo+lw*W_TEXT+2*W_EDGE,yo,w-lw*W_TEXT-2*W_EDGE);
          yo+=H_TEXT+2*W_EDGE;
        }
     
        if (t==tMap)
        {
          if (_itemsArray[n].title!=NULL)
          {
            Rect(c,xo,yo,w);
            l=strlen(_itemsArray[n].title);
            x=(w-l*W_TEXT)/2;
            if (x<0) x=0;
            strcpy(cs,_itemsArray[n].title);
            Print(xo+x,yo+H_TEXT-2,Lwhite,cs);
            yo+=H_TEXT;
          }
          if (_itemsArray[n].zoomF>0)
          {
            MapFrame(c,w,xo,yo,_itemsArray[n].xSize*_itemsArray[n].zoomF,_itemsArray[n].ySize*_itemsArray[n].zoomF);
            yo+=_itemsArray[n].ySize*_itemsArray[n].zoomF+2*W_EDGE;
          }
          else
          {
            MapFrame(c,w,xo,yo,_itemsArray[n].xSize,_itemsArray[n].ySize);
            yo+=_itemsArray[i].ySize+2*W_EDGE;
          }
        }
       
        if ((t==tCurve) || (t==tMultiCurve))
        {
          if (_itemsArray[n].title!=NULL)
          {
            Rect(c,xo,yo,w);
            l=strlen(_itemsArray[n].title);
            x=(w-l*W_TEXT)/2;
            if (x<0) x=0;
            strcpy(cs,_itemsArray[n].title);
            Print(xo+x,yo+H_TEXT-2,Lwhite,cs);
            yo+=H_TEXT;
          }
          if (_itemsArray[n].zoomF>0)
            MapFrame(c,w,xo,yo,_itemsArray[n].xSize*_itemsArray[n].zoomF,_itemsArray[n].ySize);
          else
            MapFrame(c,w,xo,yo,_itemsArray[n].xSize,_itemsArray[n].ySize);
          yo+=_itemsArray[n].ySize+2*W_EDGE;
        }  
      } // end of loop for each item in column
    
      // fill remaining space in column with the color of last item
    
      for (y=yo;y<(_hBlk[i]+_yBlk[i]);y++)
      {
        for (x=xo;x<(xo+w);x++) Dot(3*c,x,y);
      }
      xo+=w;   
    } // end of loop for each column
  }   // end of loop for each block
}


// draw items (variable parts) and display values

void Lal::Update(void)
{
  long a,b,c,d,i,j,k,n,s,t;
  long x,u,v,w;
  long xo,yo;
  long r=1;
  long w1,w2;
  long lw;
  char cs[80];
 
  for (i=0;i<_nbBlocks;i++)
  {
    xo=0;
   
    for (j=0;j<_blkCard[i];j++)
    {
      yo=_yBlk[i];
      w=_wCol[i][j];
      lw=_wBut[i][j];
     
      for (k=0;k<_colCard[i][j];k++) 
      {
        n=_itemsTable[i][j][k]; // get item index  
      
        t=_itemsArray[n].type;
        c=_itemsArray[n].color;

        if (t<3) // button array case
        {
          s=_itemsArray[n].nbButt;
          if (_itemsArray[n].title!=NULL) yo+=H_TEXT;
          if (t==tSelectorOne || (t==tSelectorClick))  u=0;
          if (t==tSelectorMany) u=1;
          v=*((long *)_itemsArray[n].argPtr);
          if (s==1)
          {
            if ((t==tSelectorClick) && (_itemsArray[n].pushed==1)) PushedButton(c,xo,yo,w);
            else Button(c,xo,yo,w);
            yo+=H_TEXT+2*W_EDGE;
          }
          else                
          { 
            r=_itemsArray[n].buttRow;
         
            if (r==0) // default
            {                 
              if ((s%3)==0)  // => s/3 rows with 3 buttons
              {
                w1=s/3;
                w2=0;
              }
              if ((s%3)==2) // => 1 row with 2 buttons, then int(s/3) rows with 3 buttons
              {
                w1=s/3;
                w2=1;
              }
              if ((s%3)==1) // => 2 rows with 2 buttons, then int(s/3) rows with 3 buttons
              {
                w1=((s-4)/3);
                w2=2;    
              }
              if (w1>0)
              {
                for (a=0;a<w1;a++)
                {
                  for (b=0;b<3;b++)
                  {
                    if (((t==tSelectorOne) && (u==v)) || ((t==tSelectorMany) && ((u&v)!=0)) ||
                        ((t==tSelectorClick) && (u==v) && (_itemsArray[n].pushed==1)))
                      PushedButton(c,xo+b*w/3,yo,w/3);
                    else Button(c,xo+b*w/3,yo,w/3);
                    if ((t==tSelectorOne) || (t==tSelectorClick)) u++;
                    if (t==tSelectorMany) u<<=1;
                  }
                  yo+=H_TEXT+2*W_EDGE;
                }
              }
              if (w2>0)
              {
                for (a=0;a<w2;a++)
                {
                  for (b=0;b<2;b++)
                  {
                    if (((t==tSelectorOne) && (u==v)) || ((t==tSelectorMany) && ((u&v)!=0)) ||
                        ((t==tSelectorClick) && (u==v) && (_itemsArray[n].pushed==1)))
                      PushedButton(c,xo+b*w/2,yo,w/2);
                    else Button(c,xo+b*w/2,yo,w/2);
                    if ((t==tSelectorOne) || (t==tSelectorClick)) u++;
                    if (t==tSelectorMany) u<<=1;
                  }
                  yo+=H_TEXT+2*W_EDGE;
                }
              }
            }
            else // custom number of buttons per row
            {
              d=s;
              while (d!=0)
              {
                if (d>=r)
                {
                  for (b=0;b<r;b++)
                  {
                    if (((t==tSelectorOne) && (u==v)) || ((t==tSelectorMany) && ((u&v)!=0)) ||
                        ((t==tSelectorClick) && (u==v) && (_itemsArray[n].pushed==1)))
                    PushedButton(c,xo+b*w/r,yo,w/r);
                    else Button(c,xo+b*w/r,yo,w/r);
                    if ((t==tSelectorOne) || (t==tSelectorClick)) u++;
                    if (t==tSelectorMany) u<<=1;
                  }
                  d-=r;
                  yo+=H_TEXT+2*W_EDGE;
                }
                else
                {
                  for (b=0;b<d;b++)
                  {
                    if (((t==tSelectorOne) && (u==v)) || ((t==tSelectorMany) && ((u&v)!=0)) ||
                        ((t==tSelectorClick) && (u==v) && (_itemsArray[n].pushed==1)))
                    PushedButton(c,xo+b*w/d,yo,w/d);
                    else Button(c,xo+b*w/d,yo,w/d);
                    if ((t==tSelectorOne) || (t==tSelectorClick)) u++;
                    if (t==tSelectorMany) u<<=1;
                  }
                  d=0;
                  yo+=H_TEXT+2*W_EDGE;
                }
              }
            }           
          } 
        }  // end of button array case
     
        if ((t==tInputKbrd) || (t==tPlusMinus) || (t==tBarGraph))
        {
          if ((_itemsArray[n].locked==LOCKED) || (_itemsArray[n].type==tBarGraph)) 
          {
            LockedButton(c,xo,yo,lw*W_TEXT+2*W_EDGE);
          }
          else 
          {
            if (_itemsArray[n].inEdit==1) PushedButton(c,xo,yo,lw*W_TEXT+2*W_EDGE);
            else Button(c,xo,yo,lw*W_TEXT+2*W_EDGE);
          }
       
          x=W_EDGE*4+lw*W_TEXT;
       
          if (t==tPlusMinus)
          {
            Input(c,xo+lw*W_TEXT+2*H_TEXT+6*W_EDGE,yo,w-lw*W_TEXT-2*H_TEXT-6*W_EDGE);
          }
          else Input(c,xo+lw*W_TEXT+2*W_EDGE,yo,w-lw*W_TEXT-2*W_EDGE);
          if (_itemsArray[n].type==tBarGraph)
            Bar(n,xo+lw*W_TEXT+3*W_EDGE,yo,w-lw*W_TEXT-4*W_EDGE);
         
          if ((t==tInputKbrd) || (t==tPlusMinus))
          {
            if (_itemsArray[n].inEdit==1) // user is entering value: cannot convert now
            {
              if (t==tPlusMinus) x+=4*W_EDGE+2*H_TEXT;
              Print(xo+x,yo+H_TEXT+1,Lblack,_itemsArray[n].tmps);
            }
            else
            {
              NumberToString(cs,_itemsArray[n].argPtr,_itemsArray[n].argType);
              cs[_itemsArray[n].nbChar]='\0';
              if (t==tPlusMinus) x+=4*W_EDGE+2*H_TEXT;
              Print(xo+x,yo+H_TEXT+1,Lblack,cs);
            }
          } 
          yo+=H_TEXT+2*W_EDGE;
        }   // end of InputKbrd, PlusMinus, BarGraph cases
       
        if (t==tMap)
        {
          if (_itemsArray[n].title!=NULL) yo+=H_TEXT;
          Map(n,xo,yo+3);
          if (_itemsArray[n].zoomF>0)
            yo+=_itemsArray[n].ySize*_itemsArray[n].zoomF+2*W_EDGE;
          else yo+=_itemsArray[n].ySize+2*W_EDGE;
        }
        
        if (t==tCurve)
        {
          if (_itemsArray[n].title!=NULL) yo+=H_TEXT;
          Curve(n,xo,yo+W_EDGE);
          yo+=_itemsArray[n].ySize+2*W_EDGE;
        }
        
        if (t==tMultiCurve)
        {
          if (_itemsArray[i].title!=NULL) yo+=H_TEXT;
          MultiCurve(n,xo,yo+W_EDGE);
          yo+=_itemsArray[n].ySize+2*W_EDGE;
        }  
      }  // end of loop for each item in column
      xo+=w;
    }    // end of loop for each column
  }      // end of loop for each block
 
  UpdateBitmap();
} 


// draw a rectangle

void Lal::Rect(long color,long xpos,long ypos,long w)
{
 long i,j;
 
  for (i=0;i<H_TEXT;i++) for (j=0;j<w;j++)  Dot(3*color,xpos+j,ypos+i);  
}


// draw button edges

void Lal::Button(long color,long xpos,long ypos,long w)
{
  long h,i,n;
 
  h=W_EDGE*2+H_TEXT;
 
  for (n=0;n<W_EDGE;n++)
  {
    for (i=0;i<(h-1);i++) Dot(3*color+2,xpos,ypos+i);     // left edge (bright)
    for (i=0;i<(h-1);i++) Dot(3*color+1,xpos+w-1,ypos+i+1); // right edge (shaded)
    for (i=0;i<(w-1);i++) Dot(3*color+2,xpos+i+1,ypos);    // top edge (bright)
    for (i=0;i<(w-1);i++) Dot(3*color+1,xpos+i,ypos+h-1);   // bottom edge (shaded)
    xpos++;
    ypos++;
    w-=2; 
    h-=2;
  }
}


// draw pushed button edges

void Lal::PushedButton(long color,long xpos,long ypos,long w)
{
  long h,i,n;
 
  h=W_EDGE*2+H_TEXT;
 
  for (n=0;n<W_EDGE;n++)
  {
    for (i=0;i<(h-1);i++) Dot(3*color+1,xpos,ypos+i);     // left edge (shaded)
    for (i=0;i<(h-1);i++) Dot(3*color+2,xpos+w-1,ypos+i+1); // right edge (bright)
    for (i=0;i<(w-1);i++) Dot(3*color+1,xpos+i+1,ypos);    // top edge (shaded)
    for (i=0;i<(w-1);i++) Dot(3*color+2,xpos+i,ypos+h-1);    // bottom edge (bright)
    xpos++;
    ypos++;
    w-=2; 
    h-=2;
  }
}

// draw locked button edges

void Lal::LockedButton(long color,long xpos,long ypos,long w)
{
  long h,i,n;
 
  h=W_EDGE*2+H_TEXT;
 
  for (n=0;n<W_EDGE;n++)
  {
    for (i=0;i<(h-1);i++) Dot(3*color,xpos,ypos+i);    // left edge
    for (i=0;i<(h-1);i++) Dot(3*color,xpos+w-1,ypos+i+1); // right edge
    for (i=0;i<(w-1);i++) Dot(3*color,xpos+i+1,ypos);    // top edge
    for (i=0;i<(w-1);i++) Dot(3*color,xpos+i,ypos+h-1);   // bottom edge
    xpos++;
    ypos++;
    w-=2; 
    h-=2;
  }
}

// draw an text input field

void Lal::Input(long color,long xpos,long ypos,long w)
{
  long i,j;
 
  for (i=0;i<H_TEXT+2*W_EDGE;i++) for (j=0;j<w;j++) Dot(3*color,xpos+j,ypos+i);                // frame
  for (i=0;i<H_TEXT;i++) for (j=0;j<(w-2*W_EDGE);j++) Dot(Lwhite,xpos+j+W_EDGE,ypos+W_EDGE+i); // background
  for (i=0;i<(w-2*W_EDGE+2);i++) Dot(3*color+1,xpos+i+W_EDGE-1,ypos+W_EDGE-1);               // top edge (shaded)
  for (i=0;i<(w-2*W_EDGE+2);i++) Dot(3*color+2,xpos+i+W_EDGE-1,ypos+W_EDGE+H_TEXT);           // bottom edge (bright)
  for (i=0;i<H_TEXT;i++) Dot(3*color+1,xpos+W_EDGE,ypos+W_EDGE+i);                          // left edge (shaded)
  for (i=0;i<H_TEXT;i++) Dot(3*color+2,xpos+w-W_EDGE-1,ypos+W_EDGE+i);                      // right edge (bright)
}


// draw a map frame

void Lal::MapFrame(long color,long w,long xpos,long ypos,long u,long h)
{
  long i,j;
 
  for (i=0;i<(h+2*W_EDGE);i++) for (j=0;j<w;j++) Dot(3*color,j+xpos,i+ypos);

  for (i=(w-u)/2-1;i<((w-u)/2+u+1);i++) Dot(3*color+1,xpos+i,ypos+W_EDGE-1); // top edge (shaded)
  for (i=(w-u)/2-1;i<((w-u)/2+u+1);i++) Dot(3*color+2,xpos+i,ypos+W_EDGE+h); // bottom edge (bright)
  for (i=0;i<h;i++) Dot(3*color+1,xpos+(w-u)/2-1,ypos+W_EDGE+i);         // left edge (shaded)
  for (i=0;i<h;i++) Dot(3*color+2,xpos+(w-u)/2+u,ypos+W_EDGE+i);         // right edge (bright)
}
 

// draw an "up" arrow (PlusMinus)

void Lal::UpArrow(long color,long xpos,long ypos)
{
  long i;
 
  for (i=0;i<S_ARW/2;i++)   Dot(3*color+2,xpos+i+S_ARW/2,ypos+i);
  for (i=0;i<S_ARW/2;i++)   Dot(3*color+1,xpos-i+S_ARW/2,ypos+i);
  for (i=0;i<S_ARW/3;i++)   Dot(3*color+2,xpos+i,ypos+S_ARW/2);
  for (i=0;i<=S_ARW/3;i++)  Dot(3*color+1,xpos+i+S_ARW/3,ypos+S_ARW-1);
  for (i=0;i<S_ARW/3;i++)   Dot(3*color+2,i+xpos+2*S_ARW/3,ypos+S_ARW/2);
  for (i=0;i<S_ARW/2;i++)   Dot(3*color+1,xpos+S_ARW/3,ypos+i+S_ARW/2);
  for (i=0;i<S_ARW/2;i++)   Dot(3*color+2,xpos+2*S_ARW/3,ypos+i+S_ARW/2);
}
 
 
// draw a "down" arrow (PlusMinus)

void Lal::DownArrow(long color,long xpos,long ypos)
{
  long i;
 
  for (i=0;i<S_ARW/2;i++)  Dot(3*color+2,xpos+i,ypos+i+S_ARW/2);
  for (i=0;i<S_ARW/2;i++)  Dot(3*color+2,xpos+i+S_ARW/2,ypos+S_ARW-i-1);
  for (i=0;i<S_ARW/3;i++)  Dot(3*color+1,xpos+i,ypos+S_ARW/2);
  for (i=0;i<=S_ARW/3;i++) Dot(3*color+1,i+xpos+S_ARW/3,ypos);
  for (i=0;i<S_ARW/3;i++)  Dot(3*color+1,xpos+i+2*S_ARW/3,ypos+S_ARW/2);
  for (i=0;i<S_ARW/2;i++)  Dot(3*color+1,xpos+S_ARW/3,ypos+i);
  for (i=0;i<S_ARW/2;i++)  Dot(3*color+2,xpos+2*S_ARW/3,ypos+i);
}
   
   
// draw a character string 

void Lal::Print(long x,long y,long color,const char *s) 
{
  long i,j,k,m;
  long c;
 
  for (i=0;i<strlen(s);i++)
  {
    c=s[i];
    if ((c<32) || (c>223)) c=223;
      c-=32;
    for (j=0;j<10;j++)
    {
      for (k=0;k<5;k++)
      {
        m=192*(1+j+(c/32)*11)+(c%32)*6+k+1;
        if (*(fontTable+m)!=0) Dot(color,x+6*i+k,y-9+j);
      }
    }
  }  
}


// draw a bar-graph

void Lal::Bar(long n,long xpos,long ypos,long w)
{
  double min,max;
  long i,j,m;
  double val;
  
  min=_itemsArray[n].vMin;
  max=_itemsArray[n].vMax;
  val=GetValue(_itemsArray[n].argPtr,_itemsArray[n].argType);

  if (val>min)
  {
    m=w*(val-min)/(max-min);
    if (m>w) m=w;
    for (i=0;i<H_TEXT;i++) for (j=0;j<m;j++)
      Dot(Lblack,xpos+j+W_EDGE-2,ypos+i+W_EDGE); 
  }
  if (val<min)  Print(xpos+W_EDGE+2,ypos+H_TEXT,Lblack,"-");
  if (val>max)  Print(xpos+w-W_EDGE-W_TEXT-2,ypos+H_TEXT,Lwhite,"+");
}


// draw a map

void Lal::Map(long n,long xPosIn,long yPosIn)
{
  long xp,yp;
  long xl,yl;
  long xo,yo;
  long xPos,yPos;
  long i,j,k,l,m,t,w,z,oz;
  unsigned long a;
  unsigned char c;
  
  double val,max,min;
  
  xp=_itemsArray[n].xSize;
  yp=_itemsArray[n].ySize;
  xo=_itemsArray[n].xOrg;
  yo=_itemsArray[n].yOrg;
  z=_itemsArray[n].zoomF;
  oz=-z;
  t=_itemsArray[n].argType;
  a=_itemsArray[n].argPtr;
  w=_itemsArray[n].width;
  
  if (z>0) xPos=(w-xp*z)/2+xPosIn; else xPos=(w-xp)/2+xPosIn;
  yPos=yPosIn;
  xl=xo+xp;
  yl=yo+yp;
  
  // search min and max limits for normalization (display with maximum contrast)
  
  max=0;
  for (i=xo;i<xl;i++)
  {
    for (j=yo;j<yl;j++)
    {
      if (z>=1)
      {
        val=Get2DValue(i,j,a,t);
      }
      else 
      {
        val=0;
        for (k=0;k<oz;k++)
        {
          for (l=0;l<oz;l++)
          {
            val+=Get2DValue(i*oz+k,j*oz+l,a,t);
          }
        }
      }
      if (val>max) max=val;
      if (((i==xo) && (j==yo)) || (val<min)) min=val;
    }
  }
  if (min==max) max++;
  
  for (i=xo;i<xl;i++)
  {
    for (j=yo;j<yl;j++)
    {
      if (z>=1)
      { 
        val=Get2DValue(i,j,a,t);
      }
      else 
      {
        val=0;
        for (k=0;k<oz;k++)
        {
          for (l=0;l<oz;l++)
          {
            val+=Get2DValue(i*oz+k,j*oz+l,a,t);
          }
        }
      }  
      c=255*(val-min)/(max-min);
      SetPixel(xPos,yPos,i-xo,j-yo,z,c,_itemsArray[n].lut);
    }
  }
}


// set LUT for maps
 
void Lal::SetLut(long a)
{
  _mapLut=a;
}

 
// display a 1-D plot

void Lal::Curve(long n,long xPosIn,long yPosIn)
{
  long xp,yl;
  long xl;
  long xo;
  long xPos,yPos;
  long i,k,lBar;
  long m,t,w,z,zPos,oz;
  unsigned long a;
  
  double val,max,min;
  
  xp=_itemsArray[n].xSize;
  yl=_itemsArray[n].ySize;
  xo=_itemsArray[n].xOrg;
  z=_itemsArray[n].zoomF;
  oz=-z;
  a=_itemsArray[n].argPtr;
  t=_itemsArray[n].argType;
  w=_itemsArray[n].width;
  
  if (z>0) xPos=(w-xp*z)/2+xPosIn; else xPos=(w-xp)/2+xPosIn;
  xl=xo+xp;
  yPos=yPosIn;
  
  max=0;
  for (i=xo;i<xl;i++)
  {
    if (z>=1)
    {
      val=Get1DValue(i,a,t);
    }
    else 
    {
      val=0;
      for (k=0;k<oz;k++)
      {
        val+=Get1DValue(i*oz+k,a,t);
      }
    }
    if ((i==xo) || (val>max)) max=val;
    if ((i==xo) || (val<min)) min=val;
  }
  if (min==max)
  {
    min--;
    max++;
  }
  if (_itemsArray[n].minPtr!=NULL) *(_itemsArray[n].minPtr)=min;
  if (_itemsArray[n].maxPtr!=NULL) *(_itemsArray[n].maxPtr)=max; 
  zPos=0;                                     
  if ((max>0) && (min<0)) zPos=(long)(yPos+(yl-6)*max/(max-min)+3);
  for (i=xo;i<xl;i++)
  {
    if (z>=1)
    { 
      val=Get1DValue(i,a,t);
    }
    else 
    {
      val=0;
      for (k=0;k<oz;k++)
      {
        val+=Get1DValue(i*oz+k,a,t);
      }
    }
    if (z>1)
    {
      if (zPos!=0) // there are negative and positive values to display
      {
        lBar=zPos-val*(zPos-yPos-3)/max;
        if (val>=0)
        {
          for (k=yPos;k<lBar;k++) for (m=0;m<z;m++)
            Dot(Lwhite,(i-xo)*z+m+xPos,k);
          for (k=lBar;k<=zPos;k++) for (m=0;m<z;m++)
            Dot(Lblack,(i-xo)*z+m+xPos,k);
          for (k=zPos+1;k<(yPos+yl);k++) for (m=0;m<z;m++)
            Dot(Lwhite,(i-xo)*z+m+xPos,k); 
        }
        else
        {
          for (k=yPos;k<zPos;k++) for (m=0;m<z;m++)
            Dot(Lwhite,(i-xo)*z+m+xPos,k);
          for (k=zPos;k<=lBar;k++) for (m=0;m<z;m++)
            Dot(Lblack,(i-xo)*z+m+xPos,k);
          for (k=lBar+1;k<(yPos+yl);k++) for (m=0;m<z;m++)
            Dot(Lwhite,(i-xo)*z+m+xPos,k); 
        }
      }  
      else  // values are either all positive or all negative
      {   
        lBar=yPos+3+(yl-6)*(max-val)/(max-min);
        if (min>=0)
        {
          for (k=yPos;k<lBar;k++) for (m=0;m<z;m++)
            Dot(Lwhite,(i-xo)*z+m+xPos,k);
          for (k=lBar;k<(yPos+yl);k++) for (m=0;m<z;m++)
            Dot(Lblack,(i-xo)*z+m+xPos,k);
        }
        else
        {
          for (k=yPos;k<lBar;k++) for (m=0;m<z;m++)
            Dot(Lblack,(i-xo)*z+m+xPos,k);
          for (k=lBar;k<(yPos+yl);k++) for (m=0;m<z;m++)
            Dot(Lwhite,(i-xo)*z+m+xPos,k);
        }
      }
    }
    else
    {
      if (zPos!=0)
      {
        lBar=zPos-val*(zPos-yPos-3)/max;
        if (val>=0)
        {
          for (k=yPos;k<lBar;k++) 
            Dot(Lwhite,i-xo+xPos,k);
          for (k=lBar;k<=zPos;k++) 
            Dot(Lblack,i-xo+xPos,k);
          for (k=zPos+1;k<(yPos+yl);k++) 
            Dot(Lwhite,i-xo+xPos,k); 
        }
        else
        {
          for (k=yPos;k<zPos;k++) 
            Dot(Lwhite,i-xo+xPos,k);
          for (k=zPos;k<=lBar;k++)
            Dot(Lblack,i-xo+xPos,k);
          for (k=lBar+1;k<(yPos+yl);k++) 
            Dot(Lwhite,i-xo+xPos,k); 
        }
      }  
      else
      {  
        lBar=yPos+3+(yl-6)*(max-val)/(max-min);    
        if (min>=0)
        { 
          for (k=yPos;k<lBar;k++) 
            Dot(Lwhite,i-xo+xPos,k);
          for (k=lBar;k<(yPos+yl);k++) 
            Dot(Lblack,i-xo+xPos,k);
        }
        else
        {
          for (k=yPos;k<lBar;k++) 
            Dot(Lblack,i-xo+xPos,k);
          for (k=lBar;k<(yPos+yl);k++) 
            Dot(Lwhite,i-xo+xPos,k);
        }
      }
    }
  }
}
 
 
// display a multiple 1-D plot

void Lal::MultiCurve(long n,long xPosIn,long yPosIn)
{
  long xp,yl;
  long xl;
  long xo;
  long xPos,yPos;
  long i,ii,j,k;
  long t,w,z,oz;
  long sVal1,sVal2;
  long yTop,yBot;
  unsigned long a;
  long n0,n1;
  char c;
  
  double val,val1,val2;
  double max,min;
  
  xp=_itemsArray[n].xSize;
  yl=_itemsArray[n].ySize;
  xo=_itemsArray[n].xOrg;
  z=_itemsArray[n].zoomF;
  oz=-z;
  a=_itemsArray[n].argPtr;
  t=_itemsArray[n].argType;
  n0=_itemsArray[n].stCurve;
  n1=_itemsArray[n].enCurve;
  
  w=_itemsArray[n].width;
  
  if (z>0) xPos=(w-xp*z)/2+xPosIn; else xPos=(w-xp)/2+xPosIn;
  yPos=yPosIn;
  xl=xo+xp;
  
  yTop=yPos;
  yBot=yPos+yl;
  
  if (z>=1) // clear previous curves
  {
    for (i=0;i<(xp*z);i++) for (j=yTop;j<yBot;j++) Dot(Lwhite,xPos+i,j);
  }
  else
  {
    for (i=0;i<xp;i++) for (j=yTop;j<yBot;j++) Dot(Lwhite,xPos+i,j);
  }
  
  for (ii=n0;ii<=n1;ii++)
  { 
    for (i=xo;i<xl;i++)
    {
      if (z>=1)
      {
        val=Get2DValue(ii,i,a,t);
      }
      else 
      {
        val=0;
        for (k=0;k<oz;k++)
        {
          val+=Get2DValue(ii,i*oz+k,a,t);
        }
      }
      if ((i==xo) || (val>max)) max=val;
      if ((i==xo) || (val<min)) min=val;
    }
    
    if (min==max)
    {
      min--;
      max++;
    }
    if (_itemsArray[n].minPtr!=NULL) *(_itemsArray[n].minPtr)=min;
    if (_itemsArray[n].maxPtr!=NULL) *(_itemsArray[n].maxPtr)=max; 
    
    for (ii=n0;ii<=n1;ii++)
    {
      c=3*(ii & 0x00000007)+1;
      
      for (i=xo;i<(xl-1);i++)
      {
        if (z>=1) // zoom-in case: need to interpolate curve by segments over z points
        { 
          val1=Get2DValue(ii,i,a,t);
          val2=Get2DValue(ii,i+1,a,t);
          
          for (j=0;j<z;j++)
          {
            sVal1=yPos+yl-yl*((val2-val1)*j/z+val1-min)/(max-min);
            sVal2=yPos+yl-yl*((val2-val1)*(j+1)/z+val1-min)/(max-min);
            
            if ((sVal1>=yTop) && (sVal1<yBot) && (sVal2>=yTop) && (sVal2<yBot)) // if segment within display
            {
              if (sVal1==sVal2) Dot(c,xPos+(i-xo)*z+j,sVal1); // draw horizontal segment
              if (sVal1<sVal2) for (k=sVal1;k<sVal2;k++) Dot(c,xPos+(i-xo)*z+j,k); 
              if (sVal2<sVal1) for (k=sVal2;k<sVal1;k++) Dot(c,xPos+(i-xo)*z+j,k);
            }
            if ((sVal1<yTop) && (sVal2<yBot) && (sVal2>=yTop)) // left end of segment above top of display
            {
              for (k=yTop;k<sVal2;k++) Dot(c,xPos+(i-xo)*z+j,k);
            }
            if ((sVal2<yTop) && (sVal1<yBot) && (sVal1>=yTop)) // right end of segment above top of display
            {
              for (k=sVal1;k<yTop;k--) Dot(c,xPos+(i-xo)*z+j,k);
            }
            if ((sVal1>=yBot) && (sVal2<yBot) && (sVal2>=yTop)) // left end of segment below bottom of display
            {
              for (k=yBot-1;k<sVal2;k--) Dot(c,xPos+(i-xo)*z+j,k);
            }
            if ((sVal2>=yBot) && (sVal1<yBot) && (sVal1>=yTop)) // right end of segment below bottom of display
            {
              for (k=sVal1;k<yBot;k++) Dot(c,xPos+(i-xo)*z+j,k);
            }
            if (((sVal1<yTop) && (sVal2>=yBot)) || ((sVal2<yTop) && (sVal1>=yBot))) // both ends out of display
            {
              for (k=yTop;k<yBot;k++) Dot(c,xPos+(i-xo)*z+j,k);
            }
          }
        }
        else    // zoom-out (binning) case
        {
          val1=0;
          val2=0;
          for (k=0;k<oz;k++)
          {
            val1+=Get2DValue(ii,i,a,t);
            val2+=Get2DValue(ii,i+1,a,t);
          }
          val1/=oz;
          val2/=oz;
         
          val1=yPos+yl-yl*(val1-min)/(max-min);
          val2=yPos+yl-yl*(val2-min)/(max-min);
          
          if ((val1>=yTop) && (val1<yBot) && (val2>=yTop) && (val2<yBot)) // if segment within display
          {
            if (val1==val2) Dot(c,xPos+i-xo,val1); // draw horizontal segment
            if (val1<val2) for (k=val1;k<val2;k++) Dot(c,xPos+i-xo,k);
            if (val2<val1) for (k=val2;k<val1;k++) Dot(c,xPos+i-xo,k);
          }
          if ((val1<yTop) && (val2<yBot) && (val2>=yTop)) // left end of segment above top of display
          {
            for (k=yTop;k<val2;k++) Dot(c,xPos+i-xo,k);
          }
          if ((val2<yTop) && (val1<yBot) && (val1>=yTop)) // right end of segment above top of display
          {
            for (k=val1;k<yTop;k++) Dot(c,xPos+i-xo,k);
          }
          if ((val1>=yBot) && (val2<yBot) && (val2>=yTop)) // left end of segment below bottom of display
          {
            for (k=yBot-1;k<val2;k--) Dot(c,xPos+i-xo,k);
          }
          if ((val2>=yBot) && (val1<yBot) && (val1>=yTop)) // right end of segment below bottom of display
          {
            for (k=val1;k<yBot;k++) Dot(c,xPos+i-xo,k);
          }
          if (((val1<yTop) && (val2>=yBot)) || ((val2<yTop) && (val1>=yBot))) // both ends out of display
          {
            for (k=yTop;k<yBot;k++) Dot(c,xPos+i-xo,k);           
          }
        }
      }
    }
  }
}



// edit item clicked in lal (according to mouse position)

void Lal::EditItem(long xw,long yw)
{
  long b,d,e,i,j,kk,l,n,o,r,s,t,u,x,y,z;
  
  long blk;   // clicked block
  long col;   // clicked column
  long xm,ym; // mouse coordinates in the column
  long tb;    // touched button (SelectorXXX case)
  long itm;   // item to edit
  long lw;
  char cs[80];
  char h;
  double v;
  long xo,yo;
  
  if (_nbBlocks>1)
  {
    for (i=0;i<_nbBlocks;i++) // find clicked block
    {
      if ((yw>=_yBlk[i]) && (yw<_yBlk[i+1]))
      {
        blk=i;
      }
    }
  }
  else blk=0;
  
  if (_blkCard[blk]>1)
  {
    for (i=0;i<_blkCard[blk];i++) // find clicked column
    {
      if ((xw>=_xCol[blk][i]) && (xw<=_xCol[blk][i+1])) col=i;
    }
  }
  else col=0;
  
  yo=_yBlk[blk];
  ym=yw-yo;
  xo=_xCol[blk][col];
  xm=xw-xo;
  
  if (_colCard[blk][col]>1)
  {   
    for (i=0;i<_colCard[blk][col];i++) // find clicked item
    {
      n=_itemsTable[blk][col][i];
      if ((ym>=_itemsArray[n].yMin) && (ym<=_itemsArray[n].yMax)) itm=n;
   }
  }
  else itm=_itemsTable[blk][col][0];
          
  t=_itemsArray[itm].type;
  y=ym-_itemsArray[itm].yMin;
  s=_itemsArray[itm].yMax-_itemsArray[itm].yMin+1;
 
  if (t<3)
  {
    if ((_itemsArray[itm].title==NULL) || ((_itemsArray[itm].title!=NULL) && (y>H_TEXT)))
    {
      if (_itemsArray[itm].title!=NULL)
      {
        y-=H_TEXT;
        s-=H_TEXT;
      }
      o=_itemsArray[itm].nbButt;
      if (o==1) tb=0;
      else
      {
        r=_itemsArray[itm].buttRow;
        if (r==0)
        { 
          if ((o==2) || (o==4)) tb=2*(y/(H_TEXT+2*W_EDGE))+2*xm/_wCol[blk][col];
          else
          {
            if ((o%3)==0) tb=3*(y/(H_TEXT+2*W_EDGE))+3*xm/_wCol[blk][col];
            if ((o%3)==1)
            {
              if (y<(o-4)*(H_TEXT+2*W_EDGE)/3) tb=3*(y/(H_TEXT+2*W_EDGE))+3*xm/_wCol[blk][col];
              else 
              {
                if ((s-y)<(H_TEXT+2*W_EDGE)) tb=o-2+2*xm/_wCol[blk][col];
                else tb=o-4+2*xm/_wCol[blk][col];
              }
            }
            if ((o%3)==2)
            {
              if ((s-y)<(H_TEXT+2*W_EDGE)) tb=o-2+2*xm/_wCol[blk][col];
              else tb=3*(y/(H_TEXT+2*W_EDGE))+3*xm/_wCol[blk][col];
            }        
          }
        }
        else // custom number of buttons per row
        {
          u=o;
          b=0;
          j=0;
          while (u!=0) // scan button-per-button
          {
            if (u>=r)
            {
              for (i=0;i<r;i++)
              {
                if ((xm>=((i*_wCol[blk][col])/r)) && (xm<(((i+1)*_wCol[blk][col])/r)) && (y>=j) && (y<(j+(H_TEXT+2*W_EDGE))))
                tb=b;
                b++;
              }
              u-=r;
              j+=H_TEXT+2*W_EDGE;
            }
            else
            {
              for (i=0;i<u;i++)
              {
                if ((xm>=((i*_wCol[blk][col])/u)) && (xm<(((i+1)*_wCol[blk][col])/u)) && (y>=j) && (y<(j+(H_TEXT+2*W_EDGE))))
                  tb=b;
                 b++;
              }
              u=0;
            }
          }
        }
      }
  
      if (t==tSelectorOne) SetValue(_itemsArray[itm].argPtr,_itemsArray[itm].argType,tb);
   
      if (t==tSelectorMany)
      {
        l=1;
        if (tb>0) for (i=0;i<tb;i++) l<<=1;
        b=(long)GetValue(_itemsArray[itm].argPtr,_itemsArray[itm].argType);
        SetValue(_itemsArray[itm].argPtr,_itemsArray[itm].argType,b^l);
      }
      if (t==tSelectorClick)
      {
        SetValue(_itemsArray[itm].argPtr,_itemsArray[itm].argType,tb);
        _itemsArray[itm].pushed=1;   // display a temporary pushed button (=click)
        Update();
        WaitABit(6);
    
        _itemsArray[itm].pushed=0;
      } 
    }   
  }
 
  if ((t==tMap) && ((_itemsArray[itm].iPoint)!=NULL))
  {
    if (_itemsArray[itm].title!=NULL)
    {
      y-=H_TEXT;
      s-=H_TEXT;
    }
    y-=W_EDGE;
    if (_itemsArray[itm].zoomF>0)
    {
      (_itemsArray[itm].iPoint)->v=y/(_itemsArray[itm].zoomF);
      xm-=(_wCol[blk][col]-_itemsArray[itm].xSize*_itemsArray[itm].zoomF)/2;
      (_itemsArray[itm].iPoint)->h=xm/(_itemsArray[itm].zoomF);
    }
    else
    {
      (_itemsArray[itm].iPoint)->v=y;
      xm-=(_wCol[blk][col]-_itemsArray[itm].xSize)/2;
      (_itemsArray[itm].iPoint)->h=xm;
    }
  }
 
  if ((t==tInputKbrd) || (t==tPlusMinus))
  {
    lw=_wBut[blk][col];
    if ((xm>=lw*W_TEXT+2*W_EDGE) && (xm<lw*W_TEXT+6*W_EDGE+2*H_TEXT) && (t==tPlusMinus)) // if click on up/down arrows
    {
      if (xm<lw*W_TEXT+4*W_EDGE+H_TEXT) // increase value (up arrow)
      {
        if (_itemsArray[itm].progrs==ARI) // arithmetical progression
        {
          v=GetValue(_itemsArray[itm].argPtr,_itemsArray[itm].argType);
          if ((v+_itemsArray[itm].step)<=_itemsArray[itm].vMax)
          SetValue(_itemsArray[itm].argPtr,_itemsArray[itm].argType,v+_itemsArray[itm].step);
        }
        else  // geometrical progression
        {
          v=GetValue(_itemsArray[itm].argPtr,_itemsArray[itm].argType);
          if ((v*(double)_itemsArray[itm].step)<=_itemsArray[itm].vMax)
          SetValue(_itemsArray[itm].argPtr,_itemsArray[itm].argType,v*_itemsArray[itm].step);
        }
      }
      else  // decrease value (down arrow)
      {
        if (_itemsArray[itm].progrs==ARI) // arithmetical progression
        { 
          v=GetValue(_itemsArray[itm].argPtr,_itemsArray[itm].argType);
          if ((v-(double)_itemsArray[itm].step)>=_itemsArray[itm].vMin)
          SetValue(_itemsArray[itm].argPtr,_itemsArray[itm].argType,v-_itemsArray[itm].step);
        }
        else
        {
          v=GetValue(_itemsArray[itm].argPtr,_itemsArray[itm].argType);
          if ((v/(double)_itemsArray[itm].step)>=_itemsArray[itm].vMin)
          SetValue(_itemsArray[itm].argPtr,_itemsArray[itm].argType,v/_itemsArray[itm].step);
        }
      }
      Update();
    }
  
    if ((xm<(lw*W_TEXT+2*W_EDGE)) && ((_itemsArray[itm].locked!=LOCKED) || (t==tPlusMinus)))
    {
      _itemsArray[itm].inEdit=1;
   
      x=0;
    
      o=_itemsArray[itm].argType;
      e=_itemsArray[itm].nbChar;
     
      NumberToString(cs,_itemsArray[itm].argPtr,o);
      l=strlen(cs);
      if (l>e)
      {
        cs[e]='\0';
        l=e;
      }
      strcpy(_itemsArray[itm].tmps,cs);
      Update();
    
      if ((o==Lstring) || (o==Lfloat) || (o==Ldouble) || (o==Lreal) || (o==Limaginary) ||
         (o==Lmodulus) || (o==Lsquaremod) || (o==LphaseRad) || (o==LphaseDeg)) 
      {
        i=32;  // all typed characters are allowed  
        j=255;
      }
      else
      {
        i=48;   // allow numbers only
        j=57;
      }
   
      y=_itemsArray[itm].yMin;  
      x=W_EDGE*4+lw*W_TEXT;
      if (t==tPlusMinus) x+=4*W_EDGE+2*H_TEXT;
   
      y+=W_EDGE+H_TEXT-3;
      DrawCaret(xo,yo,x,y,0);
    
      //y+=W_EDGE+H_TEXT-3;
      kk=0;
      r=0; 
   
      while ((kk!=RETURN_K) && (kk!=ENTER_K)) // return/enter
      { 
        kk=GetTheKey();
     
        if (kk!=-1)
        { 
          h=GetTheChar();
          if ((kk==LEFT_ARROW_K) && (r>0)) r--;  // left arrow
          if ((kk==RIGHT_ARROW_K) && (r<l)) r++; // right arrow
          if ((kk==DELETE_K) && (r!=0))        // delete
          {
            if (r==l) // caret at string end
            {
              cs[r-1]='\0'; // delete last character
              l--;
              r--;
            }
            else // delete character in the string
            {
              for (z=r;z<l;z++) cs[z-1]=cs[z];
              cs[l-1]='\0';
              l--;
              r--;
            }
          }
          if ((h=='-') && (o!=Luchar) && (o!=Lushort) && (o!=Lulong) && (r==0) && (l<=e)) // minus sign
          {
            if (l!=0) for (z=l;z>0;z--) cs[z]=cs[z-1];
            cs[0]='-';
            r++;
            l++;
            cs[l]='\0';
          }
          if ((h>=i) && (h<=j) && (l<e)) // insert allowed character
          {
            if (l!=0) for (z=l;z>r;z--) cs[z]=cs[z-1];
            cs[r]=h;
            r++;
            l++;
            cs[l]='\0';
          }  
     
          strcpy(_itemsArray[itm].tmps,cs);
          Input(_itemsArray[itm].color,xo+x-2*W_EDGE,yo+y-W_EDGE-H_TEXT+3,_itemsArray[itm].width-x+2*W_EDGE);
          Update(); 
          DrawCaret(xo,yo,x,y,r);
        }
      } // end of edition
      _itemsArray[itm].inEdit=0;
      if (o==Lstring) strcpy((char *)_itemsArray[itm].argPtr,cs);
      else
      {
        v=atof(cs);
        SetValue(_itemsArray[itm].argPtr,o,v);
      }
     
      if (t==tPlusMinus)
      {
        if (GetValue(_itemsArray[itm].argPtr,o)>_itemsArray[itm].vMax)
          SetValue(_itemsArray[itm].argPtr,o,_itemsArray[itm].vMax);
        if (GetValue(_itemsArray[itm].argPtr,o)<_itemsArray[itm].vMin)
          SetValue(_itemsArray[itm].argPtr,o,_itemsArray[itm].vMin);
      }
    }   
  }  
  Update(); 
} 


// ************************************************************
// Functions


// get value from a 2-D array

double Get2DValue(long i,long j,unsigned long a,long t)
{
  double r;
  double x,y;

  switch(t)
  {
    case Luchar:    r=(double)(((unsigned char **)a)[i][j]); break;
    case Lchar:     r=(double)(((char **)a)[i][j]); break;
        
    case Lushort:   r=(double)(((unsigned short **)a)[i][j]); break;
    case Lshort:    r=(double)(((short **)a)[i][j]); break;
    
    case Lulong:    r=(double)(((unsigned long **)a)[i][j]); break;
    case Llong:     r=(double)(((long **)a)[i][j]); break;
    
    case Lfloat:    r=(double)(((float **)a)[i][j]); break;
    
    case Ldouble:   r=((double **)a)[i][j]; break;
    
    case Lmodulus:  x=((complex **)a)[i][j].re;
                    y=((complex **)a)[i][j].im;
                    r=sqrt(x*x+y*y);
                    break;
                    
    case Lreal:      r=((complex **)a)[i][j].re; break;
    case Limaginary: r=((complex **)a)[i][j].im; break;
    
    case Lsquaremod: x=((complex **)a)[i][j].re;
                     y=((complex **)a)[i][j].im;
                     r=x*x+y*y;
                     break;
                     
    case LphaseRad:                 
    case LphaseDeg: x=((complex **)a)[i][j].re;
                    y=((complex **)a)[i][j].im;
                    
                    if ((x>0) && (y>=0))  r=atan(y/x);
                    if ((x<0) && (y>=0))  r=PI-atan(y/-x);
                    if ((x<0) && (y<0))   r=PI+atan(y/x);
                    if ((x>0) && (y<0))   r=2.*PI-atan(-y/x);
                    if ((x==0) && (y>=0)) r=PI/2.;
                    if ((x==0) && (y<0))  r=3.*PI/2.; 
                    
                    if (t==LphaseDeg) r*=180./PI;
                    break;
  }
  return(r);
}

  
// get value from a 1-D array

double Get1DValue(long i,unsigned long a,long t)
{
  double r;
  double x,y;
  
  switch(t)
  {
    case Luchar:    r=(double)(((unsigned char *)a)[i]); break;
    case Lchar:     r=(double)(((char *)a)[i]); break;
        
    case Lushort:   r=(double)(((unsigned short *)a)[i]); break;
    case Lshort:    r=(double)(((short *)a)[i]); break;
    
    case Lulong:    r=(double)(((unsigned long *)a)[i]); break;
    case Llong:     r=(double)(((long *)a)[i]); break;
    
    case Lfloat:    r=(double)(((float *)a)[i]); break;
    case Ldouble:   r=((double *)a)[i]; break;
    
    case Lmodulus:  x=((complex *)a)[i].re;
                    y=((complex *)a)[i].im;
                    r=sqrt(x*x+y*y);
                    break;
                    
    case Lreal:      r=((complex *)a)[i].re; break;
    case Limaginary: r=((complex *)a)[i].im; break;
    
    case Lsquaremod: x=((complex *)a)[i].re;
                     y=((complex *)a)[i].im;
                     r=x*x+y*y;
                     break;
                     
    case LphaseRad:                 
    case LphaseDeg: x=((complex *)a)[i].re;
                    y=((complex *)a)[i].im;
                    
                    if ((x>0) && (y>=0))  r=atan(y/x);
                    if ((x<0) && (y>=0))  r=PI-atan(y/-x);
                    if ((x<0) && (y<0))   r=PI+atan(y/x);
                    if ((x>0) && (y<0))   r=2.*PI-atan(-y/x);
                    if ((x==0) && (y>=0)) r=PI/2.;
                    if ((x==0) && (y<0))  r=3.*PI/2.; 
                    
                    if (t==LphaseDeg) r*=180./PI;
                    break;
  }
  return(r);
}


// get value from pointer

double GetValue(unsigned long a,long t)
{
  double r;
  double x,y;
  
  switch(t)
  {
    case Luchar:    r=(double)*((unsigned char *)a); break;
    case Lchar:     r=(double)*((char *)a); break;
        
    case Lushort:   r=(double)*((unsigned short *)a); break;
    case Lshort:    r=(double)*((short *)a); break;
    
    case Lulong:    r=(double)*((unsigned long *)a); break;
    case Llong:     r=(double)*((long *)a); break;
    
    case Lfloat:    r=(double)*((float *)a); break;
    case Ldouble:   r=*((double *)a); break;
    
    case Lmodulus:  x=((complex *)a)->re;
                    y=((complex *)a)->im;
                    r=sqrt(x*x+y*y);
                    break;
                    
    case Lreal:      r=((complex *)a)->re; break;
    case Limaginary: r=((complex *)a)->im; break;
    
    case Lsquaremod: x=((complex *)a)->re;
                     y=((complex *)a)->im;
                     r=x*x+y*y;
                     break;
                     
    case LphaseRad:                 
    case LphaseDeg: x=((complex *)a)->re;
                    y=((complex *)a)->im;
                    
                    if ((x>0) && (y>=0))  r=atan(y/x);
                    if ((x<0) && (y>=0))  r=PI-atan(y/-x);
                    if ((x<0) && (y<0))   r=PI+atan(y/x);
                    if ((x>0) && (y<0))   r=2.*PI-atan(-y/x);
                    if ((x==0) && (y>=0)) r=PI/2.;
                    if ((x==0) && (y<0))  r=3.*PI/2.; 
                    if (t==LphaseDeg) r*=180./PI;
                    break;
  }
  return(r);
}


// set value at a pointer

// (review cast possibilities)

void SetValue(unsigned long a,long t,char v)
{
  switch(t)
  {
    case Lchar:     *((char *)a)=v; break;    
    case Lshort:    *((short *)a)=v; break;    
    case Llong:     *((long *)a)=v; break;
    case Lfloat:    *((float *)a)=v; break;
    case Ldouble:   *((double *)a)=v; break;
    
    case Lmodulus: 
    case Lreal:
    case Limaginary:
    case Lsquaremod:
    case LphaseDeg: SetCplxValue(a,t,(double)v);
                    break;
  }
}

void SetValue(unsigned long a,long t,unsigned char v)
{
  switch(t)
  {
    case Luchar:    *((unsigned char *)a)=v; break;  
    case Lushort:   *((unsigned short *)a)=v; break;   
    case Lshort:    *((short *)a)=v; break;    
    case Llong:     *((long *)a)=v; break;
    case Lulong:    *((unsigned long *)a)=v; break;
    case Lfloat:    *((float *)a)=v; break;
    case Ldouble:   *((double *)a)=v; break;
    
    case Lmodulus: 
    case Lreal:
    case Limaginary:
    case Lsquaremod:
    case LphaseDeg: SetCplxValue(a,t,(double)v);
                    break;
  }
}

void SetValue(unsigned long a,long t,short v)
{
  switch(t)
  {   
    case Lshort:    *((short *)a)=v; break;    
    case Llong:     *((long *)a)=v; break;
    case Lfloat:    *((float *)a)=v; break;
    case Ldouble:   *((double *)a)=v; break;
    
    case Lmodulus: 
    case Lreal:
    case Limaginary:
    case Lsquaremod:
    case LphaseRad:                 
    case LphaseDeg: SetCplxValue(a,t,(double)v);
                    break;
  }
}

void SetValue(unsigned long a,long t,unsigned short v)
{
  switch(t)
  {
    case Lushort:   *((unsigned short *)a)=v; break;     
    case Llong:     *((long *)a)=v; break;
    case Lulong:    *((unsigned long *)a)=v; break;
    case Lfloat:    *((float *)a)=v; break;
    case Ldouble:   *((double *)a)=v; break;
    
    case Lmodulus: 
    case Lreal:
    case Limaginary:
    case Lsquaremod:
    case LphaseRad:                 
    case LphaseDeg: SetCplxValue(a,t,(double)v);
                    break;
  }
}

void SetValue(unsigned long a,long t,long v)
{
  switch(t)
  { 
    case Llong:     *((long *)a)=v; break;
    case Lfloat:    *((float *)a)=v; break;
    case Ldouble:   *((double *)a)=v; break;
    
    case Lmodulus: 
    case Lreal:
    case Limaginary:
    case Lsquaremod:
    case LphaseRad:                 
    case LphaseDeg: SetCplxValue(a,t,(double)v);
                    break;
  }
}

void SetValue(unsigned long a,long t,unsigned long v)
{
  switch(t)
  {
    case Lulong:    *((unsigned long *)a)=v; break;
    case Lfloat:    *((float *)a)=v; break;
    case Ldouble:   *((double *)a)=v; break;
    
    case Lmodulus: 
    case Lreal:
    case Limaginary:
    case Lsquaremod:
    case LphaseRad:                 
    case LphaseDeg: SetCplxValue(a,t,(double)v);
                    break;
  }
}

void SetValue(unsigned long a,long t,float v)
{
  switch(t)
  {
    case Lulong:    *((unsigned long *)a)=floor(v); break;
    case Llong:     *((long *)a)=floor(v); break;
    case Lfloat:    *((float *)a)=v; break;
    case Ldouble:   *((double *)a)=v; break;
    
    case Lmodulus: 
    case Lreal:
    case Limaginary:
    case Lsquaremod:
    case LphaseRad:                 
    case LphaseDeg: SetCplxValue(a,t,(double)v);
                    break;
  }
}

void SetValue(unsigned long a,long t,double v)
{
  switch(t)
  {
    case Lulong:    *((unsigned long *)a)=floor(v); break;
    case Llong:     *((long *)a)=floor(v); break;
    case Lfloat:    *((float *)a)=v; break;
    case Ldouble:   *((double *)a)=v; break;
    
    case Lmodulus: 
    case Lreal:
    case Limaginary:
    case Lsquaremod:
    case LphaseRad:                 
    case LphaseDeg: SetCplxValue(a,t,(double)v);
                    break;
  }
}

void SetCplxValue(unsigned long a,long t,double v)
{
  double r,i,m;
  
  r=((complex *)a)->re;
  i=((complex *)a)->im;
  
  switch(t)
  {
    case Lreal:      ((complex *)a)->re=v; break;
    case Limaginary: ((complex *)a)->im=v; break;
    case Lmodulus:   m=sqrt(r*r+i*i);
                     ((complex *)a)->re=r*v/m;
                     ((complex *)a)->im=i*v/m;
                     break;
    case Lsquaremod: m=sqrt(r*r+i*i);
                     ((complex *)a)->re=r*sqrt(v)/m;
                     ((complex *)a)->im=i*sqrt(v)/m;
                     break;
    case LphaseDeg:  v*=PI/180.;
    case LphaseRad:  m=sqrt(r*r+i*i);
                     ((complex *)a)->re=m*cos(v);
                     ((complex *)a)->im=m*sin(v);
                     break;
  }
}

// convert number into a character string

void NumberToString(char *s,unsigned long a,long t)
{
  short es;
  unsigned short eus;
  long el;
  unsigned long eul;
  float ef;
  double ed;
  
  switch(t)
  {
    case Lstring: strcpy(s,(char *)(a));   
                  break;
                  
    case Lchar:
    case Luchar:
    case Lshort:  es=(short)GetValue(a,t);
                  sprintf(s,"%d",es);
                  break;
   
    case Lushort: eus=(unsigned short)GetValue(a,t);
                  sprintf(s,"%d",eus);
                  break;
        
    case Llong: el=(long)GetValue(a,t);
                sprintf(s,"%ld",el);
                break;
         
    case Lulong: eul=(unsigned long)GetValue(a,t);
                 sprintf(s,"%ld",eul);
                 break;
         
    case Lfloat: ef=(float)GetValue(a,t);
                 sprintf(s,"%f",ef);
                 break;
              
    case Lreal:
    case Limaginary:
    case Lmodulus:
    case Lsquaremod:
    case LphaseDeg:
    case LphaseRad: 
    case Ldouble:   ed=GetValue(a,t);
                    sprintf(s,"%lf",ed);
                    break;
  }
}


