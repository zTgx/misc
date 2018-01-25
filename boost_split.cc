std::string str("127.0.0.1:333");
std::vector<std::string> v;
boost::split(v, str, boost::is_any_of(":"));

std::string address = v[0];
unsigned short port = static_cast<unsigned short>(std::stoi(v[1]));

std::cout << "address : " << address << std::endl;
std::cout << "port    : " << port << std::endl;
