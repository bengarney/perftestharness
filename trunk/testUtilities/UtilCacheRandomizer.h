
#define MAX_CACHE_SCRAMBLE 1024*1024*4

class UtilCacheRandomizer
{
	public:
		UtilCacheRandomizer();
		~UtilCacheRandomizer();

	int ScrambleCache( );
	void Init( unsigned int numBytes=MAX_CACHE_SCRAMBLE );

	protected:
	unsigned int m_NumBytes;

};