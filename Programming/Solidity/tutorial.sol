//Copy-paste below code in Remix IDE (https://remix.ethereum.org/)
// SPDX-License-Identifier: MIT
pragma solidity >=0.8;

//import "test2.sol";

struct DoggieKong{
    string breed;
    uint age;
}

//Give Elsu dog more toys!
contract Elsu_toys{ 
    DoggieKong public Elsu = DoggieKong("German Boy", 5);
	string[] public toys;
	function addToy(string[] calldata bro) public {
		for (uint i = 0; i < bro.length; ++i){
			toys.push(bro[i]);
		}
	}
}

//Timmy keeps record of all dogs in town, but not for free!
contract Dog_Recorder_Timmy{ 

    uint public bal;
    uint public bal_tim;
    address payable internal timmy = payable(0x5B38Da6a701c568545dCfcB03FcB875f56beddC4); //change address to any of the test accounts provided by Remix 

    function getBal() public{
        bal = msg.sender.balance;
        bal_tim = timmy.balance;
    }

    uint private count = 1;
    mapping (uint => DoggieKong) public house_no_belongs;
    DoggieKong[] public allDogs;

    function addDoggies(DoggieKong memory dog, uint _val) public payable  {
        timmy.transfer(_val); //val is in Wei, 1 Ether = 10^18 Wei
        house_no_belongs[count++] = dog;
        allDogs.push(dog);
    }
}
// Go to https://github.com/manojpramesh/solidity-cheatsheet for more (comprehensive) Solidity CheatSheet
