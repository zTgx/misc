template<typename Function>
std::enable_if_t <
    ! std::is_void <typename Function::return_type>::value,
    typename Function::return_type
>
foreach(Function f)
{
    PeerSequence peers (getActivePeers());
    for(PeerSequence::const_iterator i = peers.begin(); i != peers.end(); ++i)
        f (*i);
    return f();
}


struct send_always
{
    typedef void return_type;

    Message::pointer const& msg;

    send_always(Message::pointer const& m)
        : msg(m)
    { }

    void operator()(Peer::ptr const& peer) const
    {
        peer->send (msg);
    }
};


foreach (send_always (std::make_shared <Message> (s, protocol::mtSTATUS_CHANGE)));
