#include <vector>

class UtilMemory
{
public:
	UtilMemory();
	~UtilMemory();

   void *Get16ByteAlignedDataBuffer();
   void *Get16ByteAlignedAccessBuffer();
   static const int BufferSize = 128*1024*1024;

   int* GetIStatic64Bytes();
   float* GetFStatic64Bytes();
   float* GetFStatic64BytesAligned();
};