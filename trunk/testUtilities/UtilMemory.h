#include <vector>

class UtilMemory
{
public:
	UtilMemory();
	~UtilMemory();

   static const int BufferSize = 128*1024*1024;
   static const int AccessBufferCount = BufferSize / sizeof(int);

   int *Get16ByteAlignedAccessBuffer();
   void FillAccessBufferWithRandomRange(int min, int max, int count = AccessBufferCount);

   void *Get16ByteAlignedDataBuffer();
   void FillDataBufferWithRandomFloats(int count = BufferSize / sizeof(float));

   int* GetIStatic64Bytes();
   float* GetFStatic64Bytes();
   float* GetFStatic64BytesAligned();
};