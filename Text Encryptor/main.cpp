#include <iostream>
#include <string>
#include <limits>

class encryptor
{

private :

    std::string m_password { } ;
    int m_encryptionKey { } ;
    char m_usersChoiceOnContinuingExecution { } ;

public :

    void setPassword()
    {
        std::cout << "Give the password : " ;
        std::cin >> m_password ;
    }

    void setEncryptionKey()
    {
        std::cout << "Give the encryption key : " ;

        while(!( std::cin >> m_encryptionKey ))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout <<"Encryption key can ONLY be a value of numerical type!Re-enter input!\n" ;
            std::cout << "Give the encryption key : " ;
        }
    }

    void askIfTheUserWantsToReExecute()
    {
        std::cout << "Do you want to run the encryptor again ? (y/n) : " ;
        std::cin >> m_usersChoiceOnContinuingExecution ;
    }

    void run()
    {
        do{
            clearUserChoice() ;
            setPassword() ;
            setEncryptionKey() ;
            encrypt() ;
            getEncryptedPassword();
            prompthTheUserHisNewXORDecryptionKey();
            askIfTheUserWantsToReExecute();
        }while( m_usersChoiceOnContinuingExecution == 'y' || m_usersChoiceOnContinuingExecution == 'Y' ) ;
    }

    void encrypt()
    {
        for( char& passChar : m_password )
            passChar = static_cast<char>( static_cast<int>(passChar) ^ (m_encryptionKey & 0xFF) ) ;
    }

    void XORDecryptionKey()
    {
        std::cout << "Your new decryption key is (remember this) : " << (m_encryptionKey & 0xFF) << '\n' ;
    }

    void getEncryptedPassword()
    {
        std::cout << "The password after encryption : " << m_password << '\n' ;
        clearPassword() ;
    }

    void clearPassword(){ m_password.clear() ; }
    void clearUserChoice(){ m_usersChoiceOnContinuingExecution = { } ; }

};
int main()
{
    encryptor instance { } ;

    instance.run() ;

    return 0;
}
