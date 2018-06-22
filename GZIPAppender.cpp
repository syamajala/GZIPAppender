#include "GZIPAppender.hpp"
#include <stdio.h>

using namespace log4cxx;
using namespace log4cxx::helpers;

// Register this class with log4cxx
IMPLEMENT_LOG4CXX_OBJECT(GZIPAppender)

GZIPAppender::GZIPAppender()  {}

GZIPAppender::~GZIPAppender() {}

void GZIPAppender::append(const spi::LoggingEventPtr& event, Pool& p)
{
  if ( this->layout == NULL ) {
    LOG4CXX_ENCODE_CHAR(nameStr, name);
    std::string msg("No Layout set for the appender named [ ");
    msg.append(nameStr);
    msg.append(" ].");

    LOG4CXX_DECODE_CHAR(msgL, msg);
    errorHandler->error(msgL);
    return;
  }

  log4cxx::LogString fMsg;

  this->layout->format(fMsg, event, p);

  LOG4CXX_ENCODE_CHAR(fMsgStr, fMsg);

  // This example appender prints to the screen just like
  // a console appender. Do something with the data here
  printf("GZIPAppender: %s", fMsgStr.c_str());

}

void GZIPAppender::close()
{
  if (this->closed)
  {
    return;
  }

  this->closed = true;
}

void GZIPAppender::setFile(const LogString &file)
{

}
