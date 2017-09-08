#ifndef CERTAIN_INCLUDE_CERTAIN_PLOG_BASE_H_
#define CERTAIN_INCLUDE_CERTAIN_PLOG_BASE_H_

#include "CertainUserBase.h"

namespace Certain
{

struct PLogEntityMeta_t
{
	uint64_t iMaxPLogEntry;
};

class clsPLogBase
{
public:
	virtual ~clsPLogBase()
	{
	}

	virtual int PutValue(uint64_t iEntityID, uint64_t iEntry,
			uint64_t iValueID, const string &strValue) = 0;

	virtual int GetValue(uint64_t iEntityID, uint64_t iEntry,
			uint64_t iValueID, string &strValue) = 0;

	virtual int Put(uint64_t iEntityID, uint64_t iEntry,
			const string &strRecord) = 0;

	virtual int PutWithPLogEntityMeta(uint64_t iEntityID, uint64_t iEntry,
			const PLogEntityMeta_t &tMeta, const string &strRecord)
	{
		assert(false);
		return -1;
	}

	virtual int GetPLogEntityMeta(uint64_t iEntityID, PLogEntityMeta_t &tMeta)
	{
		return -1;
	}

	virtual int Get(uint64_t iEntityID, uint64_t iEntry,
			string &strRecord) = 0;

	virtual int LoadUncommitedEntrys(uint64_t iEntityID,
			uint64_t iMaxCommitedEntry, uint64_t iMaxLoadingEntry,
			vector< pair<uint64_t, string> > &vecRecord, bool &bHasMore) = 0;

	int GetRecord(uint64_t iEntityID, uint64_t iEntry, EntryRecord_t &tSrcRecord);
	int PutRecord(uint64_t iEntityID, uint64_t iEntry, uint64_t iMaxPLogEntry, EntryRecord_t tRecord);

	static void PrintUseTimeStat();
	static void InitUseTimeStat();
};

} // namespace Certian

#endif