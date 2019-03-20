pragma solidity ^0.4.19;

contract A {
    uint data;
    event e(address from, uint _u);
    
    function A() public {
        data = 444;
    }
    function() public payable{
        data += 333;
        e(msg.sender, data);
    }
    
    function getData() public view returns(uint) {
        return data;
    }
}

contract CallA {
    event e(bool _b);
    function CallA() public payable{

    }

    function callTest(address add) public returns(bool){
        bool b = add.call(bytes4(keccak256("getSet")));
        e(b);
        return b;
    }
}
