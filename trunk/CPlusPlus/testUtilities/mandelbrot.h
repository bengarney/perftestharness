#ifndef _MANDELBROT_H_
#define _MANDELBROT_H_

// Mandelbrot implementation licensed under the MIT, courtesy of
// Job Swarm from John Ratcliff's Code Suppository <http://code.google.com/p/jobswarm/>

// Utility to solve a mandelbrot; useful for creating CPU load.
void fractalLinear(void (*workCallback)(void) = NULL, int size=512);

// Solve a single point on mandelbrot set.
unsigned int solvePoint(unsigned int x,unsigned int y,double x1,double y1,double xscale,double yscale);

#endif