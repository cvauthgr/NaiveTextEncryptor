#include <iostream>
#include <string>

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
        std::cout << "Give the encryption key ( remember this ) : " ;
        std::cin >> m_encryptionKey ;
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
            askIfTheUserWantsToReExecute();
        }while( m_usersChoiceOnContinuingExecution == 'y' || m_usersChoiceOnContinuingExecution == 'Y' ) ;
    }

    void encrypt()
    {
        for( char& passChar : m_password )
            passChar = static_cast<char>( static_cast<int>(passChar) ^ (m_encryptionKey & 0xFF) ) ;
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
