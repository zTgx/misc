boost::asio::io_service io_service_;
boost::asio::ip::tcp::acceptor m_acceptor(io_service_);

error_code ec;
m_acceptor.open(m_protocol, ec);
m_acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true), ec);
m_acceptor.bind(local_address, ec);
m_acceptor.listen(boost::asio::socket_base::max_connections, ec);

for(;;)
{
	boost::asio::ip::tcp::socket socket_(m_acceptor.get_service);
	m_acceptor.async_accept(socket_, remote_address, handler);

	if(ec)

	createSlot();
}
