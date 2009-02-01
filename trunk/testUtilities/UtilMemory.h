#include <vector>

class UtilMemory
{
public:
	UtilMemory();
	~UtilMemory();

   float* GetStatic1024x1024_16_Aligned();
   int* GetIStatic64Bytes();
   float* GetFStatic64Bytes();
   float* GetFStatic64BytesAligned();
};