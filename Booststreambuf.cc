 * @par Examples
 * Writing directly from an streambuf to a socket:
 * @code
 * boost::asio::streambuf b;
 * std::ostream os(&b);
 * os << "Hello, World!\n";
 *
 * // try sending some data in input sequence
 * size_t n = sock.send(b.data());
 *
 * b.consume(n); // sent data is removed from input sequence
 * @endcode
 *
 * Reading from a socket directly into a streambuf:
 * @code
 * boost::asio::streambuf b;
 *
 * // reserve 512 bytes in output sequence
 * boost::asio::streambuf::mutable_buffers_type bufs = b.prepare(512);
 *
 * size_t n = sock.receive(bufs);
 *
 * // received data is "committed" from output sequence to input sequence
 * b.commit(n);
 *
 * std::istream is(&b);
 * std::string s;
 * boost::asio::streambuf stream_buf;
 * std::string s( (std::istreambuf_iterator<char>(&stream_buf)), std::istreambuf_iterator<char>() );

class basic_streambuf
  : public std::streambuf,
    private noncopyable
{
};


//boost_1_57_0/boost/asio/basic_streambuf.hpp


  void commit(std::size_t n)
  {
    if (pptr() + n > epptr())
      n = epptr() - pptr();
    pbump(static_cast<int>(n));
    setg(eback(), gptr(), pptr());
  }

  /// Remove characters from the input sequence.
  /**
   * Removes @c n characters from the beginning of the input sequence.
   *
   * @note If @c n is greater than the size of the input sequence, the entire
   * input sequence is consumed and no error is issued.
   */
  void consume(std::size_t n)
  {
    if (egptr() < pptr())
      setg(&buffer_[0], gptr(), pptr());
    if (gptr() + n > pptr())
      n = pptr() - gptr();
    gbump(static_cast<int>(n));
  }
