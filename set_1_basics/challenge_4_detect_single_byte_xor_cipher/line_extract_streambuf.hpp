#ifndef INCLUDED_LINE_EXTRACT_STREAMBUF
#define INCLUDED_LINE_EXTRACT_STREAMBUF

#include <streambuf>
#include <istream>

namespace cryptopals {

class line_extract_streambuf
    : public std::streambuf
{
    std::istream & d_inputStream;
    char d_buffer;
    std::istream::pos_type d_startPos;
    unsigned int d_numEndBytesRead;

  protected:
    virtual int_type underflow();

    /// only supports rewinding (i.e. pos == 0 and which == in)
    virtual pos_type seekpos(pos_type pos,
                             std::ios_base::openmode which = std::ios_base::in);

    /// only supports querying current position
    /// (i.e. off == 0, dir == cur, which == in)
    virtual pos_type seekoff(off_type off,
                             std::ios_base::seekdir dir,
                             std::ios_base::openmode which = std::ios_base::in);

  public:
    line_extract_streambuf(std::istream & inputStream);
};

}  // close namespace cryptopals

#endif
