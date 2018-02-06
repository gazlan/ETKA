/* ******************************************************************** **
** @@
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

/* ******************************************************************** **
**                uses pre-compiled headers
** ******************************************************************** */

#include "stdafx.h"

#include "..\shared\mmf.h"
#include "..\shared\vector.h"
#include "..\shared\vector_sorted.h"

#include "defines.h"
#include "etv.h"
#include "etvDlg.h"

/* ******************************************************************** **
** @@                   internal defines
** ******************************************************************** */

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/* ******************************************************************** **
** @@                   internal prototypes
** ******************************************************************** */

/* ******************************************************************** **
** @@                   external global variables
** ******************************************************************** */

extern DWORD   dwKeepError = 0;

/* ******************************************************************** **
** @@                   static global variables
** ******************************************************************** */

ETKA_REGION    pRegionLookup[] =
{
   "А  ",   "Австрия",
   "AUG",   "Ангола",
   "AUS",   "Австралия",
   "AZ ",   "Азербайджан",
   "В  ",   "Бельгия",
   "BDS",   "Барбадос",
   "BG ",   "Болгария",
   "BIH",   "Босния и Герцеговина",
   "BOL",   "Боливия",
   "BR ",   "Бразилия",
   "BRH",   "Бахрейн",
   "BRU",   "Бруней Даруссалан",
   "BY ",   "Беларусь",
   "C  ",   "Куба",
   "CDH",   "Канада",
   "CН ",   "Швейцария",
   "CN ",   "Китайская Народная Республика, КНР",
   "CО ",   "Колумбия",
   "CR ",   "Коста-Рика",
   "CY ",   "Кипр",
   "CZ ",   "Чешская Республика",
   "D  ",   "Федеративная республика Гесрмания",
   "DK ",   "Дания",
   "DOM",   "Доминиканская Республика",
   "DZ ",   "Алжир",
   "E  ",   "Испания",
   "ЕАК",   "Кения",
   "EAT",   "Танзания",
   "EAU",   "Уганда",
   "ЕС ",   "Эквадор",
   "ES ",   "Эль-Сальвадор",
   "EST",   "Эстония",
   "ЕТ ",   "Египет",
   "ЕТН",   "Эфиопия",
   "F  ",   "Франция",
   "FIN",   "Финляндия",
   "GB ",   "Великобритания",
   "GCA",   "Гватемала",
   "GH ",   "Гана",
   "GP ",   "Гваделупа",
   "GR ",   "Греция",
   "GUS",   "Содружество Независимых Государств (бывший СССР)",
   "GUY",   "Гайана",
   "Н  ",   "Венгрия",
   "ИК ",   "Гонконг",
   "НН ",   "Гондурас",
   "MR ",   "Хорватия",
   "I  ",   "Италия",
   "IL ",   "Израиль",
   "IHD",   "Индия",
   "IРХ",   "Ирландия",
   "IS ",   "Исландия",
   "J  ",   "Япония",
   "JA ",   "Ямайка",
   "JOR",   "Иордания",
   "KSA",   "Королевство Саудовская Аравия",
   "KWT",   "Кувейт",
   "KZ ",   "Казахстан",
   "L  ",   "Люксембург",
   "LAR",   "Ливия",
   "LT ",   "Литва",
   "LV ",   "Латвия",
   "М  ",   "Мальта",
   "МА ",   "Марокко",
   "MAL",   "Малайзия",
   "МС ",   "Момако",
   "MEX",   "Мексика",
   "МК ",   "Македония",
   "МОС",   "Мозамбик",
   "MQ ",   "Мартиника",
   "H  ",   "Норвегия",
   "НАМ",   "Намибия",
   "NAR",   "Североамериканский регион",
   "NIC",   "Никарагуа",
   "HL ",   "Нидерланды",
   "NZ ",   "Новая Зеландия",
   "ОМ ",   "Оман",
   "Р  ",   "Португалия",
   "РЕ ",   "Перу",
   "PL ",   "Польша",
   "PR ",   "Пуэрто-Рико",
   "PY ",   "Парагвай",
   "Q  ",   "Катар",
   "RA ",   "Аргентина",
   "PJB",   "Ботсвана",
   "RC ",   "Тайвань",
   "RCA",   "Центральная Африка",
   "RCB",   "Конго",
   "RCH",   "Чили",
   "RI ",   "Индонезия",
   "PJL",   "Ливан",
   "RM ",   "Мадагаскар",
   "РИМ",   "Мали",
   "RH ",   "Нигер",
   "ROK",   "Корея",
   "ROU",   "Уругвай",
   "PJP",   "Филиппины",
   "RUS",   "Российская Федерация",
   "S  ",   "Швеция",
   "SGP",   "Сингапур",
   "SK ",   "Словацкая Республика",
   "SLO",   "Словения",
   "SME",   "Суринам",
   "SH ",   "Сенегал",
   "SP ",   "Сомали",
   "SYR",   "Сирия",
   "ТС ",   "Камерун",
   "ТНА",   "Таиланд",
   "ТМ ",   "Туркменистан",
   "ТН ",   "Тунис",
   "TR ",   "Турция",
   "UA ",   "Украина",
   "UAE",   "Объединённые АрабскиеЭмираты, ОАЭ",
   "USA",   "Соединённые Штаты Америки, США",
   "WAG",   "Гамбия",
   "WAL",   "Сьерра-Леоне",
   "WAH",   "Нигерия",
   "YE ",   "Йемен",
   "YU ",   "Югославия (Сербия/Черногория)",
   "YV ",   "Венесуэла",
   "Z  ",   "Замбия",
   "ZA ",   "Южная Африка",
   "ZW ",   "Зимбабве",
   NULL,    NULL
};

/* ******************************************************************** **
** @@                   real code
** ******************************************************************** */

/* ******************************************************************** **
** @@ IsPrintable()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

bool __fastcall IsPrintable(BYTE byChr)
{
   if (byChr < 0x20)
   {
      return false;
   }

   if (byChr == 0x7F)
   {
      return false;
   }

   return true;
}

/* ******************************************************************** **
** @@ CEtvDlg::CEtvDlg()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : Constructor
** ******************************************************************** */

CEtvDlg::CEtvDlg(CWnd* pParent /*=NULL*/)
:  CDialog(CEtvDlg::IDD, pParent)
{
   //{{AFX_DATA_INIT(CEtvDlg)
      // NOTE: the ClassWizard will add member initialization here
   //}}AFX_DATA_INIT
   // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
   m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

   _pOut = NULL;

   _sDBPath = _T("");
}

void CEtvDlg::DoDataExchange(CDataExchange* pDX)
{
   CDialog::DoDataExchange(pDX);
   //{{AFX_DATA_MAP(CEtvDlg)
      // NOTE: the ClassWizard will add DDX and DDV calls here
   //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEtvDlg, CDialog)
   //{{AFX_MSG_MAP(CEtvDlg)
   ON_WM_PAINT()
   ON_WM_QUERYDRAGICON()
   ON_WM_DESTROY()
   ON_WM_CLOSE()
   //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/* ******************************************************************** **
** @@ CEtvDlg::OnInitDialog()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

BOOL CEtvDlg::OnInitDialog()
{
   CDialog::OnInitDialog();

   // Set the icon for this dialog.  The framework does this automatically
   //  when the application's main window is not a dialog
   SetIcon(m_hIcon, TRUE);       // Set big icon
   SetIcon(m_hIcon, FALSE);      // Set small icon
   
   _pOut = fopen("ETKA_Dump.txt","wt");

   _sDBPath = _T("C:\\ETKA");

   CString     sPath;
   
   sPath  = _sDBPath;
   sPath += "\\DATA\\AU\\Data1\\OVERVIEW.BIN";
   fprintf(_pOut,"\n*** AUDI\n");
   GetOverviewInfo(sPath);

   sPath  = _sDBPath;
   sPath += "\\DATA\\SE\\Data1\\OVERVIEW.BIN";
   fprintf(_pOut,"\n\n*** SEAT\n");
   GetOverviewInfo(sPath);

   sPath  = _sDBPath;
   sPath += "\\DATA\\SK\\Data1\\OVERVIEW.BIN";
   fprintf(_pOut,"\n\n*** SKODA\n");
   GetOverviewInfo(sPath);

   sPath  = _sDBPath;
   sPath += "\\DATA\\VW\\Data1\\OVERVIEW.BIN";
   fprintf(_pOut,"\n\n*** VOLKSWAGEN\n");
   GetOverviewInfo(sPath);

   fclose(_pOut);
   _pOut = NULL;

   return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEtvDlg::OnPaint() 
{
   if (IsIconic())
   {
      CPaintDC dc(this); // device context for painting

      SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

      // Center icon in client rectangle
      int cxIcon = GetSystemMetrics(SM_CXICON);
      int cyIcon = GetSystemMetrics(SM_CYICON);
      CRect rect;
      GetClientRect(&rect);
      int x = (rect.Width() - cxIcon + 1) / 2;
      int y = (rect.Height() - cyIcon + 1) / 2;

      // Draw the icon
      dc.DrawIcon(x, y, m_hIcon);
   }
   else
   {
      CDialog::OnPaint();
   }
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEtvDlg::OnQueryDragIcon()
{
   return (HCURSOR) m_hIcon;
}

void CEtvDlg::OnDestroy() 
{
   CDialog::OnDestroy();
   
   // TODO: Add your message handler code here
   
}

void CEtvDlg::OnClose() 
{
   // TODO: Add your message handler code here and/or call default
   
   CDialog::OnClose();
}

/* ******************************************************************** **
** @@ CEtvDlg::Print_01()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CEtvDlg::Print_01(BYTE F1,BYTE F2,BYTE F3,BYTE F4,BYTE F5,const BYTE* const pCurr,WORD wSize,const BYTE* const pBuf)
{
   BYTE*    pNext = (BYTE*)pCurr;

   printf("%08X [",(pCurr - pBuf));

   printf("01 %02X ",F1);

   fprintf(_pOut,"\n* ");

   char  pszRegion[MAX_PATH];

   for (int ii = 0; ii < 3; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
      sprintf(&pszRegion[ii],"%c",byChr);
   }

   printf(" ");

   fprintf(_pOut,"%s\n",GetRegion(pszRegion)  ?  GetRegion(pszRegion)  :  pszRegion);
   
   wSize -= 3;

   for (ii = 0; ii < 5; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
      fprintf(_pOut,"%c",byChr);
   }

   printf(" ");
   fprintf(_pOut," ");
   
   wSize -= 5;

   switch (F1 & 0x0F)
   {
      case 0x0D:
      {
         BYTE  F01 = *pNext++;
         BYTE  F02 = *pNext++;

         BYTE  byTextSize2 = *pNext++;

         wSize -= 3;

         printf("%02X %02X {%02X} ",F01,F02,byTextSize2);

         for (ii = 0; ii < byTextSize2; ++ii)
         {
            BYTE  byChr = *pNext++;

            printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
            fprintf(_pOut,"%c",byChr);
         }

         printf(" ");
         fprintf(_pOut," ");
   
         ASSERT(wSize > byTextSize2);

         wSize -= byTextSize2;

         for (ii = 0; ii < 3; ++ii)
         {
            BYTE  byChr = *pNext++;

            printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
            fprintf(_pOut,"%c",byChr);
         }

         printf(" ");
         fprintf(_pOut," ");
   
         ASSERT(wSize > 3);

         wSize -= 3;

         BYTE  F04= *pNext++;

         --wSize;

         ASSERT(!wSize);

         printf("%02X",F04);

         break;
      }
      case 0x09:
      {
         switch (F1 & 0xF0)
         {
            case 0xF0:
            {
               BYTE  F01 = *pNext++;
               BYTE  F02 = *pNext++;
               BYTE  F03 = *pNext++;
               BYTE  F04 = *pNext++;

               BYTE  byTextSize2 = *pNext++;

               wSize -= 5;

               printf("%02X %02X %02X %02X {%02X} ",F01,F02,F03,F04,byTextSize2);

               for (ii = 0; ii < byTextSize2; ++ii)
               {
                  BYTE  byChr = *pNext++;

                  printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
                  fprintf(_pOut,"%c",byChr);
               }

               printf(" ");
               fprintf(_pOut," ");
   
               ASSERT(wSize > byTextSize2);

               wSize -= byTextSize2;

               BYTE  bySize2 = *pNext++;

               --wSize;

               ASSERT(!wSize);

               printf("{%02X} ",bySize2);

               BYTE  F05 = *pNext++;

               printf("%02X",F05);

               break;
            }
            case 0xE0:
            {
               BYTE  F01 = *pNext++;
               BYTE  F02 = *pNext++;

               BYTE  byTextSize2 = *pNext++;

               wSize -= 3;

               printf("%02X %02X {%02X} ",F01,F02,byTextSize2);

               for (ii = 0; ii < byTextSize2; ++ii)
               {
                  BYTE  byChr = *pNext++;

                  printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
                  fprintf(_pOut,"%c",byChr);
               }

               printf(" ");
               fprintf(_pOut," ");
   
               ASSERT(wSize > byTextSize2);

               wSize -= byTextSize2;

               BYTE  F04 = *pNext++;

               --wSize;

               ASSERT(!wSize);

               printf("%02X",F04);

               break;
            }
            default:
            {
               BYTE  F01 = *pNext++;
               BYTE  F02 = *pNext++;

               BYTE  byTextSize2 = *pNext++;

               wSize -= 3;

               printf("%02X %02X {%02X} ",F01,F02,byTextSize2);

               for (ii = 0; ii < byTextSize2; ++ii)
               {
                  BYTE  byChr = *pNext++;

                  printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
               }

               printf(" ");
               fprintf(_pOut," ");
   
               ASSERT(wSize > byTextSize2);

               wSize -= byTextSize2;

               BYTE  F04 = *pNext++;

               --wSize;

               ASSERT(!wSize);

               printf("%02X",F04);

               break;
            }
         }

         break;
      }
      case 0x08:
      {
         BYTE  F04 = *pNext++;
         BYTE  F05 = *pNext++;
         BYTE  F06 = *pNext++;
         BYTE  F07 = *pNext++;

         BYTE  byTextSize2 = *pNext++;

         printf("%02X %02X %02X %02X {%02X} ",F04,F05,F06,F07,byTextSize2);

         ASSERT(wSize > 5);

         wSize -= 5;

         for (ii = 0; ii < byTextSize2; ++ii)
         {
            BYTE  byChr = *pNext++;

            printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
         }

         wSize -= byTextSize2;

         ASSERT(!wSize);

         break;
      }
      default:
      {
         BYTE  F01 = *pNext++;
         BYTE  F02 = *pNext++;

         BYTE  byTextSize = *pNext++;

         wSize -= 3;

         printf("%02X %02X {%02X} ",F01,F02,byTextSize);

         for (ii = 0; ii < byTextSize; ++ii)
         {
            BYTE  byChr = *pNext++;

            printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
         }

         printf(" ");
   
         ASSERT(wSize > byTextSize);

         wSize -= byTextSize;

         for (ii = 0; ii < wSize; ++ii)
         {
            BYTE  byChr = *pNext++;

            printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
         }

         break;
      }
   }

   printf("]\n");
}

/* ******************************************************************** **
** @@ CEtvDlg::Print_02()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CEtvDlg::Print_02(BYTE F1,BYTE F2,BYTE F3,BYTE F4,BYTE F5,const BYTE* const pCurr,WORD wSize,const BYTE* const pBuf)
{
   bool     bXmode = ((F1 & 0x04) == 0x04);

   BYTE*    pNext = (BYTE*)pCurr;

   printf("%08X [",(pCurr - pBuf));

   printf("02 %02X %02X %02X %02X %02X ",F1,F2,F3,F4,F5);

   fprintf(_pOut,"\n** ");

   for (int ii = 0; ii < 5; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
      fprintf(_pOut,"%c",byChr);
   }

   fprintf(_pOut," ");

   BYTE  F01 = *pNext++;
   BYTE  F02 = *pNext++;
   BYTE  F03 = *pNext++;

   printf("%02X %02X {%02X} ",F01,F02,F03);

   if (F03 < 0xB0)
   {
      BYTE     byTextSize2 = bXmode  ?  (F03 + 3)  :  F03;

      for (ii = 0; ii < byTextSize2; ++ii)
      {
         BYTE  byChr = *pNext++;

         printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
         fprintf(_pOut,"%c",byChr);
      }

      printf(" ");
      fprintf(_pOut," ");

      ASSERT(wSize > byTextSize2);

      wSize -= byTextSize2;

      BYTE     byLastSize = *pNext++;

      printf("{%02X} ",byLastSize);

      ASSERT(wSize);

      --wSize;

      for (ii = 0; ii < (wSize - 8); ++ii)
      {
         BYTE  byChr = *pNext++;

         printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
      }
   }
   else
   {
      BYTE  F04 = *pNext++;
      BYTE  F05 = *pNext++;
   
      BYTE     byTextSize2 = bXmode  ?  (F05 + 3)  :  F05;

      printf("%02X {%02X} ",F04,F05);

      for (ii = 0; ii < byTextSize2; ++ii)
      {
         BYTE  byChr = *pNext++;

         printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
         fprintf(_pOut,"%c",byChr);
      }

      printf(" ");
      fprintf(_pOut," ");

      ASSERT(wSize > byTextSize2);

      BYTE     byLastSize = *pNext++;

      printf("{%02X} ",byLastSize);

      ASSERT(wSize);

      --wSize;

      for (ii = 0; ii < byLastSize; ++ii)
      {
         BYTE  byChr = *pNext++;

         printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
      }
   }      

   printf("]\n");
   fprintf(_pOut," ");
}

/* ******************************************************************** **
** @@ CEtvDlg::Print_22()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CEtvDlg::Print_22(BYTE byTextSize,BYTE* pNext,WORD wSize)
{
   for (int ii = 0; ii < byTextSize; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
   }

   printf(" ");

   ASSERT(wSize > byTextSize);

   wSize -= byTextSize;

   BYTE  bySize = *pNext++;

   --wSize;

   printf("{%02X} ",bySize);

   for (ii = 0; ii < 3; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
   }

   printf(" ");

   wSize -= sizeof(BYTE) * 3;

   bySize = *pNext++;

   --wSize;

   printf("{%02X} ",bySize);

   for (ii = 0; ii < wSize; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
   }
}

/* ******************************************************************** **
** @@ CEtvDlg::Print_22_60()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CEtvDlg::Print_22_60(BYTE byTextSize,BYTE* pNext,WORD wSize)
{
   for (int ii = 0; ii < byTextSize; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
   }

   printf(" ");

   ASSERT(wSize > byTextSize);

   wSize -= byTextSize;

   BYTE  bySize = *pNext++;

   --wSize;

   printf("{%02X} ",bySize);

   for (ii = 0; ii < 3; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
   }

   printf(" ");

   wSize -= sizeof(BYTE) * 3;

   bySize = *pNext++;

   --wSize;

   printf("{%02X} ",bySize);

   for (ii = 0; ii < wSize; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
   }
}

/* ******************************************************************** **
** @@ CEtvDlg::Print_23()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CEtvDlg::Print_23(BYTE byTextSize,BYTE* pNext,WORD wSize)
{
   for (int ii = 0; ii < byTextSize; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
   }

   printf(" ");

   ASSERT(wSize > byTextSize);

   wSize -= byTextSize;

   BYTE  bySize = *pNext++;

   --wSize;

   printf("{%02X} ",bySize);

   for (ii = 0; ii < wSize; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
   }
}

/* ******************************************************************** **
** @@ CEtvDlg::Print_23_40()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CEtvDlg::Print_23_40(BYTE byTextSize,BYTE* pNext,WORD wSize)
{
   BYTE  byF0 = *pNext++;

   printf("%02X ",byF0);

   --wSize;

   for (int ii = 0; ii < wSize; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
   }
}

/* ******************************************************************** **
** @@ CEtvDlg::Print_2A()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CEtvDlg::Print_2A(BYTE byTextSize,BYTE* pNext,WORD wSize)
{
   printf("{%02X} ",byTextSize);

   for (int ii = 0; ii < byTextSize; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
   }

   printf(" ");

   ASSERT(wSize > byTextSize);

   BYTE  byF0 = *pNext++;
   BYTE  byF1 = *pNext++;

   BYTE  bySize = *pNext++;

   wSize -= (byTextSize + 3);

   printf("%02X %02X {%02X} ",byF0,byF1,bySize);

   for (ii = 0; ii < bySize; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
   }

   ASSERT(wSize > bySize);

   wSize -= bySize;

   BYTE  byF2 = *pNext++;

   --wSize;

   printf("%02X ",byF2);

   for (ii = 0; ii < 3; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
   }

   wSize -= sizeof(BYTE) * 3;

   BYTE  byF3 = *pNext++;

   --wSize;

   printf("%02X ",byF3);

   for (ii = 0; ii < wSize; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
   }
}

/* ******************************************************************** **
** @@ CEtvDlg::Print_2A_60()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CEtvDlg::Print_2A_60(BYTE byTextSize,BYTE* pNext,WORD wSize)
{
   printf("{%02X} ",byTextSize);

   for (int ii = 0; ii < byTextSize; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
   }

   printf(" ");

   ASSERT(wSize > byTextSize);

   BYTE  byF0 = *pNext++;
   BYTE  byF1 = *pNext++;

   BYTE  bySize = *pNext++;

   wSize -= (byTextSize + 3);

   printf("%02X %02X {%02X} ",byF0,byF1,bySize);

   for (ii = 0; ii < bySize; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
   }

   ASSERT(wSize > bySize);

   wSize -= bySize;

   BYTE  byF2 = *pNext++;

   --wSize;

   printf("%02X ",byF2);

   for (ii = 0; ii < 3; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
   }

   wSize -= sizeof(BYTE) * 3;

   BYTE  byF3 = *pNext++;

   --wSize;

   printf("%02X ",byF3);

   for (ii = 0; ii < wSize; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
   }
}

/* ******************************************************************** **
** @@ CEtvDlg::Print_03()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CEtvDlg::Print_03(BYTE F1,BYTE F2,BYTE F3,BYTE F4,BYTE F5,const BYTE* const pCurr,WORD wSize,const BYTE* const pBuf)
{
   BYTE*    pNext = (BYTE*)pCurr;

   printf("%08X [",(pCurr - pBuf));

   printf("03 %02X %02X %02X %02X %02X ",F1,F2,F3,F4,F5);

   BYTE  F01 = *pNext++;
   BYTE  F02 = *pNext++;

   fprintf(_pOut,"%4d ",1792 + F4);

   switch (F2 & 0xF0)
   {
      case 0xF0:
      {
         BYTE  F03 = *pNext++;

         BYTE  byTextSize = *pNext++;

         printf("%02X %02X %02X {%02X} ",F01,F02,F03,byTextSize);

         wSize -= sizeof(BYTE) * 4;

         switch (F1)
         {
            case 0x22:
            {
               Print_22(byTextSize,pNext,wSize);
               break;
            }
            case 0x23:
            {
               Print_23(byTextSize,pNext,wSize);
               break;
            }
            case 0x2A:
            {
               Print_2A(*(pNext - 4),pNext - 3,wSize + 2);
               break;
            }
         }

         break;
      }
      case 0xE0:
      {
         BYTE  F03 = *pNext++;
         BYTE  F04 = *pNext++;

         BYTE  byTextSize = *pNext++;

         printf("%02X %02X %02X %02X {%02X} ",F01,F02,F03,F04,byTextSize);

         wSize -= sizeof(BYTE) * 5;

         switch (F1)
         {
            case 0x22:
            {
               Print_22(byTextSize,pNext,wSize);
               break;
            }
            case 0x23:
            {
               Print_23(byTextSize,pNext,wSize);
               break;
            }
            case 0x2A:
            {
               Print_2A(*(pNext - 3),pNext - 2,wSize + 2);
               break;
            }
         }

         break;
      }
      case 0x70:
      {
         BYTE  byTextSize = *pNext++;

         printf("%02X %02X {%02X} ",F01,F02,byTextSize);

         wSize -= sizeof(BYTE) * 3;

         switch (F1)
         {
            case 0x22:
            {
               Print_22(byTextSize,pNext,wSize);
               break;
            }
            case 0x23:
            {
               Print_23(byTextSize,pNext,wSize);
               break;
            }
            case 0x2A:
            {
               Print_2A(*(pNext - 3),pNext - 2,wSize + 2);
               break;
            }
         }

         break;
      }
      case 0x60:
      {
         BYTE  F03 = *pNext++;

         BYTE  byTextSize = *pNext++;

         printf("%02X %02X %02X {%02X} ",F01,F02,F03,byTextSize);

         wSize -= sizeof(BYTE) * 4;

         switch (F1)
         {
            case 0x22:
            {
               Print_22_60(*(pNext - 2),pNext - 1,wSize + 1);
               break;
            }
            case 0x23:
            {
               Print_23(byTextSize,pNext,wSize);
               break;
            }
            case 0x2A:
            {
               Print_2A_60(*(pNext - 4),pNext - 3,wSize + 3);
               break;
            }
         }

         break;
      }
      case 0x40:
      {
         BYTE  byTextSize = *pNext++;

         printf("%02X %02X {%02X} ",F01,F02,byTextSize);

         wSize -= sizeof(BYTE) * 3;

         switch (F1)
         {
            case 0x22:
            {
               Print_22(byTextSize,pNext,wSize);
               break;
            }
            case 0x23:
            {
               Print_23_40(byTextSize,pNext,wSize);
               break;
            }
            case 0x2A:
            {
               Print_2A(*(pNext - 3),pNext - 2,wSize + 2);
               break;
            }
         }

         break;
      }
      default:
      {
         AfxMessageBox("Error: Print_03()");
         break;
      }
   }

   printf("]\n");
}

/* ******************************************************************** **
** @@ CEtvDlg::Print_XX()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CEtvDlg::Print_XX(BYTE F0,BYTE F1,BYTE F2,BYTE F3,BYTE F4,BYTE F5,const BYTE* const pCurr,WORD wSize,const BYTE* const pBuf)
{
   BYTE*    pNext = (BYTE*)pCurr;

   printf("%08X [",(pCurr - pBuf));

   printf("%02X %02X %02X %02X %02X %02X ",F0,F1,F2,F3,F4,F5);

   for (int ii = 0; ii < wSize; ++ii)
   {
      BYTE  byChr = *pNext++;

      printf("%c",IsPrintable(byChr)  ?  byChr  :  '#');
   }

   printf("]\n");
}

/* ******************************************************************** **
** @@ CEtvDlg::GetOverviewInfo()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CEtvDlg::GetOverviewInfo(const CString& sPath)
{
   MMF      _MF;

   if (!_MF.OpenReadOnly((LPCTSTR)sPath))
   {
      // Error !
      return;         
   }

   BYTE*    pBuf   = _MF.Buffer();
   DWORD    dwSize = _MF.Size();

   BYTE*    pCurr = pBuf;

   while (pCurr < pBuf + dwSize)
   {
      WORD     wSize = *(WORD*)pCurr;
   
      pCurr += sizeof(WORD);

      BYTE  F0_RecType = *pCurr++;

      BYTE  F1 = *pCurr++;
      BYTE  F2 = *pCurr++;
      BYTE  F3 = *pCurr++;
      BYTE  F4 = *pCurr++;
      BYTE  F5 = *pCurr++;
      
      wSize -= sizeof(BYTE) * 6;

      switch (F0_RecType)
      {
         case 0x01: 
         {
            fprintf(_pOut,"\n");
            Print_01(F1,F2,F3,F4,F5,pCurr - 4,wSize + 4,pBuf);
            pCurr += wSize;
            break;
         }
         case 0x02: 
         {
            Print_02(F1,F2,F3,F4,F5,pCurr,wSize,pBuf);
            pCurr += wSize;
            break;
         }
         case 0x03: 
         {
            Print_03(F1,F2,F3,F4,F5,pCurr,wSize,pBuf);
            pCurr += wSize;
            break;
         }
         default:
         {
            Print_XX(F0_RecType,F1,F2,F3,F4,F5,pCurr,wSize,pBuf);
            pCurr += wSize;
            break;
         }
      }
   }

   _MF.Close();
}

/* ******************************************************************** **
** @@ CEtvDlg::GetRegion()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

const char* const CEtvDlg::GetRegion(const char* const pszAbbr)
{
   for (ETKA_REGION*   pRegion = pRegionLookup; pRegion->_pszAbbr; ++pRegion)
   {
      if (!strncmp(pRegion->_pszAbbr,pszAbbr,3))
      {
         return pRegion->_pszName;
      }
   }

   return NULL;
}

/* ******************************************************************** **
**                That's All
** ******************************************************************** */
