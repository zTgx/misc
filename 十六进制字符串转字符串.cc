            {   
                std::string hex = "0x0000000000000000000000000000000000000000000000000000000000000020000000000000000000000000000000000000000000000000000000000000000d6d7954696d654d616368696e6500000000000000000000000000000000000000";
                cwarn << "hex : " << hex;
                int len = hex.length();
                std::string newString;
                for(int i=0; i< len; i+=2)
                {
                    std::string byte = hex.substr(i,2);
                    char chr = (char) (int)std::strtol(byte.c_str(), nullptr, 16);
                    if(! isprint(chr)) continue;

                    //cwarn << "chr : " << chr;
                    newString.push_back(chr);
                }

                cwarn << "zhtian output : " << newString; //myTimeMachine
            }
