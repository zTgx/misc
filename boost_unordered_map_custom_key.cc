#include <string>
#include <iostream>
#include <boost/unordered_map.hpp>
#include <boost/asio.hpp>

using namespace std;

struct person
{
    int ttl;
    boost::asio::ip::tcp::endpoint ep;

	person(int ttl, boost::asio::ip::tcp::endpoint ep)
	{
        this->ttl = ttl;
        this->ep = ep;
	}

	bool operator== (const person& p) const
	{
		return ep == p.ep;
	}
};

size_t hash_value(const person& p)
{
    return boost::hash_value(p.ep.address().to_v4().to_ulong());
}

int main()
{
	typedef boost::unordered_map<person,int> umap;
    umap m;

	person p4(23, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("1.1.1.1"), 3333));
    m.insert(umap::value_type(p4, 999));

    for(umap::iterator it=m.begin(); it != m.end(); it++)
    {
        std::cout << (*it).first.ttl << std::endl;
    }
}


