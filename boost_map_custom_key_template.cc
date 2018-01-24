template <typename Allocator = std::allocator<char>>
class OuterClass
{
	class CustomKey
	{
	public:
		int _x;

		bool operator==(const CustomKey& c) const
		{
			return _x = c._x;
		}
	};
};

template <typename T = std::allocator<char>>
std::size_t hash_value(const typename OuterClass<Allocator>::CustomKey& key) //typename 的用法，此处不加typename的话，编译器不知道::后面的CustomKey是成员变量还是类型
{
	std::size_t seed{0};

	boost::hash_value(seed, key._x);

	return seed;
}
