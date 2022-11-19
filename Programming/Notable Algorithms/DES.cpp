/*
    Pranav Chatur
    Data Encryption Standard Algorithm
    Cryptography

    Date Implememted: 19 Nov 2022
    (Note, longest ever working code written in my life till *date)

    Dynamic code hence input can be given on the way (as in run the code directly, no explanation needed).

    Sample input/outputs:-

    I)  plaintext: algorithm, key: privacy, ciphertext: 2539ee0f70985d83ac03c9c5ec54d933

        Console Output:
        Press '0' to encode string in DES Algorithm or '1' to decode hex in DES Algorithm: 0
        Enter string to be encoded: algorithm
        Enter the key: privacy

        For block 1:
        After IP: ff504e2d00ffaa1c 
        Key is e0be06474481 for Round 1 L: 00ffaa1c R: 8f4a306e 
        Key is f0366620ba42 for Round 2 L: 8f4a306e R: c6f1cf93 
        Key is e0d674748432 for Round 3 L: c6f1cf93 R: fbf0e316 
        Key is c4d3760d0c4a for Round 4 L: fbf0e316 R: 8076907d 
        Key is a6d3730cf050 for Round 5 L: 8076907d R: 4507f341 
        Key is af536321c464 for Round 6 L: 4507f341 R: 30aa6f76 
        Key is ab53d9888c82 for Round 7 L: 30aa6f76 R: 2410f549 
        Key is 1d53d98c4615 for Round 8 L: 2410f549 R: da079f73 
        Key is 3f49d8a11820 for Round 9 L: da079f73 R: 5fa8a51a 
        Key is 1e6999402a36 for Round 10 L: 5fa8a51a R: 8881bc60 
        Key is 1f2d1d35089c for Round 11 L: 8881bc60 R: f75139db 
        Key is 4f2c8d0110d3 for Round 12 L: f75139db R: bca5fd9e 
        Key is 5bacac07a025 for Round 13 L: bca5fd9e R: e02d606b 
        Key is d8acaa220dc4 for Round 14 L: e02d606b R: 4a7d07f8 
        Key is f0ae2e088197 for Round 15 L: 4a7d07f8 R: a4176e8c 
        Key is b0bea6a42168 for Round 16 L: a4176e8c R: 54724dcb 
        block 1: 2539ee0f70985d83
        For block 2:
        After IP: 0100010100010100 
        Key is e0be06474481 for Round 1 L: 00010100 R: 57751fc2 
        Key is f0366620ba42 for Round 2 L: 57751fc2 R: 851587ff 
        Key is e0d674748432 for Round 3 L: 851587ff R: 91465132 
        Key is c4d3760d0c4a for Round 4 L: 91465132 R: c9c00ede 
        Key is a6d3730cf050 for Round 5 L: c9c00ede R: c8cba62d 
        Key is af536321c464 for Round 6 L: c8cba62d R: 030345cf 
        Key is ab53d9888c82 for Round 7 L: 030345cf R: 176a04d2 
        Key is 1d53d98c4615 for Round 8 L: 176a04d2 R: 1800abf8 
        Key is 3f49d8a11820 for Round 9 L: 1800abf8 R: afd422d8 
        Key is 1e6999402a36 for Round 10 L: afd422d8 R: b2b0a93c 
        Key is 1f2d1d35089c for Round 11 L: b2b0a93c R: c45b04bd 
        Key is 4f2c8d0110d3 for Round 12 L: c45b04bd R: 6c54f033 
        Key is 5bacac07a025 for Round 13 L: 6c54f033 R: 08242844 
        Key is d8acaa220dc4 for Round 14 L: 08242844 R: 45a34b3a 
        Key is f0ae2e088197 for Round 15 L: 45a34b3a R: 5d915582 
        Key is b0bea6a42168 for Round 16 L: 5d915582 R: 7ce039ce 
        block 2: ac03c9c5ec54d933
        The encrypted message(in Hex) is 2539ee0f70985d83ac03c9c5ec54d933

    II) ciphertext: 7f8b3edddb06f0901a3740178b136cbf, key: course, plaintext: engineering

    Refer [https://page.math.tu-berlin.de/~kant/teaching/hess/krypto-ws2006/des.htm]
    for complete algorithm information (implementation and background)

*/

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <iterator>
#include <string>
#include <map>
#define all(name) name.begin(),name.end()
#define nl cout<<'\n'
#define display(name) for(auto it: name){cout<<it<<"";}cout<<" "
using namespace std;

//-------------------------------------------
//Constant Tables
vector<int> IP1 { 58, 50, 42, 34, 26, 18, 10, 2,  60, 52, 44,
            36, 28, 20, 12, 4,  62, 54, 46, 38, 30, 22,
            14, 6,  64, 56, 48, 40, 32, 24, 16, 8,  57,
            49, 41, 33, 25, 17, 9,  1,  59, 51, 43, 35,
            27, 19, 11, 3,  61, 53, 45, 37, 29, 21, 13,
            5,  63, 55, 47, 39, 31, 23, 15, 7 
};

vector<int> PC1 { 57, 49, 41, 33, 25, 17, 9,
                1, 58, 50, 42, 34, 26, 18,
                10, 2, 59, 51, 43, 35, 27,
                19, 11, 3, 60, 52, 44, 36,
                63, 55, 47, 39, 31, 23, 15,
                7, 62, 54, 46, 38, 30, 22, 
                14, 6, 61, 53, 45, 37, 29,
                21, 13, 5, 28, 20, 12, 4 
};

map<int, int> left_shift_schedule = {
    {1,1},{2,1},{9,1},{16,1},
    {3,2},{4,2},{5,2},{6,2},{7,2},{8,2},{10,2},{11,2},{12,2},{13,2},{14,2},{15,2},
};

vector<int> PC2 { 14, 17, 11, 24, 1, 5, 
                3, 28, 15, 6, 21, 10, 
                23, 19, 12, 4, 26, 8, 
                16, 7, 27, 20, 13, 2,
                41, 52, 31, 37, 47, 55, 
                30, 40, 51, 45, 33, 48,
                44, 49, 39, 56, 34, 53, 
                46, 42, 50, 36, 29, 32 
};

vector<int> E { 32, 1, 2, 3, 4, 5,
            4, 5, 6, 7, 8, 9,
            8, 9, 10, 11, 12, 13,
            12, 13, 14, 15, 16, 17,
            16, 17, 18, 19, 20, 21,
            20, 21, 22, 23, 24, 25,
            24, 25, 26, 27, 28, 29,
            28, 29, 30, 31, 32, 1 
};

vector< vector<int>> S1 { 
    {14, 4,  13, 1, 2,  15, 11, 8,  3,  10, 6,  12, 5, 9,  0,  7},
    {0, 15, 7,  4,  14, 2,  13, 1,  10, 6, 12, 11, 9,  5, 3,  8},
    {4,  1,  14, 8,  13, 6,  2, 11, 15, 12, 9, 7,  3,  10, 5,  0},
    {15, 12, 8,  2, 4,  9,  1,  7, 5,  11, 3,  14, 10, 0,  6,  13}
};

vector< vector<int>> S2 { 
    {15, 1,  8,  14, 6,  11, 3, 4,  9,  7,  2,  13, 12, 0, 5, 10},  
    {3, 13, 4,  7, 15, 2,  8,  14, 12, 0, 1,  10, 6,  9,  11, 5},
    {0, 14, 7,  11, 10, 4,  13, 1,  5,  8,  12, 6,  9,  3, 2, 15},
    {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9} 
};

vector< vector<int>> S3  { 
    {10, 0,  9,  14, 6,  3,  15, 5,  1,  13, 12, 7,  11, 4,  2,  8},  
    {13, 7,  0,  9,  3,  4, 6, 10, 2,  8,  5,  14, 12, 11, 15, 1},
    {13, 6,  4,  9,  8,  15, 3,  0,  11, 1,  2,  12, 5,  10, 14, 7},
    {1, 10, 13, 0,  6,  9,  8, 7,  4,  15, 14, 3,  11, 5,  2,  12} 
};

vector< vector<int>> S4 { 
    {7,  13, 14, 3,  0,  6,  9,  10, 1,  2, 8,  5,  11, 12, 4,  15}, 
    {13, 8,  11, 5,  6,  15, 0, 3,  4,  7, 2,  12, 1,  10, 14, 9},
    {10, 6,  9,  0, 12, 11, 7, 13, 15, 1,  3,  14, 5,  2,  8,  4},
    {3, 15, 0,  6, 10, 1,  13, 8,  9,  4,  5,  11, 12, 7, 2,  14}
};

vector< vector<int>> S5 { 
    {2,  12, 4, 1,  7,  10, 11, 6, 8,  5,  3,  15, 13, 0,  14, 9},
    {14, 11, 2,  12, 4, 7,  13, 1,  5,  0, 15, 10, 3, 9,  8,  6},
    {4,  2, 1,  11, 10, 13, 7, 8,  15, 9, 12, 5,  6,  3,  0, 14},
    {11, 8,  12, 7, 1,  14, 2, 13, 6,  15, 0,  9, 10, 4,  5,  3}
};

vector< vector<int>> S6 { 
    {12, 1,  10, 15, 9,  2,  6,  8,  0,  13, 3, 4, 14, 7,  5,  11},
    {10, 15, 4,  2,  7,  12, 9,  5, 6, 1, 13, 14, 0,  11, 3,  8},
    {9,  14, 15, 5,  2, 8, 12, 3,  7,  0,  4,  10, 1,  13, 11, 6},
    {4,  3, 2, 12, 9,  5,  15, 10, 11, 14, 1,  7,  6,  0,  8, 13}
};

vector< vector<int>> S7 { 
    {4,  11, 2,  14, 15, 0,  8, 13, 3,  12, 9,  7,  5, 10, 6,  1},
    {13, 0,  11, 7, 4,  9,  1,  10, 14, 3, 5,  12, 2,  15, 8,  6},
    {1, 4,  11, 13, 12, 3,  7, 14, 10, 15, 6,  8,  0,  5, 9,  2},
    {6,  11, 13, 8, 1,  4,  10, 7,  9,  5,  0, 15, 14, 2,  3,  12}
};

vector< vector<int>> S8 { 
    {13, 2,  8, 4,  6,  15, 11, 1,  10, 9, 3, 14, 5, 0,  12, 7},
    {1,  15, 13, 8,  10, 3,  7, 4, 12, 5, 6,  11, 0, 14, 9,  2},
    {7,  11, 4,  1, 9, 12, 14, 2,  0,  6, 10, 13, 15, 3,  5,  8},
    {2, 1, 14, 7, 4,  10, 8, 13, 15, 12, 9,  0,  3,  5, 6, 11}
};

vector<int> P { 16, 7, 20, 21, 
                29, 12, 28, 17, 
                1,  15, 23, 26, 
                5, 18, 31, 10, 
                2,  8,  24, 14, 
                32, 27, 3,  9, 
                19, 13, 30, 6,  
                22, 11,  4, 25 
};

vector<int> IP_1 { 40, 8,  48, 16, 56, 24, 64, 32, 39, 7,  47,
            15, 55, 23, 63, 31, 38, 6,  46, 14, 54, 22,
            62, 30, 37, 5,  45, 13, 53, 21, 61, 29, 36,
            4,  44, 12, 52, 20, 60, 28, 35, 3,  43, 11,
            51, 19, 59, 27, 34, 2,  42, 10, 50, 18, 58,
            26, 33, 1,  41, 9,  49, 17, 57, 25 
};

map<string, char> bin_to_hex {
    {"0000",'0'},
    {"0001",'1'},
    {"0010",'2'},
    {"0011",'3'},
    {"0100",'4'},
    {"0101",'5'},
    {"0110",'6'},
    {"0111",'7'},
    {"1000",'8'},
    {"1001",'9'},
    {"1010",'a'},
    {"1011",'b'},
    {"1100",'c'},
    {"1101",'d'},
    {"1110",'e'},
    {"1111",'f'}
};

map<char, vector<bool> > hex_to_bin {
    {'0',{0,0,0,0}},
    {'1',{0,0,0,1}},
    {'2',{0,0,1,0}},
    {'3',{0,0,1,1}},
    {'4',{0,1,0,0}},
    {'5',{0,1,0,1}},
    {'6',{0,1,1,0}},
    {'7',{0,1,1,1}},
    {'8',{1,0,0,0}},
    {'9',{1,0,0,1}},
    {'a',{1,0,1,0}},
    {'b',{1,0,1,1}},
    {'c',{1,1,0,0}},
    {'d',{1,1,0,1}},
    {'e',{1,1,1,0}},
    {'f',{1,1,1,1}}
};

//-------------------------------------------
//Basic functions

//for converting text input to binary
vector<bool> text_to_binary(string &input){
    vector<bool> input_binary;
    for(auto letter: input){
        string bin = bitset<8>((int)letter).to_string();
        for(auto digit: bin){
            input_binary.push_back((int)digit -'0');
        }
    }
    return input_binary;
}

//for converting hex input to binary
vector<bool> hex_to_binary(string &input){
    vector<bool> input_binary;
    for(auto letter: input){
        input_binary.insert(input_binary.end(),all(hex_to_bin[letter]));
    }
    return input_binary;
}

//for permuting input based on some permutation
vector<bool> permute(vector<bool> &input, vector<int> &permutation){
    vector<bool> permuted;
    for(auto position: permutation){
        permuted.push_back(input[position-1]);
    }
    return permuted;
}

//bit-wise xor function because c++ couldn't give that much
bool b_xor(bool one, bool two){return one!=two? true: false;}

//for left shifting a boolean vector
void left_shift(vector<bool> &input){
    bool temp = *(input.end()-1), temp2;
    for(vector<bool>::reverse_iterator ritr = input.rbegin()+1;ritr<input.rend();ritr++){
        temp2 = *ritr;
        *ritr = temp;
        temp = temp2;
    }
    input[input.size()-1] = temp2;
}

//for converting boolean vector to hexadecimal
string converter(vector<bool> &input){
    string returner;
    int i=0;
    while(i<input.size()){
        string test;
        char c;
        c = input[i++] + 48;
        test.push_back(c);
        c = input[i++] + 48;
        test.push_back(c);
        c = input[i++] + 48;
        test.push_back(c);
        c = input[i++] + 48;
        test.push_back(c);
        returner.push_back(bin_to_hex[test]);
    }
    return returner;
}

//for converting boolean vector to text
string binary_to_text(vector<bool> &input){
    string returner;
    int i = 0;
    vector <bool> temp;
    while(i<input.size()){
        int counter = 0;
        while(counter<8){
            temp.push_back(input[i++]);
            counter++;
        }
        int ascii = 128*temp[0] + 64*temp[1] + 32*temp[2] + 16*temp[3] + 8*temp[4];
        ascii+= 4*temp[5] + 2*temp[6] + temp[7];
        temp.clear();
        returner.push_back((char)ascii);
    }
    return returner;
}

//for breaking input into 64 bit blocks and padding
vector< vector<bool> > small_input_blocks(int mode, string &input){
    vector< vector<bool> > returner;
    vector<bool> sixty_four_bit;
    vector<bool> binary_input = !mode?text_to_binary(input): hex_to_binary(input);
    for(auto digit: binary_input){
        sixty_four_bit.push_back(digit);
        if(sixty_four_bit.size() == 64){
            returner.push_back(sixty_four_bit);
            sixty_four_bit.clear();
        }
    }

    //ensuring last block of input is also of 64 bits
    if(!sixty_four_bit.empty()){
        while(sixty_four_bit.size()!=64){
            sixty_four_bit.push_back(0);
        }
        returner.push_back(sixty_four_bit);
    }
    return returner;
}


//-------------------------------------------
//DES Specific functions

//key schedule function
vector<bool> KS(int round, vector<bool> &key){
    vector<bool> C(key.size()/2), D(key.size()/2);
    copy(key.begin(),key.end()-key.size()/2,C.begin());
    copy(key.end()-key.size()/2,key.end(),D.begin());
    int i = 0;
    while(i<left_shift_schedule[round]){
        left_shift(C);
        left_shift(D);
        ++i;
    }
    vector<bool> next_key(C);
    next_key.insert(next_key.end(),D.begin(),D.end());
    key = next_key;
    return permute(next_key,PC2);
}

//S-box 6bit to 4bit conversion function
vector<bool> S_function(vector<bool> &block, vector< vector<int> > &S){
    vector<bool> returner;
    if(block.size()!=6){cout<<"FATAL ERROR, S-Box size not equal to 6! EXITING PROGRAM...";exit(0);}
    int row = 2*block[0] + block[5];
    int col = 8*block[1] + 4*block[2] + 2*block[3] + block[4];
    for(auto digit: bitset<4>(S[row][col]).to_string()){
        returner.push_back((int)digit - '0');
    }
    if(returner.size()!=4){cout<<"FATAL ERROR, Output of S-box function not 4 bit! EXITING PROGRAM...";exit(0);}
    return returner;
}

//cipher function
vector<bool> cipher_function(int round, vector<bool> &R, vector<bool> &K, int mode){
    vector<bool> K_new = !mode? KS(round, K): K;
    cout<<"Key is ";display(converter(K_new));cout<<"for ";

    R = permute(R,E);
    vector<bool> d_box;
    if(R.size()!=K_new.size()){cout<<"SOMETHING IS WRONG sizes of R ≠ K! EXITING IMMEDIATELY...";exit(0);}
    for(int i=0;i<R.size();++i){
        d_box.push_back(b_xor(R[i],K_new[i]));
    }

    //dividing D-box into 8 S-boxes
    vector<bool> S_1,S_2,S_3,S_4,S_5,S_6,S_7,S_8;
    for(int i=0;i<48;++i){
        if(i<6){S_1.push_back(d_box[i]);}
        else if(i<12){S_2.push_back(d_box[i]);}
        else if(i<18){S_3.push_back(d_box[i]);}
        else if(i<24){S_4.push_back(d_box[i]);}
        else if(i<30){S_5.push_back(d_box[i]);}
        else if(i<36){S_6.push_back(d_box[i]);}
        else if(i<42){S_7.push_back(d_box[i]);}
        else if(i<48){S_8.push_back(d_box[i]);}
    }

    //combining 8 S_boxes
    vector<bool> S_box_combiner(S_function(S_1, S1));
    vector<bool> temp(S_function(S_2, S2));
    S_box_combiner.insert(S_box_combiner.end(),temp.begin(),temp.end());
    temp = S_function(S_3, S3);
    S_box_combiner.insert(S_box_combiner.end(),temp.begin(),temp.end());
    temp = S_function(S_4, S4);
    S_box_combiner.insert(S_box_combiner.end(),temp.begin(),temp.end());
    temp = S_function(S_5, S5);
    S_box_combiner.insert(S_box_combiner.end(),temp.begin(),temp.end());
    temp = S_function(S_6, S6);
    S_box_combiner.insert(S_box_combiner.end(),temp.begin(),temp.end());
    temp = S_function(S_7, S7);
    S_box_combiner.insert(S_box_combiner.end(),temp.begin(),temp.end());
    temp = S_function(S_8, S8);
    S_box_combiner.insert(S_box_combiner.end(),temp.begin(),temp.end());
    if(S_box_combiner.size()!=32){cout<<"FATAL ERROR, Sbox combiner isn't 32 bit! EXITING PROGRAM...";exit(0);}

    return permute(S_box_combiner,P);
}

//Feistel cipher
void feistal_cipher(int round, vector<bool> &L, vector<bool> &R, vector<bool> &K, int mode){
    vector<bool> L_new(R), R_new;
    vector<bool> fRK = cipher_function(round,R,K,mode);
    for(int i=0; i<L_new.size(); ++i){
        R_new.push_back(b_xor(L[i],fRK[i]));
    }
    L = L_new;
    R = R_new;
    return;
} 

//-------------------------------------------
//Driver functions

void encyption(){
    cout<<"Enter string to be encoded: "; 
    //taking input
    string input;
    cin>>input;
    cout<<"Enter the key: ";
    string key;
    cin>>key;
    string encrypted;

    //converting key, ensuring it is 64 bits, and permuting it through PC1
    vector<bool> binary_key = text_to_binary(key);
    while(binary_key.size()!=64){binary_key.push_back(0);}
    vector<bool> permutated_key = permute(binary_key,PC1);

    //converting each block successively
    int block_count = 1;
    for(auto block: small_input_blocks(0,input)){

    //breaking block into L and R
        cout<<"For block "<<block_count<<":";nl;
        vector<bool> post_input = permute(block, IP1);
        vector<bool> L(post_input.size()/2), R(post_input.size()/2);
        cout<<"After IP: ";display(converter(post_input));cout<<'\n';
        copy(post_input.begin(),post_input.end()-post_input.size()/2 ,L.begin());
        copy(post_input.end()-post_input.size()/2,post_input.end(),R.begin());
        int round = 1;

    //16 rounds of Feistal cipher
        while(round<17){
            feistal_cipher(round,L,R,permutated_key,0);
            cout<<"Round "<<round<<" L: ";display(converter(L));
            cout<<"R: ";display(converter(R));cout<<'\n';
            round++;
        }
    
    //Final processing
        vector<bool> pre_output(R);
        pre_output.insert(pre_output.end(),L.begin(),L.end());
        vector<bool> final_combined_block = permute(pre_output,IP_1);
        string encypted_block = converter(final_combined_block);
        encrypted.append(encypted_block);
        cout<<encypted_block;cout<<'\n';
        block_count++;
    }
    cout<<"The encrypted message(in Hex) is "<<encrypted;nl;    
}

void decryption(){
    cout<<"Enter the secret key that was shared with you earlier: ";
    //taking input
    string key;
    cin>>key;
    cout<<"Generating the keys needed for decryption...\n";
    cout<<"Enter hex to be decoded: ";
    string input;
    cin>>input;
    string decrypted;

    //Generate keys needed for decryption
    vector<bool> binary_key = text_to_binary(key);
    while(binary_key.size()!=64){binary_key.push_back(0);}
    vector<bool> permutated_key = permute(binary_key,PC1);
    vector< vector<bool> > keys;
    for(int i=1;i<17;++i){
        keys.push_back(KS(i,permutated_key));
    }

    //converting each block successively
    int block_count = 1;
    for(auto block : small_input_blocks(1,input)){

    //breaking block into L and R
        cout<<"For block "<<block_count<<":";nl;
        vector<bool> post_input = permute(block, IP1);
        vector<bool> L(post_input.size()/2), R(post_input.size()/2);
        cout<<"After IP1: ";display(converter(post_input));cout<<'\n';
        copy(post_input.begin(),post_input.end()-post_input.size()/2 ,L.begin());
        copy(post_input.end()-post_input.size()/2,post_input.end(),R.begin());
        int round = 1;

    //16 rounds of Feistal cipher
        while(round<17){
            feistal_cipher(round,L,R,keys[16-round],1);
            cout<<"Round "<<round<<" L: ";display(converter(L));
            cout<<"R: ";display(converter(R));cout<<'\n';
            round++;
        }

    //Final processing
        vector<bool> pre_output(R);
        pre_output.insert(pre_output.end(),L.begin(),L.end());
        vector<bool> final_combined_block = permute(pre_output,IP_1);
        string decypted_block = binary_to_text(final_combined_block);
        decrypted.append(decypted_block);
        cout<<"block "<<block_count<<": "<<decypted_block;cout<<'\n';
        block_count++;
    }
    cout<<"The decrypted message is "<<decrypted;nl;    
}

//MAIN
int main(){
    int choice;
    cout<<"Press ";
    while(choice!=28475){
        cout<<"'0' to encode string in DES Algorithm or '1' to decode hex in DES Algorithm: ";
        cin>>choice;
        if(!choice){
            encyption();
        }
        else if(choice==1){
            decryption();
        }
        else if(choice != 28475){
            cout<<"Incorrect choice! Try again\nPress '28475' to exit program, ";
            continue;
        }
        else{
            cout<<"Randomly typed '28475' and called it the exit code, ";
            cout<<"just like how majority of DES is designed probably\nSee you again (mostly not)\n\n\n";
            exit(0);
        }
        cout<<"\n\nPress '28475' to exit program, ";
    }
    return 0;
}
//-------------------------------------------