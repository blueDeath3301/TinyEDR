#include "pch.h"
#include "FastMutex.h"


void FastMutex::Init() {
	ExInitializeFastMutex(&_mutex);
}

void FastMutex::Lock() {
	ExAcquireFastMutex(&_mutex);
}

void FastMutex::Unlock() {
	ExReleaseFastMutex(&_mutex);
}

/*
store all process creation/destruction information in a linked list (using LIST_ENTRY structures).
Since this linked list may be accessed concurrently by multiple threads, we need to protect it with a
mutex or a fast mutex; we’ll go with fast mutex as it’s more efficient.
*/