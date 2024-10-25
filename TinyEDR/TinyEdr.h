#pragma once

#include "FastMutex.h"
#include<ntdef.h>

#define DRIVER_PREFIX "TinyEdr: "
#define DRIVER_TAG 'nmys'

struct Globals {
	LIST_ENTRY ItemsHead;
	int ItemCount;
	FastMutex Mutex;
	LARGE_INTEGER RegCookie;
};

/// <summary>
/// Since we need to store every such structure as part of a linked list, each data structure must contain
///a LIST_ENTRY instance that points to the next and previous items.Since these LIST_ENTRY objects
///should not be exposed to user mode, we will define extended structures containing these entries in
///a different file, that is not shared with user mode.
///In a new file called SysMon.h we add a generic structure that holds a LIST_ENTRY together with the
///actual data structure :
/// </summary>
/// <typeparam name="T"></typeparam>
/// 
template<typename T>
struct FullItem {
	LIST_ENTRY Entry;
	T Data;
};

///
