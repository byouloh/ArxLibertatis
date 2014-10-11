/*
 * Copyright 2014 Arx Libertatis Team (see the AUTHORS file)
 *
 * This file is part of Arx Libertatis.
 *
 * Arx Libertatis is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Arx Libertatis is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Arx Libertatis.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ARX_PLATFORM_PROFILER_PROFILER_H
#define ARX_PLATFORM_PROFILER_PROFILER_H

#include "platform/Platform.h"
#include "platform/Thread.h"
#include "platform/Time.h"

namespace profiler {
	
	//! Initialize the Profiler
	void initialize();
	
	//! Write the collected profile data to disk
	void flush();
	
	void registerThread(const std::string& threadName);
	void unregisterThread();
	
	void addProfilePoint(const char* tag, thread_id_type threadId, u64 startTime, u64 endTime);
}

#if BUILD_PROFILER_INSTRUMENT

class ProfileScope {
public:
	explicit ProfileScope(const char* tag)
		: m_tag(tag)
		, m_startTime(platform::getTimeUs())
	{
		arx_assert(tag != 0 && tag[0] != '\0');
	}
	
	~ProfileScope() {
		profiler::addProfilePoint(m_tag, Thread::getCurrentThreadId(), m_startTime, platform::getTimeUs());
	}
	
private:
	const char* m_tag;
	u64         m_startTime;
};

#define ARX_PROFILE(tag)           ProfileScope profileScope##__LINE__(#tag)
#define ARX_PROFILE_FUNC()         ProfileScope profileScope##__LINE__(__FUNCTION__)

#else

#define ARX_PROFILE(tag)           ARX_DISCARD(tag)
#define ARX_PROFILE_FUNC()         ARX_DISCARD()

#endif // BUILD_PROFILER_INSTRUMENT

#endif // ARX_PLATFORM_PROFILER_PROFILER_H
