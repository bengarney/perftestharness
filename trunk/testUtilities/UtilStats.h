
#include <vector>

class UtilStats
{
	public:
		UtilStats();
		~UtilStats();

	void Reset();
	double GetStdDeviation();
	double GetMean();
	unsigned int GetCount();
	void AddDataPoint( double dataPoint );
	

	protected:
	std::vector<double> m_Data;

};