#include "UtilStats.h"
#include "UtilFullScreenQuad.h"
#include "UtilCacheRandomizer.h"


class IUtil
{
	public:
		static IUtil* GetInstance();
		UtilFullScreenQuad* GetUtilFullScreenQuad(){return &m_FullScreenQuad;};
		UtilCacheRandomizer* GetUtilCacheRandomizer(){return &m_CacheRandomizer;};
		UtilStats* GetUtilStats(){return &m_UtilStats;};
	
protected:
		IUtil(){};
		~IUtil(){};

	protected:
		static IUtil* m_Instance;

	UtilFullScreenQuad m_FullScreenQuad;
	UtilCacheRandomizer m_CacheRandomizer;
	UtilStats m_UtilStats;
};

inline IUtil* IUtil::GetInstance()
{
	if( m_Instance==0 )
	{
		m_Instance = new IUtil();
	}

	return m_Instance;
}