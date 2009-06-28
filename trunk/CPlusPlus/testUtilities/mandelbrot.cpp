#include <stdlib.h>

#define MAX_ITERATIONS 65536
#define FRACTAL_SIZE 2048

//********************************************************************************
// solves a single point in the mandelbrot set.
//********************************************************************************
static inline unsigned int mandelbrotPoint(unsigned int iterations,double real,double imaginary)
{
   double fx,fy,xs,ys;
   unsigned int count;

   double two(2.0);

   fx = real;
   fy = imaginary;
   count = 0;

   do
   {
      xs = fx*fx;
      ys = fy*fy;
      fy = (two*fx*fy)+imaginary;
      fx = xs-ys+real;
      count++;
   } while ( xs+ys < 4.0 && count < iterations);

   return count;
}

static inline unsigned int solvePoint(unsigned int x,unsigned int y,double x1,double y1,double xscale,double yscale)
{
   return mandelbrotPoint(MAX_ITERATIONS,(double)x*xscale+x1,(double)y*yscale+y1);
}

//********************************************************************************
// solves the fractal using a single core/single thread in a single set for/next loops
//********************************************************************************
void fractalLinear(void (*workCallback)(void), int fractalSize)
{
   double  x1 = -0.56017680903960034334758968;
   double  x2 = -0.5540396934395273995800156;
   double  y1 = -0.63815211573948702427222672;
   double  y2 = y1+(x2-x1);

   double   xscale = (x2-x1)/(double)fractalSize;
   double   yscale = (y2-y1)/(double)fractalSize;

   unsigned char *fractal = (unsigned char*)malloc(sizeof(unsigned char)*fractalSize*fractalSize);
   unsigned char *dest = fractal;
   for (unsigned int y=0; y<fractalSize; y++)
   {
      for (unsigned int x=0; x<fractalSize; x++)
      {
         unsigned int v = solvePoint(x,y,x1,y1,xscale,yscale);
         if ( v == MAX_ITERATIONS )
            v = 0;
         else
            v = v&0xFF;
         *dest++ = (char)v;

         if(workCallback) workCallback();
      }
   }
   free(fractal);
}