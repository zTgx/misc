#!/bin/bash

if [ $# -lt 1 ]; then
    echo -e "\\033[0;31mUsage : ./a.sh [name|symbol|...] [Args...] \\033[0m"

    exit
fi

case $1 in
    "name")
    echo "Calling Interface : name"

    ;;
    "symbol")
    echo "Calling Interface : symbol"

    ;;
    "decimals")
    echo "Calling Interface : decimals"

    ;;
    "totalSupply")
    echo "Calling Interface : totalSupply"
   
    ;;
    "balanceOf")
    echo "Calling Interface Name : balanceOf"
    if [ $# -ne 2 ]; then
        echo -e "\\033[0;31mArgs Error : balanceOf, Need a param [owner] \\033[0m"
        exit
    fi

    ;;
    "transfer")
    echo "Calling Interface Name : transfer"
    if [ $# -ne 3 ]; then
        echo -e "\\033[0;31mArgs Error : transfer , Need 2 params [spender] [value] \\033[0m"
        exit
    fi

    ;;
    "transferFrom")
    echo "Calling Interface Name : transferFrom"
    if [ $# -ne 4 ]; then
        echo -e "\\033[0;31mArgs Error : transferFrom , Need 3 params [owner] [spender] [value] \\033[0m"
        exit
    fi

    ;;
    "approve")
    echo "Calling Interface Name : approve"
    if [ $# -ne 3 ]; then
        echo -e "\\033[0;31mArgs Error : approve, Need 2 params [spender] [value] \\033[0m"
        exit
    fi
    ;;
    "allowance")
    echo "Calling Interface Name : allowance"
    if [ $# -ne 3 ]; then
        echo -e "\\033Args Error : allowance , Need 2 Params [owner] [spender] \\033[0m"
        exit
    fi
    ;;
    *)
    echo -e "\\033[0;31mInput Wrong Interface Name, Check it again \\033[0m"
    echo -e "\\033[0;32mUage : ./a.sh [name|symbol|...] [Args...] \\033[0m"
    exit
    ;;
esac

echo -e "\\033[0;31m--------------------------BBBBBBBBBBBBBBBBBBBBBBBBBBBBBegin----------------------------------------------------"

payloadDir="./payload/"
payloadName="$1"".txt"
payloadpath=${payloadDir}${payloadName}
echo -e "\\033[0;32mLoading payload file : [ "${payloadpath} "]" 
echo -e "\\033[0m"

luaScript=`cat ${payloadpath}` #$(<${payloadpath})
echo -e "\\033[0;33mLua script Source : "
echo -e "\\033[0m"${luaScript}
echo 

payloadHex=`echo ${luaScript} | xxd -p`
echo -e "\\033[0;34mLua script Hex :"
echo -e "\\033[0m"${payloadHex}
echo 

#sed s/[[:space:]]//g 删除所有的空格

returnvalue=""
function callcurl()
{
returnvalue=`curl -X POST -d '{ "method": "submit", "params": [{"secret": "snoPBjXtMeMyMHUVTgbuqAfg1SUTb", "tx_json": {"TransactionType": "ConfigContract", "Account": "jHb9CJAWyB4jr91VRWn96DkukG4bwdtyTh", "Method": 1, "Amount": "100000000", "Payload": "${payloadHex}"，"Args": [{"Arg": {"Parameter": ""}}]}}]}' 127.0.0.1:5060 > html.txt`
}

callcurl $*

echo ${returnvalue}
echo
echo `cat html.txt`
echo 

echo -e "\\033[0;37m---------------------------EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEnd---------------------------------------------------\\033[0m"
