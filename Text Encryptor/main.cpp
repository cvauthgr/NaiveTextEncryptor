#include <bitset>
#include <iostream>
#include <random>
#include <string>
#include <vector>

int main()
{
    //Get the password

    std::string password { } ;
    std::cout << "Password : " ;
    std::cin >> password ;

    //Get the passwords characters

    std::vector<char> passwordChars { } ;

    std::cout << "Password characters" << std::endl ;

    for ( std::size_t index { 0 } ; index < password.length() ; ++ index )
    {
        passwordChars.push_back( password[index] ) ;
        std::cout << passwordChars[index] << '\n' ;
    }

    //Get those characters converted to integers

    std::cout << "Characters to integers " << std::endl ;

    std::vector<int> charsToIntegers { } ; //.capacity -> std::size_t

    for ( std::size_t index { 0 } ; index < passwordChars.size() ; ++ index)
    {
        charsToIntegers.push_back( passwordChars[index] ) ;
        std::cout << charsToIntegers[index] << '\n' ;
    }

    //Implicit convertion of ints to bits

    std::vector<std::bitset<8>> integersToBits { } ;

    std::cout << "Integers to bits" << std::endl ;

    for ( std::size_t index { 0 } ; index < charsToIntegers.size() ; ++ index)
    {
        //Same size vectors , constructing the new element in the place of the old one
        integersToBits.emplace_back(charsToIntegers[index]);
        std::cout << integersToBits[index] << '\n' ;
    }

    //Reversing the bits

    std::cout << "Reversed bits " << std::endl ;

    for ( std::size_t index { 0 } ; index < integersToBits.size() ; ++ index)
    {
        integersToBits.at(index).flip(  ) ;
        std::cout << integersToBits[index] << '\n' ;
    }

    //Reversed bits back to chars through .to_ulong() and then cast to int

    std::cout << "Reversed bits back to ints" << std::endl ;

    for ( std::size_t index { 0 } ; index < passwordChars.size() ; ++ index)
    {
        charsToIntegers[index] = static_cast<int>(integersToBits[index].to_ulong()) ;
        std::cout << charsToIntegers[index] << '\n' ;
    }

    //Reversed ints back to chars through .to_string()

    std::cout << "Reversed ints back to encrypted chars "<< std::endl ;

    std::vector<char> encryptedChars (  std::ssize(charsToIntegers) );

    for ( std::size_t index { 0 } ; index < charsToIntegers.size() ; ++ index)
    {
        encryptedChars[index] =  static_cast<char>(charsToIntegers[index] )  ;
        std::cout << encryptedChars[index] << '\n' ;
    }

    //Put it back to a string , our encrypted password

    std::string encryptedPassword ( std::ssize(encryptedChars) , ' ' );

    for ( std::size_t index { 0 } ; index < encryptedChars.size() ; ++ index )
    {
        encryptedPassword[index] = encryptedChars[index] ;
    }

    std::cout << "Encrypted Password : " << encryptedPassword ;

    return 0;
}
