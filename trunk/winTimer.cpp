#include <windows.h>
#include <assert.h>
#include <stdio.h>

// Timer based on <http://www.codeguru.com/Cpp/W-P/system/timers/article.php/c5759/>
bool inTimer = false;
LARGE_INTEGER iStart, iStop, freq;

void startTimer()
{
   assert(!inTimer);
   inTimer = true;

   if ( freq.QuadPart == 0 )
   {
      QueryPerformanceFrequency(&freq);
      freq.QuadPart /= 1000;
   }

   QueryPerformanceCounter(&iStart);
}

double stopTimer()
{
   assert(inTimer);
   inTimer = false;

   QueryPerformanceCounter(&iStop);
   return ((double)iStop.QuadPart - (double)iStart.QuadPart) / (double)freq.QuadPart;
}

double currentTime()
{
   return GetTickCount() / 1000.0;
}

