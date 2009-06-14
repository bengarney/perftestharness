#include "UtilStats.h"
#include "UtilFullScreenQuad.h"
#include "UtilCacheRandomizer.h"
#include "UtilLogger.h"
#include "UtilMemory.h"

/// Dock for various utility helper classes.
class IUtil
{
public:
   static UtilFullScreenQuad *GetUtilFullScreenQuad()
   {
		return &m_FullScreenQuad;
   }

	static UtilCacheRandomizer *GetUtilCacheRandomizer()
   {
		return &m_CacheRandomizer;
   }

	static UtilStats *GetUtilStats()
   {
		return &m_UtilStats;
   }

   static UtilLogger *GetUtilLogger()
   {
		return &m_UtilLogger;
   }

   static UtilMemory *GetUtilMemory()
   {
		return &m_UtilMemory;
   }

private:
	static UtilFullScreenQuad m_FullScreenQuad;
	static UtilCacheRandomizer m_CacheRandomizer;
	static UtilStats m_UtilStats;
   static UtilLogger m_UtilLogger;
	static UtilMemory m_UtilMemory;
};
