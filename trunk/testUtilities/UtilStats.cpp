
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
	double sum=0.0f;
	for( unsigned int i=0;i<m_Data.size();i++ )
	{
		sum+=m_Data.at(i);
	}

	double mean=sum/m_Data.size();

	for( unsigned int i=0;i<m_Data.size();i++ )
	{
		sum+=(m_Data.at(i)-mean)*(m_Data.at(i)-mean);
	}

	double sdMean =sum/m_Data.size();
	double sd = sqrt(sdMean);
	return sd;
}

double UtilStats::GetMean()
{
	double sum=0.0f;
	for( unsigned int i=0;i<m_Data.size();i++ )
	{
		sum+=m_Data.at(i);
	}

	double mean=sum/m_Data.size();

	return mean;
}

void UtilStats::AddDataPoint( double dataPoint )
{
	m_Data.push_back(dataPoint);
}


unsigned int UtilStats::GetCount()
{
	return m_Data.size();
}