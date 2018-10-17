auto spw = std::make_shared<Widget>();          //spw被构造之后，被指向的Widget
std::weak_ptr<Widget> wpw(spw);                 //wpw和spw指向相同的Widget，引用
std::shared_ptr<Widget> spw1 = wpw.lock();      //如果wpw已经失效了，spw1是null
