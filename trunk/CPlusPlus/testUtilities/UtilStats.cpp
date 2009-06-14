#include <math.h>
#include "UtilStats.h"

UtilStats::UtilStats()
{

}

UtilStats::~UtilStats()
{

}

void UtilStats::Reset()
{
	m_Data.clear();
}

double UtilStats::GetStdDeviation()
{
	double mean = GetMean(), sum = 0.0;
	
   for( unsigned int i=0;i<m_Data.size();i++ )
	{
      double delta = (m_Data.at(i)-mean);
		sum += delta * delta;
	}

   return sqrt(sum);
}

double UtilStats::GetMean()
{
	double sum = 0.0f;
	for( unsigned int i=0;i<m_Data.size();i++ )
		sum += m_Data[i];

	return sum / double(m_Data.size());
}

void UtilStats::AddDataPoint( double dataPoint )
{
	m_Data.push_back(dataPoint);
}

unsigned int UtilStats::GetCount()
{
	return m_Data.size();
}

double UtilStats::GetMin()
{
   double res = 1e10;
   for(unsigned int i=0; i<m_Data.size(); i++)
      if(res > m_Data[i]) res = m_Data[i];
   return res;
}

double UtilStats::GetMax()
{
   double res = -1e10;
   for(unsigned int i=0; i<m_Data.size(); i++)
      if(res < m_Data[i]) res = m_Data[i];
   return res;
}