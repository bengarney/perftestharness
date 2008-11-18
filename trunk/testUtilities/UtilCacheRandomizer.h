


class UtilCacheRandomizer
{
	public:
		UtilCacheRandomizer();
		~UtilCacheRandomizer();

	int ScrambleCache( );
	void Init( unsigned int numBytes );

	protected:
	unsigned char* m_pArray;
	unsigned int m_NumBytes;

};