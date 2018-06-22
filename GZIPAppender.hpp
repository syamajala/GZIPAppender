#ifndef DDS_APPENDER_H
#define DDS_APPENDER_H

#include <log4cxx/fileappender.h>
#include <log4cxx/spi/loggingevent.h>
#include <string>
#include "gzstream.h"

namespace log4cxx
{

  class GZIPAppender : public FileAppender
  {
  public:
    DECLARE_LOG4CXX_OBJECT(GZIPAppender)

    BEGIN_LOG4CXX_CAST_MAP()
    LOG4CXX_CAST_ENTRY(GZIPAppender)
    LOG4CXX_CAST_ENTRY_CHAIN(AppenderSkeleton)
    END_LOG4CXX_CAST_MAP()

    GZIPAppender();
    ~GZIPAppender();

    // This method is called by the AppenderSkeleton#doAppend method
    void append(const spi::LoggingEventPtr& event, log4cxx::helpers::Pool& p);

    void close();

    bool isClosed() const { return closed; }

    bool requiresLayout() const { return true; }

    virtual void setFile(const LogString &file);
  };

}
#endif
