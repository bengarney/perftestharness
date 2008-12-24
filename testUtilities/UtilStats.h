#include <vector>

class UtilStats
{
public:
	UtilStats();
	~UtilStats();

   void Reset();

   void AddDataPoint( double dataPoint );

   unsigned int GetCount();
   double GetStdDeviation();
	double GetMean();
   double GetMin();
   double GetMax();
	
private:
	std::vector<double> m_Data;
};