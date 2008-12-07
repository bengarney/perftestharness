


class UtilCacheRandomizer
{
	public:
		UtilCacheRandomizer();
		~UtilCacheRandomizer();

	int ScrambleCache( );
	void Init( unsigned int numBytes );

	protected:
	unsigned int m_NumBytes;

};