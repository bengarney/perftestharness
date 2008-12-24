#include "UtilStats.h"
#include "UtilFullScreenQuad.h"
#include "UtilCacheRandomizer.h"
#include "UtilLogger.h"

/// Dock for various utility helper classes.
class IUtil
{
public:
	static IUtil* Get();
	
   UtilFullScreenQuad *GetUtilFullScreenQuad()
   {
      return &m_FullScreenQuad;
   }

	UtilCacheRandomizer *GetUtilCacheRandomizer()
   {
      return &m_CacheRandomizer;
   }

	UtilStats *GetUtilStats()
   {
      return &m_UtilStats;
   }

   UtilLogger *GetUtilLogger()
   {
      return &m_UtilLogger;
   }

private:
	static IUtil* m_Instance;

	UtilFullScreenQuad m_FullScreenQuad;
	UtilCacheRandomizer m_CacheRandomizer;
	UtilStats m_UtilStats;
   UtilLogger m_UtilLogger;
};

inline IUtil* IUtil::Get()
{
	if( m_Instance==0 )
		m_Instance = new IUtil();

	return m_Instance;
}